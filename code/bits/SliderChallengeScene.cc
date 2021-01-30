#include "SliderChallengeScene.h"

#include <gf/Log.h>

#include "GameHub.h"

namespace tlw {
  SliderChallengeScene::SliderChallengeScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_sliderEntity(game.resources)
  , m_stopCursorAction("StopCursor")
  , m_increaseSpeedAction("IncreaseSpeed")
  , m_decreaseSpeedAction("DecreaseSpeed")
  , m_resetAction("Reset")
  {
    setClearColor(gf::Color::Black);

    m_stopCursorAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::A);
    m_stopCursorAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::B);
    m_stopCursorAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::X);
    m_stopCursorAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Y);
    addAction(m_stopCursorAction);

    m_increaseSpeedAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::RightBumper);
    addAction(m_increaseSpeedAction);

    m_decreaseSpeedAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::LeftBumper);
    addAction(m_decreaseSpeedAction);

    m_resetAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Start);
    m_resetAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Back);
    addAction(m_resetAction);

    addHudEntity(m_sliderEntity);
  }

  void SliderChallengeScene::reset(SliderChallengeDifficulty difficulty) {
    m_sliderEntity.setDifficulty(difficulty);
  }

  void SliderChallengeScene::doHandleActions([[maybe_unused]] gf::Window& window) {
    if (!isActive()) {
      return;
    }

    if (m_stopCursorAction.isActive()) {
      bool hit = m_sliderEntity.stopCursor();
      if (hit) {
        gf::Log::debug("Target hit!\n");
        m_game.state.result = ChallengeResult::Success;
      } else {
        gf::Log::debug("Target missed... Loser!\n");
        m_game.state.result = ChallengeResult::Failure;
      }

      m_game.plot.onSliderChallengeEnd();
    }

    if (m_increaseSpeedAction.isActive()) {
      m_sliderEntity.increaseSpeed();
    }

    if (m_decreaseSpeedAction.isActive()) {
      m_sliderEntity.decreaseSpeed();
    }

    if (m_resetAction.isActive()) {
      m_sliderEntity.reset();
    }
  }

}
