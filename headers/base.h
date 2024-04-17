#include "back_data.h"






/* -------------------------------------------------------------------------- */
//!                               BEJEGYZES CLASS                              !//
/* -------------------------------------------------------------------------- */

class Bejegyzes: public Telefon{
        private:
            unsigned int varos;         // iranyito szama                   (alapeset: 0 )
            unsigned int havi_dij;      // havi dijja az elofizetesnek      (alapesset: 0)
        
        public:

            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Bejegyzes(): Telefon(), varos(0), havi_dij(0)
            {if (DEBUG) std::cout<<"Bejegyzes ctor"<<std::endl;}

            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Bejegyzes(char *v, size_t lv, char *k, size_t lk, char *b, size_t lb,
                        unsigned long int sz, unsigned long int bu,unsigned int va, 
                        unsigned int h): Telefon(v, lv, k, lk, b, lb, sz, bu), varos(va), havi_dij(h){
                            if (DEBUG) std::cout<< "Beegyzes param ctor" <<std::endl;}

            /* ------------------------------- DESTRUKTOR ------------------------------- */
            ~Bejegyzes(){if (DEBUG) std::cout<<"Bejegyzes dtor"<<std::endl;}

            /* -------------------------------- GETTEREK -------------------------------- */
            unsigned int getVaros()const{return varos;}     //* visszaadja a varos iranyito szamat
            unsigned int getHavi() const{return havi_dij;}  //* visszaadja a havi dijjat
};

void bejegyzesKi(Bejegyzes& be){
    std::cout << be.getVezetek() << " "  << be.getKereszt() << " " << be.getVaros() << " " << be.getBece() << " " 
            <<"+" << be.getSzemTell() << " " << "+" << be.getCegesTell() << " " << be.getHavi(); 
}