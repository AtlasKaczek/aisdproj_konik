#ifndef FUNKCJE
#define FUNKCJE
/// Plik Header 
/**
* Plik ten służy do importowania funckji z innych plików, do pliku docelowego.  
*/

void wyswietlSzachownice(int* szachownica[], int wielkosc);

void wyczyscSzachownice(int* szachownica[], int wielkosc);

void wpiszPozycje(int *x, int *y, int wielkosc);

void ustawNaSzachownicy(int* szachownica[], int x, int y);

int sprawdzRuch(int* szachownica[], int wielkosc, int x, int y, int nx, int ny, int wariant);

int wykonajRuch(int* szachownica[], int *x, int *y, int *nx, int *ny, int wariant);

void ustawPozycje(int* szachownica[], int wielkosc, int *x, int *y, int *ktory, int wariant);

int symuluj(int* szachownica[], int wielkosc, int *x, int *y, int ktory);

#endif