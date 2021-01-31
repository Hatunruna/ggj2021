#ifndef INFO_ENTITY_H
#define INFO_ENTITY_H

#include <gf/Entity.h>
#include <gf/ResourceManager.h>

namespace tlw {

  class InfoEntity : public gf::Entity {
  public:
    InfoEntity(gf::ResourceManager& resources);
    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;
    void setSearchActive(bool state);
    void setDialogActive(bool state);

  private:
    gf::Texture& m_searchTexture;
    bool m_searchActive;

    gf::Texture& m_dialogTexture;
    bool m_dialogActive;
  };


}


#endif // INFO_ENTITY_H
