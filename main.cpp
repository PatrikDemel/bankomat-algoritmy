/******************************************************************************
 ALGORITMY A PROGRAMOVÁNÍ - PROJEKT BANKOMAT
 Autor: Patrik Demel

 Program, který v cyklu přijímá od uživatele čísla a ke každému vypisuje
 jeho slovní vyjádření a nejoptimálnější rozklad na bankovky o hodnotách 100,
 200, 500, 1000, 5000 Kč a mincí o hodnotách 1,2,5,10,20, a 50 Kč.
******************************************************************************/

// Import knihoven a nastavení jmenného prostoru
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Deklarace funkcí
int hlavniMenu();

int main()
{
    // Pole se slovním vyjádřením čísel 1-19
    string seznamCisla[] = {"jedna", "dva", "tři", "čtyři", "pět", "šest", "sedm", "osm", "devět", "deset", "jedenáct", "dvanáct", "třináct", "čtrnáct", "patnáct", "šesenáct", "sedmnáct", "osmnáct", "devatenáct"};

    // Pole se slovním vyjádřením desítek
    string seznamDesitky[] = {"deset", "dvacet", "třicet", "čtyřicet", "padesát", "šedesát", "sedmdesát", "osmdesát", "devadesát"};

    // Pole se slovním vyjádřením stovek
    string seznamStovky[] = {"sto", "dvěstě", "třista", "čtyřista", "pětset", "šestset", "sedmset", "osmset", "devětset"};

    // Pole se slovním vyjádřením tisíců
    string seznamTisice[] = {"tisíc", "dvatisíce", "třitisíce", "čtyřitisíce", "pěttisíc", "šesttisíc", "sedmtisíc", "osmtisíc", "devěttisíc"};

    // Volání funkce hlavniMenu()
    hlavniMenu();

    return 0;
}

// Funkce zajišťující vstup od uživatele a jeho validaci
int hlavniMenu()
{
    // Texty chybových hlášek a výzev
    string pouzeCisloError = "Chyba: povolené je pouze celé číslo.";                              // Hláška pro nečíselný vstup
    string spatnyRozsahError = "Chyba: povolené je pouze celé číslo v rozpětí 1-9999";            // Hláška pro číslo mimo rozsah 1-9999
    string hlavniMenuText = ">> Zadejte celé číslo v rozpětí 1-9999 (0 pro ukončení programu): "; // Výzva pro zadání vstupu

    // Nekonečný cyklus - ukončí se pouze, pokud je ve vstupu zadána 0
    while (true)
    {
        int cislo;

        // Vypsání výzvy pro zadání čísla a následný pokus o uložení do proměnné cislo
        cout << endl
             << hlavniMenuText;
        cin >> cislo;

        // Kontrola, zda vstup byl číselný
        if (cin.fail())
        {
            cin.clear();            // Zrušení chybového stavu
            cin.ignore(1000, '\n'); // Vymazání zbytku špatného vstupu

            // Zobrazení chybové hlášky a návrat na začátek cyklu
            cout << pouzeCisloError << endl
                 << endl;
            continue;
        }

        // Ukončení programu při vsutpu 0
        else if (cislo == 0)
        {
            exit(0);
        }

        // Kontrola velikosti čísla
        else if (cislo < 1 || cislo > 9999)
        {
            cin.clear();            // Zrušení chybového stavu
            cin.ignore(1000, '\n'); // Vymazání zbytku špatného vstupu

            // Zobrazení chybové hlášky a návrat na začátek cyklu
            cout << spatnyRozsahError << endl
                 << endl;
            continue;
        }

        // Vstup je platné číslo
        else
        {
            // Navrácení hodnoty cislo a přerušení cyklu
            return cislo;
        }
    }
}