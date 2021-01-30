#ifndef STREAK_ENTITY_H
#define STREAK_ENTITY_H

#include <gf/Entity.h>
#include <gf/Font.h>
#include <gf/ResourceManager.h>
#include <gf/Shapes.h>
#include <gf/Gamepad.h>

namespace tlw {

  class StreakEntity : public gf::Entity {
  public:
    StreakEntity(gf::ResourceManager& resources, std::vector<gf::GamepadButton> streak);
    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;
    void displayPlayerAnswer(gf::GamepadButton button);
    void success();
    void failed();
    bool m_canPlay;
    bool m_success;
    bool m_failed;

  private:
    gf::Font& m_font;
    gf::Texture& m_backgroundTexture; 
    std::vector<gf::GamepadButton> m_streak;
    std::vector<gf::GamepadButton> m_streakPlayer;
    std::vector<gf::CircleShape> m_buttons;
    gf::Font& m_wordsFont;
    float m_radius;
    gf::Clock m_clock;
    gf::Time m_timer;
    float m_displayPosition;
    float m_opacity;
    std::string gamepadValue(gf::GamepadButton button);
  };


}


#endif // STREAK_ENTITY_H
