#include "GameData.h"

#include "I18N.h"

using namespace gf::literals;

namespace tlw {

    GameData::GameData() {
        chapters = {
          {
            _("Chapter 1."),
            _("I have been called by Ms Dread to handle a very particular situation. Ms Dread is the lawyer of Ms Wood. Ms Wood has just died and nobody can find her last will. My mission is to find it.\nI don't know exactly where to start but I should see Ms Dread first. She may have valuable information for me.")
          },
          {
            _("Chapter 2."),
            _("This investigation is not as simple as I thought. I should talk to the villagers to know more about Ms Wood. I feel there is much left to be discovered.")
          },
          {
            _("Chapter 3."),
            _("ahahha")
          },
        };

        dialogs = {
            /*
             * Chapter 1
             */
            {
              "Chap1Dread1"_id, {
                DialogType::Investigation, {
                  { _("Raymond"),   _("Good evening Ms Dread. I am Raymond Adupif, at your service. Can you tell me more about the situation?") },
                  { _("Ms Dread"),  _("Good evening Mr Adupif. I'm glad you're here. The situation is terrible. The last will of Ms Wood is lost!") },
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
                  { _("Mr Gustavo"),  _("You seem to be a friend of animals! Want to buy some food for them?") },
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
                  { _("Raymond"),   _("Yes, I found some interesting things. It seems Ms Wood had animals in her house but they have disappearred.") },
                  { _("Raymond"),   _("We should find them, they may be able to tell us what happened to this last will.") },
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
                  { _("Raymond"),   _("Good evening, ladies. My name is Raymond Adupif and I have been hired by Ms Dread to find Ms Wood's will.") },
                  { _("Nona"),      _("Nice to meet you, Mr Adupif. During my evening walk, I saw Ms Dread waiting near the dock. I understood that someone would come to visit our beautiful village.") },
                  { _("Raymond"),   _("I see that nothing escapes you, ladies. Could you tell me about your village?") },
                  { _("Morta"),     _("Of course Mr Adupif. You see the pink store next to Ms Wood's house? It's the store of Ms Bouquet, the florist.") },
                  { _("Decima"),    _("A little further down the square is Mr Gustavo's store. He sells a lot of pet stuffs. We often saw there Stock and Holly, Ms Wood's pets.") },
                  { _("Raymond"),   _("Stock and Holly?") },
                  { _("Nona"),      _("Yes, Stock is Ms Wood's dog and Holly is her cat.") },
                  { _("Decima"),    _("They are so affectionate! Much more than all those stray animals.") },
                },
                {
                  _("Raymond"),   _("These elderly ladies need to know everything about the neighborhood. Maybe they know where Holly and Stock might be?")
                },
                {
                  _("Raymond"),   _("I have one last question for you. Did you notice anything strange on the night of Ms Wood's death?")
                }
              }
            },
            {
              "Chap2Elders_Success"_id, {
                DialogType::Normal, {
                  { _("Nona"), _("That night? No, nothing in particular.") },
                  { _("Morta"), _("Nothing to report on my side too. ") },
                  { _("Decima"), _("I remember hearing the stray dog of the neighborhood fighting and knocking over the garbage cans near Ms Wood's house.") },
                }
              }
            },
            {
              "Chap2Elders_Failure"_id, {
                DialogType::Normal, {
                  { _("Nona"), _("We have told you everything we have to say. Leave us alone now.") },
                }
              }
            },
            {
              "Chap2SearchGarbageCan"_id, {
                DialogType::Normal, {
                  { _("Raymond"), _("The garbage cans have been overturned and there are signs of a struggle. I'm going to look around, maybe I'll find a clue.") },
                }
              }
            },
            {
              "Chap2SearchGarbageCan_Success"_id, {
                DialogType::Normal, {
                  { _("Raymond"), _("Wrappings, food scraps, newspapers... And a dog collar! Maybe it's the one from Stock?") },
                }
              }
            },
            {
              "Chap2SearchGarbageCan_Failure"_id, {
                DialogType::Normal, {
                  { _("Raymond"), _("Wrappings, food scraps, newspapers... Nothing useful.") },
                }
              }
            },
            {
              "Chap2BouquetInvestigation"_id, {
                DialogType::Investigation, {
                  { _("Raymond"),   _("Hello Ms Bouquet? I am Raymond Adupif and I was hired by Ms Dread to find Ms Wood's will.") },
                  { _("Bouquet"),   _("Hello Mr Adupif! How can I help you?") },
                  { _("Raymond"),   _("I'm looking for M. Wood's animals, do you have any informations about them?") },
                  { _("Bouquet"),   _("Unfortunately no. It is not often that I come across pets in my store, you know.") },
                },
                {
                  _("Raymond"),   _("Her store is in the center of the village. Maybe she can tell me more about the neighborhood?")
                },
                {
                  _("Raymond"),   _("I see. However, do you have any idea where Ms. Wood's animals might be hiding?")
                }
              }
            },
            {
              "Chap2BouquetInvestigation_Success"_id, {
                DialogType::Normal, {
                  { _("Raymond"), _("I know that there are some cats in the alley behind my shop.") },
                }
              }
            },
            {
              "Chap2BouquetInvestigation_Failure"_id, {
                DialogType::Normal, {
                  { _("Raymond"), _("No, sorry not to be able to help you more.") },
                }
              }
            },
            {
              "Chap2Bouquet"_id, {
                DialogType::Normal, {
                  { _("Raymond"), _("Did you find the pets?") },
                }
              }
            },
            {
              "RaymondEndChapter2"_id, {
                DialogType::Normal, {
                  { _("Raymond"), _("I should do my report to Ms. Dread.") },
                }
              }
            },
            {
              "Chap2Dread_Finished"_id, {
                DialogType::Normal, {
                  { _("Ms Dread"),  _("Do you have any news for me?.") },
                  { _("Raymond"),   _("Yes, I found some interesting things. It seems Ms Wood had animals in her house but they have disappearred.") },
                  { _("Raymond"),   _("We should find them, they may be able to tell us what happened to this last will.") },
                }
              }
            },

            /*
            * Chapter 3
            */
            {
              "Chap3MafiaCatInvestigation"_id, {
                DialogType::Investigation, {
                  { _("Riff"),   _("Who are you and what are you doing here?") },
                  { _("Raymond"),   _("Sorry to bother you, but I am a detective some inhabitants told me about your pack and I have some question for you about Ms Wood") },
                  { _("Riff"),   _("We aren't going to answer any of your question, detective.") },
                  { _("Raymond"),   _("I'm looking for Ms Wood's animals, it seems that they are gone.") },
                  { _("Riff"),   _("Try looking for her stupid dog and his gang") },
                  { _("Raymond"),   _("A gang?") },
                  { _("Riff"),   _("Yeah, they are constently making mess near the restaurant") },
                  { _("Raymond"),   _("Do you have any more informations that could help me?") }
                },
                {
                  _("Raymond"),   _("I'm sure they have more things to tell me about the situation!")
                }
              }
            },
            {
              "Chap3MafiaCatInvestigation_Success"_id, {
                DialogType::Normal, {
                  { _("Riff"), _("Yeah, try to look after the florist, she seem a bit obsessed by Ms. Wood's house. She is always looking at her house.") },
                  { _("Raymond"), _("Thanks for the help.") },
                  { _("Riff"), _("I hope you will remember this, detective.") }
                },
                {
                  _("Raymond"), _("I will follow their advice and look after the florist.")
                }
              }
            },
            {
              "Chap3MafiaCatInvestigation_Failure"_id, {
                DialogType::Normal, {
                  { _("Riff"), _("No, we already told you about what we know, get away from us now.") }
                }
              }
            },
            {
              "Chap3MafiaDogInvestigation"_id, {
                DialogType::Investigation, {
                  { _("Bernardo"), _("Hello Mr. Adupif!") },
                  { _("Raymond"), _("Hmh? Hello, how do you know my name?") },
                  { _("Bernardo"), _("We know a lot of things about what happens here.") },
                  { _("Raymond"), _("Then you should be able to help me, I'm looking for Ms Wood's animals do you know where they could be?") },
                  { _("Bernardo"), _("We know a lot of things about what happens here.") },
                  { _("Bernardo"), _("The cat gang is acting weirds currently, they are very suspect.") },
                  { _("Raymond"), _("Thanks, I will look after them, do you have more to tell me about?") }
                }
              },
            },
            {
              "Chap3MafiaDogInvestigation_Success"_id, {
                DialogType::Normal, {
                  { _("Bernardo"), _("The cat gang and Mr. Gustavo seems to be really close from each other, look after him and you will find who did that to Ms. Wood.") },
                  { _("Raymond"), _("Thanks for the help.") },
                },
                {
                  _("Raymond"), _("I will follow their advice and look after Mr. Gustavo.")
                }
              }
            },
            {
              "Chap3MafiaDogInvestigation_Failure"_id, {
                DialogType::Normal, {
                  { _("Bernardo"), _("We have nothing more to tell you.") }
                }
              }
            },
            {
              "Chap3MafiaDog2"_id, {
                DialogType::Normal, {
                  { _("DogPack"), _("We have nothing more to tell you.") }
                }
              }
            },
            {
              "Chap3Elders"_id, {
                DialogType::Normal, {
                  { _("Nona"), _("How is the case going Mr. Adupif?") },
                  { _("Morta"), _("We want to know gossip!") },
                  { _("Decima"), _("Please tell us what you heard!")},
                  { _("Raymond"), _("Sorry but I'm not allowed to tell you more about this.")},
                  { _("Decima"), _("Oh, it is a shame.")}
                }
              }
            },
            {
              "RaymondEndChapter"_id, {
                DialogType::Normal, {
                  { _("Raymond"),   _("I know enough. It's time for my report to Ms. Dread.") }
                },
              }
            },

        };

      /*
       * Chapter 4
       */

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
      { BuildingType::Fountain, gf::vec(27, 19) },
      { BuildingType::House1, gf::vec(43, 13) },
      { BuildingType::House2, gf::vec(43, 22) },
      { BuildingType::Pub, gf::vec(19, 28) },
      { BuildingType::GarbageCan, gf::vec(15, 13) },
    };

    limitClues = {
      2,
      3,
      3,
    };
  };

}
