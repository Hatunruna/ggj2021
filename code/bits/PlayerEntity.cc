#include "PlayerEntity.h"

#include <gf/RenderTarget.h>
#include <gf/Sprite.h>

#include "GameState.h"
#include "GameData.h"
#include "Constants.h"

namespace tlw {

  PlayerEntity::PlayerEntity(gf::ResourceManager& resources, GameState& state, const GameData& data)
  : m_playerTexture(resources.getTexture("images/player.png"))
  , m_state(state)
  , m_data(data)
  , m_cooldownMove(0.f)
  {
    m_playerTexture.setSmooth(true);
  }

  void PlayerEntity::update(gf::Time time) {
    m_cooldownMove += time.asSeconds();
  }

  void PlayerEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Sprite sprite(m_playerTexture);
    sprite.setPosition(m_state.hero.pos * TileSize);
    target.draw(sprite, states);
  }

  void PlayerEntity::move(gf::Direction dir)
  {
    //cooldown move in seconds
    constexpr float cooldownMove = 0.25f;
    constexpr int moveValue = 1;

    gf::Vector2i nextPos = m_state.hero.pos + gf::displacement(dir) * moveValue;

    if (m_cooldownMove > cooldownMove && m_data.tiles(nextPos) == TileState::Walkable) {
      m_cooldownMove = 0.f;
      m_state.hero.pos = nextPos;
    }
  }
}
