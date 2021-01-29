#include "StreakChallenge.h"

#include <iostream>
#include <gf/Color.h>
#include <gf/Sprite.h>
#include <gf/Transformable.h>
#include <gf/Circ.h>
#include <gf/Drawable.h>
#include <gf/Shapes.h>

#include "GameHub.h"

namespace tlw {

    StreakChallenge::StreakChallenge(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  {
    setClearColor(gf::Color::White);
  }

}
