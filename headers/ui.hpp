#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "macro.h"

class UI{
    public:
        void clearScreen();
        void header();
        void logo();
        void menu();
        int menuPontValasztas();

};

#endif
