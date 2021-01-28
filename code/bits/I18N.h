#ifndef I18N_H
#define I18N_H

#include <boost/locale.hpp>

inline
std::string _(const std::string& text) {
  return boost::locale::gettext(text.c_str());
}

#define N_(text) text

#endif // I18N_H
