#include <stdio.h>
#include <stdlib.h>


// FUNCKJE SZACHOWNICA
void wyswietlSzachownice(int* szachownica[], int wielkosc) {
    printf("Szachownica (%d na %d): \n\n", wielkosc, wielkosc);
    for (int i = 0; i < wielkosc; i++)
    {
        for (int j = 0; j < wielkosc; j++)
        {
            if(szachownica[i][j] == -1) {
                printf(" K");
            } else {
                printf(" %d", szachownica[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void wyczyscSzachownice(int* szachownica[], int wielkosc) {
    for (int i = 0; i < wielkosc; i++)
    {
        for (int j = 0; j < wielkosc; j++)
        {
            szachownica[i][j] = 0;
        }
    }
    
}

// FUNKCJE KONIK
void wpiszPozycje(int *x, int *y, int wielkosc) {
    do {
        printf("Podaj pozycje konika\nx: ");
        scanf(" %d", x);
        printf("y: ");
        scanf(" %d", y);
        if (!(*x>=0 && *x<wielkosc && *y>=0 && *y<wielkosc))
        {
            printf("Poza szachownica!\n");
        }
        
    } while (!(*x>=0 && *x<wielkosc && *y>=0 && *y<wielkosc));
    printf("\n");
}

void ustawNaSzachownicy(int* szachownica[], int x, int y) {
    szachownica[y][x] = -1;
}

int main()
{
    // SZACHOWNICA
    int wielkosc; // wielkosc szachownicy
    printf("Podaj wielkosc szachownicy: ");
    scanf("%d", &wielkosc);
    int szachownica[wielkosc][wielkosc]; // szachownica
    
    int* szachownicaWSK[wielkosc]; // tablica wskaznikow (uzytkowa)
    for (int i = 0; i < wielkosc; i++) {
        szachownicaWSK[i]= szachownica[i];  
    }

    wyczyscSzachownice(szachownicaWSK, wielkosc);
    wyswietlSzachownice(szachownicaWSK, wielkosc);

    //POZYCJA KONIKA
    int x; // pozycja na osi x
    int y; // pozycja na osi y
    wpiszPozycje(&x,&y, wielkosc);
    ustawNaSzachownicy(szachownicaWSK, x, y);

    wyswietlSzachownice(szachownicaWSK, wielkosc);
    return 0;
}