#ifndef BUILDING_ENTITY_H
#define BUILDING_ENTITY_H

#include <gf/Entity.h>
#include <gf/ResourceManager.h>

namespace tlw {
  struct GameData;

  class BuildingEntity : public gf::Entity {
  public:
    BuildingEntity(gf::ResourceManager& resources, GameData& data);

    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;

  private:
    GameData& m_data;
    gf::Texture& m_floristShopTexture;
    gf::Texture& m_woodHouseTexture;
    gf::Texture& m_benchUpTexture;
    gf::Texture& m_benchDownTexture;
    gf::Texture& m_benchLeftTexture;
  };
}

#endif // BUILDING_ENTITY_H
