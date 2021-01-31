#ifndef STREAK_ENTITY_H
#define STREAK_ENTITY_H

#include <gf/Activities.h>
#include <gf/Entity.h>
#include <gf/Font.h>
#include <gf/Gamepad.h>
#include <gf/Random.h>
#include <gf/ResourceManager.h>
#include <gf/Shapes.h>

#include "GameState.h"

namespace tlw {
  class StreakEntity : public gf::Entity {
  public:
    StreakEntity(gf::ResourceManager& resources, gf::Random& random);

    void reset(int buttonCount);
    void addPlayerInput(gf::GamepadButton gamepadButton);
    bool isCorrect() const;
    ChallengeResult getStatus() const;

    void update(gf::Time time) override;
    void render(gf::RenderTarget& target, const gf::RenderStates& states) override;

  private:
    void generateStreak(int buttonCount);

  private:
    gf::Random m_random;
    gf::Font& m_buttonFont;
    gf::Font& m_messageFont;
    gf::Texture& m_buttonSolutionTexture;
    gf::Texture& m_buttonPlayerTexture;

    ChallengeResult m_status;
    std::vector<gf::GamepadButton> m_streakSolution;
    std::vector<gf::GamepadButton> m_streakPlayer;
    float m_countdown;


    float m_timer;
    float m_opacity;
    gf::activity::AnyActivity m_activities;
  };
}


#endif // STREAK_ENTITY_H
