#include "fachnote.h"
#include <stdexcept>
#include <string>
using namespace ::std;

fachnote::fachnote(const string &f, const benotung &n) : fach(f), note(n)
{
    if(f.length() == 0)
    {
        throw invalid_argument("unzulaessiges Fach!");
    }
}
