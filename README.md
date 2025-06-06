# 📞 Telefonkönyv — Programozás Alapjai 2.
### 📝 Házi Feladat Dokumentáció · 2024.05.18

---

## 📚 Tartalomjegyzék

- [📌 Feladat](#-feladat)
- [🛠️ Feladatspecifikáció](#️-feladatspecifikáció)
- [📋 Pontosított feladatspecifikáció](#-pontosított-feladatspecifikáció)
- [⚙️ Algoritmusok és függvények](#️-algoritmusok-és-függvények)
- [🖥️ A program kezelőfelülete](#-a-program-kezelőfelülete)
- [🔧 A program főbb funkciói](#-a-program-főbb-funkciói)
- [🚀 Futtatás](#-futtatás)
- [💬 Megjegyzés](#-megjegyzés)

---

## 📌 Feladat

**Telefonkönyv alkalmazás egyszerűsített objektummodelljének megvalósítása.**

### Tárolt adatok:

- Név (vezetéknév, keresztnév)
- Becenév
- Munkahelyi szám
- Privát szám
- Város
- Előfizetés (Ft)

### Alapműveletek

- 📥 Adatok felvétele
- 🗑️ Adatok törlése
- 📄 Listázás

> STL tárolók használata nem megengedett.

---

## 🛠️ Feladatspecifikáció

Parancssoros alkalmazás, amely képes fájlból betölteni, logolni és kezelni bejegyzéseket:

- Szöveges fájl: `source.txt`
- Visszaállítás: `source_backup.txt`
- Naplózás: `.log` fájl időbélyeggel
- Hibás inputok kezelése

---

## 📋 Pontosított feladatspecifikáció

### Osztályok

- **Ember** – név, becenév
- **Telefon** – munkahelyi és privát szám
- **Bejegyzes** – irányítószám, előfizetés
- **Telefonszotar** – bejegyzések tárolása és műveletek
- **UI** – felhasználói interfész, inputkezelés

---

## ⚙️ Algoritmusok és függvények

Néhány fontosabb:

- `getX()`, `setX()`
- `addBejegyzes()`, `bejTorles()`, `modosit()`
- `feltoltesTelefonkonyv()`, `factoryReset()`
- `osszeBej()`, `rendez()`
- `Telefonkonyvkereses()`, `lin_keres()`
- `clearScreen()`, `menu()`, `log()`, `ido()`
- `bejegyzesBE()`, `bejegyzesKI()`, `bejegyzesMOD()`
- `kereses()`

---

## 🖥️ A program kezelőfelülete

A felhasználó az alábbi menüpontokból választhat:

1. Bejegyzés hozzáadása  
2. Bejegyzés törlése  
3. Bejegyzés módosítása  
4. Bejegyzések listázása  
5. Keresés  
6. Kilépés

---

## 🔧 A program főbb funkciói

### ➕ Bejegyzés hozzáadása
Felhasználó által megadott új bejegyzés mentése.

### ❌ Bejegyzés törlése
Sorszám alapján történő bejegyzéstörlés.

### ✏️ Bejegyzés módosítása
Meglévő bejegyzés lecserélése új adatokkal.

### 📄 Telefonkönyv megtekintése
Összes bejegyzés listázása a képernyőn.

### 🔍 Keresés
Vezetéknév vagy más adat alapján keresés.

### 🚪 Kilépés
Adatok mentése, program kilépése.

---

## 🚀 Futtatás

### 💻 Ajánlott környezet

- Ékezeteket támogató terminál
- ASCII karaktermegjelenítés

### 🔧 Parancs

```bash
g++ -o program main.cpp cpp/*.cpp -DMEMTRACE -Wall -Werror
./program
```

---

## 💬 Megjegyzés

Ez a házi feladat célja, hogy gyakorlatban is alkalmazza az objektumorientált tervezést, fájlkezelést, hibakezelést és a modularizált programozást — STL nélkül.

---

**Készítette: RobiiHUN · 📆 2024.05.18 · ❤️ C++**
