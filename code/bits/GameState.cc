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
        { gf::InvalidId, gf::vec(32, 13), CharacterVisibility::Visible }
      },
      { CharacterType::Moirai,
        { gf::InvalidId, gf::vec(32, 20), CharacterVisibility::Visible }
      },
      { CharacterType::Dread,
        { gf::InvalidId, gf::vec(15, 23), CharacterVisibility::Visible }
      },
      { CharacterType::DogPack,
        { gf::InvalidId, gf::vec(22, 32), CharacterVisibility::Visible }
      },
      { CharacterType::Gustavo,
        { gf::InvalidId, gf::vec(38, 29), CharacterVisibility::Visible }
      },
    };
  }

}
