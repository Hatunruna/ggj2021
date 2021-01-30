#include "CharacterEntity.h"

#include <gf/RenderTarget.h>
#include <gf/Sprite.h>

#include "Constants.h"
#include "GameState.h"

namespace tlw {
  CharacterEntity::CharacterEntity(gf::ResourceManager& resources, GameState& state)
  : m_resources(resources)
  , m_state(state)
  {

  }

  void CharacterEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    for (const auto & [ characterType, character ] : m_state.characters) {
      if (character.visibility == CharacterVisibility::Visible) {
        gf::Sprite sprite;

        switch (characterType) {
        case CharacterType::BadCat:
          sprite.setTexture(m_resources.getTexture("images/wood_cat.png"));
          break;

        case CharacterType::GoodDog:
          sprite.setTexture(m_resources.getTexture("images/wood_dog.png"));
          break;

        case CharacterType::Florist:
          sprite.setTexture(m_resources.getTexture("images/florist.png"));
          break;

        case CharacterType::Moirai:
          sprite.setTexture(m_resources.getTexture("images/moirai.png"));
          break;
        }

        sprite.setPosition(TileSize * character.pos);
        target.draw(sprite, states);
      }
    }
  }
}
