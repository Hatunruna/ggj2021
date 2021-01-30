#include "SliderEntity.h"

#include <gf/Coordinates.h>
#include <gf/RenderTarget.h>
#include <gf/Log.h>
#include <gf/Shapes.h>

#include "Constants.h"

namespace {
  namespace ga = gf::activity;

  auto createActivity(int delay, float& cursorPosition) {
    return ga::sequence(
      // ga::delay(gf::seconds(tlw::TransitionDelay)), // TODO: Comment to test
      ga::repeat(
        ga::sequence(
          ga::value(0.0f, 1.0f, cursorPosition, gf::seconds(delay), gf::Ease::expoInOut),
          ga::value(1.0f, 0.0f, cursorPosition, gf::seconds(delay), gf::Ease::expoInOut)
        )
      )
    );
  }

}

namespace tlw {
  SliderEntity::SliderEntity()
  : m_easeDelay(static_cast<int>(SliderChallengeDifficulty::Medium))
  , m_cursorPosition(0.0f)
  , m_activity(std::make_unique<ga::AnyActivity>(createActivity(m_easeDelay, m_cursorPosition)))
  {

  }

  void SliderEntity::setDifficulty(SliderChallengeDifficulty difficulty) {
    m_easeDelay = static_cast<int>(difficulty);
    m_cursorPosition = 0.0f;
    m_activity = std::make_unique<ga::AnyActivity>(createActivity(m_easeDelay, m_cursorPosition));
  }

  void SliderEntity::increaseSpeed() {
    --m_easeDelay;
    m_activity = std::make_unique<ga::AnyActivity>(createActivity(m_easeDelay, m_cursorPosition));
    gf::Log::debug("Increase speed: new delay = %d\n", m_easeDelay);
  }

  void SliderEntity::decreaseSpeed() {
    ++m_easeDelay;
    m_activity = std::make_unique<ga::AnyActivity>(createActivity(m_easeDelay, m_cursorPosition));
    gf::Log::debug("Decrease speed: new delay = %d\n", m_easeDelay);
  }

  void SliderEntity::update(gf::Time time) {
    m_activity->run(time);
  }

  void SliderEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Coordinates coords(target);

    gf::RectF sliderBox = gf::RectF::fromCenterSize(coords.getCenter(), coords.getRelativeSize(gf::vec(0.40f, 0.025f)));

    gf::RectangleShape slider(sliderBox);
    slider.setColor(gf::Color::Violet);
    target.draw(slider, states);

    gf::RectangleShape cursor(coords.getRelativeSize(gf::vec(0.01f, 0.03f)));
    cursor.setAnchor(gf::Anchor::Center);
    auto cursorPosition = gf::vec(sliderBox.getTopLeft().x + sliderBox.getSize().width * m_cursorPosition, coords.getCenter().y);
    cursor.setPosition(cursorPosition);
    cursor.setColor(gf::Color::Cyan);
    target.draw(cursor, states);
  }
}
