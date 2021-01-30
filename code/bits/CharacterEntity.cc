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
    for (const auto& entry: m_state.characters) {
      CharacterType characterType = entry.first;
      const Character& character = entry.second;
      if (character.visible) {
        gf::Sprite sprite;

        switch (characterType) {
        case CharacterType::BadCat:
          sprite.setTexture(m_resources.getTexture("images/cat.png"));
          break;
        }

        sprite.setPosition(TileSize * character.pos);
        target.draw(sprite, states);
      }
    }
  }
}
