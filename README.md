

HÁZI FELADAT

Programozás alapjai 2.

Feladatválasztás/feladatspecifikáció



2024\.04.13





# <a name="_toc163978278"></a>Feladat
### Telefonkönyv
Tervezze meg egy telefonkönyv alkalmazás egyszerűsített objektummodelljét, majd valósítsa azt meg! A telefonkönyvben kezdetben az alábbi adatokat akarjuk tárolni, de később bővíteni akarunk:

- Név (vezetéknév, keresztnév)
- becenév
- város
- munkahelyi szám
- privát szám
- előfizetés

Az alkalmazással minimum a következő műveleteket kívánjuk elvégezni:

- adatok felvétele
- adatok törlése
- listázás

A rendszer lehet bővebb funkcionalitású (pl. módosítás, keresés), ezért nagyon fontos, hogy jól határozza meg az objektumokat és azok felelősségét. Demonstrálja a működést külön modulként fordított tesztprogrammal! A megoldáshoz **ne** használjon STL tárolót!


# <a name="_toc163978279"></a>Feladatspecifikáció

A feladat egy telefonkönyv készítése. Az alkalmazásom parancssorban fog futni. A megoldásommal lehet adatokat felvenni/törölni, listázni és részletesen keresni (akár név, becenév, vagy telefonszám alapján. ) 

A telefonkönyvem ’bejegyzései’ tartalmazni fognak nevet (keresztnév, vezetéknév, becenév) lakhely (város), munkahelyi és személyes telefonszámot, illetve előfizetés (Ft-ban). 

A felhasználó lépéseit, illetve a program főbb futási elemeit egy .log fájlban lesznek vezetve, illetve időbélyeggel ellátva.

A teszteléshez olyan programot készítek, melyben a konzolos kezelői felület standard inputjáról érkező hibás bemeneteket is helyesen kezeli. Ezeket egyaránt jelzi a felhasználónak és a .log fájlban is feltüntetésre kerül.
