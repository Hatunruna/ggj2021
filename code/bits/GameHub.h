#ifndef GAME_HUB_H
#define GAME_HUB_H

#include <gf/GameManager.h>
#include <gf/SegueEffects.h>

#include "DialogScene.h"
#include "GameData.h"
#include "GameState.h"
#include "IntroductionScene.h"
#include "Plot.h"
#include "SliderChallengeScene.h"
#include "StreakChallenge.h"
#include "StartScene.h"
#include "WorldScene.h"

namespace tlw {

  struct GameHub : gf::GameManager {
    GameHub();

    GameData data;
    GameState state;
    Plot plot;

    StartScene start;
    IntroductionScene introduction;
    WorldScene world;
    StreakChallenge streakChallenge;
    SliderChallengeScene sliderChallenge;
    DialogScene dialog;

    gf::BlackoutSegueEffect blackout;
  };

}


#endif // GAME_HUB_H
