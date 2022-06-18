#ifndef FACHNOTE_H
#define FACHNOTE_H
#include "benotung.h"
#include <string>
using namespace ::std;

class fachnote {
private:
public:
  const string fach;
  const benotung note;

  explicit fachnote(
      const string &,
      const benotung &); // explicit, da keine Typanpassung stattfinden soll.

  // explicit fachnote(const fachnote &);
  fachnote &operator=(const fachnote &) = delete;
  fachnote(fachnote &&) = delete;
  fachnote &operator=(fachnote &&) = delete;
};
#endif // FACHNOTE_H
