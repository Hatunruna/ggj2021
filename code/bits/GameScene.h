#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <gf/Scene.h>

namespace tlw {

  struct GameHub;

  class GameScene : public gf::Scene {
  public:
    GameScene(GameHub& game);

  private:
    GameHub& m_game;
  };
}

#endif // GAME_SCENE_H
