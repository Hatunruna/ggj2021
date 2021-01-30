#include "SliderEntity.h"

#include <gf/Coordinates.h>
#include <gf/RenderTarget.h>
#include <gf/Log.h>
#include <gf/Shapes.h>

#include "Constants.h"

namespace {
  constexpr gf::Vector2f SliderRelativeSize = gf::vec(0.40f, 0.025f);
  constexpr gf::Vector2f CursorRelativeSize = gf::vec(0.01f, 0.03f);
  constexpr gf::Vector2f GoalRelativeSize = gf::vec(CursorRelativeSize.x * 3.0f, SliderRelativeSize.y);

  namespace ga = gf::activity;

  auto createActivity(int delay, float& cursorPosition) {
    return ga::sequence(
      // ga::delay(gf::seconds(tlw::TransitionDelay)), // TODO: Comment to test
      ga::repeat(
        ga::sequence(
          ga::value(0.0f, 1.0f, cursorPosition, gf::seconds(delay), gf::Ease::quartInOut),
          ga::value(1.0f, 0.0f, cursorPosition, gf::seconds(delay), gf::Ease::quartInOut)
        )
      )
    );
  }

}

namespace tlw {
  SliderEntity::SliderEntity()
  : m_easeDelay(static_cast<int>(SliderChallengeDifficulty::Medium))
  , m_cursorPosition(0.0f)
  , m_activity(createActivity(m_easeDelay, m_cursorPosition))
  {

  }

  void SliderEntity::setDifficulty(SliderChallengeDifficulty difficulty) {
    m_easeDelay = static_cast<int>(difficulty);
    m_cursorPosition = 0.0f;
    m_activity = ga::AnyActivity(createActivity(m_easeDelay, m_cursorPosition));
  }

  bool SliderEntity::stopCursor() const {
    float upperBounds = 0.5f + GoalRelativeSize.width;
    float lowerBounds = 0.5f - GoalRelativeSize.width;
    return m_cursorPosition >= lowerBounds && m_cursorPosition <= upperBounds;
  }

  void SliderEntity::increaseSpeed() {
    --m_easeDelay;
    m_activity = ga::AnyActivity(createActivity(m_easeDelay, m_cursorPosition));
    gf::Log::debug("Increase speed: new delay = %d\n", m_easeDelay);
  }

  void SliderEntity::decreaseSpeed() {
    ++m_easeDelay;
    m_activity = ga::AnyActivity(createActivity(m_easeDelay, m_cursorPosition));
    gf::Log::debug("Decrease speed: new delay = %d\n", m_easeDelay);
  }

  void SliderEntity::update(gf::Time time) {
    m_activity.run(time);
  }

  void SliderEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Coordinates coords(target);

    gf::RectF sliderBox = gf::RectF::fromCenterSize(coords.getCenter(), coords.getRelativeSize(SliderRelativeSize));

    gf::RectangleShape slider(sliderBox);
    slider.setColor(gf::Color::Violet);
    target.draw(slider, states);

    gf::RectangleShape goals(coords.getRelativeSize(GoalRelativeSize));
    goals.setAnchor(gf::Anchor::Center);
    goals.setPosition(coords.getCenter());
    goals.setColor(gf::Color::Green);
    target.draw(goals, states);

    gf::RectangleShape cursor(coords.getRelativeSize(CursorRelativeSize));
    cursor.setAnchor(gf::Anchor::Center);
    auto cursorPosition = gf::vec(sliderBox.getTopLeft().x + sliderBox.getSize().width * m_cursorPosition, coords.getCenter().y);
    cursor.setPosition(cursorPosition);
    cursor.setColor(gf::Color::Cyan);
    target.draw(cursor, states);
  }
}
