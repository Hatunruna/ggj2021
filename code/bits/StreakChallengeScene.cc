#include "StreakChallengeScene.h"
#include "GameHub.h"
constexpr auto NUMBER_TOUCH = 5;

namespace tlw {

  StreakChallengeScene::StreakChallengeScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_streakEntity(game.resources)
  , m_buttonA("A")
  , m_buttonB("B")
  , m_buttonX("X")
  , m_buttonY("Y")
  , m_gameEnd(false)
  , m_endTimer(0.f)
  {
    generateStreak();
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

  void StreakChallengeScene::reset()
  {
    m_streakEntity.reset();
    m_streakPlayer.clear();
    m_gameEnd = false;
    m_endTimer = 0.f;
    generateStreak();
    m_streakEntity.updateStreak(m_streak);
  }

  void StreakChallengeScene::generateStreak() {
    m_streak.clear();

    for (int i = 0; i < NUMBER_TOUCH ; i++) {
      m_streak.push_back(static_cast<gf::GamepadButton>(m_game.random.computeUniformInteger(1, 4)));
    }
  }

  void StreakChallengeScene::doProcessEvent([[maybe_unused]] gf::Event& event) {
  }

  void StreakChallengeScene::doHandleActions([[maybe_unused]] gf::Window& window) {
    if (!isActive()) {
      return;
    }

    if (m_streakEntity.canPlay()) {
      if (m_streakPlayer.size() == m_streak.size()) {
        if (m_streak == m_streakPlayer) {
          m_streakEntity.success();
        }
        else {                
          m_streakEntity.failed();
        }

        m_game.state.searchs[m_game.state.currSearch].done = true;
        m_game.state.currSearch = InvalidSearch;
        m_gameEnd = true;
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
    }
  }

  void StreakChallengeScene::doUpdate([[maybe_unused]] gf::Time time) {
    if (m_gameEnd) {
      m_endTimer += time.asSeconds();

      //Time in seconds before vanish of the scene
      constexpr float timeBeforeVanish = 3.f;
      if (m_endTimer >= timeBeforeVanish) {
        m_game.popScene();
      }
    }
  }
}
