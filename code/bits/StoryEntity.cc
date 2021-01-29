#include "StoryEntity.h"

#include <gf/Coordinates.h>
#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/Sprite.h>
#include <gf/Text.h>

#include "GameData.h"
#include "GameState.h"
#include "I18N.h"

namespace tlw {

  StoryEntity::StoryEntity(gf::ResourceManager& resources, const GameData& data, GameState& state)
  : m_font(resources.getFont("Tippa.ttf")) // "LiberationMono-Regular.ttf"
  , m_data(data)
  , m_state(state)
  {
  }

  void StoryEntity::update([[maybe_unused]] gf::Time time) {
  }

  void StoryEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Coordinates coords(target);

    float titleWidth = coords.getRelativeSize({ 0.6f, 0.0f }).width;
    unsigned titleCharacterSize = coords.getRelativeCharacterSize(0.05f);

    gf::Text title(m_data.story.chapters[m_state.chapter].title, m_font, titleCharacterSize);
    title.setOutlineThickness(titleCharacterSize / 100.f);
    title.setOutlineColor(gf::Color::White);
    title.setParagraphWidth(titleWidth);
    title.setAlignment(gf::Alignment::Left);
    title.setColor(gf::Color::White);
    title.setPosition(coords.getRelativePoint({ 0.5, 0.2 }));
    title.setAnchor(gf::Anchor::BottomCenter);
    target.draw(title, states);

    gf::RectangleShape line(coords.getRelativeSize({ 0.6f, 0.002f }));
    line.setColor(gf::Color::White);
    line.setPosition(coords.getRelativePoint({ 0.5, 0.22 }));
    line.setAnchor(gf::Anchor::Center);
    target.draw(line, states);

    float textWidth = coords.getRelativeSize({ 0.6f, 0.0f }).width;
    unsigned textCharacterSize = coords.getRelativeCharacterSize(0.04f);

    gf::Text text(m_data.story.chapters[m_state.chapter].text, m_font, textCharacterSize);
    text.setOutlineThickness(textCharacterSize / 100.f);
    text.setOutlineColor(gf::Color::White);
    text.setParagraphWidth(textWidth);
    text.setAlignment(gf::Alignment::Justify);
    text.setLineSpacing(1.2f);
    text.setColor(gf::Color::White);
    text.setPosition(coords.getRelativePoint({ 0.5, 0.3 }));
    text.setAnchor(gf::Anchor::TopCenter);
    target.draw(text, states);
  }

}
