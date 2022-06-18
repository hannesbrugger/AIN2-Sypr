#ifndef FACHNOTEN_LISTE_H
#define FACHNOTEN_LISTE_H
#include "fachnote.h"

class fachnoten_liste final {
private:
  class element;
  element *head;
  void (*vFunctionCall)(fachnote *);

public:
  ~fachnoten_liste();
  // fachnoten_liste &operator=();
  fachnoten_liste &insert(fachnote *);

  // explicit fachnoten_liste(void (__cdecl *) (fachnote *));
  // explicit fachnoten_liste(vFunctionCall);
  explicit fachnoten_liste(void(fachnote *));

  fachnoten_liste(const fachnoten_liste &) = delete;
  fachnoten_liste &operator=(const fachnoten_liste &) = delete;
  fachnoten_liste(fachnoten_liste &&) = delete;
  fachnoten_liste &operator=(fachnoten_liste &&) = delete;

  class iterator final {
  private:
    element *current;
    explicit iterator(element *);

  public:
    bool operator!=(const iterator &) const;
    fachnote *&operator*() const;
    iterator &operator++();
    friend class fachnoten_liste;
  };
  iterator begin();
  iterator end();
};

#endif // FACHNOTEN_LISTE_H
