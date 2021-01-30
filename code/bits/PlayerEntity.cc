#include "PlayerEntity.h"

#include <gf/Shapes.h>
#include <gf/RenderTarget.h>
#include <gf/Log.h>

#include "GameState.h"
#include "Constants.h"

namespace tlw {

  PlayerEntity::PlayerEntity(GameState& state)
  : m_state(state)
  , m_cooldownMove(0.f)
  {
  }

  void PlayerEntity::update(gf::Time time) {
    m_cooldownMove += time.asSeconds();
  }

  void PlayerEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::RectangleShape playerSquare(TileSize);
    playerSquare.setColor(gf::Color::Red);
    playerSquare.setPosition(m_state.hero.pos * TileSize);
    target.draw(playerSquare, states);
  }

  void PlayerEntity::move(gf::Direction dir)
  {
    //cooldown move in seconds
    constexpr float cooldownMove = 0.25f;

    if (m_cooldownMove > cooldownMove)
    {
      m_cooldownMove = 0.f;

      constexpr int moveValue = 1;
      m_state.hero.pos += gf::displacement(dir) * moveValue;
    }
  }
}