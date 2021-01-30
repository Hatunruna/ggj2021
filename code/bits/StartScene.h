#ifndef START_SCENE_H
#define START_SCENE_H

#include <gf/Scene.h>
#include <gf/Action.h>

#include "TitleEntity.h"

namespace tlw {

  struct GameHub;

  class StartScene : public gf::Scene {
  public:
    StartScene(GameHub& game);

  private:
    void doHandleActions(gf::Window& window) override;

  private:
    GameHub& m_game;

    gf::Action m_startAction;

    // TODO remove the test actions later
    gf::Action m_memoryAction;
    gf::Action m_sliderAction;
    gf::Action m_dialogAction;

    TitleEntity m_titleEntity;
  };

}

#endif // START_SCENE_H
