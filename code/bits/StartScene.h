#ifndef START_SCENE_H
#define START_SCENE_H

#include <gf/Scene.h>

#include "TitleEntity.h"

namespace tlw {

  struct GameHub;

  class StartScene : public gf::Scene {
  public:
    StartScene(GameHub& game);

  private:
    GameHub& m_game;

    TitleEntity m_title;
  };

}

#endif // START_SCENE_H
