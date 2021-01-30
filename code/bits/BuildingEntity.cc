#include "BuildingEntity.h"

#include <gf/RenderTarget.h>
#include <gf/ResourceManager.h>
#include <gf/Sprite.h>

#include "Constants.h"
#include "GameData.h"

namespace tlw {
  BuildingEntity::BuildingEntity(gf::ResourceManager& resources, GameData& data)
  : m_data(data)
  , m_floristShopTexture(resources.getTexture("images/florist_shop.png"))
  {
    m_floristShopTexture.setSmooth(true);
  }

  void BuildingEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    for (const auto & [ buildingType, building ] : m_data.buildings) {
      gf::Sprite sprite;

      switch (buildingType) {
      case BuildingType::FloristShop:
        sprite.setTexture(m_floristShopTexture);
        break;
      }

      sprite.setPosition(TileSize * building.pos);
      target.draw(sprite, states);
    }
  }
}
