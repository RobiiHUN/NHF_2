#include <iostream>
#include <string>




#include "headers/base.hpp"
//#include "headers/test.hpp"  //TODO teszt
#include "headers/ui.hpp"
#include "headers/search_tree.hpp"







int main(){
        //test(); //teszt fuggveny csak akkor tortenik valami, ha a macro.h-ban a TEST makro true-n van
        try
        {
                Telefonkonyv tk;
                UI ui(tk);
        }
        catch(const std::runtime_error& e)
        {
                std::cerr << e.what() << "A program nem fut le, mert nem létezik se a source sem a backup file! Kösz, hello!"<< '\n';
        }catch(const std::exception& e)
        {
                std::cerr << e.what() << "ERORR 404" <<'\n'; 
        }
        
        
                
        //TODO test program irasa
        //TODO exeptions befejezni
        //TODO dokumentacio


        

return 0;
}