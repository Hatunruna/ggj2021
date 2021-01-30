#include "SliderEntity.h"

#include <gf/Coordinates.h>
#include <gf/RenderTarget.h>
#include <gf/Shapes.h>

namespace {
  namespace ga = gf::activity;

  auto createActivity(float& cursorPosition) {
    return ga::repeat(
      ga::sequence(
        ga::value(0.0f, 1.0f, cursorPosition, gf::seconds(4.6f), gf::Ease::expoInOut),
        ga::value(1.0f, 0.0f, cursorPosition, gf::seconds(4.6f), gf::Ease::expoInOut)
      )
    );
  }

}

namespace tlw {
  SliderEntity::SliderEntity()
  : m_activity(createActivity(m_cursorPosition))
  {

  }

  void SliderEntity::update(gf::Time time) {
    m_activity.run(time);
  }

  void SliderEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Coordinates coords(target);

    gf::RectangleShape slider(coords.getRelativeSize(gf::vec(0.40f, 0.025f)));
    slider.setAnchor(gf::Anchor::Center);
    slider.setPosition(coords.getCenter());
    slider.setColor(gf::Color::Violet);
    target.draw(slider, states);

    gf::RectangleShape cursor(coords.getRelativeSize(gf::vec(0.01f, 0.03f)));
    cursor.setAnchor(gf::Anchor::Center);
    auto cursorPosition = gf::vec(coords.getCenter().width - slider.getSize().width * 0.5f, coords.getCenter().height);
    cursor.setPosition(cursorPosition);
    cursor.setColor(gf::Color::Cyan);
    target.draw(cursor, states);
  }
}
