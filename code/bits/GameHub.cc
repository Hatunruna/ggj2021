#include "GameHub.h"

#include "config.h"

namespace tlw {

  GameHub::GameHub()
  : GameManager("The Lost Will", { GAME_DATA_DIR })
  , start(*this)
  {
    pushScene(start);
  }

}
