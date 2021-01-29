#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <gf/Action.h>
#include <gf/Scene.h>

namespace tlw {

  struct GameHub;

  class GameScene : public gf::Scene {
  public:
    GameScene(GameHub& game);

  private:
    virtual void doProcessEvent(gf::Event& event) override;

  private:
    GameHub& m_game;

    // Actions
    gf::Action m_moveXAction;
  };
}

#endif // GAME_SCENE_H
