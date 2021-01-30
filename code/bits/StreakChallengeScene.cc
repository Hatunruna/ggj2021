#include "StreakChallengeScene.h"
#include "GameHub.h"
constexpr auto NUMBER_TOUCH = 4;;

namespace tlw {

    StreakChallengeScene::StreakChallengeScene(GameHub& game)
        : gf::Scene(game.getRenderer().getSize())
        , m_game(game)
        , m_streak(generateStreak())
        , m_streakEntity(game.resources, m_streak)
        , m_clock()
        , m_timer()
        , m_buttonA("A")
        , m_buttonB("B")
        , m_buttonX("X")
        , m_buttonY("Y")
    {
        m_timer = m_clock.restart();
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
        gf::Random random = gf::Random::Random(time(NULL));
        for (int i = 0; i < NUMBER_TOUCH ; i++) {
            streak.push_back((gf::GamepadButton)random.computeUniformInteger(1, 4));
        }

        return streak;
    }

    void StreakChallengeScene::doProcessEvent(gf::Event& event) {
        
    }

    void StreakChallengeScene::doHandleActions([[maybe_unused]] gf::Window& window) {
        if (m_streakEntity.m_canPlay) {

            if (m_streakPlayer.size() == m_streak.size()) {
                if (m_streak == m_streakPlayer) {
                    gf::Log::info("SUCCESS \n");
                    m_streakEntity.success();
                    return;
                }
                else {
                    for (int i = 0; i < m_streakPlayer.size(); ++i) {

                        gf::Log::info("%d , %d \n", m_streak.at(i), m_streakPlayer.at(i));

                    }
                    m_streakEntity.failed();
                    gf::Log::info("FAILED \n");
                    return;
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
        }
    }
}
