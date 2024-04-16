    /* -------------------------------------------------------------------------- */ // control + shift + Y
    
    /* --------------------------- option + shift + - --------------------------- */
    
    
    /* -------------------------------------------------------------------------- */
    /*                               opt+ shift + 0                               */
    /* -------------------------------------------------------------------------- */









/* ----------------- Ezzel a 'debug' modot tudjuk kapcsolni ----------------- */
#define DEBUG true
/* -------------------------------------------------------------------------- */

/* ---------------------------- ALAP TELEFONSZAM ---------------------------- */
#define TELL_ALAP 06200000000
/* -------------------------------------------------------------------------- */





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


            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Ember(): vezeteknev(NULL), len_vez(0), keresztnev(NULL), len_kereszt(0), becenev(NULL), len_bece(0){
                if (DEBUG) std::cout<<"Ember ctor"<<std::endl;
            }
            
            
            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Ember(char *v, size_t lv, char *k, size_t lk, char *b, size_t lb): vezeteknev(v), len_vez(lv), keresztnev(k), len_kereszt(lk), becenev(b), len_bece(lb){
                if (DEBUG) std::cout<<"Ember param ctor"<<std::endl;
                }
};

/* -------------------------------------------------------------------------- */
/*                                TELEFON CLASS                               */
/* -------------------------------------------------------------------------- */

class Telefon: public Ember{
        private:

            unsigned long int szemelyes;        // sajat tellszam   (11 szam)
            unsigned long int business;         // ceges tellszam   (11 szam)
        
        public:


            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Telefon(): szemelyes(TELL_ALAP), business(TELL_ALAP)
            {if (DEBUG) std::cout<<"Telefon ctor"<<std::endl;}

            /* ------------------------ KONSTRUKTOR PARAMETERREL ------------------------ */
            Telefon(unsigned long int sz, unsigned long int b): szemelyes(sz), business(b)
            {if (DEBUG) std::cout<<"Telefon param ctor"<<std::endl;}
            

};

