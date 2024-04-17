#include "back_data.h"






/* -------------------------------------------------------------------------- */
//!                               BEJEGYZES CLASS                              !//
/* -------------------------------------------------------------------------- */

class Bejegyzes: public Telefon{
        private:
            unsigned int varos;         // iranyito szama                   (alapeset: Budapest I. )
            unsigned int havi_dij;      // havi dijja az elofizetesnek      (alapesset: 0)
        
        public:

            /* ---------------------- KONSTRUKTOR PARAMETER NELKUL ---------------------- */
            Bejegyzes(): varos(1016), havi_dij(0)
            {if (DEBUG) std::cout<<"Bejegyzes ctor"<<std::endl;}

            /* ----------------------- KONSTRUKTOR PARAMETEREKKEL ----------------------- */
            Bejegyzes(unsigned int v, unsigned int h): varos(v), havi_dij(h)
            {if (DEBUG) std::cout<<"Beegyzes param ctor"<<std::endl;}

            /* ------------------------------- DESTRUKTOR ------------------------------- */
            ~Bejegyzes(){if (DEBUG) std::cout<<"Bejegyzes dtor"<<std::endl;}

            /* -------------------------------- GETTEREK -------------------------------- */
            unsigned int getVaros()const{return varos;}     //* visszaadja a varos iranyito szamat
            unsigned int getHavi() const{return havi_dij;}  //* visszaadja a havi dijjat
};