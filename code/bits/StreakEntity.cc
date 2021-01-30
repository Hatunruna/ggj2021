#include "StreakEntity.h"

#include <gf/Coordinates.h>
#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Sprite.h>
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
}

namespace tlw {

  StreakEntity::StreakEntity(gf::ResourceManager& resources, gf::Random& random)
  : m_random(random)
  , m_buttonFont(resources.getFont("Tippa.ttf"))
  , m_messageFont(resources.getFont("Aquifer.otf"))
  , m_status(StreakChallengeStatus::ShowingSolution)
  , m_opacity(1.0f)
  , m_activities(createActivity(m_opacity))
  {
    generateStreak(5);
  }

  // reset all value from last game
  void StreakEntity::reset(int buttonCount) {
    generateStreak(buttonCount);
    m_status = StreakChallengeStatus::ShowingSolution;
    m_activities.restart();
    m_streakPlayer.clear();
    m_opacity = 1.0f;
  }

  void StreakEntity::addPlayerInput(gf::GamepadButton gamepadButton) {
    if (m_status == StreakChallengeStatus::WaitingPlayerInput) {
      m_streakPlayer.push_back(gamepadButton);

      if (m_streakPlayer.size() == m_streakSolution.size()) {
        m_status = StreakChallengeStatus::ShowingResultMessage;
      }
    }
  }

  bool StreakEntity::isCorrect() const {
    return m_streakPlayer == m_streakSolution;
  }

  StreakChallengeStatus StreakEntity::getStatus() const {
    return m_status;
  }

  void StreakEntity::update(gf::Time time) {
    auto status = m_activities.run(time);

    if (status == gf::ActivityStatus::Finished && m_status == StreakChallengeStatus::ShowingSolution) {
      m_status = StreakChallengeStatus::WaitingPlayerInput;
    }
  }

  void StreakEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Coordinates coords(target);

    auto renderButton = [this, &target, &states, &coords](gf::GamepadButton gamepadButton, float buttonRelativeXPosition, const gf::Color4f& buttonColor){
      auto position = coords.getRelativePoint({ buttonRelativeXPosition, 0.5f });
      float radius = coords.getRelativeSize(gf::vec(0.03f, 0.0f)).width;
      int fontSize = coords.getRelativeCharacterSize(0.075f);
      float opacity = (m_status == StreakChallengeStatus::ShowingSolution ? m_opacity : 1.0f);

      gf::CircleShape circle(radius);
      circle.setPosition(position);
      circle.setAnchor(gf::Anchor::Center);
      circle.setOutlineThickness(radius * 0.05f);
      circle.setColor(buttonColor * gf::Color::Opaque(opacity));
      circle.setOutlineColor(gf::Color::White * gf::Color::Opaque(opacity));
      target.draw(circle, states);

      gf::Text textButton(gamepadValue(gamepadButton), m_messageFont, fontSize);
      textButton.setPosition(position);
      textButton.setAnchor(gf::Anchor::Center);
      textButton.setColor(gf::Color::White * gf::Color::Opaque(opacity));
      target.draw(textButton, states);
    };

    float buttonRelativeXPosition = 1.0f / (m_streakSolution.size() + 1); // initialie position for the first circle
    if (m_status == StreakChallengeStatus::ShowingSolution) {
      for (const auto& gamepadButton: m_streakSolution) {
        renderButton(gamepadButton, buttonRelativeXPosition, gf::Color::Red);
        buttonRelativeXPosition += 1.0f / (m_streakSolution.size() + 1);
      }
    } else {
      for (const auto& gamepadButton: m_streakPlayer) {
        renderButton(gamepadButton, buttonRelativeXPosition, gf::Color::Blue);
        buttonRelativeXPosition += 1.0f / (m_streakSolution.size() + 1);
      }

      if (m_status == StreakChallengeStatus::ShowingResultMessage) {
        gf::Text message((isCorrect() ? _("Success") : _("Failed")), m_messageFont, coords.getRelativeCharacterSize(0.1f));
        message.setColor(gf::Color::White);
        auto messagePosition = coords.getRelativeSize(gf::vec(0.5f, 0.3f));
        message.setPosition(messagePosition);
        message.setAnchor(gf::Anchor::Center);
        target.draw(message, states);
      }
    }
  }

  void StreakEntity::generateStreak(int buttonCount) {
    m_streakSolution.clear();
    for (int i = 0; i < buttonCount; ++i) {
      m_streakSolution.push_back(static_cast<gf::GamepadButton>(m_random.computeUniformInteger(1, 4)));
    }
  }
}
