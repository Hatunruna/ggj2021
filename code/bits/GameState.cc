#include "GameState.h"

namespace tlw {

  GameState::GameState() {
    characters = {
      { CharacterType::BadCat,
        { gf::InvalidId, gf::vec(13, 18), CharacterVisibility::Visible }
      },
      { CharacterType::GoodDog,
        { gf::InvalidId, gf::vec(15, 30), CharacterVisibility::Visible }
      },
      { CharacterType::Florist,
        { gf::InvalidId, gf::vec(32, 12), CharacterVisibility::Visible }
      },
      { CharacterType::Moirai,
        { gf::InvalidId, gf::vec(32, 19), CharacterVisibility::Visible }
      },
    };
  }

}
