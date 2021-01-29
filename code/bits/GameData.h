#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <string>
#include <vector>

namespace tlw {

  struct Chapter {
    std::string title;
    std::string text;
  };

  struct Story {
    Story();

    std::vector<Chapter> chapters;
  };

  struct GameData {
    Story story;
  };

}

#endif // GAME_DATA_H
