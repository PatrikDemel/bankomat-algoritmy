/***********************************************************************************************
 ALGORITMY A PROGRAMOVÁNÍ - PROJEKT BANKOMAT
 Autor: Patrik Demel

 Vstup: číslo od 1 do 9999
 Výstup: slovní reprezentace čísla a jeho rozložení v bankovkách a mincích

 Program, který v cyklu přijímá od uživatele čísla a ke každému vypisuje jeho slovní vyjádření
 a nejoptimálnější rozklad na bankovky a mince.
***********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/* --- Deklarace funkcí --- */
int hlavniMenu();
void vypisCisloSlovy(int cislo);
void rozkladBankovek(int cislo);

/* ========================================================================== */
/*  HLAVNÍ FUNKCE                                                             */
/* ========================================================================== */
int main()
{
    /* --- Spuštění hlavního menu programu --- */
    hlavniMenu();
    return 0;
}

/* ========================================================================== */
/*  FUNKCE PRO ZAJIŠTĚNÍ VSTUPU A ŘÍZENÍ PROGRAMU                              */
/* ========================================================================== */
int hlavniMenu()
{
    /* --- Texty pro komunikaci s uživatelem --- */
    const string ERROR_CISLO =
        "Chyba: povolené je pouze celé číslo.";
    const string ERROR_ROZSAH =
        "Chyba: povolené je pouze celé číslo v rozpětí 1-9999";
    const string TEXT_VYZVA =
        ">> Zadejte celé číslo v rozpětí 1-9999 (0 pro ukončení programu): ";

    /* --- Hlavní smyčka programu --- */
    while (true)
    {
        int cislo;

        /* --- Načtení vstupu od uživatele --- */
        cout << endl
             << TEXT_VYZVA;
        cin >> cislo;

        /* --- Kontrola číselného vstupu --- */
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
            cout << "Program ukončen.";
            return 0;
        }

        /* --- Kontrola povoleného rozsahu --- */
        if (cislo < 1 || cislo > 9999)
        {
            cout << ERROR_ROZSAH << endl
                 << endl;
            continue;
        }

        /* --- Zpracování platného vstupu --- */
        vypisCisloSlovy(cislo);
        rozkladBankovek(cislo);
    }
}

/* ========================================================================== */
/*  FUNKCE PRO SLOVNÍ VYJÁDŘENÍ ČÍSLA                                         */
/* ========================================================================== */
void vypisCisloSlovy(int cislo)
{
    /* --- Slovní reprezentace čísel --- */
    string seznamCisla[] = {"jedna", "dva", "tři", "čtyři", "pět", "šest", "sedm", "osm", "devět",
                            "deset", "jedenáct", "dvanáct", "třináct", "čtrnáct", "patnáct",
                            "šestnáct", "sedmnáct", "osmnáct", "devatenáct"};
    string seznamDesitky[] = {"deset", "dvacet", "třicet", "čtyřicet", "padesát",
                              "šedesát", "sedmdesát", "osmdesát", "devadesát"};
    string seznamStovky[] = {"sto", "dvěstě", "třista", "čtyřista", "pětset",
                             "šestset", "sedmset", "osmset", "devětset"};
    string seznamTisice[] = {"tisíc", "dvatisíce", "třitisíce", "čtyřitisíce",
                             "pěttisíc", "šesttisíc", "sedmtisíc", "osmtisíc", "devěttisíc"};

    /* --- Příprava proměnných --- */
    string vysledek;
    int puvodniCislo = cislo;

    /* --- Rozklad čísla na tisíce, stovky, desítky a jednotky --- */
    if (cislo >= 1000)
    {
        vysledek += seznamTisice[cislo / 1000 - 1];
        cislo %= 1000;
    }

    if (cislo >= 100)
    {
        vysledek += seznamStovky[cislo / 100 - 1];
        cislo %= 100;
    }

    if (cislo >= 20)
    {
        vysledek += seznamDesitky[cislo / 10 - 1];
        cislo %= 10;
    }

    if (cislo >= 1)
    {
        vysledek += seznamCisla[cislo - 1];
    }

    /* --- Výpis slovního vyjádření čísla --- */
    cout << "Slovní vyjádření "
         << ": " << vysledek << endl;
}

/* ========================================================================== */
/*  FUNKCE PRO ROZKLAD BANKOVEK                                               */
/* ========================================================================== */
void rozkladBankovek(int cislo)
{
    /* --- Hodnoty bankovek a mincí --- */
    int hodnoty[] = {5000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    bool prvni = true;

    /* --- Výpis rozkladu částky --- */
    cout << "Rozklad na bankovky: ";

    /* --- Postupný rozklad částky od nejvyšší hodnoty --- */
    for (int h : hodnoty)
    {
        int pocet = cislo / h;

        if (pocet > 0)
        {
            if (!prvni)
                cout << " + ";

            cout << pocet << "x" << h;
            cislo %= h;
            prvni = false;
        }
    }

    cout << endl
         << endl;
}
