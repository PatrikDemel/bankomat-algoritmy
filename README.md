# 💸 Bankomat

- **Autor:** Patrik Demel
- **Jazyk:** C++
- **Typ aplikace:** Konzolová aplikace
- **Předmět:** Algoritmy a programování

## Zadání projektu

Cílem projektu je vytvořit konzolový program, který bude v cyklu přijímat od uživatele celé číslo v rozsahu 1-9999 a ke každému zadanému číslu:

- vypíše slovní vyjádření čísla v českém jazyce,
- vypíše nejoptimálnější rozklad částky na bankovky a mince.

Program musí:

- kontrolovat správnost vstupu,
- umožňit opakované zadávaní čísel,
- umožnit ukončení programu zadáním čísla 0,
- používat minimální množství knihoven,
- být přehledně strukturován do funkcí.

## Funkční specifikace

### Vstup

- celé číslo v rozsahu 1-9999
- číslo 0 ukončí program
- nečíselný nebo neplatný výstup je ošetřen chybovou hláškou

### Výstup

- slovní vyjádření zadaného čísla (např. 145 → `stočtyřicetpět`)
- optimální vyjádření rozklad částky pomocí bankovek a mincí (např. 145 → `1x100, 2x20, 1x5`)
- bankovky: `100, 200, 500, 1000, 2000, 5000 Kč`
- mince: `1, 2, 5, 10, 20, 50 Kč`

## Struktura programu

Program je rozdělen do následujících částí:

- `main()` - vstupní bod programu
- `hlavniMenu()` - řízení běhu programu a práce se vstupem
- `vypisCisloSlovy(int cislo)` - převod čísla na slovní vyjádření
- `rozkladBankovek(int cislo)` - rozklad částky na bankovky a mince

## Popis funkcí

### main()

**Účel:** Spouští hlavní logiku programu.

**Popis činnosti:** Funkce volá `hlavniMenu()`, která zajišťuje celý běh aplikace. Po ukončení menu se ukončí i hlavní funkce.

![Vývojový diagram funkce main()](https://raw.githubusercontent.com/PatrikDemel/bankomat-algoritmy/refs/heads/main/vyvojove%20diagramy/main.png)

### hlavniMenu()

**Účel:** Zajišťuje komunikaci s uživatelem, načítání vstupu, jeho validaci a řízení programu.

**Hlavní kroky:**

- vypíše výzvu k zadání čísla,
- načte vstup pomocí `cin`,
- ověří, zda byl zadán platný číselný vstup,
- kontroluje rozsah hodnoty (1-9999),
- při zadání `0` ukončí program,
- při platném vstupu volá další funkce programu.

**Ošetření chyb:**

- nečíselný vstup (`cin.fail()`),
- číslo mimo povolený rozsah.

**Popis činnosti:** Funkce volá `hlavniMenu()`, která zajišťuje celý běh aplikace. Po ukončení menu se ukončí i hlavní funkce.

![Vývojový diagram funkce hlavniMenu()](https://raw.githubusercontent.com/PatrikDemel/bankomat-algoritmy/refs/heads/main/vyvojove%20diagramy/hlavniMenu.png)

### vypisCisloSlovy(int cislo)

**Účel:** Převede zadané číslo na jeho slovní vyjádření v českém jazyce.

**Použité principy:**

- pole řetězců pro:
  - jednotky a čísla 1-19,
  - desítky,
  - stovky,
  - tisíce
- postupný rozklad čísla na jednotlivé řady: tisíce → stovky → desítky → jednotky

**Výstup:** Slovní vyjádření čísla bez mezer (např. 232 → `dvěstětřicetdva`).

![Vývojový diagram funkce vypisCisloSlovy()](https://raw.githubusercontent.com/PatrikDemel/bankomat-algoritmy/refs/heads/main/vyvojove%20diagramy/vypisSlovy.png)

#### rozkladBankovek(int cislo)

**Účel:** Vypočítá a vypíše nejoptimálnější rozklad částky na bankovky a mince.

**Použitý algoritmus:** Greedy algoritmus - postupné dělení částky od nejvyšší hodnoty bankovky/mince k nejnižší.

**Použité hodnoty:** `{5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1}`

**Výstup:** Počet jednotlivých bankovek a mincí ve formátu: `1x100 + 2x20 + 3x1`

![Vývojový diagram funkce vypisBankovek()](https://raw.githubusercontent.com/PatrikDemel/bankomat-algoritmy/refs/heads/main/vyvojove%20diagramy/vypisBankovek.png)

## Ukázka běhu programu

```
>> Zadejte celé číslo v rozpětí 1-9999 (0 pro ukončení programu): 145
Slovní vyjádření : stočtyřicetpět
Rozklad na bankovky: 1x100 + 2x20 + 1x5
```
