#include <iostream>
#include "back_data.h"



/* ------------------------------ 2 PUBLIC TEST ----------------------------- */

class Data: public Number, public Date{
 int name;
 
 public:
    Data(): name(12){}
    Data(int b_name): name(b_name){}
    int getName()const {return name;}


};
