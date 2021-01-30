#ifndef STREAK_CHALLENGE_SCENE_H
#define STREAK_CHALLENGE_SCENE_H

#include <vector>
#include <iostream>
#include <gf/Scene.h>
#include <gf/Random.h>
#include <gf/Log.h>
#include <gf/Action.h>
#include <gf/Color.h>
#include <gf/Sprite.h>
#include <gf/Transformable.h>
#include <gf/Circ.h>
#include <gf/Drawable.h>
#include <gf/Shapes.h>

#include "StreakEntity.h"

namespace tlw {

  struct GameHub;

  class StreakChallengeScene : public gf::Scene {
  public:
    StreakChallengeScene(GameHub& game);
    void reset();
  
  private:
    virtual void doProcessEvent(gf::Event& event) override;
    virtual void doHandleActions(gf::Window& window) override;
    virtual void doUpdate(gf::Time time) override;
    void generateStreak();

  private:
    GameHub& m_game;
    StreakEntity m_streakEntity;
    std::vector<gf::GamepadButton> m_streak;
    std::vector<gf::GamepadButton> m_streakPlayer;
    gf::Action m_buttonA;
    gf::Action m_buttonB;
    gf::Action m_buttonX;
    gf::Action m_buttonY;
    bool m_gameEnd;
    float m_endTimer;
  };

}

#endif // STREAK_CHALLENGE_SCENE_H
