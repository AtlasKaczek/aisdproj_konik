#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"
/// Funckje szachownica
/** 
* Funckja wyświetla szachownię, która została podana przez użytkownika.
*/
// FUNCKJE SZACHOWNICA: Wyświetla planszę do gry
void wyswietlSzachownice(int* szachownica[], int wielkosc) {
    printf("Szachownica (%d na %d): \n\n", wielkosc, wielkosc); // wyświetlenie szachownicy
    for (int i = 0; i < wielkosc; i++)  // petla tworza szachownice o wielkosci podanej przez uzytkownika
        {
        for (int j = 0; j < wielkosc; j++)
        {
            if(szachownica[i][j] == -1) {
                printf(" K");
            }
            else if (szachownica[i][j] == 0) {
                printf(" _");
            } 
            else {
                printf(" %d", szachownica[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
/// Funkcja wyczyść szchownicę 
/**
* Funckja zeruje wszystkie miejsca na szachownicy 
*/
// funckja zeruje wszystkie miejsca szachownicy: plansza jest pust. 
void wyczyscSzachownice(int* szachownica[], int wielkosc) {
    for (int i = 0; i < wielkosc; i++)
    {
        for (int j = 0; j < wielkosc; j++)
        {
            szachownica[i][j] = 0;
        }
    }
    
}
/// Funkcja konik 
/**
* Funkcja wczytuje z klawiatury użytkownika dane jakie podał,
* Następnie podaną pozycję przez użytkownika przekazuje do programu
* Konik zostaje ustawiony na pozycji 
*/
// FUNKCJE KONIK: Funkcja odpowiadająca za wczytanie pozycji konika podanej przez użytkownika
void wpiszPozycje(int *x, int *y, int wielkosc) {
    do {
        printf("Podaj pozycje konika\nx: "); //wyswietla zapytanie dotyczące miejsca startu konika
        scanf(" %d", x);             // wczytanie pozycji podanej przez użytkownika
        printf("y: ");                  
        scanf(" %d", y);
        if (!(*x>=0 && *x<wielkosc && *y>=0 && *y<wielkosc))    // wyswietleneie bledu z braku mozliwosci ruchu 
        {
            printf("Poza szachownica!\n");  
        }
        
    } while (!(*x>=0 && *x<wielkosc && *y>=0 && *y<wielkosc));
    printf("\n");
}
/// Ustaw na szachownicy 
/* 
* Jest to funckja pomocnicza do funckji wyświetl, ustawia na danej pozycji szachownicy wartość -1, która jest wyświetlana jako funckaj k.
*/
// fuknkcja wybraną pozycje na szachwoniy

void ustawNaSzachownicy(int* szachownica[], int x, int y) {
    szachownica[y][x] = -1;
}
/// Sprawdź pozycję
/**
* pozycja podana przez użytkownika jest sprawdzana za pomocą komendy if, która podstawia do poniższych możliwości
* W momencie gdy dane podane przez użytkownika nie zgadzają się, zwracana jest informacja o błędzie. 
*/
// funckajca sprawdza czy ruch konika jest możliwy i zgodny z zasadmi.
int sprawdzRuch(int* szachownica[], int wielkosc, int x, int y, int nx, int ny, int wariant) {
    
    switch (wariant)
    {
    case 0:
        nx = x+1;     // sprawdza czy ruch w prawo jest mozliwy 
        ny = y+2;       // sprawdza czy dwa ruchu do gory sa mozliwe
        break;
    case 1:
        nx = x+2;   // sprawda czy dwa ruchy w prawo sa mozliwe 
        ny = y+1;   // sprawdza czy ruch do gory jest mozliwy 
        break;
    case 2:
        nx = x+2;   // sprawdza czy dwa ruchy w prawo sa mozliwe
        ny = y-1;   // sprawdza czy ruch w dol jest mozliwy 
        break;
    case 3:
        nx = x+1; // sprawdza czy ruch w prawo jest mozliwy 
        ny = y-2;  // sprawdza czy dwa ruchy w dol sa molziwe
        break;
    case 4:
        nx = x-1;   // sprawdza czy ruch w lewo jest mozliwy
        ny = y-2;  // sprawdza czy dwa ruchy w dol sa mozliwe
        break;
    case 5:
        nx = x-2; // sprawdza czy dwa ruchy w lewo sa mozliwe
        ny = y-1;   // sprawdza czy ruch w dol jest mozliwy 
        break;
    case 6:
        nx = x-2; //sprawdza czy dwa ruchy w lewo sa mozliwe
        ny = y+1; // sprawda czy ruch w gore jest mozliwy
        break;
    case 7:
        nx = x-1; //sprawdza czy ruch w lewo jest mozliwy 
        ny = y+2; // sprawdza czy dwa ruchy w gore sa mozlwie
        break; 
    }
    if(nx>=0 && nx<wielkosc && ny>=0 && ny<wielkosc && szachownica[ny][nx]==0) {
        return 0; // Prawda
    }
    return 1; // Falsz
}
/// Wykonaj ruch 
/** 
* Za pomocą wcześniej podanych danych przez użytkownika, program wykonuje możliwe ruchy. 
* Wykonane ruchy zawsze są zgodne z jednym z 8 założeń podanych w kodzie. 
*/ 
int wykonajRuch(int* szachownica[], int *x, int *y, int *nx, int *ny, int wariant) {
    switch (wariant)
    {
    case 0:
        *nx = *x+1; // przesuniecie o pozycje w prawo 
        *ny = *y+2; // przesuniecie o dwie pozycje do gory
        break;
    case 1:
        *nx = *x+2; // przesuniecie o dwie pozycje w prawo   
        *ny = *y+1; // przesunicie o dwie pozycje do gory
        break;
    case 2:
        *nx = *x+2;  // przesuniecie o dwie pozycje w prawo
        *ny = *y-1; // przesuniecie o jedna pozycje w dol
        break;
    case 3:
        *nx = *x+1;  // przesuniecie o jedna pozycje w prawo
        *ny = *y-2;  // przesuniecie o dwie pozycje w dol
        break;
    case 4:
        *nx = *x-1;  // przesunicie o jedna pozycje w lewo   
        *ny = *y-2;  // przesuniecie o dwie pozycje w dol
        break;
    case 5:
        *nx = *x-2; // przesuniecie o dwie pozycje w lewo
        *ny = *y-1; // przesunicie o jedna pozycje w dol 
        break;
    case 6:
        *nx = *x-2; // przesuniecie o dwie pozycje w lewo
        *ny = *y+1; // przesuniecie o jedna pozycje w gore
        break;
    case 7:
        *nx = *x-1; // przesuniecie o jedna pozycje w lewo   
        *ny = *y+2; // przesuniecie o dwie pozycje w gore
        break;
    }
    *x = *nx;
    *y = *ny;
    return 0;
}
/// Ustaw Pozycję 
/**
* Program ustawia konika na pozycji, która została wcześniej podana przez użytkownika i sprawdzona przez funkcję "Sprawdź ruch"
*/
// ustawia pozycję konika na szachownicy
void ustawPozycje(int* szachownica[], int wielkosc, int *x, int *y, int *ktory, int wariant) {
    int nx, ny;

    if (sprawdzRuch(szachownica, wielkosc, *x, *y, nx, ny, wariant) == 0)
    {  
        szachownica[*y][*x] = *ktory;
        wykonajRuch(szachownica, x, y, &nx, &ny, wariant); // wykonuje posuniecie konika podany przez uzytkownika
        ustawNaSzachownicy(szachownica, nx, ny); // ustawia na szachownicy konika
        wyswietlSzachownice(szachownica, wielkosc); // wyswietla szachownice o wielkosci podanej przez uzytkownika
        *ktory = *ktory + 1;
    } else {
        printf("Ruch niemozliwy!\n\n"); // pokazanie, ze ustawienie jest niemozliwe do wykonania
    }
}
/// Symuluj 
/** 
* Jest implementacja algorytmu rozwiązującego problem konika szachowego.
* Program sprawdza wszystkie przejścia konika, aby móc wyświetlić końcową tablicę, która jest zapełniona ruchami .
*/
int symuluj(int* szachownica[], int wielkosc, int *x, int *y, int ktory) {

    int nx, ny = 0;

    szachownica[*y][*x] = ktory;

    if (ktory == wielkosc*wielkosc)
    {
        wyswietlSzachownice(szachownica, wielkosc);
        return 0;
    } else {
        for (int i = 0; i < 8; i++)
        {
            if (sprawdzRuch(szachownica, wielkosc, *x, *y, nx, ny, i) == 0)
            {
                switch (i) {
                case 0:
                    nx = *x+1; // przesuniecie o pozycje w prawo 
                    ny = *y+2; // przesuniecie o dwie pozycje do gory
                    break;
                case 1:
                    nx = *x+2; // przesuniecie o dwie pozycje w prawo   
                    ny = *y+1; // przesunicie o dwie pozycje do gory
                    break;
                case 2:
                    nx = *x+2;  // przesuniecie o dwie pozycje w prawo
                    ny = *y-1; // przesuniecie o jedna pozycje w dol
                    break;
                case 3:
                    nx = *x+1;  // przesuniecie o jedna pozycje w prawo
                    ny = *y-2;  // przesuniecie o dwie pozycje w dol
                    break;
                case 4:
                    nx = *x-1;  // przesunicie o jedna pozycje w lewo   
                    ny = *y-2;  // przesuniecie o dwie pozycje w dol
                    break;
                case 5:
                    nx = *x-2; // przesuniecie o dwie pozycje w lewo
                    ny = *y-1; // przesunicie o jedna pozycje w dol 
                    break;
                case 6:
                    nx = *x-2; // przesuniecie o dwie pozycje w lewo
                    ny = *y+1; // przesuniecie o jedna pozycje w gore
                    break;
                case 7:
                    nx = *x-1; // przesuniecie o jedna pozycje w lewo   
                    ny = *y+2; // przesuniecie o dwie pozycje w gore
                    break;
                }
                if (symuluj(szachownica, wielkosc, &nx, &ny, ktory+1) == 0)
                {
                    return 0;
                }
                
            }
            
        }
        szachownica[*y][*x] = 0;
        
    }

    return 1;
    
}