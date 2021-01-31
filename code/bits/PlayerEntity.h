#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include <gf/Animation.h>
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
    const GameData& m_data;
    gf::Time m_moveCooldown;
    gf::Direction m_currentDirection;
    bool stillRuning;

    gf::Texture& m_waitUpTexture;
    gf::Texture&  m_runUpTexture;
    gf::Animation m_runUpAnimation;

    gf::Texture& m_waitBottomTexture;
    gf::Texture&  m_runBottomTexture;
    gf::Animation m_runBottomAnimation;

    gf::Texture& m_waitLeftTexture;
    gf::Texture&  m_runLeftTexture;
    gf::Animation m_runLeftAnimation;

    gf::Texture& m_waitRightTexture;
    gf::Texture& m_runRightTexture;
    gf::Animation m_runRightAnimation;

    gf::Animation* m_currentAnimation;
  };

}


#endif // PLAYER_ENTITY_H
