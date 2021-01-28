#ifndef GAME_HUB_H
#define GAME_HUB_H

#include <gf/GameManager.h>

#include "StartScene.h"
#include "IntroductionScene.h"

namespace tlw {

  struct GameHub : gf::GameManager {
    GameHub();

    StartScene start;
    IntroductionScene introduction;

  };

}


#endif // GAME_HUB_H
