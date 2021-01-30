#ifndef SLIDER_ENTITY_H
#define SLIDER_ENTITY_H

#include <gf/Activities.h>
#include <gf/Entity.h>

namespace tlw {

  class SliderEntity : public gf::Entity {
  public:
    SliderEntity();

    void update(gf::Time time) override;
    void render(gf::RenderTarget &target, const gf::RenderStates &states) override;

  private:
    float m_cursorPosition;
    gf::activity::AnyActivity m_activity;
  };
}

#endif // SLIDER_ENTITY_H
