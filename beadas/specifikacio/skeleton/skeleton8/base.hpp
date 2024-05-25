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
            Ember(): vezeteknev("N/A"), len_vez(3), keresztnev("N/A"), len_kereszt(3), becenev("N/A"), len_bece(3){      //*konsruktor parameter nelkul
                if (DEBUG) std::cout<<"Ember ctor"<<std::endl;};

            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Ember(char *v, size_t lv, char *k, size_t lk, char *b, size_t lb): EMBER_ROVID{ //*konstruktor parameterekkel
                if (DEBUG) std::cout<<"Ember param ctor"<<std::endl;
                }
            Ember(const std::string& v, size_t lv, const std::string& k, size_t lk, const std::string& b, size_t lb): //*konstruktor parameterekkel es stringkezelessel
                vezeteknev(v.c_str()), len_vez(lv), keresztnev(k.c_str()), len_kereszt(lk), becenev(b.c_str()), len_bece(lb){
                if (DEBUG) std::cout<<"Ember param ctor"<<std::endl;
                } // a fajlbol valo bolvasashoz

            /* -------------------------------- DESTRUKTOR ------------------------------ */
            ~Ember(){if (DEBUG) std::cout<<"Ember dtor"<<std::endl;}


            /* -------------------------------- GETTEREK -------------------------------- */
            const char* getVezetek()const{return vezeteknev;}      //* visszaadja a vezeteknevet
            size_t getLenVez()const{return len_vez;}            //* visszaadja a vezeteknev hosszat
            const char* getKereszt()const{return keresztnev;}       //* visszaadja a keresztnevet
            size_t getLenKer()const{return len_kereszt;}           //* visszaadja a keresztnev hosszat
            const char* getBece()const{return becenev;}        //* visszaadja a becenevet
            size_t getLenBece()const{return len_bece;}           //* visszaadja a becenev hosszat
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
            Telefon(){szemelyes = 100;business = 0;if (DEBUG) std::cout<<"Telefon ctor"<<std::endl;}   //*konstruktor parameter nelkul



            /* ------------------------ KONSTRUKTOR PARAMETERREL ------------------------ */
            Telefon(unsigned long int sz, unsigned long int bu): szemelyes(sz), business(bu){          //*konstruktor parameterekkel
                if (DEBUG) std::cout<<"Telefon param ctor"<<std::endl;}


           /* ------------------------------- DESTRUKTOR ------------------------------- */
            ~Telefon(){if (DEBUG) std::cout<<"Telefon dtor"<<std::endl;}
 
           /* -------------------------------- GETTEREK -------------------------------- */
           unsigned long int getSzemTell()const{return szemelyes;}      //* visszaadja a szemelyes telefonszamot
           unsigned long int getCegesTell()const{return business;}      //* visszaada a ceges telefonszamot
           size_t getLenSzem()const{return std::to_string(szemelyes).length();} //* visszaadja a szemelyes telefonszam hosszat
           size_t getLenCeg()const{return std::to_string(business).length();}   //* visszaadja a ceges telefonszam hosszat
};


void clearScreen(){if(DEBUG) return;std::cout << "\033[2J\033[1;1H";}






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
            Bejegyzes(): ember(), telefon(),  varos(0), havi_dij(0){
                if (DEBUG) std::cout<<"Bejegyzes ctor"<<std::endl;
                    }

            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Bejegyzes(const Ember& e, const Telefon& t,  unsigned int v, unsigned int h):
                ember(e), telefon(t),  varos(v), havi_dij(h){
                    if (DEBUG) std::cout<<"Bejegyzes param ctor"<<std::endl;}


            /* ------------------------------- DESTRUKTOR ------------------------------- */
            ~Bejegyzes(){if (DEBUG) std::cout<<"Bejegyzes dtor"<<std::endl;}

            /* -------------------------------- GETTEREK -------------------------------- */
            unsigned int getVaros()const{return varos;}                       //* visszaadja a varos iranyito szamat
            unsigned int getHavi() const{return havi_dij;}                        //* visszaadja a havi dijjat
            unsigned long int getSzemTell()const{return telefon.getSzemTell();}               //* visszaadja a szemelyes telefonszamot
            unsigned long int getCegeTell()const{return telefon.getCegesTell();}               //* visszaadja a ceges telefonszamot
            const char* getVezetek()const{return ember.getVezetek();}                      //* visszaadja a vezeteknevet
            const char* getKereszt()const{return ember.getKereszt();}                      //* visszaadja a keresztnevet
            const char* getBece()const{return ember.getBece();}                         //* visszaadja a becenevet
            size_t getLenVez()const{return ember.getLenVez();}                            //* visszaadja a vezeteknev hosszat
            size_t getLenKer()const{return ember.getLenKer();}                           //* visszaadja a keresztnev hosszat
            size_t getLenBece()const{return ember.getLenBece();}                           //* visszaadja a becenev hosszat
            size_t getLenSzem()const{return telefon.getLenSzem();}                           //* visszaadja a szemelyes telefonszam hosszat
            size_t getLenCeg()const{return telefon.getLenCeg();}                            //* visszaadja a ceges telefonszam hosszat
            size_t getLenVar()const{return std::to_string(varos).length();}                           //* visszaadja a varos iranyito szam hosszat

};

/* ========================================================================== */
//!                            TELEFONKÖNYV KIÍRÁSA                           !//
/* ========================================================================== */

void header(){          //fejlec kiirasa
    clearScreen();    //toroljuk a kepernyot
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "=";
    }
    std::endl(std::cout);
    
    int width = 20; // Oszlop szélessége
    std::cout << std::setw(10) <<std::left <<"Vezeteknév" 
              << std::setw(width - 10) << std::setfill(' ') << ""

              << std::setw(11) <<std::left << "Keresztnév" 
              << std::setw(width - 11) << std::setfill(' ') << ""

              << std::setw(7) <<std::left << "Becenév"
              << std::setw(width - 7) << std::setfill(' ') << ""

              << std::setw(14) <<std::left << "Sz.telefonszám"
              << std::setw(width - 14) << std::setfill(' ') << ""

              << std::setw(5) <<std::left << "Város" 
              << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "=";
    }
    std::endl(std::cout);
}
void bejegyzesKi(Bejegyzes& be){        //bejegyzes kiirasa
    header();
    int width = 20; // Oszlop szélessége
    std::cout << std::setw(be.getLenVez()) <<std::left <<be.getVezetek() 
              << std::setw((width - be.getLenVez())) << std::setfill(' ') << ""

              << std::setw(be.getLenKer()) <<std::left << be.getKereszt() 
              << std::setw(width - be.getLenKer()) << std::setfill(' ') << ""

              << std::setw(be.getLenBece()) <<std::left << be.getBece() 
              << std::setw(width - be.getLenBece()) << std::setfill(' ') << ""

              << std::setw(be.getLenSzem()) <<std::left << be.getSzemTell() 
              << std::setw(width - be.getLenSzem()) << std::setfill(' ') << ""

              << std::setw(be.getLenVar()) <<std::left << be.getVaros() 
              << std::endl;
}


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
        Telefonkonyv(): bejegyzesek(), meret(0){
            if (DEBUG) std::cout<<"Telefonkonyv ctor"<<std::endl;
                }
        /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
        Telefonkonyv(size_t size) : bejegyzesek(new Bejegyzes[size]), meret(size) {
            if (DEBUG) std::cout << "Telefonkonyv param ctor" << std::endl;
        }
        Telefonkonyv(Bejegyzes* b, size_t m) : bejegyzesek(b), meret(m) {
            if (DEBUG) std::cout << "Telefonkonyv param ctor" << std::endl;
        }
        
        /* ------------------------------- DESTRUKTOR ------------------------------- */
        ~Telefonkonyv(){
            if (DEBUG) std::cout << "Telefonkonyv dtor" << std::endl;
            delete[] bejegyzesek;
                }

        /* ---------------------------- MERET VISSZADASA ---------------------------- */
        size_t getMeret()const{
            return meret;
        }

        /* ------------------------------- MASOLO CTOR ------------------------------ */
        Telefonkonyv(const Telefonkonyv& other) : bejegyzesek(new Bejegyzes[other.meret]), meret(other.meret) {
            for (size_t i = 0; i < meret; ++i) {
            bejegyzesek[i] = other.bejegyzesek[i];
                }
        }

        /* --------------------------- EGYENLOSEG OPERATOR -------------------------- */
        Telefonkonyv& operator=(const Telefonkonyv& other) {
            if (this != &other) {
                delete[] bejegyzesek;
                meret = other.meret;
                bejegyzesek = new Bejegyzes[meret];
                for (size_t i = 0; i < meret; ++i) {
                    bejegyzesek[i] = other.bejegyzesek[i];
                }
            }
            return *this;
        }

        /* --------------------------- BEJEGYZES HOZZADASA -------------------------- */

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

        /* ------------------------------- KIIRATAS -------------------------------- */

        void kiir() const{ 
            header();
            for (size_t i = 0; i < meret; ++i) {
                bejegyzesKi(bejegyzesek[i]);
            }
        }

        void feltoltesTelefonkonyv(const std::string& filename);
           //TODO megcsinalni a feltoltest
        
        Bejegyzes& Telefonykonyvkeres(const Bejegyzes& be);
            //TODO megcsinalni a keresest

};






#endif