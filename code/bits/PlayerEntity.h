#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include <gf/Direction.h>
#include <gf/Entity.h>
#include <gf/ResourceManager.h>

namespace tlw {
  struct GameState;

  class PlayerEntity : public gf::Entity {
  public:
    PlayerEntity(gf::ResourceManager& resources, GameState& state);
    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;
    void move(gf::Direction dir);

  private:
    GameState& m_state;
    gf::Texture& m_playerTexture;
    float m_cooldownMove;
  };

}


#endif // PLAYER_ENTITY_H
