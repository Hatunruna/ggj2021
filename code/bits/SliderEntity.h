#ifndef SLIDER_ENTITY_H
#define SLIDER_ENTITY_H

#include <gf/Activities.h>
#include <gf/Entity.h>
#include <gf/Font.h>
#include <gf/ResourceManager.h>

#include "GameState.h"

namespace tlw {
  enum class SliderChallengeDifficulty : int {
    Easy = 6,
    Medium = 4,
    Hard = 2,
  };

  class SliderEntity : public gf::Entity {
  public:
    SliderEntity(gf::ResourceManager& resources);

    void setDifficulty(SliderChallengeDifficulty difficulty);
    bool isHit() const;
    ChallengeResult getStatus() const;

    bool stopCursor();
    // TODO: To debug and test functions, remove it later
    void increaseSpeed();
    void decreaseSpeed();
    void reset();

    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;


  private:
    gf::Font& m_font;

    int m_easeDelay;
    float m_cursorPosition;
    gf::activity::AnyActivity m_activity;
    bool m_played;
    gf::Texture& m_buttonTexture;
  };
}

#endif // SLIDER_ENTITY_H
