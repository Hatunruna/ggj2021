#include "Plot.h"

#include "GameHub.h"

using namespace gf::literals;

namespace tlw {
  Plot::Plot(GameHub& game)
  : m_game(game)
  {
    loadChapter(0);
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

      case "Chap1SearchWoodHouse"_id:
        m_game.state.nextDialogSuccess = "Chap1SearchWoodHouse_Success"_id;
        m_game.state.nextDialogFailure = "Chap1SearchWoodHouse_Failure"_id;
        m_game.state.result = ChallengeResult::None;
        m_game.pushScene(m_game.streakChallenge);
        break;

      case "Chap1Dread_Success"_id:
      case "Chap1Dread_Failure"_id:
      case "Chap1SearchWoodHouse_Success"_id:
      case "Chap1SearchWoodHouse_Failure"_id:
        if (checkEndChapter()) {
          m_game.state.currentDialog = "RaymondEndChapter"_id;
          m_game.pushScene(m_game.dialog);
        }
        break;

      case "Chap1Elders1"_id:
        m_game.state.characters[CharacterType::Elders].dialog = "Chap1Elders2"_id;
        break;

      case "Chap1Dread_NotFinished"_id:
        break;

      case "Chap1Dread_Finished"_id:
        loadChapter(++m_game.state.chapter);
        break;

      default:
        break;
    }
  }

  void Plot::onStreakChallengeEnd() {
    assert(m_game.state.result != ChallengeResult::None);

    if (m_game.state.result == ChallengeResult::Success) {
      m_game.state.currentDialog = m_game.state.nextDialogSuccess;
    } else {
      assert(m_game.state.result == ChallengeResult::Failure);
      m_game.state.currentDialog = m_game.state.nextDialogFailure;
    }

    ++m_game.state.finishedSearchs;

    m_game.pushScene(m_game.dialog);
  }

  void Plot::onSliderChallengeEnd() {
    assert(m_game.state.result != ChallengeResult::None);

    if (m_game.state.result == ChallengeResult::Success) {
      m_game.state.currentDialog = m_game.state.nextDialogSuccess;
    } else {
      assert(m_game.state.result == ChallengeResult::Failure);
      m_game.state.currentDialog = m_game.state.nextDialogFailure;
    }

    ++m_game.state.finishedInvestigations;

    m_game.pushScene(m_game.dialog);
  }

  bool Plot::checkEndChapter() {
    if ((m_game.state.finishedInvestigations + m_game.state.finishedSearchs) >= m_game.data.limitClues[m_game.state.chapter]) {
      m_game.state.characters.at(CharacterType::Dread).dialog = "Chap1Dread_Finished"_id;
      return true;
    }

    return false;
  }


    void Plot::loadChapter(int chapterNumber) {
      switch (chapterNumber) {
      case 0:
        // TODO: remove this
        // m_game.state.currentDialog = "Chap1Dread1"_id;

        m_game.state.characters[CharacterType::Holly].visibility = CharacterVisibility::Hidden;
        m_game.state.characters[CharacterType::Stock].visibility = CharacterVisibility::Hidden;

        m_game.state.characters[CharacterType::Bouquet].dialog = "Chap1Bouquet1"_id;
        m_game.state.characters[CharacterType::Elders].dialog = "Chap1Elders1"_id;
        m_game.state.characters[CharacterType::Dread].dialog = "Chap1Dread1"_id;
        m_game.state.characters[CharacterType::Gustavo].dialog = "Chap1Gustavo1"_id;
        break;

      case 1:
        m_game.state.characters[CharacterType::Bouquet].dialog = gf::InvalidId;
        m_game.state.characters[CharacterType::Elders].dialog = "Chap2Elders"_id;
        m_game.state.characters[CharacterType::Dread].dialog = gf::InvalidId;
        m_game.state.characters[CharacterType::Gustavo].dialog = gf::InvalidId;
        break;

      default:
        break;
      }
    }

}
