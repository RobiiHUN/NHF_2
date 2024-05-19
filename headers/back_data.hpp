#ifndef BACK_DATA_HPP
#define BACK_DATA_HPP
   




#include <iostream>
#include <string>
#include <cstdlib>  //kijelzo torleshez






#include "macro.h"











/* ========================================================================== */
//!                                EMBER CLASS                               !//
/* ========================================================================== */



class Ember{
        private:
            
            std::string vezeteknev;       //* nev eltarolasa din. tombben  //TODO: char* -> std::string
            std::string keresztnev;       //* nev eltarolasa din. tombben
            std::string becenev;          //* nev eltarolasa din. tombben

            
        
        public:
            

            


            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Ember();

            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Ember(std::string *v, std::string *k, std::string *b);
            Ember(std::string v, std::string k, std::string b);


            /* -------------------------------- DESTRUKTOR ------------------------------ */
            ~Ember();


            /* -------------------------------- GETTEREK -------------------------------- */
            std::string getVezetek()const;      //* visszaadja a vezeteknevet
            size_t getLenVez()const;            //* visszaadja a vezeteknev hosszat
            std::string getKereszt()const;      //* visszaadja a keresztnevet
            size_t getLenKer()const;            //* visszaadja a keresztnev hosszat
            std::string getBece()const;         //* visszaadja a becenevet
            size_t getLenBece()const;           //* visszaadja a becenev hosszat

        /* -------------------------------- SETTEREK -------------------------------- */
        void setVezetek(std::string v);
        void setKereszt(std::string k);
        void setBece(std::string b);

        /* ------------------------------- MASOLO CTOR ------------------------------ */
        Ember(const Ember& other);

        /* --------------------------- EGYENLOSEG OPERATOR -------------------------- */
        Ember& operator=(const Ember& other);
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





#endif