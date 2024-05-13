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
        
        UI(Telefonkonyv& t):tk(t){menu();}
        
        void clearScreen();
        void header();
        void logo();
        void menu();
        int bemenetCHECK(int, int);
        void bejegyzesBE();
        void bejegyzesKI();
       


        
        
        //TODO modositas
        //TODO kereses


};

#endif
