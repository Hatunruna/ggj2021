#ifndef WORLD_SCENE_H
#define WORLD_SCENE_H

#include <gf/Action.h>
#include <gf/Scene.h>

namespace tlw {

  struct GameHub;

  class WorldScene : public gf::Scene {
  public:
    WorldScene(GameHub& game);

  private:
    virtual void doProcessEvent(gf::Event& event) override;

  private:
    GameHub& m_game;

    // Actions
    gf::Action m_moveXAction;
  };
}

#endif // WORLD_SCENE_H
