#ifndef BENOTUNG_H
#define BENOTUNG_H

class benotung
{
public:
    explicit benotung(int note);
    static const benotung beste;
    static const benotung schlechteste;
    int int_value() const;
    bool ist_bestanden();
    friend bool operator==(const benotung&, const benotung&);
    // Frage: welche Memberfunktionen erzeugt der Compiler zusätzlich implizit
    // in benotung? Implementiert er die in diesem Fall korrekt?
    // Antwort:
private:
    int note;
};

#endif
