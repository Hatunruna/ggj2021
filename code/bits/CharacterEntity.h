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
    gf::Texture& m_hollyTexture;
    gf::Texture& m_stockTexture;
    gf::Texture& m_bouquetTexture;
    gf::Texture& m_eldersTexture;
    gf::Texture& m_dreadTexture;
    gf::Texture& m_dogPackTexture;
    gf::Texture& m_catPackTexture;
  };
}

#endif // CHARACTER_ENTITY_H
