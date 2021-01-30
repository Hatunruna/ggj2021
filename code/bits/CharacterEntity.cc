#include "CharacterEntity.h"

#include <gf/RenderTarget.h>
#include <gf/Sprite.h>

#include "Constants.h"
#include "GameState.h"

namespace tlw {
  CharacterEntity::CharacterEntity(gf::ResourceManager& resources, GameState& state)
  : m_state(state)
  , m_woodCatTexture(resources.getTexture("images/wood_cat.png"))
  , m_woodDogTexture(resources.getTexture("images/wood_dog.png"))
  , m_floristTexture(resources.getTexture("images/florist.png"))
  , m_moiraiTexture(resources.getTexture("images/moirai.png"))
  , m_dreadTexture(resources.getTexture("images/dread.png"))
  , m_dogPackTexture(resources.getTexture("images/dog_pack.png"))
  {
    m_woodCatTexture.setSmooth(true);
    m_woodDogTexture.setSmooth(true);
    m_floristTexture.setSmooth(true);
    m_moiraiTexture.setSmooth(true);
    m_dreadTexture.setSmooth(true);
    m_dogPackTexture.setSmooth(true);
  }

  void CharacterEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    for (const auto & [ characterType, character ] : m_state.characters) {
      if (character.visibility == CharacterVisibility::Visible && characterType != CharacterType::Gustavo) {
        gf::Sprite sprite;

        switch (characterType) {
        case CharacterType::BadCat:
          sprite.setTexture(m_woodCatTexture);
          break;

        case CharacterType::GoodDog:
          sprite.setTexture(m_woodDogTexture);
          break;

        case CharacterType::Florist:
          sprite.setTexture(m_floristTexture);
          sprite.setOrigin(gf::projy(TileSize));
          break;

        case CharacterType::Moirai:
          sprite.setTexture(m_moiraiTexture);
          sprite.setOrigin(gf::projy(TileSize));
          break;

        case CharacterType::Dread:
          sprite.setTexture(m_dreadTexture);
          break;

        case CharacterType::DogPack:
          sprite.setTexture(m_dogPackTexture);
          sprite.setOrigin(gf::projy(TileSize));
          break;
        }

        sprite.setPosition(TileSize * character.pos);
        target.draw(sprite, states);
      }
    }
  }
}
