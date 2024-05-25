//#include <iostream>
//#include <string>




//#include "base.hpp"

#include "test.hpp" 











int main(){
        #ifdef CPORTA
        teszt(); return 0; //teszt fuggveny csak akkor tortenik valami, ha a macro.h-ban a TEST makro true-n van
        #endif
        try
        {
                Telefonkonyv tk;
                UI ui(tk);
        }
        catch(const std::runtime_error& e)
        {
                std::cerr << e.what() << "A program nem fut le, mert nem létezik se a source sem a backup file! Kösz, hello!"<< '\n';
        }
        
        



        

return 0;
}