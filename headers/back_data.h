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
#include <string>





/* ----------------- Ezzel a 'debug' modot tudjuk kapcsolni ----------------- */
#define DEBUG false
/* -------------------------------------------------------------------------- */


/* ------------------------- EMBER KONSTRUKTOR ROVID ------------------------ */
#define EMBER_ROVID vezeteknev(v), len_vez(lv), keresztnev(k), len_kereszt(lk), becenev(b), len_bece(lb)
/* -------------------------------------------------------------------------- */





/* ========================================================================== */
//!                                EMBER CLASS                               !//
/* ========================================================================== */



class Ember{
        private:
            
            const char *vezeteknev;       //* nev eltarolasa din. tombben
            size_t len_vez;         //* nev hossza
            const char *keresztnev;       //* nev eltarolasa din. tombben
            size_t len_kereszt;     //* nev hossza
            const char *becenev;          //* nev eltarolasa din. tombben
            size_t len_bece;        //* nev hossza

            
        
        public:


            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Ember(): vezeteknev("N/A"), len_vez(0), keresztnev("N/A"), len_kereszt(0), becenev("N/A"), len_bece(0){
                if (DEBUG) std::cout<<"Ember ctor"<<std::endl;
            }
            
            
            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Ember(char *v, size_t lv, char *k, size_t lk, char *b, size_t lb): EMBER_ROVID{
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
            const char* getVezetek()const{return vezeteknev;}      //* visszaadja a vezeteknevet
            size_t getLenVez()const{return len_vez;}         //* visszaadja a vezeteknev hosszat
            const char* getKereszt()const{return keresztnev;}      //* visszaadja a keresztnevet
            size_t getLenKer()const{return len_kereszt;}     //* visszaadja a keresztnev hosszat
            const char* getBece()const{return becenev;}            //* visszaadja a becenevet
            size_t getLenBece()const{return len_bece;}       //* visszaadja a becenev hosszat
};

/* ========================================================================== */
//!                               TELEFON CLASS                              !//
/* ========================================================================== */

class Telefon: public Ember{
        private:

            unsigned long int szemelyes;        //* sajat tellszam   (11 szam, alapeset: 0)
            unsigned long int business;         //* ceges tellszam   (11 szam, alapeset: 0)
        
        public:


            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Telefon(): Ember(), szemelyes(0), business(0)
            {if (DEBUG) std::cout<<"Telefon ctor"<<std::endl;}


            /* ------------------------ KONSTRUKTOR PARAMETERREL ------------------------ */
            Telefon(char *v, size_t lv, char *k, size_t lk, char *b, size_t lb,unsigned long int sz, unsigned long int bu):
            Ember(v,lv,k,lk,b,lb) ,szemelyes(sz), business(bu){
                if (DEBUG) std::cout<<"Telefon param ctor"<<std::endl;}


           /* ------------------------------- DESTRUKTOR ------------------------------- */
            ~Telefon(){if (DEBUG) std::cout<<"Telefon dtor"<<std::endl;}
 
           /* -------------------------------- GETTEREK -------------------------------- */
           unsigned long int getSzemTell()const{return szemelyes;}      //* visszaadja a szemelyes telefonszamot
           unsigned long int getCegesTell()const{return business;}      //* visszaada a ceges telefonszamot
};

