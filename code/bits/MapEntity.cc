#include "MapEntity.h"

#include <gf/RenderTarget.h>
#include <gf/Log.h>

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

  MapEntity::MapEntity(gf::ResourceManager& resources)
  : m_layersMaker(resources)
  {
    if (m_mapLayers.loadFromFile(resources.getAbsolutePath("map/world.tmx"))) {
      m_mapLayers.visitLayers(m_layersMaker);
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