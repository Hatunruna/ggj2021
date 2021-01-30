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
  , m_playerEntity(game.state)
  , m_characterEntity(game.resources, game.state)
  , m_mapEntity(game.resources)
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

    addWorldEntity(m_mapEntity);
    addWorldEntity(m_playerEntity);
    addWorldEntity(m_characterEntity);

    setWorldViewSize(TileSize * gf::Vector2f(8.f, 8.f));
  }

  void WorldScene::doProcessEvent(gf::Event& event) {
    /*switch (event.type) {
      case gf::EventType::GamepadAxisMoved: {
        const gf::GamepadAxisEvent& gamepadEvent = event.gamepadAxis;
        std::string gamepadName = gf::Gamepad::getName(gamepadEvent.id);
        int32_t eventID = static_cast<int32_t>(gamepadEvent.id);
        std::string axisName = gf::Gamepad::getAxisName(gamepadEvent.axis);
        int16_t value = gamepadEvent.value;

        gf::Log::debug("gamepad: %s\n", gamepadName.c_str());
        gf::Log::debug("eventID: %d\n", eventID);
        gf::Log::debug("axisName: %s\n", axisName.c_str());
        gf::Log::debug("axisName: %d\n", value);
        break;
      }

      default:
        break;
    }*/
  }

  void WorldScene::doHandleActions([[maybe_unused]] gf::Window& window) {
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

    // gf::Log::debug("New player position: %dx%d\n", m_game.state.hero.pos.x, m_game.state.hero.pos.y);
  }

  void WorldScene::doUpdate([[maybe_unused]] gf::Time time) {
    //TODO: do offset to point in the middle of the tile
    setWorldViewCenter(m_game.state.hero.pos * TileSize);
  }
}
