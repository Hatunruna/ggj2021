#include "StreakChallengeScene.h"

#include "Constants.h"
#include "GameHub.h"

namespace tlw {

  StreakChallengeScene::StreakChallengeScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_endTimer(0.0f)
  , m_streakEntity(game.resources, game.random)
  , m_buttonA("A")
  , m_buttonB("B")
  , m_buttonX("X")
  , m_buttonY("Y")
  , currentDifficulty(5)
  , m_resetAction("ResetAction")
  , m_increaseDifficultyAction("IncreaseDifficulty")
  , m_decreaseDifficultyAction("DecreaseDifficulty")
  {
    setClearColor(gf::Color::Black);

    addHudEntity(m_streakEntity);

    m_buttonA.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::A);
    addAction(m_buttonA);

    m_buttonB.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::B);
    addAction(m_buttonB);

    m_buttonX.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::X);
    addAction(m_buttonX);

    m_buttonY.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Y);
    addAction(m_buttonY);

    m_resetAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Start);
    m_resetAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::Back);
    addAction(m_resetAction);

    m_increaseDifficultyAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::RightBumper);
    addAction(m_increaseDifficultyAction);

    m_decreaseDifficultyAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::LeftBumper);
    addAction(m_decreaseDifficultyAction);
  }

  void StreakChallengeScene::reset(int buttonCount)
  {
    m_endTimer = 0.0f;
    m_streakEntity.reset(buttonCount);
  }

  void StreakChallengeScene::doProcessEvent([[maybe_unused]] gf::Event& event) {
  }

  void StreakChallengeScene::doHandleActions([[maybe_unused]] gf::Window& window) {
    if (!isActive()) {
      return;
    }

    if (m_buttonA.isActive()) {
      m_streakEntity.addPlayerInput(gf::GamepadButton::A);
    } else if (m_buttonB.isActive()) {
      m_streakEntity.addPlayerInput(gf::GamepadButton::B);
    } else if (m_buttonX.isActive()) {
      m_streakEntity.addPlayerInput(gf::GamepadButton::X);
    } else if (m_buttonY.isActive()) {
      m_streakEntity.addPlayerInput(gf::GamepadButton::Y);
    }

    if (m_resetAction.isActive()) {
      reset(currentDifficulty);
    }
    if (m_increaseDifficultyAction.isActive()) {
      reset(++currentDifficulty);
    }
    if (m_decreaseDifficultyAction.isActive()) {
      reset(--currentDifficulty);
    }
  }

  void StreakChallengeScene::doUpdate([[maybe_unused]] gf::Time time) {
    if (!isActive()) {
      return;
    }

    assert(m_game.state.currSearch != InvalidSearch);

    if (m_streakEntity.getStatus() != ChallengeResult::None) {
      m_endTimer += time.asSeconds();

      //Time in seconds before vanish of the scene
      if (m_endTimer >= SceneBeforeVanishDelay) {
        assert(m_game.state.currSearch < m_game.state.searchs.size());
        m_game.state.searchs.at(m_game.state.currSearch).done = true;
        m_game.state.currSearch = InvalidSearch;
        m_game.popScene();
      }
    }
  }
}
