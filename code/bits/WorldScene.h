#ifndef WORLD_SCENE_H
#define WORLD_SCENE_H

#include <gf/Action.h>
#include <gf/Scene.h>

#include "PlayerEntity.h"

namespace tlw {

  struct GameHub;

  class WorldScene : public gf::Scene {
  public:
    WorldScene(GameHub& game);

  private:
    virtual void doProcessEvent(gf::Event& event) override;

    virtual void doHandleActions(gf::Window& window) override;

  private:
    GameHub& m_game;

    // Actions
    gf::Action m_moveXPosAction;
    gf::Action m_moveXNegAction;
    gf::Action m_moveYPosAction;
    gf::Action m_moveYNegAction;

    PlayerEntity m_playerEntity;
  };
}

#endif // WORLD_SCENE_H
