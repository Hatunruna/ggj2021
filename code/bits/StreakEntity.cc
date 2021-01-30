#include "StreakEntity.h"

#include <gf/Coordinates.h>
#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Sprite.h>
#include <gf/Text.h>

#include "I18N.h"

namespace tlw {

  StreakEntity::StreakEntity(gf::ResourceManager& resources)
  : m_font(resources.getFont("Tippa.ttf"))
  , m_backgroundTexture(resources.getTexture("logo.png"))
  , m_streak()
  , m_buttons()
  , m_radius(75.0f)
  , m_wordsFont(resources.getFont("Aquifer.otf"))
  , m_timer(0.0)
  , m_displayPosition(1.0f / (m_buttons.size() + 1))
  , m_opacity(100)
  , m_canPlay(false)
  , m_streakPlayer()
  , m_success(false)
  , m_failed(false)
  , m_reset(false)
  {
  }

  // fill m_streakPlayer vector that will be displayed in render()
  void StreakEntity::displayPlayerAnswer(gf::GamepadButton button) {
    m_streakPlayer.push_back(button);
  }

  // reset all value from last game
  void StreakEntity::reset() {

    m_reset = true;
    m_success = false;
    m_failed = false;
    m_canPlay = false;

    m_streak = { };
    m_streakPlayer = { };
    m_buttons = { };

    m_opacity = 1;
    m_timer = 0.0f;
  }

  // give a new streak for the next game
  void StreakEntity::updateStreak(std::vector< gf::GamepadButton> streak) {
      
    m_streak = streak;

    for (gf::GamepadButton button : streak) {

      gf::CircleShape circle;
      circle.setRadius(m_radius);
      circle.setAnchor(gf::Anchor::Center);
      circle.setOutlineThickness(5);
      circle.setColor(gf::Color::Red);
      circle.setOutlineColor(gf::Color::White);

      m_buttons.insert(m_buttons.begin(), circle);
    }

    m_timer = 0.0f;
  }

  // return the string represented by the GamepadButton button
  std::string StreakEntity::gamepadValue(gf::GamepadButton button) {
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

  // return true if player can enter his answer, false otherwise
  bool StreakEntity::canPlay() {
    return m_canPlay;
  }

  // mark current streak as successed
  void StreakEntity::success() {
    m_success = true;
  }

  // mark current streak as failed
  void StreakEntity::failed() {
    m_failed = true;
  }

  void StreakEntity::update(gf::Time time) {
    m_timer += time.asSeconds();
  }

  void StreakEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    int i = 0;
    std::string buttonName;
    gf::Coordinates coords(target);

    m_displayPosition = 1.0f / (m_buttons.size() + 1); // initialie position for the first circle

    // reset success and fail text
    if (m_reset) {
      m_success = false;
      m_failed = false; 
      m_reset = false;
      return;
    }


    // successed streak
    if (m_success) {
      gf::Text text("SUCCESS", m_wordsFont);
      text.setCharacterSize(100);
      text.setAnchor(gf::Anchor::Center);
      text.setPosition(coords.getRelativePoint({ 0.5f , 0.5f }));
      text.setColor(gf::Color::Green);
      target.draw(text, states);
      m_canPlay = false;
      return;
    }

    // failed streak
    if (m_failed) {
      gf::Text text("FAILED", m_wordsFont);
      text.setCharacterSize(100);
      text.setAnchor(gf::Anchor::Center);
      text.setPosition(coords.getRelativePoint({ 0.5f , 0.5f }));
      text.setColor(gf::Color::Red);
      target.draw(text, states);
      m_canPlay = false;
      return;
    }

    // rendering player answer 
    for (gf::GamepadButton button : m_streakPlayer) {

      gf::CircleShape circlePlayer; 
      circlePlayer.setPosition(coords.getRelativePoint({ m_displayPosition , 0.5f }));
      buttonName = gamepadValue(button);

      gf::Text textPlayer(buttonName, m_wordsFont);
      textPlayer.setCharacterSize(30);
      textPlayer.setAnchor(gf::Anchor::Center);
      textPlayer.setColor(gf::Color::White);

      circlePlayer.setRadius(m_radius);
      circlePlayer.setAnchor(gf::Anchor::Center);
      circlePlayer.setOutlineThickness(5);
      circlePlayer.setColor(gf::Color::Blue);
      circlePlayer.setOutlineColor(gf::Color::White);


      textPlayer.setPosition(coords.getRelativePoint({ m_displayPosition , 0.5f }));

      target.draw(circlePlayer, states);
      target.draw(textPlayer, states);

      m_displayPosition += 1.0f / (m_buttons.size() + 1);
    }


    // rendering game streak 
    for (gf::CircleShape circle : m_buttons) {
        
      circle.setPosition(coords.getRelativePoint({ m_displayPosition , 0.5f }));

      buttonName = gamepadValue(m_streak.at(i));
      gf::Text text(buttonName, m_wordsFont);
      i++;
            
      text.setCharacterSize(30);
      text.setAnchor(gf::Anchor::Center);

      if (m_timer > 4.0) {
        text.setColor(gf::Color::Opaque(m_opacity));
        circle.setColor(gf::Color::Opaque(m_opacity));
        circle.setOutlineColor(gf::Color::Opaque(m_opacity));

        m_opacity -= 0.25f;
        m_opacity = gf::clamp(m_opacity, 0.0f, 1.0f);
        m_canPlay = true;
            
      }else {
        text.setColor(gf::Color::White);
      }

      text.setPosition(coords.getRelativePoint({ m_displayPosition , 0.5f }));
      target.draw(circle, states);
      target.draw(text, states);
      m_displayPosition += 1.0f / (m_buttons.size() + 1);
    }
  }
}
