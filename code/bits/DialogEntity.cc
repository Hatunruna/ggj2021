#include "DialogEntity.h"

#include <cassert>

#include <gf/Coordinates.h>
#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/Text.h>

#include "GameData.h"
#include "GameState.h"
#include "I18N.h"

namespace tlw {

  DialogEntity::DialogEntity(gf::ResourceManager& resources, const GameData& data, GameState& state)
  : m_speakerFont(resources.getFont("Tippa.ttf"))
  , m_wordsFont(resources.getFont("Aquifer.otf"))
  , m_data(data)
  , m_state(state)
  {
  }

  void DialogEntity::update([[maybe_unused]] gf::Time time) {
  }

  void DialogEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    if (m_state.currentDialog == gf::InvalidId) {
      return;
    }

    auto it = m_data.dialogs.find(m_state.currentDialog);
    assert(it != m_data.dialogs.end());
    auto& [ currentId, currentDialog ] = *it;
    assert(m_state.currentLine < currentDialog.lines.size());
    auto& currentLine = currentDialog.lines[m_state.currentLine];

    gf::Coordinates coords(target);

    // TODO background

    unsigned speakerCharacterSize = coords.getRelativeCharacterSize(0.05f);

    gf::Text speaker(currentLine.speaker, m_speakerFont, speakerCharacterSize);
    speaker.setColor(gf::Color::White);
    speaker.setPosition(coords.getRelativePoint({ 0.2, 0.6 }));
    speaker.setAnchor(gf::Anchor::TopLeft);
    target.draw(speaker, states);

    float wordsWidth = coords.getRelativeSize({ 0.6f, 0.0f }).width;
    unsigned wordsCharacterSize = coords.getRelativeCharacterSize(0.04f);

    gf::Text words(currentLine.words, m_wordsFont, wordsCharacterSize);
    words.setParagraphWidth(wordsWidth);
    words.setAlignment(gf::Alignment::Justify);
    words.setColor(gf::Color::White);
    words.setPosition(coords.getRelativePoint({ 0.2, 0.7 }));
    words.setAnchor(gf::Anchor::TopLeft);
    target.draw(words, states);
  }

}
