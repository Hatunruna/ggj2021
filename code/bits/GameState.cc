#include "GameState.h"

namespace tlw {

  GameState::GameState() {
    characters = {
      { CharacterType::BadCat,
        { gf::InvalidId, gf::vec(0, 0), CharacterVisibility::Visible }
      },
      { CharacterType::GoodDog,
        { gf::InvalidId, gf::vec(1, 0), CharacterVisibility::Visible }
      },
      { CharacterType::Florist,
        { gf::InvalidId, gf::vec(2, 0), CharacterVisibility::Visible }
      },
      { CharacterType::Moirai,
        { gf::InvalidId, gf::vec(3, 0), CharacterVisibility::Visible }
      },
    };
  }

}
