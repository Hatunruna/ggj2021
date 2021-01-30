#include "GameHub.h"

#include "config.h"

namespace tlw {

  GameHub::GameHub()
  : GameManager("The Lost Will", { GAME_DATADIR })
  , plot(*this)
  , start(*this)
  , introduction(*this)
  , world(*this)
  , streakChallenge(*this)
  , sliderChallenge(*this)
  , dialog(*this)
  {
    pushScene(start);
  }

}
