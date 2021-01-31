#include "StreakEntity.h"

#include <gf/Coordinates.h>
#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Sprite.h>
#include <gf/StringUtils.h>
#include <gf/Text.h>

#include "I18N.h"

namespace {
  constexpr int ShowingSolutionDelay = 3;
  constexpr int ShowingSolutionFadingDelay = 1;


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

  namespace ga = gf::activity;

  auto createActivity(float& opacity) {
    return ga::sequence(
      ga::delay(gf::seconds(ShowingSolutionDelay)),
      ga::value(1.0f, 0.0f, opacity, gf::seconds(ShowingSolutionFadingDelay), gf::Ease::expoIn)
    );
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
}

namespace tlw {

  StreakEntity::StreakEntity(gf::ResourceManager& resources, gf::Random& random)
  : m_random(random)
  , m_buttonFont(resources.getFont("Tippa.ttf"))
  , m_messageFont(resources.getFont("Aquifer.otf"))
  , m_buttonSolutionTexture(resources.getTexture("images/button_solution.png"))
  , m_buttonPlayerTexture(resources.getTexture("images/button_player.png"))
  , m_status(ChallengeResult::None)
  , m_countdown(ShowingSolutionDelay + ShowingSolutionFadingDelay)
  , m_opacity(1.0f)
  , m_activities(createActivity(m_opacity))
  , m_timer(ShowingSolutionDelay+ShowingSolutionFadingDelay)
  {
    generateStreak(5);
    m_buttonSolutionTexture.setSmooth(true);
    m_buttonPlayerTexture.setSmooth(true);
  }

  // reset all value from last game
  void StreakEntity::reset(int buttonCount) {
    generateStreak(buttonCount);
    m_status = ChallengeResult::None;
    m_activities.restart();
    m_streakPlayer.clear();
    m_opacity = 1.0f;
    m_countdown = ShowingSolutionDelay + ShowingSolutionFadingDelay;
  }

  void StreakEntity::addPlayerInput(gf::GamepadButton gamepadButton) {
    if (m_countdown < 0.0f && m_streakPlayer.size() < m_streakSolution.size()) {
      m_streakPlayer.push_back(gamepadButton);
    }
  }

  bool StreakEntity::isCorrect() const {
    bool equals = m_streakPlayer == m_streakSolution;
    return m_streakPlayer == m_streakSolution;
  }

  ChallengeResult StreakEntity::getStatus() const {
    return m_status;
  }

  void StreakEntity::update(gf::Time time) {
    auto status = m_activities.run(time);
    m_countdown -= time.asSeconds();
  }

  void StreakEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Coordinates coords(target);
    int fontSize = coords.getRelativeCharacterSize(0.075f);

    gf::RectangleShape background(target.getSize());
    background.setPosition(gf::vec(0.0f, 0.0f));
    background.setColor(gf::Color::Black * gf::Color::Opaque(0.7f));
    target.draw(background, states);

    auto renderButton = [&](gf::GamepadButton gamepadButton, float buttonRelativeXPosition, const gf::Texture& texture){
      auto position = coords.getRelativePoint({ buttonRelativeXPosition, 0.5f });
      unsigned fontSize = coords.getRelativeCharacterSize(0.075f);
      float radius = coords.getRelativeSize(gf::vec(0.06f, 0.0f)).width;
      float radiusScale = radius / texture.getSize().height;
      float opacity = (m_countdown >= 0.0f ? m_opacity : 1.0f);
      gf::Color4f colorButton = getColor(gamepadButton);

      gf::Sprite sprite(texture);
      sprite.setPosition(position);
      sprite.setAnchor(gf::Anchor::Center);
      sprite.setColor(colorButton);
      sprite.setScale(radiusScale);
      target.draw(sprite, states);

      gf::Text textButton(gamepadValue(gamepadButton), m_messageFont, fontSize);
      textButton.setPosition(position);
      textButton.setAnchor(gf::Anchor::Center);
      textButton.setColor(gf::Color::White * gf::Color::Opaque(opacity));
      target.draw(textButton, states);

    };

    auto renderMessage = [&](const std::string& messageString) {
      gf::Text message(messageString, m_messageFont, coords.getRelativeCharacterSize(0.1f));
      message.setColor(gf::Color::White);
      auto messagePosition = coords.getRelativeSize(gf::vec(0.5f, 0.3f));
      message.setPosition(messagePosition);
      message.setAnchor(gf::Anchor::Center);
      target.draw(message, states);
    };

    float buttonRelativeXPosition = 1.0f / (m_streakSolution.size() + 1); // initialie position for the first circle
    if (m_countdown >= 0.0f) {
      for (const auto& gamepadButton: m_streakSolution) {
        renderButton(gamepadButton, buttonRelativeXPosition, m_buttonPlayerTexture);
        buttonRelativeXPosition += 1.0f / (m_streakSolution.size() + 1);
      }
    } else {

//       gf::Text textInstruction("Enter the streak : ", m_messageFont, fontSize);
//       textInstruction.setAnchor(gf::Anchor::Center);
//       textInstruction.setColor(gf::Color::White);
//       textInstruction.setPosition(coords.getRelativePoint({ 0.5f, 0.1f }));
//       target.draw(textInstruction, states);

      for (const auto& gamepadButton: m_streakPlayer) {
        renderButton(gamepadButton, buttonRelativeXPosition, m_buttonPlayerTexture);
        buttonRelativeXPosition += 1.0f / (m_streakSolution.size() + 1);
      }
    }

    // Render message
    if (m_countdown >= 0.0f) {
      m_countdown = (m_countdown < 0.0f ? 0.0f : m_countdown);
      renderMessage(gf::formatString(_("Memorize: %d seconds.").c_str(), static_cast<int>(m_countdown)));
    } else if (m_countdown < 0.0f && m_streakPlayer.size() < m_streakSolution.size()) {
      renderMessage(_("Repeat the sequence:"));
    } else {
      bool success = isCorrect();
      m_status = (success ? ChallengeResult::Success : ChallengeResult::Failure);
      renderMessage((success ? _("Success") : _("Failed")));
    }
  }

  void StreakEntity::generateStreak(int buttonCount) {
    m_streakSolution.clear();
    for (int i = 0; i < buttonCount; ++i) {
      m_streakSolution.push_back(static_cast<gf::GamepadButton>(m_random.computeUniformInteger(1, 4)));
    }
  }
}
