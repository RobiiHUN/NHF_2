#include "base.hpp"


/* ========================================================================== */
/*                                  BEJEGYZES                                 */
/* ========================================================================== */

/* ------------------------------ KONSTRUKTOROK ----------------------------- */

Bejegyzes::Bejegyzes(): telefon(), ember(), varos(0), havi_dij(0){
    if (DEBUG) std::cout<<"Bejegyzes ctor"<<std::endl;
}

Bejegyzes::Bejegyzes(const Ember& e, const Telefon& t,  unsigned int v, unsigned int h):
                telefon(t), ember(e), varos(v), havi_dij(h){
                    if (DEBUG) std::cout<<"Bejegyzes param ctor"<<std::endl;}

/* ------------------------------ DESTROKTOROK ------------------------------ */
Bejegyzes::~Bejegyzes(){if (DEBUG) std::cout<<"Bejegyzes dtor"<<std::endl;}