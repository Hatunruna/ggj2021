#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include <gf/Entity.h>
#include <gf/Gamepad.h>
#include <gf/Vector.h>

namespace tlw {

  class PlayerEntity : public gf::Entity {
  public:
    PlayerEntity();
    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;
    void moveX(gf::GamepadAxisDirection dir);
    void moveY(gf::GamepadAxisDirection dir);

  private:

    gf::Vector2i m_pos;
  };

}


#endif // PLAYER_ENTITY_H
