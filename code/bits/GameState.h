#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <cstddef>
#include <map>
#include <vector>

#include <gf/Id.h>
#include <gf/Vector.h>

namespace tlw {

  constexpr int InvalidSearch = -1;

  enum class CharacterType : int {
    Holly,
    Stock,
    Bouquet,
    Elders,
    Dread,
    Gustavo,
    DogPack,
    CatPack,
  };

  enum class CharacterVisibility {
    Visible,
    Hidden,
  };

  struct Character {
    gf::Id dialog = gf::InvalidId;

    gf::Vector2i pos;
    CharacterVisibility visibility = CharacterVisibility::Hidden;
  };

  struct Hero {
    gf::Vector2i pos = {16, 20};
  };

  enum class ChallengeResult {
    None,
    Success,
    Failure,
  };

  struct Search {
    gf::Vector2i pos;
    std::size_t chapter;
    bool done = false;
  };

  struct GameState {
    GameState();

    std::size_t chapter = 0;

    gf::Id currentDialog = gf::InvalidId;
    std::size_t currentLine = 0;
    gf::Id nextDialogSuccess = gf::InvalidId;
    gf::Id nextDialogFailure = gf::InvalidId;

    ChallengeResult result = ChallengeResult::None;

    Hero hero;
    std::map<CharacterType, Character> characters;

    std::vector<Search> searchs;
    int currSearch = InvalidSearch;
  };

}

#endif // GAME_STATE_H
