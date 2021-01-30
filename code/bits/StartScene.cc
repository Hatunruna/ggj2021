#include "StartScene.h"

#include <gf/Color.h>

#include "Constants.h"
#include "GameHub.h"

namespace tlw {

  StartScene::StartScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_startAction("Start")
  , m_sliderAction("Slider")
  , m_streakAction("Streak")
  , m_dialogAction("Dialog")
  , m_titleEntity(game.resources)
  {
    setClearColor(gf::Color::Black);

    m_startAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::A);
    addAction(m_startAction);

    // Sequence scene
    m_streakAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::X);
    addAction(m_streakAction);

    m_sliderAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::B);
    addAction(m_sliderAction);

    m_dialogAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Y);
    addAction(m_dialogAction);

    addHudEntity(m_titleEntity);
  }

  void StartScene::doHandleActions([[maybe_unused]] gf::Window& window) {
    if (!isActive()) {
      return;
    }

    if (m_startAction.isActive()) {
      //m_game.replaceScene(m_game.introduction, m_game.blackout, gf::seconds(TransitionDelay));
      m_game.replaceScene(m_game.world);
    }


    if (m_sliderAction.isActive()) {
        m_game.replaceScene(m_game.sliderChallenge, m_game.blackout, gf::seconds(TransitionDelay));
    }
    if (m_streakAction.isActive()) {
      m_game.replaceScene(m_game.streakChallenge, m_game.blackout, gf::seconds(2));
    }

    if (m_dialogAction.isActive()) {
      m_game.replaceScene(m_game.dialog);
    }
  }

}
