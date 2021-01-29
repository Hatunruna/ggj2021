#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <cstddef>

namespace tlw {

  struct HeroSkills {
    int observation = 50;
    int persuasion = 50;
  };

  struct GameState {
    std::size_t chapter = 0;
    HeroSkills skills;
  };

}

#endif // GAME_STATE_H
