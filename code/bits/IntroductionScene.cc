#include "IntroductionScene.h"

#include <gf/Color.h>

#include "GameHub.h"

namespace tlw {

  IntroductionScene::IntroductionScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  {
    setClearColor(gf::Color::Black);
  }

}
