#include "StoryEntity.h"

#include <gf/Coordinates.h>
#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Sprite.h>
#include <gf/Text.h>

#include "I18N.h"

namespace tlw {

  namespace {

    constexpr const char *Story0 =
      N_("Monday.\nI have been called by Mr X to handle a very particular situation. Mr X is the mayor of the little town of Y. One of his inhabitants, Ms Z has just died. And nobody can find her last will. My mission is to find it.\nI don't know exactly where to start but I should see Mr X first, I think. He may have valuable information for me.")
    ;


  }

  StoryEntity::StoryEntity(gf::ResourceManager& resources)
  : m_font(resources.getFont("Tippa.ttf")) // "LiberationMono-Regular.ttf"
  {
  }

  void StoryEntity::update([[maybe_unused]] gf::Time time) {
  }

  void StoryEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Coordinates coords(target);

    float textWidth = coords.getRelativeSize({ 0.6f, 0.0f }).width;
    unsigned textCharacterSize = coords.getRelativeCharacterSize(0.04f);

    gf::Text text(boost::locale::gettext(Story0), m_font, textCharacterSize);
    text.setOutlineThickness(0.2f);
    text.setOutlineColor(gf::Color::White);
    text.setParagraphWidth(textWidth);
    text.setAlignment(gf::Alignment::Justify);
    text.setLineSpacing(1.2f);
    text.setColor(gf::Color::White);
    text.setPosition(coords.getCenter());
    text.setAnchor(gf::Anchor::Center);
    target.draw(text, states);
  }

}
