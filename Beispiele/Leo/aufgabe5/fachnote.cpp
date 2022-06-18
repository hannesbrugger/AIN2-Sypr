#include "fachnote.h"
#include <stdexcept>
#include <string>

fachnote::fachnote(const std::string &f, const benotung &n) : fach(f), note(n)
{
  if(f.length() == 0) {
    throw std::invalid_argument("unzulaessiges Fach!");
  }
}
