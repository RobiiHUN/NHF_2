#include <iostream>
#include <string>




#include "headers/base.hpp"
#include "headers/test.hpp"
#include "headers/ui.hpp"
#include "headers/search_tree.hpp"







int main(){
        test(); //teszt fuggveny csak akkor tortenik valami, ha a macro.h-ban a TEST makro true-n van
        
        Telefonkonyv tk;
        UI ui(tk);
        tk.kiir();
        

















return 0;
}