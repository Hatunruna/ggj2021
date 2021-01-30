#include "Plot.h"

#include "GameHub.h"

using namespace gf::literals;

namespace tlw {
  Plot::Plot(GameHub& game)
  : m_game(game)
  {
    // TODO: remove this
    m_game.state.currentDialog = "Chap1DreadFirstMeeting"_id;
  }

  void Plot::onDialogEnd(gf::Id dialogId) {
    switch (dialogId) {
      case "Chap1DreadFirstMeeting"_id:
        break;

      default:
        break;
    }
  }

}
