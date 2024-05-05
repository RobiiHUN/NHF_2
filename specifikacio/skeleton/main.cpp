#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



#include "base.hpp"
#include "gtest_lite.h"






int main(){
        /* ----------------------------- TESTELESHEZ JO ----------------------------- */

char vezeteknev1[] = "Test";
size_t l_vez = 5;
char keresztnev[] = "Kalapacs";
size_t l_ker = 9;
char becenev[] = "Kalad";
size_t l_bece = 5;


        /* -------------------------------------------------------------------------- */

/* option shift a        */



Ember ember(vezeteknev1, l_vez, keresztnev, l_ker, becenev, l_bece);
Ember ember2;
Telefon tf;
Telefon tf2(36203952740, 36401239876);
Bejegyzes bejegyzes;
Bejegyzes bejegy(ember, tf2, 1, 100);
//header();
//bejegyzesKi(bejegy);
Telefonkonyv tk;

/* ------------------------- EMBER PARAMETERES KTOR ------------------------- */
TEST(Ember, paramctor)
        EXPECT_EQ(vezeteknev1, ember.getVezetek());
        EXPECT_EQ(l_vez, ember.getLenVez());
        EXPECT_EQ(keresztnev, ember.getKereszt());
        EXPECT_EQ(l_ker, ember.getLenKer());
        EXPECT_EQ(becenev, ember.getBece());
        EXPECT_EQ(l_bece, ember.getLenBece());

END     

/* ------------------------- EMBER PARAMNELKULI CTOR ------------------------ */

TEST(Ember, paramn.)
        EXPECT_EQ("N/A", ember2.getVezetek());
        EXPECT_EQ(3, ember2.getLenVez());
        EXPECT_EQ("N/A", ember2.getKereszt());
        EXPECT_EQ(3, ember2.getLenKer());
        EXPECT_EQ("N/A", ember2.getBece());
        EXPECT_EQ(3, ember2.getLenBece());    
END

/* ------------------------ TELEFON PARAMNELKULI CTOR ----------------------- */

TEST(Telefon, paramn.)
        
        EXPECT_EQ(100, tf.getSzemTell());
        EXPECT_EQ(0, tf.getCegesTell());
END

/* -------------------------- TELEFON PRAMATER CTOR ------------------------- */

TEST(Telefon, param.)

        EXPECT_EQ(36203952740, tf2.getSzemTell());
        EXPECT_EQ(36401239876, tf2.getCegesTell());
END


/* --------------------- BEJEGYZES PARAMATERNELKULI CTOR -------------------- */

TEST(Bejegyzes, paramn.)
        EXPECT_EQ(0, bejegyzes.getVaros());
        EXPECT_EQ(0, bejegyzes.getHavi());
        EXPECT_EQ(100, bejegyzes.getSzemTell());
        EXPECT_EQ(0, bejegyzes.getCegeTell());
        EXPECT_EQ("N/A", bejegyzes.getVezetek());
        EXPECT_EQ("N/A", bejegyzes.getKereszt());
        EXPECT_EQ("N/A", bejegyzes.getBece());
        EXPECT_EQ(3, bejegyzes.getLenVez());
        EXPECT_EQ(3, bejegyzes.getLenKer());
        EXPECT_EQ(3, bejegyzes.getLenBece());
        EXPECT_EQ(3, bejegyzes.getLenSzem());
        EXPECT_EQ(1, bejegyzes.getLenVar());
END

/* ------------------------ BEJEGYZES PARAMETER CTOR ------------------------ */

TEST(Bejegyzes, param)
        EXPECT_EQ(1, bejegy.getVaros());
        EXPECT_EQ(100, bejegy.getHavi());
        EXPECT_EQ(36203952740, bejegy.getSzemTell());
        EXPECT_EQ(36401239876, bejegy.getCegeTell());
        EXPECT_EQ(vezeteknev1, bejegy.getVezetek());
        EXPECT_EQ(keresztnev, bejegy.getKereszt());
        EXPECT_EQ(becenev, bejegy.getBece());
        EXPECT_EQ(l_vez, bejegy.getLenVez());
        EXPECT_EQ(l_ker, bejegy.getLenKer());
        EXPECT_EQ(l_bece, bejegy.getLenBece());
        EXPECT_EQ(11, bejegy.getLenSzem());
        EXPECT_EQ(1, bejegy.getLenVar());
END

/* --------------------- TELEFONKONYV PARAMNELKULI CTOR --------------------- */
TEST(Telefonkonyv, paramn.)
        EXPECT_EQ(0, tk.getMeret());
END

/* ------------------------- TELEFONKONYV PARAM CTOR ------------------------ */
TEST(Telefonkonyv, param)
        Telefonkonyv tk2(5);
        EXPECT_EQ(5, tk2.getMeret());
END



return 0;
}