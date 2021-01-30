#include "StreakEntity.h"

#include <gf/Coordinates.h>
#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Sprite.h>
#include <gf/Text.h>

#include "I18N.h"

namespace tlw {

    StreakEntity::StreakEntity(gf::ResourceManager& resources, std::vector<gf::GamepadButton> streak)
        : m_font(resources.getFont("Tippa.ttf"))
        , m_backgroundTexture(resources.getTexture("logo.png"))
        , m_streak(streak)
        , m_buttons()
        , m_radius(75.0f)
        , m_wordsFont(resources.getFont("Aquifer.otf"))
        , m_clock()
        , m_timer(m_clock.restart())
        , m_displayPosition(1.0f / (m_buttons.size() + 1))
        , m_opacity(100)
        , m_canPlay(false)
        , m_streakPlayer()
        , m_success(false)
        , m_failed(false)
  {

      for (gf::GamepadButton button : m_streak) {

          gf::CircleShape circle;
          circle.setRadius(m_radius);
          circle.setAnchor(gf::Anchor::Center);
          circle.setOutlineThickness(5);
          circle.setColor(gf::Color::Red);
          circle.setOutlineColor(gf::Color::White);

          m_buttons.insert(m_buttons.begin(), circle);
      }
  }

  void StreakEntity::displayPlayerAnswer(gf::GamepadButton button) {
      m_streakPlayer.push_back(button);
  }

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
  void StreakEntity::success() {
      m_success = true;
  }
  void StreakEntity::failed() {
      m_failed = true;
  }

  void StreakEntity::update([[maybe_unused]] gf::Time time) {
      m_timer.addTo(time);
  }

  void StreakEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {

        m_displayPosition = 1.0f / (m_buttons.size() + 1);
        int i = 0;
        std::string buttonName;

        gf::Coordinates coords(target);

        if (m_success) {
            gf::Text text("SUCCESS", m_wordsFont);
            text.setPosition(coords.getRelativePoint({ 0.5 , 0.2 }));
            text.setColor(gf::Color::White);
            target.draw(text, states);
        }

        if (m_failed) {
            gf::Text text("FAILED", m_wordsFont);
            text.setPosition(coords.getRelativePoint({ 0.5 , 0.2 }));
            text.setColor(gf::Color::White);
            target.draw(text, states);
        }

        // rendering player answer 
        for (gf::GamepadButton button : m_streakPlayer) {

            gf::CircleShape circlePlayer; 
            circlePlayer.setPosition(coords.getRelativePoint({ m_displayPosition , 0.5 }));
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


            textPlayer.setPosition(coords.getRelativePoint({ m_displayPosition , 0.5 }));

            target.draw(circlePlayer, states);
            target.draw(textPlayer, states);

            m_displayPosition += 1.0f / (m_buttons.size() + 1);
        }

        m_displayPosition = 1.0f / (m_buttons.size() + 1);



        // rendering game streak 
        for (gf::CircleShape circle : m_buttons) {
            circle.setPosition(coords.getRelativePoint({ m_displayPosition , 0.5 }));

            buttonName = gamepadValue(m_streak.at(i));
            i++;
            gf::Text text(buttonName, m_wordsFont);
            
            text.setCharacterSize(30);
            text.setAnchor(gf::Anchor::Center);

            if (m_timer.asSeconds() > 4.0) {
                text.setColor(gf::Color::Opaque(m_opacity));
                circle.setColor(gf::Color::Opaque(m_opacity));
                circle.setOutlineColor(gf::Color::Opaque(m_opacity));

                m_opacity -= 0.25f;
                m_opacity = gf::clamp(m_opacity, 0.0f, 1.0f);
                m_canPlay = true;
            }else {
                text.setColor(gf::Color::White);
            }

            text.setPosition(coords.getRelativePoint({ m_displayPosition , 0.5 }));
            target.draw(circle, states);
            target.draw(text, states);
            m_displayPosition += 1.0f / (m_buttons.size() + 1);

        }

  }
}
