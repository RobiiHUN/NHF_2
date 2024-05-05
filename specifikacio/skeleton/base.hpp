#ifndef BASE_HPP
#define BASE_HPP

//#include "back_data.hpp"
#include <iomanip>  //a tablazathoz kell
#include <string>
#include <cstdlib>  //kijelzo torleshez
#include <iostream>


/* ========================================================================== */
/*           A BEJEGYZES ES A TELEFONT CSAK A JPORTA MIATT RAKOM IDE          */
/* ========================================================================== */




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
};


void clearScreen();






/* -------------------------------------------------------------------------- */
//!                               BEJEGYZES CLASS                              !//
/* -------------------------------------------------------------------------- */

class Bejegyzes{
        private:
            Ember ember;                // ember adatai
            Telefon telefon;            // telefonszam
            unsigned int varos;         // iranyito szama                   (alapeset: 0 )
            unsigned int havi_dij;      // havi dijja az elofizetesnek      (alapesset: 0)
        
        public:

            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Bejegyzes();

            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Bejegyzes(const Ember& e, const Telefon& t,  unsigned int v, unsigned int h);

            /* ------------------------------- DESTRUKTOR ------------------------------- */
            ~Bejegyzes();

            /* -------------------------------- GETTEREK -------------------------------- */
            unsigned int getVaros()const;                       //* visszaadja a varos iranyito szamat
            unsigned int getHavi() const;                       //* visszaadja a havi dijjat
            unsigned long int getSzemTell()const;               //* visszaadja a szemelyes telefonszamot
            unsigned long int getCegeTell()const;               //* visszaadja a ceges telefonszamot
            const char* getVezetek()const;                      //* visszaadja a vezeteknevet
            const char* getKereszt()const;                      //* visszaadja a keresztnevet
            const char* getBece()const;                         //* visszaadja a becenevet
            size_t getLenVez()const;                            //* visszaadja a vezeteknev hosszat
            size_t getLenKer()const;                            //* visszaadja a keresztnev hosszat
            size_t getLenBece()const;                           //* visszaadja a becenev hosszat
            size_t getLenSzem()const;                           //* visszaadja a szemelyes telefonszam hosszat
            size_t getLenCeg()const;                            //* visszaadja a ceges telefonszam hosszat
            size_t getLenVar()const;                            //* visszaadja a varos iranyito szam hosszat

};

/* ========================================================================== */
//!                            TELEFONKÖNYV KIÍRÁSA                           !//
/* ========================================================================== */

void header();
void bejegyzesKi(Bejegyzes& be);

/* ========================================================================== */
//!                               TELEFONKONYV                               !//
/* ========================================================================== */


//TODO: tokeletesiteni
class Telefonkonyv{
    private:
        Bejegyzes* bejegyzesek;      //bejegyzesek tombje
        size_t meret;               //tomb merete
    public:
        /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
        Telefonkonyv();
        /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
        Telefonkonyv(size_t size);
        Telefonkonyv(Bejegyzes* b, size_t m);
        
        /* ------------------------------- DESTRUKTOR ------------------------------- */
        ~Telefonkonyv();

        /* ---------------------------- MERET VISSZADASA ---------------------------- */
        size_t getMeret()const;

        /* ------------------------------- MASOLO CTOR ------------------------------ */
        Telefonkonyv(const Telefonkonyv& other);

        /* --------------------------- EGYENLOSEG OPERATOR -------------------------- */
        Telefonkonyv& operator=(const Telefonkonyv& other);

        /* --------------------------- BEJEGYZES HOZZADASA -------------------------- */

        void addBejegyzes(const Bejegyzes& bejegyzes);

        /* ------------------------------- KIIRATAS -------------------------------- */

        void kiir() const;

        void feltoltesTelefonkonyv(const std::string& filename);
           //TODO megcsinalni a feltoltest
        
        Bejegyzes& Telefonykonyvkeres(const Bejegyzes& be);
            //TODO megcsinalni a keresest

};






#endif