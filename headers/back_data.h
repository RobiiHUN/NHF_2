    /* -------------------------------------------------------------------------- */ // control + shift + Y
    
    /* --------------------------- option + shift + - --------------------------- */
    
    
    /* -------------------------------------------------------------------------- */
    /*                               opt+ shift + 0                               */
    /* -------------------------------------------------------------------------- */

#include "base.h";



/* -------------------------------------------------------------------------- */
/*                                 EMBER CLASS                                */
/* -------------------------------------------------------------------------- */

class Ember{
        private:
            char *vezeteknev;       //nev eltarolasa din. tombben
            size_t len_vez;         // nev hossza
            char *keresztnev;       //nev eltarolasa din. tombben
            size_t len_kereszt;     // nev hossza
            char *becenev;          //nev eltarolasa din. tombben
            size_t len_bece;        // nev hossza
        
        public:
            Ember(): vezeteknev(NULL), len_vez(0), keresztnev(NULL), len_kereszt(0), becenev(NULL), len_bece(0){if(DEBUG)std::cout<<"Ember ctor"<<std::endl;};

};

/* -------------------------------------------------------------------------- */
/*                                TELEFON CLASS                               */
/* -------------------------------------------------------------------------- */

class Telefon: public Ember{
        private:
            unsigned long int szemelyes;        // sajat tellszam
            unsigned long int business;         // ceges tellszam
        
        public:

};

