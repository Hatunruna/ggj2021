#include "StreakChallengeScene.h"
#include "GameHub.h"
constexpr auto NUMBER_TOUCH = 5;

namespace tlw {

  StreakChallengeScene::StreakChallengeScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_streakEntity(game.resources)
  , m_clock()
  , m_buttonA("A")
  , m_buttonB("B")
  , m_buttonX("X")
  , m_buttonY("Y")
  , m_gameEnd(false)
  {
    m_streak = generateStreak();
    m_streakEntity.updateStreak(m_streak);
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
  }


  std::vector<gf::GamepadButton> StreakChallengeScene::generateStreak() {
    std::vector<gf::GamepadButton> streak;

    for (int i = 0; i < NUMBER_TOUCH ; i++) {
      streak.push_back(static_cast<gf::GamepadButton>(m_game.random.computeUniformInteger(1, 4)));
    }
    return streak;
  }

  void StreakChallengeScene::doProcessEvent(gf::Event& event) {

  }

  void StreakChallengeScene::doHandleActions([[maybe_unused]] gf::Window& window) {  
    if (m_streakEntity.canPlay()) {
      if (m_streakPlayer.size() == m_streak.size()) {
        m_gameEnd = true;
        if (m_streak == m_streakPlayer) {
          m_streakEntity.success();
        }
        else {                
          m_streakEntity.failed();
        }
      }

      if (m_buttonA.isActive()) {
        m_streakPlayer.push_back(gf::GamepadButton::A);
        gf::Log::info("A Pressed \n");

        m_streakEntity.displayPlayerAnswer(gf::GamepadButton::A);
      }
      else if (m_buttonB.isActive()) {
        m_streakPlayer.push_back(gf::GamepadButton::B);
        gf::Log::info("B Pressed \n");

        m_streakEntity.displayPlayerAnswer(gf::GamepadButton::B);
      }
      else if (m_buttonX.isActive()) {

        m_streakPlayer.push_back(gf::GamepadButton::X);
        gf::Log::info("X Pressed \n");
                

        m_streakEntity.displayPlayerAnswer(gf::GamepadButton::X);
      }
      else if (m_buttonY.isActive()) {
        m_streakPlayer.push_back(gf::GamepadButton::Y);
        gf::Log::info("Y Pressed \n");

        m_streakEntity.displayPlayerAnswer(gf::GamepadButton::Y);
      }

    } else {
      if (m_gameEnd) {
        if (m_buttonX.isActive()) { // press X to start a new game
          m_streakEntity.reset();
          m_streakPlayer = {};
          m_streak = generateStreak();
          m_gameEnd = false;
          m_streakEntity.updateStreak(m_streak);
        }
      }
    }
  }
}
