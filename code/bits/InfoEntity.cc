#include "InfoEntity.h"

#include <gf/Coordinates.h>
#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Sprite.h>

namespace tlw {

  InfoEntity::InfoEntity(gf::ResourceManager& resources)
  : m_searchTexture(resources.getTexture("logo.png"))
  , m_searchActive(false)
  , m_dialogTexture(resources.getTexture("logo.png"))
  , m_dialogActive(false)
  {
  }

  void InfoEntity::update([[maybe_unused]] gf::Time time) {
  }

  void InfoEntity::render(gf::RenderTarget &target, const gf::RenderStates &states) {
    gf::Coordinates coords(target);


    if (m_searchActive) {
      float searchHeight = coords.getRelativeSize(gf::vec(0.0f, 0.1f)).height;
      float searchScale = searchHeight / m_searchTexture.getSize().height;

      gf::Sprite search(m_searchTexture);
      search.setPosition(coords.getRelativePoint(gf::vec(0.95f, 0.1f)));
      search.setAnchor(gf::Anchor::Center);
      search.setScale(searchScale);
      target.draw(search, states);
    }

    if (m_dialogActive) {
      float dialogHeight = coords.getRelativeSize(gf::vec(0.0f, 0.1f)).height;
      float dialogScale = dialogHeight / m_searchTexture.getSize().height;

      gf::Sprite dialog(m_dialogTexture);
      dialog.setPosition(coords.getRelativePoint(gf::vec(0.95f, 0.2f)));
      dialog.setAnchor(gf::Anchor::Center);
      dialog.setScale(dialogScale);
      target.draw(dialog, states);
    }
  }

  void InfoEntity::setSearchActive(bool state) {
    m_searchActive = state;
  }

  void InfoEntity::setDialogActive(bool state) {
    m_dialogActive = state;
  }
}
