#include "StartScene.h"

#include <gf/Color.h>

#include "GameHub.h"

namespace tlw {

  StartScene::StartScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_title(game.resources)
  {
    setClearColor(gf::Color::Black);

    addHudEntity(m_title);
  }

}
