#include "Memory.h"

#include <gf/Color.h>
#include <gf/Sprite.h>
#include <gf/Circ.h>

#include "GameHub.h"

namespace tlw {

    Memory::Memory(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  {
    setClearColor(gf::Color::White);

    // Define a circle, with a center at  (10, 10) and a radius of 20
    gf::CircI c1({ 10, 10 }, 20);
    gf::CircI c2({ 0, 0 }, 2);




  }

}
