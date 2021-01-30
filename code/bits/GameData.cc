#include "GameData.h"

#include "I18N.h"

using namespace gf::literals;

namespace tlw {

  GameData::GameData() {
    chapters = {
      {
        _("Monday."),
        _("I have been called by Ms Dread to handle a very particular situation. Ms Dread is the lawyer of Ms Wood. Ms Wood has just died and nobody can find her last will. My mission is to find it.\nI don't know exactly where to start but I should see Ms Dread first. She may have valuable information for me.")
      }
    };

    dialogs = {
      /*
       * Chapter 1
       */
      {
        "Chap1Dread1"_id, {
          DialogType::Normal, {
            { _("Raymond"),   _("Good evening Ms Dread. I am Raymond Adupif, at your service. Can you tell me more about the situation?") },
            { _("Ms Dread"),  _("Good evening M. Adupif. I'm glad you're here. The situation is terrible. The last will of Ms Wood is lost!") },
            { _("Ms Dread"),  _("Ms Wood has no child. She has designated someone to be her heir in her last will. Until we find this last will, the case is open.") },
            { _("Raymond"),   _("I see. So let's start simply: do you know where she lived?") },
            { _("Ms Dread"),  _("She lived in the beautiful house in the north of the main place.") },
            { _("Ms Dread"),  _("I will stay here until you have found something. I want to stay informed about your progress so come here regularly for reports.") },
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
      /*
       * Chapter 2
       */
      /*
       * Chapter 3
       */
      /*
       * Chapter 4
       */
    };
  }

}
