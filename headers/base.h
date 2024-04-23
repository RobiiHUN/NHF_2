#include "back_data.h"
#include <iomanip>  //a tablazathoz kell







/* -------------------------------------------------------------------------- */
//!                               BEJEGYZES CLASS                              !//
/* -------------------------------------------------------------------------- */

class Bejegyzes{
        private:
            Telefon telefon;            // telefonszamok
            Ember ember;                // ember adatai
            unsigned int varos;         // iranyito szama                   (alapeset: 0 )
            unsigned int havi_dij;      // havi dijja az elofizetesnek      (alapesset: 0)
        
        public:

            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Bejegyzes(): telefon(), ember(), varos(0), havi_dij(0)
            {if (DEBUG) std::cout<<"Bejegyzes ctor"<<std::endl;}

            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Bejegyzes(const Ember& e, const Telefon& t,  unsigned int v, unsigned int h):
                telefon(t), ember(e), varos(v), havi_dij(h){if (DEBUG) std::cout<<"Bejegyzes param ctor"<<std::endl;}

            /* ------------------------------- DESTRUKTOR ------------------------------- */
            ~Bejegyzes(){if (DEBUG) std::cout<<"Bejegyzes dtor"<<std::endl;}

            /* -------------------------------- GETTEREK -------------------------------- */
            unsigned int getVaros()const{return varos;}     //* visszaadja a varos iranyito szamat
            unsigned int getHavi() const{return havi_dij;}  //* visszaadja a havi dijjat
            unsigned long int getSzemTell()const{return telefon.getSzemTell();} //* visszaadja a szemelyes telefonszamot
            unsigned long int getCegeTell()const{return telefon.getCegesTell();}   //* visszaadja a ceges telefonszamot
            const char* getVezetek()const{return ember.getVezetek();}      //* visszaadja a vezeteknevet
            const char* getKereszt()const{return ember.getKereszt();}      //* visszaadja a keresztnevet
            const char* getBece()const{return ember.getBece();}            //* visszaadja a becenevet
            size_t getLenVez()const{return ember.getLenVez();}         //* visszaadja a vezeteknev hosszat
            size_t getLenKer()const{return ember.getLenKer();}         //* visszaadja a keresztnev hosszat
            size_t getLenBece()const{return ember.getLenBece();}       //* visszaadja a becenev hosszat
            size_t getLenSzem()const{return telefon.getLenSzem();} //* visszaadja a szemelyes telefonszam hosszat
            size_t getLenCeg()const{return telefon.getLenCeg();}   //* visszaadja a ceges telefonszam hosszat
            size_t getLenVar()const{return std::to_string(varos).length();} //* visszaadja a varos iranyito szam hosszat

};




class Telefonkonyv{
    private:
        Bejegyzes* bejegyzesek;      //bejegyzesek tombje
        size_t meret;               //tomb merete
    public:


        
        

};


//void bejegyzesKi(Bejegyzes& be){
 //   std::cout << be.getVezetek() << " " << be.getKereszt() << " "<<be.getSzemTell() << " " <<be.getVaros() << std::endl;
//}

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

//* -------------------------- EGY BEJEGYZES KIÍRÁSA ------------------------- *//

void bejegyzesKi(Bejegyzes& be){        //bejegyzes kiirasa
    
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
