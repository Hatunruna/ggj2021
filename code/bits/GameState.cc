#include "GameState.h"

using namespace gf::literals;

namespace tlw {

  GameState::GameState()
  : chapter(0)
  , finishedInvestigations(0)
  , finishedSearchs(0)
  {
    characters = {
      { CharacterType::Holly,
        { gf::InvalidId, gf::vec(13, 18), CharacterVisibility::Visible }
      },
      { CharacterType::Stock,
        { gf::InvalidId, gf::vec(15, 30), CharacterVisibility::Visible }
      },
      { CharacterType::Bouquet,
        { gf::InvalidId, gf::vec(32, 13), CharacterVisibility::Visible }
      },
      { CharacterType::Elders,
        { gf::InvalidId, gf::vec(32, 20), CharacterVisibility::Visible }
      },
      { CharacterType::Dread,
        { gf::InvalidId, gf::vec(15, 23), CharacterVisibility::Visible }
      },
      { CharacterType::DogPack,
        { gf::InvalidId, gf::vec(22, 32), CharacterVisibility::Visible }
      },
      { CharacterType::CatPack,
        { gf::InvalidId, gf::vec(34,  6), CharacterVisibility::Visible }
      },
      { CharacterType::Gustavo,
        { gf::InvalidId, gf::vec(38, 29), CharacterVisibility::Visible }
      },
    };

    searchs = {
      // { "Chap1Search"_id, 5, gf::vec(11, 18), 0 },
      // { "Chap1Search"_id, 3, gf::vec(10, 18), 0 },
      // { "Chap1Search"_id, 4, gf::vec( 9, 18), 0 },
      { "Chap1SearchWoodHouse"_id, 2, gf::vec(22, 13), 0 },
      { "Chap2SearchGarbageCan"_id, 3, gf::vec(15, 13), 1 },
    };
  }
}
