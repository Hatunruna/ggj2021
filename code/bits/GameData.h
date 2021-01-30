#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <map>
#include <string>
#include <vector>

#include <gf/Id.h>

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
  };

  struct GameData {
    GameData();

    std::vector<Chapter> chapters;
    std::map<gf::Id, Dialog> dialogs;
  };

}

#endif // GAME_DATA_H
