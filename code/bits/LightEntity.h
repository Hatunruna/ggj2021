#ifndef LIGHT_ENTITY_H
#define LIGHT_ENTITY_H

#include <gf/Entity.h>
#include <gf/LightSystem.h>
#include <gf/Texture.h>
#include <gf/Vector.h>

namespace tlw {
  struct GameData;

  class LightEntity : public gf::Entity {
  public:
    LightEntity(gf::Vector2i size, GameData& data);

    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;

  private:
    gf::Texture m_texture;
    std::vector<gf::LightPointEmission> m_points;
    std::vector<gf::LightShape> m_shapes;
    gf::LightSystem m_system;
  };

}


#endif // LIGHT_ENTITY_H
