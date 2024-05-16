#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "macro.h"
#include "base.hpp"

class UI{
    Telefonkonyv& tk;

    public:
        UI();
        UI(Telefonkonyv& t);
        
        void clearScreen();
        void header();
        void logo();
        void menu();
        int bemenetCHECK(int, int);
        void bejegyzesBE();     //bejegyzes hozzaadasa
        void bejegyzesKI();     //bejegyzes torlese
        void bejegyzesMOD();    //bejegyzes modositasa
        void kereses();
       


        
        
        
        //TODO kereses


};

#endif
