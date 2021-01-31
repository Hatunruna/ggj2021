#include "Plot.h"

#include "GameHub.h"

using namespace gf::literals;

namespace tlw {
  Plot::Plot(GameHub& game)
  : m_game(game)
  {
    // TODO: remove this
//     m_game.state.currentDialog = "Chap1Dread1"_id;

    m_game.state.characters[CharacterType::Holly].visibility = CharacterVisibility::Hidden;
    m_game.state.characters[CharacterType::Stock].visibility = CharacterVisibility::Hidden;

    m_game.state.characters[CharacterType::Bouquet].dialog = "Chap1Bouquet1"_id;
    m_game.state.characters[CharacterType::Elders].dialog = "Chap1Elders1"_id;
    m_game.state.characters[CharacterType::Dread].dialog = "Chap1Dread1"_id;
    m_game.state.characters[CharacterType::Gustavo].dialog = "Chap1Gustavo1"_id;

  }

  void Plot::onDialogEnd(gf::Id dialogId) {
    switch (dialogId) {
      case "Chap1Dread1"_id:
        m_game.state.characters[CharacterType::Dread].dialog = "Chap1Dread_NotFinished"_id;
        m_game.state.nextDialogSuccess = "Chap1Dread_Success"_id;
        m_game.state.nextDialogFailure = "Chap1Dread_Failure"_id;
        m_game.state.result = ChallengeResult::None;
        m_game.pushScene(m_game.sliderChallenge);
        break;

      case "Chap1Elders1"_id:
        m_game.state.characters[CharacterType::Elders].dialog = "Chap1Elders2"_id;
        break;

      case "Chap1Dread_NotFinished"_id:
        break;

      case "Chap1Dread_Finished"_id:
        break;

      case "Chap1Search"_id:
        m_game.state.nextDialogSuccess = "Chap1Dread_Success"_id;
        m_game.state.nextDialogFailure = "Chap1Dread_Failure"_id;
        m_game.state.result = ChallengeResult::None;
        gf::Log::debug("push challenge\n");
        m_game.pushScene(m_game.streakChallenge);

      default:
        break;
    }
  }

  void Plot::onStreakChallengeEnd() {
  }

  void Plot::onSliderChallengeEnd() {
    assert(m_game.state.result != ChallengeResult::None);

    if (m_game.state.result == ChallengeResult::Success) {
      m_game.state.currentDialog = m_game.state.nextDialogSuccess;
    } else {
      assert(m_game.state.result == ChallengeResult::Failure);
      m_game.state.currentDialog = m_game.state.nextDialogFailure;
    }

    // m_game.popScene();
    gf::Log::debug("push end dialog\n");
    m_game.pushScene(m_game.dialog);
  }

}
