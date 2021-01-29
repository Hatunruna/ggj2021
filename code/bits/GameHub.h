#ifndef GAME_HUB_H
#define GAME_HUB_H

#include <gf/GameManager.h>
#include <gf/SegueEffects.h>

#include "GameData.h"
#include "WorldScene.h"
#include "GameState.h"
#include "IntroductionScene.h"
#include "StreakChallenge.h"
#include "StartScene.h"

namespace tlw {

  struct GameHub : gf::GameManager {
    GameHub();

    GameData data;
    GameState state;

    StartScene start;
    IntroductionScene introduction;
    WorldScene world;
    StreakChallenge streakChallenge;

    gf::BlackoutSegueEffect blackout;
  };

}


#endif // GAME_HUB_H
