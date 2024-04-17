    /* -------------------------------------------------------------------------- */ // control + shift + Y
    
    /* --------------------------- option + shift + - --------------------------- */
    
    
    /* -------------------------------------------------------------------------- */
    /*                               opt+ shift + 0                               */
    /* -------------------------------------------------------------------------- */

//TODO ez ilyen
//? ilyen is van
/// @brief vezeteknev test




#include <iostream>
#include "back_data.cpp"


/* ----------------- Ezzel a 'debug' modot tudjuk kapcsolni ----------------- */
#define DEBUG false
/* -------------------------------------------------------------------------- */

/* ---------------------------- ALAP TELEFONSZAM ---------------------------- */
#define TELL_ALAP 06200000000
/* -------------------------------------------------------------------------- */





/* ========================================================================== */
//!                                EMBER CLASS                               !//
/* ========================================================================== */



class Ember{
        private:
            
            char *vezeteknev;       //* nev eltarolasa din. tombben
            size_t len_vez;         //* nev hossza
            char *keresztnev;       //* nev eltarolasa din. tombben
            size_t len_kereszt;     //* nev hossza
            char *becenev;          //* nev eltarolasa din. tombben
            size_t len_bece;        //* nev hossza
        
        public:


            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Ember(): vezeteknev(NULL), len_vez(0), keresztnev(NULL), len_kereszt(0), becenev(NULL), len_bece(0){
                if (DEBUG) std::cout<<"Ember ctor"<<std::endl;
            }
            
            
            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Ember(char *v, size_t lv, char *k, size_t lk, char *b, size_t lb): vezeteknev(v), len_vez(lv), keresztnev(k), len_kereszt(lk), becenev(b), len_bece(lb){
                if (DEBUG) std::cout<<"Ember param ctor"<<std::endl;
                }

            /* -------------------------------- DESTRUKTOR ------------------------------ */
            ~Ember(){ //TODO ezzel mi van?
                ////delete[] vezeteknev;
                ////delete[] keresztnev;
                ////delete[] becenev;
                if (DEBUG) std::cout<<"Ember dtor"<<std::endl;

            }

            /* -------------------------------- GETTEREK -------------------------------- */
            char* getVezetek()const{return vezeteknev;}      //* visszaadja a vezeteknevet
            size_t getLenVez()const{return len_vez;}         //* visszaadja a vezeteknev hosszat
            char* getKereszt()const{return keresztnev;}      //* visszaadja a keresztnevet
            size_t getLenKer()const{return len_kereszt;}     //* visszaadja a keresztnev hosszat
            char* getBece()const{return becenev;}            //* visszaadja a becenevet
            size_t getLenBece()const{return len_bece;}       //* visszaadja a becenev hosszat
};

/* ========================================================================== */
//!                               TELEFON CLASS                              !//
/* ========================================================================== */

class Telefon: public Ember{
        private:

            unsigned long int szemelyes;        //* sajat tellszam   (11 szam, alapeset: TELL_ALAP)
            unsigned long int business;         //* ceges tellszam   (11 szam, alapeset: TELL_ALAP)
        
        public:


            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Telefon(): szemelyes(TELL_ALAP), business(TELL_ALAP)
            {if (DEBUG) std::cout<<"Telefon ctor"<<std::endl;}


            /* ------------------------ KONSTRUKTOR PARAMETERREL ------------------------ */
            Telefon(unsigned long int sz, unsigned long int b): szemelyes(sz), business(b)
            {if (DEBUG) std::cout<<"Telefon param ctor"<<std::endl;}


           /* ------------------------------- DESTRUKTOR ------------------------------- */
            ~Telefon(){if (DEBUG) std::cout<<"Telefon dtor"<<std::endl;}
 
           /* -------------------------------- GETTEREK -------------------------------- */
           unsigned long int getSzemTell()const{return szemelyes;}      //* visszaadja a szemelyes telefonszamot
           unsigned long int getCegesTell()const{return business;}      //* visszaada a ceges telefonszamot
};

