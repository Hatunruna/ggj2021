#include "IntroductionScene.h"

#include <gf/Color.h>

#include "GameHub.h"

namespace tlw {

  IntroductionScene::IntroductionScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_storyEntity(game.resources, game.data, game.state)
  , m_skipAction("Skip")
  {
    setClearColor(gf::Color::Black);

    m_skipAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::A);
    m_skipAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::B);
    m_skipAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::X);
    m_skipAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Y);
    addAction(m_skipAction);

    addHudEntity(m_storyEntity);
  }

  void IntroductionScene::doHandleActions([[maybe_unused]] gf::Window& window) {
    if (!isActive()) {
      return;
    }

    if (m_skipAction.isActive()) {
      m_game.replaceScene(m_game.world, m_game.blackout, gf::seconds(2));
    }
  }

}
