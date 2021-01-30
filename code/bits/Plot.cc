#include "Plot.h"

#include "GameHub.h"

using namespace gf::literals;

namespace tlw {
  Plot::Plot(GameHub& game)
  : m_game(game)
  {
    // TODO: remove this
    m_game.state.currentDialog = "Chap1Dread1"_id;
  }

  void Plot::onDialogEnd(gf::Id dialogId) {
    switch (dialogId) {
      case "Chap1Dread1"_id:
        m_game.state.currentDialog = "Chap1Elders1"_id;
        break;

      case "Chap1Elders1"_id:
        m_game.state.currentDialog = "Chap1Dread_NotFinished"_id;
        break;

      case "Chap1Dread_NotFinished"_id:
        m_game.state.currentDialog = "Chap1Dread_Finished"_id;
        break;

      case "Chap1Dread_Finished"_id:
        m_game.state.currentDialog = "Chap1Dread1"_id;
        break;

      default:
        break;
    }
  }

}
