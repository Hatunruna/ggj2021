#ifndef CHARACTER_ENTITY_H
#define CHARACTER_ENTITY_H

#include <gf/Entity.h>
#include <gf/ResourceManager.h>

namespace tlw {

  struct GameState;

  class CharacterEntity : public gf::Entity {
  public:
    CharacterEntity(gf::ResourceManager& resources, GameState& state);

    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;

  private:
    GameState& m_state;
    gf::Texture& m_woodCatTexture;
    gf::Texture& m_woodDogTexture;
    gf::Texture& m_floristTexture;
    gf::Texture& m_moiraiTexture;
    gf::Texture& m_dreadTexture;
    gf::Texture& m_dogPackTexture;
  };
}

#endif // CHARACTER_ENTITY_H
