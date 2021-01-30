#include "DialogScene.h"

#include <gf/Color.h>

#include "GameHub.h"

using namespace gf::literals;

namespace tlw {

  DialogScene::DialogScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_nextAction("Next")
  , m_dialogEntity(game.resources, game.data, game.state)
  {
    setClearColor(gf::Color::Black);

    m_nextAction.addGamepadButtonControl(gf::AnyGamepad, gf::GamepadButton::A);
    addAction(m_nextAction);

    addHudEntity(m_dialogEntity);


    // TODO: remove this
    m_game.state.currentDialog = "Chap1DreadFirstMeeting"_id;

  }

  void DialogScene::doHandleActions([[maybe_unused]] gf::Window& window) {
    if (m_nextAction.isActive()) {
    }
  }

}
