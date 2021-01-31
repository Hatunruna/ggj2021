#include "SliderEntity.h"

#include <gf/Coordinates.h>
#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/Text.h>
#include <gf/Gamepad.h>
#include <gf/Sprite.h>

#include "Constants.h"
#include "I18N.h"


namespace {

// return the string represented by the GamepadButton button
  std::string gamepadValue(gf::GamepadButton button) {
    if (button == gf::GamepadButton::A) {
      return "A";
    }
    else if (button == gf::GamepadButton::B) {
      return "B";
    }
    else if (button == gf::GamepadButton::X) {
      return "X";
    }
    else if (button == gf::GamepadButton::Y) {
      return "Y";
    }
    return "A";
  }

  gf::Color4f getColor(gf::GamepadButton gamepadButton) {
    if (gamepadButton == gf::GamepadButton::A) {
      return gf::Color::Green;
    }
    else if (gamepadButton == gf::GamepadButton::B) {
      return gf::Color::Red;
    }
    else if (gamepadButton == gf::GamepadButton::X) {
      return gf::Color::Blue;
    }
    else if (gamepadButton == gf::GamepadButton::Y) {
      return gf::Color::Yellow;
    }
    return gf::Color::Black;
  }

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
  , m_buttonTexture(resources.getTexture("images/button_player.png"))
  {

  }

  void SliderEntity::setDifficulty(SliderChallengeDifficulty difficulty) {
    m_played = false;
    m_easeDelay = static_cast<int>(difficulty);
    m_cursorPosition = 0.0f;
    m_activity = ga::AnyActivity(createActivity(m_easeDelay, m_cursorPosition));
  }

  bool SliderEntity::isHit() const {
    float upperBounds = 0.5f + GoalRelativeSize.width + 2.0f * CursorRelativeSize.width;
    float lowerBounds = 0.5f - GoalRelativeSize.width - 2.0f * CursorRelativeSize.width;
    return m_cursorPosition >= lowerBounds && m_cursorPosition <= upperBounds;
  }

  bool SliderEntity::stopCursor() {
    m_played = true;
    return isHit();
  }

  ChallengeResult SliderEntity::getStatus() const {
    if (!m_played) {
      return ChallengeResult::None;
    }

    return (isHit() ? ChallengeResult::Success : ChallengeResult::Failure);
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

  void SliderEntity::reset() {
    m_played = false;
    gf::Log::debug("Reset\n");
  }

  void SliderEntity::update(gf::Time time) {
    if (!m_played) {
      m_activity.run(time);
    }
  }

  void SliderEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Coordinates coords(target);

    auto renderMessage = [&](const std::string& messageString) {
      gf::Text message(messageString, m_font, coords.getRelativeCharacterSize(0.05f));
      message.setColor(gf::Color::White);
      auto messagePosition = coords.getRelativeSize(gf::vec(0.5f, 0.2f));
      message.setPosition(messagePosition);
      message.setAnchor(gf::Anchor::Center);
      target.draw(message, states);
    };

    auto renderButton = [&](gf::GamepadButton gamepadButton, gf::Vector2f buttonPosition, const gf::Texture& texture) {
      auto position = coords.getRelativePoint(buttonPosition);
      unsigned fontSize = coords.getRelativeCharacterSize(0.075f);
      float radius = coords.getRelativeSize(gf::vec(0.06f, 0.0f)).width;
      float radiusScale = radius / texture.getSize().height;
      gf::Color4f colorButton = getColor(gamepadButton);

      gf::Sprite sprite(texture);
      sprite.setPosition(position);
      sprite.setAnchor(gf::Anchor::Center);
      sprite.setColor(colorButton);
      sprite.setScale(radiusScale);
      target.draw(sprite, states);

      gf::Text textButton(gamepadValue(gamepadButton), m_font, fontSize);
      textButton.setPosition(position);
      textButton.setAnchor(gf::Anchor::Center);
      textButton.setColor(gf::Color::White * gf::Color::Opaque(0.7f));
      target.draw(textButton, states);
    };

    gf::RectangleShape background(target.getSize());
    background.setPosition(gf::vec(0.0f, 0.0f));
    background.setColor(gf::Color::Black * gf::Color::Opaque(0.7f));
    target.draw(background, states);

    gf::RectF sliderBox = gf::RectF::fromCenterSize(coords.getCenter(), coords.getRelativeSize(SliderRelativeSize));
    gf::RoundedRectangleShape slider(sliderBox);
    slider.setRadius(sliderBox.getHeight() / 4);
    slider.setColor(gf::Color::Gray());
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
    cursor.setColor(gf::Color::Yellow * gf::Color::Opaque(0.7f));
    target.draw(cursor, states);

    if (m_played) {
      (isHit() ? renderMessage(_("You got the clue!")) : renderMessage(_("You missed the clue!")));
      gf::Text message((isHit() ? _("Success") : _("Failed")), m_font, coords.getRelativeCharacterSize(0.1f));
      message.setColor(gf::Color::White);
      auto messagePosition = slider.getPosition();
      messagePosition.x = coords.getCenter().x;
      messagePosition.y -=  3.0f * slider.getSize().height;
      message.setPosition(messagePosition);
      message.setAnchor(gf::Anchor::Center);
      target.draw(message, states);
    }
    else {
        renderMessage(_("Hit the target to \n get a new clue: "));
        renderButton(gf::GamepadButton::A, { 0.5,0.9 }, m_buttonTexture);

    }
  }
}
