#include "GameState.h"

namespace tlw {

  GameState::GameState() {
    Character character;
    character.pos = gf::vec(0, 0);
    character.visible = true;
    characters.insert({ CharacterType::BadCat, character });

    character.pos = gf::vec(1, 0);
    character.visible = true;
    characters.insert({ CharacterType::GoodDog, character });
  }

}
