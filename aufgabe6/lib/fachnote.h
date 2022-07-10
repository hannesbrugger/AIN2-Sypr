// fachnote.h
#ifndef FACHNOTE_H
#define FACHNOTE_H

#include <string>
#include "benotung.h"

class fachnote
{
private:

public:
    const std::string fach;
    const benotung note;

    fachnote(const std::string&, const benotung&);
    
    fachnote &operator=(const fachnote&) = delete;
    fachnote(fachnote&&) = delete;
    fachnote &operator=(fachnote&&) = delete;
};

#endif
