#ifndef STORY_ENTITY_H
#define STORY_ENTITY_H

#include <gf/Entity.h>
#include <gf/Font.h>
#include <gf/ResourceManager.h>

namespace tlw {

  class StoryEntity : public gf::Entity {
  public:
    StoryEntity(gf::ResourceManager& resources);
    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;

  private:
    gf::Font& m_font;
  };


}


#endif // STORY_ENTITY_H
