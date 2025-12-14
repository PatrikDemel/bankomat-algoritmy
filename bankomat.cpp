/***********************************************************************************************
 ALGORITMY A PROGRAMOVÁNÍ - PROJEKT BANKOMAT
 Autor: Patrik Demel

 Vstup: číslo od 1 do 9999
 Výstup: slovní reprezentace čísla a jeho rozložení v bankovkách a mincích

 Program, který v cyklu přijímá od uživatele čísla a ke každému vypisuje jeho slovní vyjádření
 a nejoptimálnější rozklad na bankovky o hodnotách 100, 200, 500, 1000, 5000 Kč a mincí o
 hodnotách 1,2,5,10,20, a 50 Kč.
***********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

// Deklarace funkcí
int hlavniMenu();
void vypisCisloSlovy(int num);

/* ========================================================================== */
/*  HLAVNÍ FUNKCE                                                             */
/* ========================================================================== */
int main()
{
    hlavniMenu();

    return 0;
}

/* ========================================================================== */
/*  FUNKCE PRO ZAJIŠTĚNÍ VSTUPU                                               */
/* ========================================================================== */
int hlavniMenu()
{
    /* --- Texty pro komunikaci s uživatelem --- */
    const string ERROR_CISLO =
        "Chyba: povolene je pouze cele cislo.";
    const string ERROR_ROZSAH =
        "Chyba: povolene je pouze cele cislo v rozpeti 1-9999";
    const string TEXT_VYZVA =
        ">> Zadejte cele cislo v rozpeti 1-9999 (0 pro ukonceni programu): ";

    /* --- Hlavní nekonečná smyčka programu --- */
    while (true)
    {
        int cislo;

        /* --- Načtení vstupu od uživatele --- */
        cout << endl
             << TEXT_VYZVA;
        cin >> cislo;

        /* --- Kontrola, zda byl vstup číselný --- */
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << ERROR_CISLO << endl
                 << endl;
            continue;
        }

        /* --- Ukončení programu --- */
        if (cislo == 0)
        {
            return 0;
        }

        /* --- Kontrola povoleného rozsahu --- */
        if (cislo < 1 || cislo > 9999)
        {
            cout << ERROR_ROZSAH << endl
                 << endl;
            continue;
        }

        /* --- Platný vstup – zpracování čísla --- */
        vypisCisloSlovy(cislo);
    }
}

/* ========================================================================== */
/*  FUNKCE PRO SLOVNÍ VYJÁDŘENÍ ČÍSLA                                         */
/* ========================================================================== */
void vypisCisloSlovy(int cislo)
{
    /* --- Seznam slovních vyjádření čísel --- */
    string seznamCisla[] = {"jedna", "dva", "tři", "čtyři", "pět", "šest", "sedm", "osm", "devět", "deset", "jedenáct", "dvanáct", "třináct", "čtrnáct", "patnáct", "šestnáct", "sedmnáct", "osmnáct", "devatenáct"};
    string seznamDesitky[] = {"deset", "dvacet", "třicet", "čtyřicet", "padesát", "šedesát", "sedmdesát", "osmdesát", "devadesát"};
    string seznamStovky[] = {"sto", "dvěstě", "třista", "čtyřista", "pětset", "šestset", "sedmset", "osmset", "devětset"};
    string seznamTisice[] = {"tisíc", "dvatisíce", "třitisíce", "čtyřitisíce", "pěttisíc", "šesttisíc", "sedmtisíc", "osmtisíc", "devěttisíc"};

    /* --- Příprava proměnných --- */
    string vysledek;
    int puvodniCislo = cislo;

    /* --- Zpracování tisíců --- */
    if (cislo >= 1000)
    {
        vysledek += seznamTisice[cislo / 1000 - 1];
        cislo %= 1000;
    }

    /* --- Zpracování stovek --- */
    if (cislo >= 100)
    {
        vysledek += seznamStovky[cislo / 100 - 1];
        cislo %= 100;
    }

    /* --- Zpracování desítek --- */
    if (cislo >= 20)
    {
        vysledek += seznamDesitky[cislo / 10 - 1];
        cislo %= 10;
    }

    /* --- Zpracování jednotek --- */
    if (cislo >= 1)
    {
        vysledek += seznamCisla[cislo - 1];
    }

    /* --- Výpis výsledku --- */
    cout << "Slovni vyjadreni cisla " << puvodniCislo
         << ": " << vysledek << endl
         << endl;
}
