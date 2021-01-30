#ifndef PLOT_H
#define PLOT_H

#include <gf/Id.h>

namespace tlw {

  struct GameHub;


  class Plot {
  public:
    Plot(GameHub& game);

    void onDialogEnd(gf::Id dialogId);

  private:
    GameHub& m_game;
  };

}

#endif // PLOT_H
