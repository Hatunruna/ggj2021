#ifndef WORLD_SCENE_H
#define WORLD_SCENE_H

#include <gf/Action.h>
#include <gf/Scene.h>

#include "BuildingEntity.h"
#include "CharacterEntity.h"
#include "PlayerEntity.h"
#include "MapEntity.h"
#include "InfoEntity.h"
#include "LightEntity.h"
#include "GameState.h"

namespace tlw {

  struct GameHub;

  class WorldScene : public gf::Scene {
  public:
    WorldScene(GameHub& game);

  private:
    virtual void doProcessEvent(gf::Event& event) override;

    virtual void doHandleActions(gf::Window& window) override;

    virtual void doUpdate(gf::Time time) override;

    std::size_t getSearch();

    CharacterType getDialog();

  private:
    GameHub& m_game;

    // Actions
    gf::Action m_moveXPosAction;
    gf::Action m_moveXNegAction;
    gf::Action m_moveYPosAction;
    gf::Action m_moveYNegAction;
    gf::Action m_talkOrSearchAction;
    gf::Action m_fullscreenAction;

    // TODO: debug, to remove
    gf::Action m_printPositionAction;

    MapEntity m_mapEntity;
    BuildingEntity m_buildingEntity;
    CharacterEntity m_characterEntity;
    PlayerEntity m_playerEntity;

    InfoEntity m_infoEntity;

    LightEntity m_lightEntity;
  };
}

#endif // WORLD_SCENE_H
