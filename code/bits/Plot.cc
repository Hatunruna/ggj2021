#include "Plot.h"

#include "GameHub.h"

using namespace gf::literals;

namespace tlw {
  Plot::Plot(GameHub& game)
  : m_game(game)
  {
    // TODO: remove this
//     m_game.state.currentDialog = "Chap1Dread1"_id;

    m_game.state.characters[CharacterType::Florist].dialog = "Chap1Bouquet1"_id;
    m_game.state.characters[CharacterType::Moirai].dialog = "Chap1Elders1"_id;

  }

  void Plot::onDialogEnd(gf::Id dialogId) {
    switch (dialogId) {
      case "Chap1Elders1"_id:
        m_game.state.characters[CharacterType::Moirai].dialog = "Chap1Elders2"_id;
        break;

      case "Chap1Dread1"_id:
        break;

      case "Chap1Dread_NotFinished"_id:
        break;

      case "Chap1Dread_Finished"_id:
        break;

      default:
        break;
    }
  }

  void Plot::onStreakChallengeEnd() {
  }

  void Plot::onSliderChallengeEnd() {
  }

}
