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
  }

  void DialogScene::doHandleActions([[maybe_unused]] gf::Window& window) {
    if (m_nextAction.isActive()) {
      auto it = m_game.data.dialogs.find(m_game.state.currentDialog);
      assert(it != m_game.data.dialogs.end());
      auto& [ currentId, currentDialog ] = *it;

      ++m_game.state.currentLine;

      if (m_game.state.currentLine == currentDialog.lines.size()) {
        m_game.state.currentDialog = gf::InvalidId;
        m_game.state.currentLine = 0;
        m_game.plot.onDialogEnd(currentId);

        // TODO: pop scene
      }
    }
  }

}
