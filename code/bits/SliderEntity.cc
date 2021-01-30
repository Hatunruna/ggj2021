#include "SliderEntity.h"

#include <gf/Coordinates.h>
#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/Text.h>

#include "Constants.h"
#include "I18N.h"

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
  SliderEntity::SliderEntity(gf::ResourceManager& resources)
  : m_font(resources.getFont("Tippa.ttf"))
  , m_easeDelay(static_cast<int>(SliderChallengeDifficulty::Medium))
  , m_cursorPosition(0.0f)
  , m_activity(createActivity(m_easeDelay, m_cursorPosition))
  , m_played(false)
  {

  }

  void SliderEntity::setDifficulty(SliderChallengeDifficulty difficulty) {
    m_played = false;
    m_easeDelay = static_cast<int>(difficulty);
    m_cursorPosition = 0.0f;
    m_activity = ga::AnyActivity(createActivity(m_easeDelay, m_cursorPosition));
  }

  bool SliderEntity::isHit() const {
    float upperBounds = 0.5f + GoalRelativeSize.width;
    float lowerBounds = 0.5f - GoalRelativeSize.width;
    return m_cursorPosition >= lowerBounds && m_cursorPosition <= upperBounds;
  }

  bool SliderEntity::stopCursor() {
    m_played = true;
    return isHit();
  }

  void SliderEntity::increaseSpeed() {
    m_played = false;
    --m_easeDelay;
    m_activity = ga::AnyActivity(createActivity(m_easeDelay, m_cursorPosition));
    gf::Log::debug("Increase speed: new delay = %d\n", m_easeDelay);
  }

  void SliderEntity::decreaseSpeed() {
    m_played = false;
    ++m_easeDelay;
    m_activity = ga::AnyActivity(createActivity(m_easeDelay, m_cursorPosition));
    gf::Log::debug("Decrease speed: new delay = %d\n", m_easeDelay);
  }

  void SliderEntity::update(gf::Time time) {
    if (!m_played) {
      m_activity.run(time);
    }
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

    if (m_played) {
      gf::Text message((isHit() ? _("Success") : _("Failed")), m_font, coords.getRelativeCharacterSize(0.1f));
      message.setColor(gf::Color::White);
      auto messagePosition = slider.getPosition();
      messagePosition.x = coords.getCenter().x;
      messagePosition.y -=  3.0f * slider.getSize().height;
      message.setPosition(messagePosition);
      message.setAnchor(gf::Anchor::Center);
      target.draw(message, states);
    }
  }
}
