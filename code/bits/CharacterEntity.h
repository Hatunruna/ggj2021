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
    gf::ResourceManager& m_resources;
    GameState& m_state;
  };
}

#endif // CHARACTER_ENTITY_H
