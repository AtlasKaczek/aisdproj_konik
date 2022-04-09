#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

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
// fuknkcja wybraną pozycje na szachwoniy
void ustawNaSzachownicy(int* szachownica[], int x, int y) {
    szachownica[y][x] = -1;
}
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
    if(nx>=0 && nx<wielkosc && ny>=0 && ny<wielkosc && szachownica[nx][ny]==0) {
        return 0; // Prawda
    }
    return 1; // Falsz
}
// funkcja rozpatrująca wszystie mozliwosci poruszania się konika szchowego po szchownicy.
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
