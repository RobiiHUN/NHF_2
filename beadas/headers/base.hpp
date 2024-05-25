#ifndef BASE_HPP
#define BASE_HPP

#include "back_data.hpp"
#include <iomanip>  
#include "memtrace.h"






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
            std::string getVezetek()const;                      //* visszaadja a vezeteknevet
            std::string getKereszt()const;                      //* visszaadja a keresztnevet
            std::string getBece()const;                         //* visszaadja a becenevet
            size_t getLenVez()const;                            //* visszaadja a vezeteknev hosszat
            size_t getLenKer()const;                            //* visszaadja a keresztnev hosszat
            size_t getLenBece()const;                           //* visszaadja a becenev hosszat
            size_t getLenSzem()const;                           //* visszaadja a szemelyes telefonszam hosszat
            size_t getLenCeg()const;                            //* visszaadja a ceges telefonszam hosszat
            size_t getLenVar()const;                            //* visszaadja a varos iranyito szam hosszat


            
            /* -------------------------------- SETTEREK -------------------------------- */
            void setVaros(unsigned int v);                      //* beallitja a varos iranyito szamat
            void setHavi(unsigned int h);                       //* beallitja a havi dijjat
            void setSzemTell(unsigned long int sz);             //* beallitja a szemelyes telefonszamot
            void setCegeTell(unsigned long int ce);             //* beallitja a ceges telefonszamot
            void setVezetek(std::string v);          //* beallitja a vezeteknevet
            void setKereszt(std::string k);          //* beallitja a keresztnevet
            void setBece(std::string b);             //* beallitja a becenevet

            /* -------------------------------- KIIRATAS -------------------------------- */
            void bejegyzesKi(int sorszam)const;                            //* kiirja a bejegyzest

};





/* ========================================================================== */
//!                               TELEFONKONYV                               !//
/* ========================================================================== */









class Telefonkonyv{
    private:
        Bejegyzes* bejegyzesek;      //bejegyzesek tombje
        size_t meret;               //tomb merete

        
        
    public:
        /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
        Telefonkonyv();
        /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
        Telefonkonyv(size_t m);
        Telefonkonyv(Bejegyzes* b, size_t m);
        
        /* ------------------------------- DESTRUKTOR ------------------------------- */
        ~Telefonkonyv();

        /* ---------------------------- MERET VISSZADASA ---------------------------- */
        size_t getMeret()const;
        Bejegyzes& getBejegyzes(int i)const; 

        /* ------------------------------- MASOLO CTOR ------------------------------ */
        Telefonkonyv(const Telefonkonyv& other);

        /* --------------------------- EGYENLOSEG OPERATOR -------------------------- */
        Telefonkonyv& operator=(const Telefonkonyv& other);

        /* --------------------------- BEJEGYZES HOZZADASA -------------------------- */

        void addBejegyzes(const Bejegyzes& bejegyzes);

        /* ------------------------------- KIIRATAS -------------------------------- */

        void kiir() const; //exception ha üres a tomb

        /* ------------------------- FAJLBOL VALO FELTOLTES ------------------------- */
        void feltoltesTelefonkonyv(const std::string& fajlnev);

        /* --------------------------------- MENTES --------------------------------- */
        void mentesTelefonkonyv(const std::string& fajlnev)const;

        /* ------------------------------- TORLES -------------------------------- */
        void bejTorles(size_t i); 
        /* ------------------------------- MODOSITAS ------------------------------- */
        void modosit(size_t sorszam, const Bejegyzes be);
        
        /* ------------------------------ FACTORY RESET ----------------------------- */
        void factoryReset(const std::string& forras, const std::string& cel);

        /* -------------------------------- RENDEZES -------------------------------- */
        
        int osszeBej(const Bejegyzes& a, const Bejegyzes& b)const; 
        void rendez();

        /* -------------------------------- KERESO -------------------------------- */
        Bejegyzes* Telefonykonyvkeres(std::string kersett)const;
        Bejegyzes* lin_keres(std::string kersett, int mod)const; //mod 1 - keresztnev, 2 - becenev, 3 - szem. tell.szam, 4 - ceg.tell.szam, 5 - varos, 6 - havi dij
            

        


      
            

};







#endif