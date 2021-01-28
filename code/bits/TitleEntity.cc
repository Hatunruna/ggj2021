#include "TitleEntity.h"

#include <gf/Coordinates.h>
#include <gf/RenderTarget.h>
#include <gf/Text.h>

namespace tlw {

  TitleEntity::TitleEntity(gf::ResourceManager& resources)
  : m_font(resources.getFont("Tippa.ttf"))
  {
  }

  void TitleEntity::update([[maybe_unused]] gf::Time time) {
  }

  void TitleEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Coordinates coords(target);

    unsigned titleCharacterSize = coords.getRelativeCharacterSize(0.1f);

    gf::Text title("The Lost Will", m_font, titleCharacterSize);
    title.setColor(gf::Color::White);
    title.setPosition(coords.getCenter());
    title.setAnchor(gf::Anchor::Center);
    target.draw(title, states);

    unsigned subtitleCharacterSize = coords.getRelativeCharacterSize(0.05f);

    gf::Text subtitle("A game by Hatunruna", m_font, subtitleCharacterSize);
    subtitle.setColor(gf::Color::White);
    subtitle.setPosition(coords.getRelativePoint({ 0.5f, 0.6f }));
    subtitle.setAnchor(gf::Anchor::Center);
    target.draw(subtitle, states);


  }

}

