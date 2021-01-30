#ifndef MAP_ENTITY_H
#define MAP_ENTITY_H

#include <gf/Entity.h>
#include <gf/Tmx.h>
#include <gf/TmxOps.h>
#include <gf/ResourceManager.h>

namespace tlw {
  struct GameData;

  class LayersMaker : public gf::TmxVisitor {
  public:
    LayersMaker(gf::ResourceManager& resources);
    virtual void visitTileLayer(const gf::TmxLayers& map, const gf::TmxTileLayer& layer) override;

  public:
    std::vector<gf::TileLayer> layers;

  private:
    gf::ResourceManager& m_resources;
  };

  class MapEntity : public gf::Entity {
  public:
    MapEntity(gf::ResourceManager& resources, GameData& data);
    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;

  private:
    gf::TmxLayers m_mapLayers;
    LayersMaker m_layersMaker;
  };

}


#endif // MAP_ENTITY_H
