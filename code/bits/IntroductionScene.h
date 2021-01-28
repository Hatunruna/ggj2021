#ifndef INTRODUCTION_SCENE_H
#define INTRODUCTION_SCENE_H

#include <gf/Scene.h>

namespace tlw {

  struct GameHub;

  class IntroductionScene : public gf::Scene {
  public:
    IntroductionScene(GameHub& game);

  private:
    GameHub& m_game;
  };

}

#endif // INTRODUCTION_SCENE_H
