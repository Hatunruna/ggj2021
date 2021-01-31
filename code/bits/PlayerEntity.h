#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include <gf/Direction.h>
#include <gf/Entity.h>
#include <gf/ResourceManager.h>

namespace tlw {
  struct GameState;
  struct GameData;

  class PlayerEntity : public gf::Entity {
  public:
    PlayerEntity(gf::ResourceManager& resources, GameState& state, const GameData& data);
    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;
    void move(gf::Direction dir);

  private:
    GameState& m_state;
    gf::Texture& m_playerTexture;
    const GameData& m_data;
    gf::Time m_moveCooldown;
    gf::Direction m_currentDirection;
    gf::Texture& m_RayUp;
    gf::Texture& m_RayDown;
    gf::Texture& m_RayLeft;
    gf::Texture& m_RayRight;
  };

}


#endif // PLAYER_ENTITY_H
