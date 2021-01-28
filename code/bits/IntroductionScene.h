#ifndef INTRODUCTION_SCENE_H
#define INTRODUCTION_SCENE_H

#include <gf/Scene.h>

#include "StoryEntity.h"

namespace tlw {

  struct GameHub;

  class IntroductionScene : public gf::Scene {
  public:
    IntroductionScene(GameHub& game);

  private:
    GameHub& m_game;

    StoryEntity m_storyEntity;
  };

}

#endif // INTRODUCTION_SCENE_H
