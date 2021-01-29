#include "StartScene.h"

#include <gf/Color.h>

#include "GameHub.h"

namespace tlw {

  StartScene::StartScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_startAction("Start")
  , m_memoryAction("Memory")
  , m_titleEntity(game.resources)
  {
    setClearColor(gf::Color::Black);

    m_startAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::A);
    m_startAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::B);
    addAction(m_startAction);


    // Sequence scene
    m_memoryAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::X);
    m_memoryAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Y);
    addAction(m_memoryAction);

    addHudEntity(m_titleEntity);
  }

  void StartScene::doHandleActions([[maybe_unused]] gf::Window& window) {

    if (m_startAction.isActive()) {
      m_game.replaceScene(m_game.introduction, m_game.blackout, gf::seconds(2));
    }
    if (m_memoryAction.isActive()) {
        m_game.replaceScene(m_game.memory, m_game.blackout, gf::seconds(2));
    }
  }

}
