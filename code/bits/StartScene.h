#ifndef START_SCENE_H
#define START_SCENE_H

#include <gf/Scene.h>

namespace xy {

  struct GameHub;

  class StartScene : public gf::Scene {
  public:
    StartScene(GameHub& game);

  private:
    GameHub& m_game;
  };

}

#endif // START_SCENE_H
