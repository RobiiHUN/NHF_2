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



class Telefonkonyv{
    private:
        Bejegyzes* bejegyzesek;      //bejegyzesek tombje
        size_t meret;               //tomb merete
    public:
        /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
        Telefonkonyv() : bejegyzesek(), meret(0) {
            if (DEBUG) std::cout << "Telefonkonyv ctor" << std::endl;
        }
        /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
        Telefonkonyv(size_t size) : bejegyzesek(new Bejegyzes[size]), meret(size) {
            if (DEBUG) std::cout << "Telefonkonyv param ctor" << std::endl;
        }
        Telefonkonyv(Bejegyzes* b, size_t m) : bejegyzesek(b), meret(m) {
            if (DEBUG) std::cout << "Telefonkonyv param ctor" << std::endl;
        }
        
        /* ------------------------------- DESTRUKTOR ------------------------------- */
        ~Telefonkonyv() {
            if (DEBUG) std::cout << "Telefonkonyv dtor" << std::endl;
            delete[] bejegyzesek;
        }
        Telefonkonyv(const Telefonkonyv& other) : bejegyzesek(new Bejegyzes[other.meret]), meret(other.meret) {
            for (size_t i = 0; i < meret; ++i) {
                bejegyzesek[i] = other.bejegyzesek[i];
            }
        }
        Telefonkonyv& operator=(const Telefonkonyv& other) { //egyenloseg operator tulterheles
            if (this == &other) {
                return *this;
            }
            delete[] bejegyzesek;
            bejegyzesek = new Bejegyzes[other.meret];
            meret = other.meret;
            for (size_t i = 0; i < meret; ++i) {
                bejegyzesek[i] = other.bejegyzesek[i];
            }
            return *this;
        }


        void addBejegyzes(const Bejegyzes& bejegyzes) { //bejegyzes hozzaadasa a telefonkonyvhez
            if (meret == 0) {
                bejegyzesek = new Bejegyzes[1];
                meret = 1;
            } else {
                Bejegyzes* temp = new Bejegyzes[meret + 1];
                for (size_t i = 0; i < meret; ++i) {
                    temp[i] = bejegyzesek[i];
                    
                }
                delete[] bejegyzesek;
                bejegyzesek = temp;
                ++meret;
            }
            bejegyzesek[meret - 1] = bejegyzes;
        }

        void kiir() {           //kiirja a telefonkonyvet, de meg nem a teljeset
            header();
            for (size_t i = 0; i < meret; ++i) {
                bejegyzesKi(bejegyzesek[i]);
            }
            
        }

        void feltoltesTelefonkonyv(const std::string& filename) {
           //TODO megcsinalni a feltoltest
        }


        /* void feltoltesTelefonkonyv(const std::string& filename) {
            std::ifstream file(filename);
            std::string line;
            
            header();

            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string vezeteknev, keresztnev, becenev;
                unsigned long int szemelyes, ceges;
                unsigned int varos, havi_dij;

                std::getline(iss, vezeteknev, ';');
                std::getline(iss, keresztnev, ';');
                std::getline(iss, becenev, ';');
                iss >> szemelyes;
                iss.ignore(); // ';' karakter átugrása
                iss >> ceges;
                iss.ignore(); // ';' karakter átugrása
                iss >> varos;
                iss.ignore(); // ';' karakter átugrása
                iss >> havi_dij;

                Ember ember(vezeteknev, vezeteknev.length(), keresztnev, keresztnev.length(), becenev, becenev.length());
                Telefon telefon(szemelyes, ceges);
                Bejegyzes bejegyzes(ember, telefon, varos, havi_dij); 
                addBejegyzes(bejegyzes);
                bejegyzesKi(bejegyzes);
            }
        } */


};





#endif