#include "CharacterEntity.h"

#include <gf/RenderTarget.h>
#include <gf/Sprite.h>

#include "Constants.h"
#include "GameState.h"

namespace tlw {
  CharacterEntity::CharacterEntity(gf::ResourceManager& resources, GameState& state)
  : m_state(state)
  , m_hollyTexture(resources.getTexture("images/holly.png"))
  , m_stockTexture(resources.getTexture("images/stock.png"))
  , m_bouquetTexture(resources.getTexture("images/bouquet.png"))
  , m_eldersTexture(resources.getTexture("images/elders.png"))
  , m_dreadTexture(resources.getTexture("images/dread.png"))
  , m_dogPackTexture(resources.getTexture("images/dog_pack.png"))
  , m_catPackTexture(resources.getTexture("images/cat_pack.png"))
  {
    m_hollyTexture.setSmooth(true);
    m_stockTexture.setSmooth(true);
    m_bouquetTexture.setSmooth(true);
    m_eldersTexture.setSmooth(true);
    m_dreadTexture.setSmooth(true);
    m_dogPackTexture.setSmooth(true);
    m_catPackTexture.setSmooth(true);
  }

  void CharacterEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    for (const auto & [ characterType, character ] : m_state.characters) {
      if (character.visibility == CharacterVisibility::Visible && characterType != CharacterType::Gustavo) {
        gf::Sprite sprite;

        switch (characterType) {
        case CharacterType::Holly:
          sprite.setTexture(m_hollyTexture);
          break;

        case CharacterType::Stock:
          sprite.setTexture(m_stockTexture);
          break;

        case CharacterType::Bouquet:
          sprite.setTexture(m_bouquetTexture);
          sprite.setOrigin(gf::projy(TileSize));
          break;

        case CharacterType::Elders:
          sprite.setTexture(m_eldersTexture);
          sprite.setOrigin(gf::projy(TileSize));
          break;

        case CharacterType::Dread:
          sprite.setTexture(m_dreadTexture);
          break;

        case CharacterType::DogPack:
          sprite.setTexture(m_dogPackTexture);
          sprite.setOrigin(gf::projy(TileSize));
          break;

        case CharacterType::CatPack:
          sprite.setTexture(m_catPackTexture);
          sprite.setOrigin(TileSize * gf::vec(2, 1));
          break;
        }

        sprite.setPosition(TileSize * character.pos);
        target.draw(sprite, states);
      }
    }
  }
}
