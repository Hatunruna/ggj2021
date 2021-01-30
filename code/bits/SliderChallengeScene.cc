#include "SliderChallengeScene.h"

#include "GameHub.h"

namespace tlw {
  SliderChallengeScene::SliderChallengeScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  {
    setClearColor(gf::Color::Black);

    addHudEntity(m_sliderEntity);
  }

}
