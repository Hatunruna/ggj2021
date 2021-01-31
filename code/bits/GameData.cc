#include "GameData.h"

#include "I18N.h"

using namespace gf::literals;

namespace tlw {

  GameData::GameData() {
    chapters = {
      {
        _("Chapter 1."),
        _("I have been called by Ms Dread to handle a very particular situation. Ms Dread is the lawyer of Ms Wood. Ms Wood has just died and nobody can find her last will. My mission is to find it.\nI don't know exactly where to start but I should see Ms Dread first. She may have valuable information for me.")
      }
    };

    dialogs = {
      /*
       * Chapter 1
       */
      {
        "Chap1Dread1"_id, {
          DialogType::Investigation, {
            { _("Raymond"),   _("Good evening Ms Dread. I am Raymond Adupif, at your service. Can you tell me more about the situation?") },
            { _("Ms Dread"),  _("Good evening M. Adupif. I'm glad you're here. The situation is terrible. The last will of Ms Wood is lost!") },
            { _("Ms Dread"),  _("Ms Wood has no child. She has designated someone to be her heir in her last will. Until we find this last will, the case is open.") },
            { _("Raymond"),   _("I see. So let's start simply: do you know where she lived?") },
            { _("Ms Dread"),  _("She lived in the beautiful house in the north of the main place.") },
            { _("Ms Dread"),  _("I will stay here until you have found something. I want to stay informed about your progress so come here regularly for reports.") },
          },
          {
            _("Raymond"),   _("Maybe she knows something more about Ms Wood. I should ask her.")
          },
          {
            _("Raymond"),   _("Can you tell me something more about Ms Wood that could help me?")
          }
        }
      },
      {
        "Chap1Dread_Success"_id, {
          DialogType::Normal, {
            { _("Ms Dread"),  _("If I remember well, Ms Wood had a cat and a dog. She considered them as her children.") },
            { _("Raymond"),   _("I see! I take note of this fact.") },
          }
        }
      },
      {
        "Chap1Dread_Failure"_id, {
          DialogType::Normal, {
            { _("Ms Dread"),  _("I am afraid I can not tell you more than what I have already told you. Sorry.") },
            { _("Raymond"),   _("No problem, I have to find other clues.") },
          }
        }
      },
      {
        "Chap1Elders1"_id, {
          DialogType::Normal, {
            { _("Nona"),      _("Who are you, young stranger?") },
            { _("Decima"),    _("Do not talk to him, Nona, he seems weird.") },
            { _("Morta"),     _("I agree with Decima.") },
            { _("Raymond"),   _("Sorry, I did not want to bother you, ladies.") },
          }
        }
      },
      {
        "Chap1Elders2"_id, {
          DialogType::Normal, {
            { _("Decima"),    _("You again?") },
            { _("Nona"),      _("What do you want at the end?") },
            { _("Morta"),     _("Definitely, we should not talk to him.") },
            { _("Raymond"),   _("Sorry, I did not want to bother you, ladies.") },
          }
        }
      },
      {
        "Chap1Bouquet1"_id, {
          DialogType::Normal, {
            { _("Ms Bouquet"),  _("Do you want to buy some flowers?") },
            { _("Raymond"),     _("No, thank you. Maybe another day!") },
          }
        }
      },
      {
        "Chap1Gustavo1"_id, {
          DialogType::Normal, {
            { _("Ms Gustavo"),  _("You seem to be a friend of animals! Want to buy some food for them?") },
            { _("Raymond"),     _("Well, my cat is already too fat. Sorry.") },
          }
        }
      },
      {
        "Chap1Dread_NotFinished"_id, {
          DialogType::Normal, {
            { _("Ms Dread"),  _("Do you have any news for me?.") },
            { _("Raymond"),   _("Not yet, I must continue my investigation.") },
          }
        }
      },
      {
        "Chap1Dread_Finished"_id, {
          DialogType::Normal, {
            { _("Ms Dread"),  _("Do you have any news for me?.") },
            { _("Raymond"),   _("Yes, I found some interesting things. It seems Ms Wood had animals in her house but they have disappearred. We should find them, they may be able to tell us what happened to this last will.") },
          }
        }
      },
      {
        "Chap1SearchWoodHouse"_id, {
          DialogType::Normal, {
            { _("Raymond"),   _("What is that?") }
          },
        }
      },
      {
        "Chap1SearchWoodHouse_Success"_id, {
          DialogType::Normal, {
            { _("Raymond"),   _("It's some animal footprints.") }
          },
        }
      },
      {
        "Chap1SearchWoodHouse_Failure"_id, {
          DialogType::Normal, {
            { _("Raymond"),   _("It's just some dirts.") }
          },
        }
      },
      {
        "RaymondEndChapter"_id, {
          DialogType::Normal, {
            { _("Raymond"),   _("I know enough. It's time for my report.") }
          },
        }
      },
      /*
       * Chapter 2
       */
      {
        "Chap2Elders"_id, {
          DialogType::Investigation, {
            { _("Raymond"),   _("Good evening, ladies. My name is Raymond Adupif and I have been hired by Mrs. Dread to find Mrs. Wood's will.") },
            { _("Nona"),      _("Nice to met you, Mr. Adupif. During my evening walk, I saw Mrs. Dread waiting near the pontoon. I understood that someone would come to visit our beautiful village.") },
            { _("Raymond"),   _("I see that nothing escapes you, ladies. Could you tell me about your village?") },
            { _("Morta"),     _("Of course Mr. Adupif. You see the pink store next to Mrs. Wood's house? It's the store of Mrs. Bouquet, the florist.") },
            { _("Decima"),    _("A little further down the square is Mr. Gustavo's store. He sells a lot of pet stuffs. We often saw there Stock and Holly, Mrs. Wood's pets.") },
            { _("Raymond"),   _("Stock and Holly?") },
            { _("Nona"),      _("Yes, Stock is Ms. Wood's dog and Holly is her cat.") },
            { _("Decima"),    _("They are so affectionate! Much more than all those stray animals.") },
          },
          {
            _("Raymond"),   _("These elderly ladies need to know everything about the neighbourhood. Maybe they know where Holly and Stock might be?")
          },
          {
            _("Raymond"),   _("I have one last question for you. Do you know where Holly and Stock might be hiding?")
          }
        }
      },

      /*
       * Chapter 3
       */
      /*
       * Chapter 4
       */
    };

    buildings = {
      { BuildingType::BouquetShop, gf::vec(31, 9) },
      { BuildingType::BouquetNeighbor1, gf::vec(35, 9) },
      { BuildingType::BouquetNeighbor2, gf::vec(39, 9) },
      { BuildingType::WoodHouse, gf::vec(22, 9) },
      { BuildingType::WoodNeighbor, gf::vec(18, 9) },
      { BuildingType::BenchUp, gf::vec(27, 16) },
      { BuildingType::BenchLeft, gf::vec(23, 19) },
      { BuildingType::BenchDown, gf::vec(27, 24) },
      { BuildingType::BenchDown, gf::vec(29, 34) },
      { BuildingType::GustavoShop, gf::vec(38, 27) },
    };

    limitClues = {
      2,
    };
  }

}
