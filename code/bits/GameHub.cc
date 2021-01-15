#include "GameHub.h"

#include "config.h"

namespace xy {

  GameHub::GameHub()
  : GameManager("undefined", { GAME_DATA_DIR })
  , start(*this)
  {
    pushScene(start);
  }

}
