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
    gf::Texture& m_bouquetShopTexture;
    gf::Texture& m_bouquetNeighbor1Texture;
    gf::Texture& m_bouquetNeighbor2Texture;
    gf::Texture& m_woodHouseTexture;
    gf::Texture& m_woodNeighborTexture;
    gf::Texture& m_benchUpTexture;
    gf::Texture& m_benchDownTexture;
    gf::Texture& m_benchLeftTexture;
    gf::Texture& m_gustavoShopTexture;
    gf::Texture& m_fountainTexture;
    gf::Texture& m_house1Texture;
    gf::Texture& m_house2Texture;
    gf::Texture& m_pubTexture;
    gf::Texture& m_garbageCanTexture;
  };
}

#endif // BUILDING_ENTITY_H
