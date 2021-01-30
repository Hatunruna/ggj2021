#ifndef DIALOG_SCENE_H
#define DIALOG_SCENE_H

#include <gf/Action.h>
#include <gf/Scene.h>

#include "DialogEntity.h"

namespace tlw {

  struct GameHub;

  class DialogScene : public gf::Scene {
  public:
    DialogScene(GameHub& game);

  private:
    void doHandleActions(gf::Window& window) override;

  private:
    GameHub& m_game;

    gf::Action m_nextAction;

    DialogEntity m_dialogEntity;
  };

}

#endif // DIALOG_SCENE_H
