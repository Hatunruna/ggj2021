#include "LightEntity.h"

#include <gf/LightTextures.h>

#include "Constants.h"
#include "GameData.h"

namespace tlw {

  namespace {

    constexpr int LightSize = 2048;
    constexpr float LightAttenuation = 5.0f;
    constexpr float LightRadius = 20.0f;

    gf::Vector2i computeBuildingSize(BuildingType type) {
      switch (type) {
        case BuildingType::BouquetShop:
          return gf::vec(12, 4);
        case BuildingType::BouquetNeighbor1:
        case BuildingType::BouquetNeighbor2:
        case BuildingType::WoodHouse:
        case BuildingType::WoodNeighbor:
        case BuildingType::BenchUp:
        case BuildingType::BenchDown:
        case BuildingType::BenchLeft:
        case BuildingType::GustavoShop:
        case BuildingType::Fountain:
        case BuildingType::House1:
        case BuildingType::House2:
        case BuildingType::Pub:
        case BuildingType::GarbageCan:
        case BuildingType::Car:
          break;
      }

      return gf::vec(0, 0);
    }


  }

  LightEntity::LightEntity(gf::Vector2i size, GameData& data)
  : m_texture(gf::LightTextures::createRealisticLight(LightSize, LightAttenuation, LightRadius))
  , m_system(size)
  {
    m_texture.setSmooth();

    for (auto pos : data.tiles.getPositionRange()) {
      if (data.tiles(pos) == TileState::Light) {
        gf::LightPointEmission point(m_texture);
        point.setPosition((pos + 0.5f) * TileSize);
        point.setAnchor(gf::Anchor::Center);
        point.setSourceRadius(LightRadius);
        point.setShadowOverExtendMultiplier(20.0f);

        m_points.push_back(std::move(point));
      }
    }

    for (auto& building : data.buildings) {
      auto size = computeBuildingSize(building.type);

      if (size == gf::vec(0, 0)) {
        continue;
      }

      gf::RectF rect = gf::RectF::fromPositionSize(building.pos * TileSize, size * TileSize);
      gf::LightShape shape(rect);
      m_shapes.push_back(std::move(shape));
    }

    m_system.setAmbientColor(gf::Color::Gray(0.02f));

    for (auto& point : m_points) {
      m_system.addLightPoint(point);
    }

    for (auto& shape : m_shapes) {
      m_system.addLightShape(shape);
    }
  }

  void LightEntity::update([[maybe_unused]] gf::Time time) {
  }

  void LightEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    target.draw(m_system, states);
  }

}
