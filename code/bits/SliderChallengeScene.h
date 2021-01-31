#ifndef SLIDER_CHALLENGE_SCENE_H
#define SLIDER_CHALLENGE_SCENE_H

#include <gf/Action.h>
#include <gf/Scene.h>

#include "SliderEntity.h"

namespace tlw {

  struct GameHub;

  class SliderChallengeScene : public gf::Scene {
  public:
    SliderChallengeScene(GameHub& game);

    void reset(SliderChallengeDifficulty difficulty);

  private:
    void doHandleActions([[maybe_unused]] gf::Window& window) override;
    virtual void doUpdate(gf::Time time) override;

  private:
    GameHub& m_game;
    SliderEntity m_sliderEntity;
    float m_endTimer;

    gf::Action m_stopCursorAction;
    // TODO: To debug and test actions, remove it later
    gf::Action m_increaseSpeedAction;
    gf::Action m_decreaseSpeedAction;
    gf::Action m_resetAction;
  };
}

#endif // SLIDER_CHALLENGE_SCENE_H
