#include "GameScene.h"

#include <gf/Log.h>

#include "GameHub.h"

namespace tlw {
  GameScene::GameScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_moveXAction("MoveX")
  {
    setClearColor(gf::Color::White);

    // m_moveXAction.addGamepadAxisControl(gf::AnyGamepad, gf::GamepadAxis::LeftX, gf::GamepadAxisDirection::Negative);
    // m_moveXAction.addGamepadAxisControl(gf::AnyGamepad, gf::GamepadAxis::LeftY, gf::GamepadAxisDirection::Negative);
    // addAction(m_moveXAction);
  }

  void GameScene::doProcessEvent(gf::Event& event) {
    switch (event.type) {
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
    }
  }
}
