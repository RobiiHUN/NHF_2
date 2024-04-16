#include <iostream>
#include "back_data.h"


/* ----------------- Ezzel a 'debug' modot tudjuk kapcsolni ----------------- */
#define DEBUG = FALSE;
/* -------------------------------------------------------------------------- */




/* -------------------------------------------------------------------------- */
/*                               BEJEGYZES CLASS                              */
/* -------------------------------------------------------------------------- */

class Bejegyzes: public Telefon{
        private:
            unsigned int varos;         // iranyito szama
            unsigned int havi_dij;      // havi dijja az elofizetesnek


};