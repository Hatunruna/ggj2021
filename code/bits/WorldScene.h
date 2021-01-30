#ifndef WORLD_SCENE_H
#define WORLD_SCENE_H

#include <gf/Action.h>
#include <gf/Scene.h>

#include "CharacterEntity.h"
#include "PlayerEntity.h"
#include "MapEntity.h"

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
    CharacterEntity m_characterEntity;
    MapEntity m_mapEntity;
  };
}

#endif // WORLD_SCENE_H
