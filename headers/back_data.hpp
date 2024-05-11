#ifndef BACK_DATA_HPP
#define BACK_DATA_HPP
   
   
    /* -------------------------------------------------------------------------- */ // control + shift + Y
    
    /* --------------------------- option + shift + - --------------------------- */
    
    
    /* -------------------------------------------------------------------------- */
    /*                               opt+ shift + 0                               */
    /* -------------------------------------------------------------------------- */

//TODO ez ilyen
//? ilyen is van
/// @brief vezeteknev test




#include <iostream>
#include <string>
#include <cstdlib>  //kijelzo torleshez






#include "macro.h"











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
            Ember();

            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Ember(char *v, size_t lv, char *k, size_t lk, char *b, size_t lb);
            Ember(const std::string& v, size_t lv, const std::string& k, size_t lk, const std::string& b, size_t lb); // a fajlbol valo bolvasashoz

            /* -------------------------------- DESTRUKTOR ------------------------------ */
            ~Ember();


            /* -------------------------------- GETTEREK -------------------------------- */
            const char* getVezetek()const;      //* visszaadja a vezeteknevet
            size_t getLenVez()const;            //* visszaadja a vezeteknev hosszat
            const char* getKereszt()const;      //* visszaadja a keresztnevet
            size_t getLenKer()const;            //* visszaadja a keresztnev hosszat
            const char* getBece()const;         //* visszaadja a becenevet
            size_t getLenBece()const;           //* visszaadja a becenev hosszat

        /* -------------------------------- SETTEREK -------------------------------- */
        void setVezetek(const char* v, size_t lv){vezeteknev = v; len_vez = lv;}
        void setKereszt(const char* k, size_t lk){keresztnev = k; len_kereszt = lk;}
        void setBece(const char* b, size_t lb){becenev = b; len_bece = lb;}
};

/* ========================================================================== */
//!                                 TELEFON CLASS                              !//
/* ========================================================================== */

class Telefon{
        private:

            unsigned long int szemelyes;        //* sajat tellszam   (11 szam, alapeset: 0)
            unsigned long int business;         //* ceges tellszam   (11 szam, alapeset: 0)
        
        public:


            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Telefon();


            /* ------------------------ KONSTRUKTOR PARAMETERREL ------------------------ */
            Telefon(unsigned long int, unsigned long int);


           /* ------------------------------- DESTRUKTOR ------------------------------- */
            ~Telefon();
 
           /* -------------------------------- GETTEREK -------------------------------- */
           unsigned long int getSzemTell()const;      //* visszaadja a szemelyes telefonszamot
           unsigned long int getCegesTell()const;      //* visszaada a ceges telefonszamot
           size_t getLenSzem()const; //* visszaadja a szemelyes telefonszam hosszat
           size_t getLenCeg()const;   //* visszaadja a ceges telefonszam hosszat

           /* -------------------------------- SETTEREK -------------------------------- */
           void setSzemTell(unsigned long int sz){szemelyes = sz;}
           void setCegesTell(unsigned long int ce){business = ce;}
};




void clearScreen();

#endif