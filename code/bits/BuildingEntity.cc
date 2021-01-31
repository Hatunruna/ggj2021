#include "BuildingEntity.h"

#include <gf/RenderTarget.h>
#include <gf/ResourceManager.h>
#include <gf/Sprite.h>

#include "Constants.h"
#include "GameData.h"

namespace tlw {
  BuildingEntity::BuildingEntity(gf::ResourceManager& resources, GameData& data)
  : m_data(data)
  , m_bouquetShopTexture(resources.getTexture("images/bouquet_shop.png"))
  , m_bouquetNeighbor1Texture(resources.getTexture("images/bouquet_neighbor1.png"))
  , m_bouquetNeighbor2Texture(resources.getTexture("images/bouquet_neighbor2.png"))
  , m_woodHouseTexture(resources.getTexture("images/wood_house.png"))
  , m_woodNeighborTexture(resources.getTexture("images/wood_neighbor.png"))
  , m_benchUpTexture(resources.getTexture("images/bench_up.png"))
  , m_benchDownTexture(resources.getTexture("images/bench_down.png"))
  , m_benchLeftTexture(resources.getTexture("images/bench_left.png"))
  , m_gustavoShopTexture(resources.getTexture("images/gustavo_shop.png"))
  , m_fountainTexture(resources.getTexture("images/fountain.png"))
  , m_house1Texture(resources.getTexture("images/house1.png"))
  , m_house2Texture(resources.getTexture("images/house1.png"))
  , m_pubTexture(resources.getTexture("images/pub.png"))
  , m_garbageCanTexture(resources.getTexture("images/garbage_can.png"))
  {
    m_bouquetShopTexture.setSmooth(true);
    m_bouquetNeighbor1Texture.setSmooth(true);
    m_bouquetNeighbor2Texture.setSmooth(true);
    m_woodHouseTexture.setSmooth(true);
    m_woodNeighborTexture.setSmooth(true);
    m_benchUpTexture.setSmooth(true);
    m_benchDownTexture.setSmooth(true);
    m_benchLeftTexture.setSmooth(true);
    m_gustavoShopTexture.setSmooth(true);
    m_fountainTexture.setSmooth(true);
    m_house1Texture.setSmooth(true);
    m_house2Texture.setSmooth(true);
    m_pubTexture.setSmooth(true);
    m_garbageCanTexture.setSmooth(true);
  }

  void BuildingEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    for (const auto& building : m_data.buildings) {
      gf::Sprite sprite;

      switch (building.type) {
      case BuildingType::BouquetShop:
        sprite.setTexture(m_bouquetShopTexture);
        break;

      case BuildingType::BouquetNeighbor1:
        sprite.setTexture(m_bouquetNeighbor1Texture);
        break;

      case BuildingType::BouquetNeighbor2:
        sprite.setTexture(m_bouquetNeighbor2Texture);
        break;

      case BuildingType::WoodHouse:
        sprite.setTexture(m_woodHouseTexture);
        break;

      case BuildingType::WoodNeighbor:
        sprite.setTexture(m_woodNeighborTexture);
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

      case BuildingType::Fountain:
        sprite.setTexture(m_fountainTexture);
        break;

      case BuildingType::House1:
        sprite.setTexture(m_house1Texture);
        break;

      case BuildingType::House2:
        sprite.setTexture(m_house2Texture);
        break;

      case BuildingType::Pub:
        sprite.setTexture(m_pubTexture);
        break;

      case BuildingType::GarbageCan:
        sprite.setTexture(m_garbageCanTexture);
        break;
      }

      sprite.setPosition(TileSize * building.pos);
      target.draw(sprite, states);
    }
  }
}
