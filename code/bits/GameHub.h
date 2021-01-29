#ifndef GAME_HUB_H
#define GAME_HUB_H

#include <gf/GameManager.h>

#include "GameData.h"
#include "GameState.h"
#include "IntroductionScene.h"
#include "StartScene.h"

namespace tlw {

  struct GameHub : gf::GameManager {
    GameHub();

    GameData data;
    GameState state;

    StartScene start;
    IntroductionScene introduction;

  };

}


#endif // GAME_HUB_H
