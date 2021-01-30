#include "PlayerEntity.h"

#include <gf/Shapes.h>
#include <gf/RenderTarget.h>
#include <gf/Log.h>

namespace tlw {

  PlayerEntity::PlayerEntity()
  : m_pos(0, 0)
  {
  }

  void PlayerEntity::update([[maybe_unused]] gf::Time time) {
  }

  void PlayerEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::RectangleShape playerSquare(gf::Vector2f(100.f, 50.f));
    playerSquare.setColor(gf::Color::Red);
    playerSquare.setPosition(m_pos);
    playerSquare.setAnchor(gf::Anchor::Center);
    target.draw(playerSquare, states);
  }

  void PlayerEntity::moveX(gf::GamepadAxisDirection dir)
  {
    constexpr int moveXValue = 50;
    m_pos.x += (dir == gf::GamepadAxisDirection::Positive) ? moveXValue : -moveXValue;
  }

  void PlayerEntity::moveY(gf::GamepadAxisDirection dir)
  {
    constexpr int moveYValue = 50;
    m_pos.y += (dir == gf::GamepadAxisDirection::Positive) ? moveYValue : -moveYValue;
  }
}