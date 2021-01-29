#ifndef MEMORY_SCENE_H
#define MEMORY_SCENE_H

#include <gf/Scene.h>

namespace tlw {

  struct GameHub;

  class Memory : public gf::Scene {
  public:
      Memory(GameHub& game);
  private:
    GameHub& m_game;
  };

}

#endif // MEMORY_SCENE_H
