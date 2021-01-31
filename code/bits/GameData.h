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

  enum class DialogType {
    Normal,
    Investigation,
    Search,
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

  enum class TileState {
    Walkable,
    NoWalkable,
  };

  enum class BuildingType {
    BouquetShop,
    BouquetNeighbor1,
    BouquetNeighbor2,
    WoodHouse,
    WoodNeighbor,
    BenchUp,
    BenchDown,
    BenchLeft,
    GustavoShop,
    Fountain,
    House1,
    House2,
    Pub,
  };

  struct Building {
    BuildingType type;
    gf::Vector2i pos;
  };

  struct GameData {
    GameData();

    std::vector<Chapter> chapters;
    std::map<gf::Id, Dialog> dialogs;
    gf::Array2D<TileState, int> tiles;
    std::vector<Building> buildings;
    std::vector<int> limitClues; // Number of clues (INVESTIGATION or SEARCH) to pass to next chapter
  };

}

#endif // GAME_DATA_H
