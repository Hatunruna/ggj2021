#include "WorldScene.h"

#include <gf/Log.h>

#include "GameHub.h"
#include "Constants.h"

namespace tlw {
  WorldScene::WorldScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_moveXPosAction("MoveXPositive")
  , m_moveXNegAction("MoveXNegative")
  , m_moveYPosAction("MoveYPositive")
  , m_moveYNegAction("MoveYNegative")
  , m_talkOrSearchAction("Talk or search")
  , m_printPositionAction("PrintPosition")
  , m_mapEntity(game.resources, game.data)
  , m_buildingEntity(game.resources, game.data)
  , m_characterEntity(game.resources, game.state)
  , m_playerEntity(game.resources, game.state, game.data)
  {
    setClearColor(gf::Color::White);

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

    m_printPositionAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Start);
    m_printPositionAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Back);
    addAction(m_printPositionAction);

    addWorldEntity(m_mapEntity);
    addWorldEntity(m_buildingEntity);
    addWorldEntity(m_characterEntity);
    addWorldEntity(m_playerEntity);

    setWorldViewSize(TileSize * gf::Vector2f(8.f, 8.f));
  }

  void WorldScene::doProcessEvent([[maybe_unused]] gf::Event& event) {
  }

  void WorldScene::doHandleActions([[maybe_unused]] gf::Window& window) {
    if (!isActive()) {
      return;
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
    }

    if (m_talkOrSearchAction.isActive()) {
      for (auto & [ characterType, character ] : m_game.state.characters) {
        if (character.visibility != CharacterVisibility::Visible) {
          continue;
        }

        if (gf::chebyshevDistance(m_game.state.hero.pos, character.pos) <= 1) {
          if (character.dialog != gf::InvalidId) {
            m_game.state.currentDialog = character.dialog;
            m_game.pushScene(m_game.dialog);
          }
        }
      }
    }

    if (m_printPositionAction.isActive()) {
      gf::Log::debug("Player position: %dx%d\n", m_game.state.hero.pos.x, m_game.state.hero.pos.y);
    }
  }

  void WorldScene::doUpdate([[maybe_unused]] gf::Time time) {
    setWorldViewCenter((m_game.state.hero.pos + 0.5f) * TileSize);
  }
}
