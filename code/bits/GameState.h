#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <cstddef>

#include <gf/Id.h>

namespace tlw {

  struct Character {
    gf::Id dialog = gf::InvalidId;
  };

  struct GameState {
    std::size_t chapter = 0;

    gf::Id currentDialog = gf::InvalidId;
    std::size_t currentLine = 0;

  };

}

#endif // GAME_STATE_H
