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
    StreakEntity(gf::ResourceManager& resources);
    void displayPlayerAnswer(gf::GamepadButton button);
    void updateStreak(std::vector< gf::GamepadButton> streak);
    bool canPlay();
    void reset();
    void success();
    void failed();

  private:
    void update(gf::Time time) override;
    void render(gf::RenderTarget& target, const gf::RenderStates& states) override;
    std::vector<gf::GamepadButton> m_streak;
    std::vector<gf::GamepadButton> m_streakPlayer;
    std::vector<gf::CircleShape> m_buttons;
    std::string gamepadValue(gf::GamepadButton button);
    gf::Texture& m_backgroundTexture; 
    gf::Font& m_font;
    gf::Font& m_wordsFont;
    float m_timer;
    float m_radius;
    float m_displayPosition;
    float m_opacity;
    bool m_reset;
    bool m_canPlay;
    bool m_success;
    bool m_failed;
  };


}


#endif // STREAK_ENTITY_H
