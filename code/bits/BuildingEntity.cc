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
  , m_woodHouseTexture(resources.getTexture("images/wood_house.png"))
  , m_benchUpTexture(resources.getTexture("images/bench_up.png"))
  , m_benchDownTexture(resources.getTexture("images/bench_down.png"))
  , m_benchLeftTexture(resources.getTexture("images/bench_left.png"))
  , m_gustavoShopTexture(resources.getTexture("images/gustavo_shop.png"))
  {
    m_floristShopTexture.setSmooth(true);
    m_woodHouseTexture.setSmooth(true);
    m_benchUpTexture.setSmooth(true);
    m_benchDownTexture.setSmooth(true);
    m_benchLeftTexture.setSmooth(true);
    m_gustavoShopTexture.setSmooth(true);
  }

  void BuildingEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    for (const auto& building : m_data.buildings) {
      gf::Sprite sprite;

      switch (building.type) {
      case BuildingType::FloristShop:
        sprite.setTexture(m_floristShopTexture);
        break;

      case BuildingType::WoodHouse:
        sprite.setTexture(m_woodHouseTexture);
        break;

      case BuildingType::BenchUp:
        sprite.setTexture(m_benchUpTexture);
        break;

      case BuildingType::BenchDown:
        sprite.setTexture(m_benchDownTexture);
        break;

      case BuildingType::BenchLeft:
        sprite.setTexture(m_benchLeftTexture);
        break;

      case BuildingType::GustavoShop:
        sprite.setTexture(m_gustavoShopTexture);
        break;
      }

      sprite.setPosition(TileSize * building.pos);
      target.draw(sprite, states);
    }
  }
}
