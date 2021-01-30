#include "PlayerEntity.h"

#include <gf/Shapes.h>
#include <gf/RenderTarget.h>
#include <gf/Log.h>

#include "GameState.h"

namespace tlw {

  PlayerEntity::PlayerEntity(GameState& state)
  : m_state(state)
  {
  }

  void PlayerEntity::update([[maybe_unused]] gf::Time time) {
  }

  void PlayerEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::RectangleShape playerSquare(gf::Vector2f(100.f, 50.f));
    playerSquare.setColor(gf::Color::Red);
    playerSquare.setPosition(m_state.hero.pos);
    playerSquare.setAnchor(gf::Anchor::Center);
    target.draw(playerSquare, states);
  }

  void PlayerEntity::move(gf::Direction dir)
  {
    constexpr int moveValue = 50;
    m_state.hero.pos += gf::displacement(dir) * moveValue;
  }
}