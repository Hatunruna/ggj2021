#ifndef SLIDER_ENTITY_H
#define SLIDER_ENTITY_H

#include <memory>

#include <gf/Activities.h>
#include <gf/Entity.h>

namespace tlw {
  enum class SliderChallengeDifficulty : int {
    Easy = 6,
    Medium = 4,
    Hard = 2,
  };

  class SliderEntity : public gf::Entity {
  public:
    SliderEntity();

    void setDifficulty(SliderChallengeDifficulty difficulty);
    bool stopCursor() const;

    // TODO: To debug and test functions, remove it later
    void increaseSpeed();
    void decreaseSpeed();

    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;


  private:
    int m_easeDelay;
    float m_cursorPosition;
    std::unique_ptr<gf::activity::AnyActivity> m_activity;
  };
}

#endif // SLIDER_ENTITY_H
