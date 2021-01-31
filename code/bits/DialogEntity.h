#ifndef DIALOG_ENTITY_H
#define DIALOG_ENTITY_H

#include <gf/Entity.h>
#include <gf/Font.h>
#include <gf/ResourceManager.h>

namespace tlw {
  struct GameData;
  struct GameState;

  class DialogEntity : public gf::Entity {
  public:
    DialogEntity(gf::ResourceManager& resources, const GameData& data, GameState& state);
    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;

  private:
    gf::Font& m_speakerFont;
    gf::Font& m_wordsFont;
    gf::Texture& m_playerDialogTexture;
    const GameData& m_data;
    GameState& m_state;
  };


}

#endif // DIALOG_ENTITY_H
