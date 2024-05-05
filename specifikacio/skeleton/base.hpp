#ifndef BASE_HPP
#define BASE_HPP

#include "back_data.hpp"
#include <iomanip>  //a tablazathoz kell



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