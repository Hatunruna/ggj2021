#ifndef SLIDER_CHALLENGE_SCENE_H
#define SLIDER_CHALLENGE_SCENE_H

#include <gf/Scene.h>

#include "SliderEntity.h"

namespace tlw {

  struct GameHub;

  class SliderChallengeScene : public gf::Scene {
  public:
    SliderChallengeScene(GameHub& game);

  private:
    GameHub& m_game;
    SliderEntity m_sliderEntity;
  };
}

#endif // SLIDER_CHALLENGE_SCENE_H
