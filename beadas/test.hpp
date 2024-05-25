#ifndef TEST_HPP
#define TEST_HPP


#include "ui.hpp"







void teszt(){
        #ifdef CPORTA 
        
                /* ========================================================================== */
                //!                                 EMBER TEST                                 */
                /* ========================================================================== */
                
                /* ------------------------- PARAMETER NELKULI CTOR ------------------------- */
                

                TEST(Ember, paramn.ctor)
                        Ember paramn;
                        std::string ures = "";
                        EXPECT_EQ(ures, paramn.getVezetek());
                        EXPECT_EQ(ures, paramn.getKereszt());
                        EXPECT_EQ(ures, paramn.getBece());
                END     


                /* ----------------------------- PARAMETER CTOR ----------------------------- */
                
                TEST(Ember, paramctor)
                        
                        std::string vezetek = "Test";
                        std::string keresztnev = "Janos";
                        std::string becenev = "Jani";
                        Ember ember(vezetek,keresztnev, becenev);

                        EXPECT_EQ(vezetek, ember.getVezetek());
                        EXPECT_EQ(keresztnev, ember.getKereszt());
                        EXPECT_EQ(becenev, ember.getBece());
                END

                /* ----------------------- MASOL CTOR ES EGYENLOSEG OP ---------------------- */

                TEST(Ember, masol ctor es egyenloseg op)
                        std::string vezetek = "Test";
                        std::string keresztnev = "Janos";
                        std::string becenev = "Jani";
                        Ember forras(vezetek, keresztnev, becenev);
                        Ember cel(forras);
                        Ember egyenlo;

                        EXPECT_EQ(forras.getBece(), cel.getBece());
                        EXPECT_EQ(forras.getKereszt(), cel.getKereszt());
                        EXPECT_EQ(forras.getBece(), cel.getBece());

                        egyenlo = forras; 
                        EXPECT_EQ(forras.getBece(), egyenlo.getBece());
                        EXPECT_EQ(forras.getKereszt(), egyenlo.getKereszt());
                        EXPECT_EQ(forras.getBece(), egyenlo.getBece());                              

                END

                /* ------------------------------- GETTER TEST ------------------------------ */

                TEST (Ember, getterek)
                        std::string vezetek = "Test";
                        std::string keresztnev = "Janos";
                        std::string becenev = "Jani";
                        Ember forras(vezetek, keresztnev, becenev);

                        EXPECT_EQ(vezetek, forras.getVezetek());
                        EXPECT_EQ(keresztnev, forras.getKereszt());
                        EXPECT_EQ(becenev, forras.getBece());
                        EXPECT_EQ(vezetek.length(), forras.getLenVez());
                        EXPECT_EQ(keresztnev.length(), forras.getLenKer());
                        EXPECT_EQ(becenev.length(), forras.getLenBece());

                END
                
                /* -------------------------------- SETTEREK -------------------------------- */

                TEST (Ember, setter)
                        std::string vezetek = "Test";
                        std::string keresztnev = "Janos";
                        std::string becenev = "Jani";
                        Ember vizsgalando;

                        vizsgalando.setVezetek(vezetek);
                        vizsgalando.setKereszt(keresztnev);
                        vizsgalando.setBece(becenev);

                        EXPECT_EQ(vezetek, vizsgalando.getVezetek());
                        EXPECT_EQ(keresztnev, vizsgalando.getKereszt());
                        EXPECT_EQ(becenev, vizsgalando.getBece());
                END



                /* ========================================================================== */
                //!                            TELEFON OBJ. TESZT                             */
                /* ========================================================================== */

                /* ------------------------------- PARAMN CTOR ------------------------------ */
                
                TEST(Telefon, paramn.ctor)
                        Telefon test;
                        EXPECT_EQ(0, test.getSzemTell());
                        EXPECT_EQ(0, test.getCegesTell());

                
                END

                /* --------------------------- PARA CTOR ES GETTER -------------------------- */

                TEST(Telefon, param.ctor es getter)
                        unsigned long int szem = 36209871234;   //11 karakter
                        unsigned long int ceg = 36701239876;    //11 karakter
                        Telefon test(szem, ceg);

                        EXPECT_EQ(szem, test.getSzemTell());
                        EXPECT_EQ(ceg, test.getCegesTell());
                        EXPECT_EQ(std::to_string(szem).length(), test.getLenSzem());
                        EXPECT_EQ(std::to_string(ceg).length(), test.getLenCeg());

                END


                /* ========================================================================== */
                //!                               BEJEGYZES TEST                               */
                /* ========================================================================== */
                
                /* ------------------------------ PARAMN. CTOR ------------------------------ */
                
                TEST(Bejegyzes, paramn.ctor)
                        Bejegyzes test;
                        std::string ures = "";
                        
                        EXPECT_EQ(0, test.getVaros());
                        EXPECT_EQ(0, test.getHavi());
                        EXPECT_EQ(0, test.getSzemTell());
                        EXPECT_EQ(0, test.getCegeTell());
                        EXPECT_EQ(ures, test.getVezetek());
                        EXPECT_EQ(ures, test.getKereszt());
                        EXPECT_EQ(ures, test.getBece());

                END

                /* ------------------------------- PARAM CTOR ------------------------------- */

                TEST(Bejegyzes, param.ctor)
                        std::string vezetek = "Test";
                        std::string keresztnev = "Janos";
                        std::string becenev = "Jani";
                        unsigned long int szem = 36209871234;   //11 karakter
                        unsigned long int ceg = 36701239876;    //11 karakter
                        unsigned int varos = 4355;
                        unsigned int havi = 23450;

                        Ember ember(vezetek, keresztnev, becenev);
                        Telefon tel(szem, ceg);
                        Bejegyzes test(ember, tel, varos, havi);

                        EXPECT_EQ(vezetek, test.getVezetek());
                        EXPECT_EQ(keresztnev, test.getKereszt());
                        EXPECT_EQ(becenev, test.getBece());
                        EXPECT_EQ(szem, test.getSzemTell());
                        EXPECT_EQ(ceg, test.getCegeTell());
                        EXPECT_EQ(varos, test.getVaros());
                        EXPECT_EQ(havi, test.getHavi());


                END


                /* --------------------------- GETTEREK TESTELESE --------------------------- */
                TEST(Bejegyzes, getterek)
                        std::string vezetek = "Test";
                        std::string keresztnev = "Janos";
                        std::string becenev = "Jani";
                        unsigned long int szem = 36209871234;   //11 karakter
                        unsigned long int ceg = 36701239876;    //11 karakter
                        unsigned int varos = 4355;
                        unsigned int havi = 23450;

                        Ember ember(vezetek, keresztnev, becenev);
                        Telefon tel(szem, ceg);
                        Bejegyzes test(ember, tel, varos, havi);

                        EXPECT_EQ(vezetek, test.getVezetek());
                        EXPECT_EQ(keresztnev, test.getKereszt());
                        EXPECT_EQ(becenev, test.getBece());
                        EXPECT_EQ(szem, test.getSzemTell());
                        EXPECT_EQ(ceg, test.getCegeTell());
                        EXPECT_EQ(varos, test.getVaros());
                        EXPECT_EQ(havi, test.getHavi());
                        EXPECT_EQ(vezetek.length(), test.getLenVez());
                        EXPECT_EQ(keresztnev.length(), test.getLenKer());
                        EXPECT_EQ(becenev.length(), test.getLenBece());
                        EXPECT_EQ(std::to_string(szem).length(), test.getLenSzem());
                        EXPECT_EQ(std::to_string(ceg).length(), test.getLenCeg());
                        EXPECT_EQ(std::to_string(varos).length(), test.getLenVar());
                        
                END

                /* ------------------------------- SETTER TEST ------------------------------ */
                TEST(Bejegyzes, setterek)
                        std::string vezetek = "Test";
                        std::string keresztnev = "Janos";
                        std::string becenev = "Jani";
                        unsigned long int szem = 36209871234;   //11 karakter
                        unsigned long int ceg = 36701239876;    //11 karakter
                        unsigned int varos = 4355;
                        unsigned int havi = 23450;
                        Bejegyzes test;

                        test.setVezetek(vezetek);
                        test.setKereszt(keresztnev);
                        test.setBece(becenev);
                        test.setSzemTell(szem);
                        test.setCegeTell(ceg);
                        test.setVaros(varos);
                        test.setHavi(havi);


                        EXPECT_EQ(vezetek, test.getVezetek());
                        EXPECT_EQ(keresztnev, test.getKereszt());
                        EXPECT_EQ(becenev, test.getBece());
                        EXPECT_EQ(szem, test.getSzemTell());
                        EXPECT_EQ(ceg, test.getCegeTell());
                        EXPECT_EQ(varos, test.getVaros());
                        EXPECT_EQ(havi, test.getHavi());

                END

                /* ========================================================================== */
                /*                                TELEFONKONYV                                */
                /* ========================================================================== */

                /* -------------------------------- GETTEREK -------------------------------- */
                
                
                //Telefonkonyv test;
                //test.factoryReset("source_backup.txt", "source.txt"); //ezzel allitunk mindent vissza

                
                
                TEST(Telefonkonyv,getterek)
                        Telefonkonyv test;
                        EXPECT_EQ(20, test.getMeret()); 

                END

                /* -------------------------- BEJEGYZES HOZZAADASA -------------------------- */
                TEST(Telefonkonyv, bej.hozzaadasa)
                        std::string vezetek = "Test";
                        std::string keresztnev = "Janos";
                        std::string becenev = "Jani";
                        unsigned long int szem = 36209871234;   //11 karakter
                        unsigned long int ceg = 36701239876;    //11 karakter
                        unsigned int varos = 4355;
                        unsigned int havi = 23450;

                        Ember ember(vezetek, keresztnev, becenev);
                        Telefon tel(szem, ceg);
                        Bejegyzes bejegyzes(ember, tel, varos, havi); 
                        Telefonkonyv test;               
                        
                        EXPECT_EQ(20, test.getMeret());
                        test.addBejegyzes(bejegyzes);
                        EXPECT_EQ(vezetek, test.getBejegyzes(20).getVezetek());
                        test.bejTorles(20);
                        
                
                
                END

                /* ---------------------------- FELTOLTES FAJLBOL --------------------------- */

                TEST(Telefonkonyv, feltoltes fajlbol)
                        Telefonkonyv test;
                        EXPECT_EQ(20,test.getMeret());
                END


                /* -------------------------------- FELTOLTES ------------------------------- */

                TEST(Telefonkonyv, bej.torlese)
                        Telefonkonyv test;
                        EXPECT_EQ(20, test.getMeret());
                        test.bejTorles(19);
                        EXPECT_EQ(19, test.getMeret());
                        
                        
                END



                /* -------------------------------- RENDEZES -------------------------------- */
                TEST(Telefonkonyv, rendezes)
                        Telefonkonyv test;
                        
                        EXPECT_EQ(19, test.getMeret());
                        
                        bool megfelelo = false;
                        if (test.osszeBej(test.getBejegyzes(2), test.getBejegyzes(1))>0)
                        {
                                megfelelo = true;
                        }
                        
                        EXPECT_EQ(true, megfelelo);
                        

                END

                /* --------------------------------- KERESO --------------------------------- */
                TEST(Telefonkonyv, kereso)
                        Telefonkonyv test;
                        bool megfelelo = false;

                        Bejegyzes* bej = test.Telefonykonyvkeres("Becky");
                        if(bej != nullptr){
                                megfelelo = true;
                        }

                        EXPECT_EQ(true, megfelelo);


                END


                

               
        
       
        #endif
}
#endif