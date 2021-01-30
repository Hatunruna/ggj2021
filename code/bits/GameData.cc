#include "GameData.h"

#include "I18N.h"

using namespace gf::literals;

namespace tlw {

  GameData::GameData() {
    chapters = {
      {
        _("Monday."),
        _("I have been called by Mr X to handle a very particular situation. Mr X is the mayor of the little town of Y. One of his inhabitants, Ms Z has just died. And nobody can find her last will. My mission is to find it.\nI don't know exactly where to start but I should see Mr X first, I think. He may have valuable information for me.")
      }
    };

    dialogs = {
      { "Chap1DreadFirstMeeting"_id, {
        DialogType::Normal, {
            { _("Raymond"), _("Good evening Ms Dread. I am Raymond Adupif, at your service. Can you tell me more about the situation?") },
            { _("Ms Dread"), _("Hello!") }

          }
        }
      }

    };
  }

}
