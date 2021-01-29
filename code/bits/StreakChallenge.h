#ifndef STREAK_CHALLENGE_H
#define STREAK_CHALLENGE_H

#include <gf/Scene.h>

namespace tlw {

  struct GameHub;

  class StreakChallenge : public gf::Scene {
  public:
      StreakChallenge(GameHub& game);
  private:
    GameHub& m_game;

   
  };

}

#endif // STREAK_CHALLENGE_H
