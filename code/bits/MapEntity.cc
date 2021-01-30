#include "MapEntity.h"

#include <gf/RenderTarget.h>
#include <gf/Log.h>
#include <gf/Array2D.h>

#include "GameData.h"

namespace tlw {

  LayersMaker::LayersMaker(gf::ResourceManager& resources)
  : m_resources(resources)
  {
  }

  void LayersMaker::visitTileLayer(const gf::TmxLayers& map, const gf::TmxTileLayer& layer) {
    if (!layer.visible) {
      return;
    }

    layers.emplace_back(gf::makeTileLayer(map, layer, m_resources));
  }

  MapEntity::MapEntity(gf::ResourceManager& resources, GameData& data)
  : m_layersMaker(resources)
  {
    if (m_mapLayers.loadFromFile(resources.getAbsolutePath("map/world.tmx"))) {
      m_mapLayers.visitLayers(m_layersMaker);

      if (m_layersMaker.layers.size() > 0) {
        gf::TileLayer& tileLayer = m_layersMaker.layers[0];
        gf::Array2D<TileState, int> currTiles(tileLayer.getMapSize());
        int mapSizeX = tileLayer.getMapSize().x;
        int mapSizeY = tileLayer.getMapSize().y;

        for (int x = 0; x < mapSizeX; ++x) {
          for (int y = 0; y < mapSizeY; ++y) {
            TileState tile;
            switch (tileLayer.getTile({x, y}))
            {
              case 1:
              case 7:
              case 8:
              case 9:
              case 10:
              case 11:
              case 12:
              case 13:
              case 14:
              case 15:
              case 16:
              {
                tile = TileState::Walkable;
                break;
              }

              default:
              {
                tile = TileState::NoWalkable;
                break;
              }
            }

            currTiles({x, y}) = tile;
          }
        }

        data.tiles = currTiles;
      }
    }
  }

  void MapEntity::update([[maybe_unused]] gf::Time time) {

  }

  void MapEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    for (auto& layer : m_layersMaker.layers) {
      target.draw(layer);
    }
  }
}
