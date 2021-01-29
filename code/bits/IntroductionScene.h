#ifndef INTRODUCTION_SCENE_H
#define INTRODUCTION_SCENE_H

#include <gf/Action.h>
#include <gf/Scene.h>

#include "StoryEntity.h"

namespace tlw {

  struct GameHub;

  class IntroductionScene : public gf::Scene {
  public:
    IntroductionScene(GameHub& game);


  private:
    void doHandleActions(gf::Window& window) override;

  private:
    GameHub& m_game;

    StoryEntity m_storyEntity;

    gf::Action m_skipAction;
  };

}

#endif // INTRODUCTION_SCENE_H
