#ifndef BENOTUNG_H
#define BENOTUNG_H
//#include <stdexcept>

class benotung {
private:
  int note;

public:
  // benotung() = delete;
  explicit benotung(int);
  int int_value() const;

  const static benotung beste;
  const static benotung schlechteste;

  bool ist_bestanden() const;
  friend bool operator==(const benotung &, const benotung &);
  // implizit wird der Destruktor vom Compiler erzeugt,
  // der für alle Instanzvariablen
  // mit Klassen-Typ deren Destruktor aufruft.
  // Der Destruktor wird nicht richtig implementiert, da wir
  // nicht den Standard-Konstruktor verwenden???
};
#endif // BENOTUNG_H
