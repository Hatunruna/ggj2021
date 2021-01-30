#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <map>
#include <string>
#include <vector>

#include <gf/Id.h>
#include <gf/Array2D.h>
#include <gf/Vector.h>

namespace tlw {

  struct Chapter {
    std::string title;
    std::string text;
  };


  enum DialogType {
    Normal,
    Investigation,
  };

  struct DialogLine {
    std::string speaker;
    std::string words;
  };

  struct Dialog {
    DialogType type;
    std::vector<DialogLine> lines;
    DialogLine thoughts;
    DialogLine question;
  };

  enum TileState {
    Walkable,
    NoWalkable
  };

  struct GameData {
    GameData();

    std::vector<Chapter> chapters;
    std::map<gf::Id, Dialog> dialogs;

    gf::Array2D<TileState, int> tiles;
  };

}

#endif // GAME_DATA_H
