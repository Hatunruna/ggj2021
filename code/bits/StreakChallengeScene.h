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
    void reset(int buttonCount);

  private:
    virtual void doProcessEvent(gf::Event& event) override;
    virtual void doHandleActions(gf::Window& window) override;
    virtual void doUpdate(gf::Time time) override;

  private:
    GameHub& m_game;
    float m_endTimer;

    gf::Action m_buttonA;
    // TODO: debug, remove later
    int currentDifficulty;
    gf::Action m_resetAction;
    gf::Action m_increaseDifficultyAction;
    gf::Action m_decreaseDifficultyAction;

    StreakEntity m_streakEntity;
  };

}

#endif // STREAK_CHALLENGE_SCENE_H
