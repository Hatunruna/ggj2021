#include "GameHub.h"

#include "config.h"

namespace tlw {

  GameHub::GameHub()
  : GameManager("The Lost Will", { GAME_DATADIR })
  , start(*this)
  , introduction(*this)
  , world(*this)
  , streakChallenge(*this)
  , dialog(*this)
  {
    pushScene(start);
  }

}
