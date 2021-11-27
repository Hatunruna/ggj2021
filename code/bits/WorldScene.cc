#include "WorldScene.h"

#include <gf/Log.h>

#include "GameHub.h"
#include "Constants.h"

namespace {
  //Vision of player in number of tiles
  constexpr gf::Vector2f VisionPlayer(8.f, 8.f);
}

namespace tlw {
  WorldScene::WorldScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_moveXPosAction("MoveXPositive")
  , m_moveXNegAction("MoveXNegative")
  , m_moveYPosAction("MoveYPositive")
  , m_moveYNegAction("MoveYNegative")
  , m_talkOrSearchAction("Talk or search")
  , m_fullscreenAction("Fullscreen")
  , m_printPositionAction("PrintPosition")
  , m_mapEntity(game.resources, game.data)
  , m_buildingEntity(game.resources, game.data)
  , m_characterEntity(game.resources, game.state)
  , m_playerEntity(game.resources, game.state, game.data)
  , m_infoEntity(game.resources)
  , m_lightEntity(game.getRenderer().getSize(), game.data)
  {
    setClearColor(gf::Color::Black);

    m_moveXPosAction.addGamepadAxisControl(gf::AnyGamepad, gf::GamepadAxis::LeftX, gf::GamepadAxisDirection::Positive);
    m_moveXPosAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::DPadRight);
    m_moveXPosAction.setContinuous();
    addAction(m_moveXPosAction);

    m_moveXNegAction.addGamepadAxisControl(gf::AnyGamepad, gf::GamepadAxis::LeftX, gf::GamepadAxisDirection::Negative);
    m_moveXNegAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::DPadLeft);
    m_moveXNegAction.setContinuous();
    addAction(m_moveXNegAction);

    m_moveYPosAction.addGamepadAxisControl(gf::AnyGamepad, gf::GamepadAxis::LeftY, gf::GamepadAxisDirection::Positive);
    m_moveYPosAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::DPadDown);
    m_moveYPosAction.setContinuous();
    addAction(m_moveYPosAction);

    m_moveYNegAction.addGamepadAxisControl(gf::AnyGamepad, gf::GamepadAxis::LeftY, gf::GamepadAxisDirection::Negative);
    m_moveYNegAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::DPadUp);
    m_moveYNegAction.setContinuous();
    addAction(m_moveYNegAction);

    m_talkOrSearchAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::A);
    addAction(m_talkOrSearchAction);

    m_fullscreenAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Guide);
    addAction(m_fullscreenAction);

    m_printPositionAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Start);
    m_printPositionAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Back);
    addAction(m_printPositionAction);

    addWorldEntity(m_mapEntity);
    addWorldEntity(m_buildingEntity);
    addWorldEntity(m_characterEntity);
    addWorldEntity(m_playerEntity);
    addWorldEntity(m_lightEntity);

    addHudEntity(m_infoEntity);

    setWorldViewSize(TileSize * VisionPlayer);
  }

  void WorldScene::doProcessEvent([[maybe_unused]] gf::Event& event) {
  }

  void WorldScene::doHandleActions(gf::Window& window) {
    if (!isActive()) {
      return;
    }

    if (m_fullscreenAction.isActive()) {
      window.toggleFullscreen();
    }

    //Actions for moving player
    if (m_moveXPosAction.isActive()) {
      m_playerEntity.move(gf::Direction::Right);
    } else if (m_moveXNegAction.isActive()) {
      m_playerEntity.move(gf::Direction::Left);
    } else if (m_moveYPosAction.isActive()) {
      m_playerEntity.move(gf::Direction::Down);
    } else if (m_moveYNegAction.isActive()) {
      m_playerEntity.move(gf::Direction::Up);
    } else {
      m_playerEntity.move(gf::Direction::Center);
    }

    if (m_talkOrSearchAction.isActive()) {
      // Check NPC
      CharacterType characterType = getDialog();
      if (characterType != CharacterType::None) {
        auto & character = m_game.state.characters[characterType];
        m_game.state.currentDialog = character.dialog;
        m_game.pushScene(m_game.dialog);
      }

      // Check search
      std::size_t searchId = getSearch();
      if (searchId != InvalidSearch) {
        auto & search = m_game.state.searchs[searchId];

        m_game.state.currentDialog = search.dialog;
        m_game.pushScene(m_game.dialog);
        m_game.state.currSearch = searchId;
        m_game.streakChallenge.reset(search.buttonCount);
      }
    }

    if (m_printPositionAction.isActive()) {
      gf::Log::debug("Player position: %dx%d\n", m_game.state.hero.pos.x, m_game.state.hero.pos.y);
    }
  }

  void WorldScene::doUpdate([[maybe_unused]] gf::Time time) {
    setWorldViewCenter(m_game.state.hero.middle + 0.5f * TileSize);

    m_infoEntity.setSearchActive(getSearch() != InvalidSearch);
    m_infoEntity.setDialogActive(getDialog() != CharacterType::None);
  }

  std::size_t WorldScene::getSearch() {
    for (std::size_t i = 0; i < m_game.state.searchs.size(); ++i) {
      auto & search = m_game.state.searchs[i];

      if (search.done || search.chapter != m_game.state.chapter) {
        continue;
      }

      if (gf::chebyshevDistance(m_game.state.hero.pos, search.pos) <= 1) {
        if (search.dialog != gf::InvalidId) {
          return i;
        }
      }
    }

    return InvalidSearch;
  }

  CharacterType WorldScene::getDialog() {
    for (auto & [ characterType, character ] : m_game.state.characters) {
      if (character.visibility != CharacterVisibility::Visible) {
        continue;
      }

      if (gf::chebyshevDistance(m_game.state.hero.pos, character.pos) <= 1) {
        if (character.dialog != gf::InvalidId) {
          return characterType;
        }
      }
    }

    return CharacterType::None;
  }
}
