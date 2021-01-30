#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <cstddef>

#include <gf/Id.h>
#include <gf/Vector.h>

namespace tlw {

  struct Character {
    gf::Id dialog = gf::InvalidId;
  };

  struct Hero {
    gf::Vector2i pos = {0, 0};
  };

  struct GameState {
    std::size_t chapter = 0;

    gf::Id currentDialog = gf::InvalidId;
    std::size_t currentLine = 0;

    Hero hero;
  };

}

#endif // GAME_STATE_H
