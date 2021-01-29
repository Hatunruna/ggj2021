#ifndef STORY_ENTITY_H
#define STORY_ENTITY_H

#include <gf/Entity.h>
#include <gf/Font.h>
#include <gf/ResourceManager.h>

namespace tlw {
  struct GameData;
  struct GameState;

  class StoryEntity : public gf::Entity {
  public:
    StoryEntity(gf::ResourceManager& resources, const GameData& data, GameState& state);
    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;

  private:
    gf::Font& m_font;
    const GameData& m_data;
    GameState& m_state;
  };


}


#endif // STORY_ENTITY_H
