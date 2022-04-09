#include <stdio.h>
#include <stdlib.h>

// FUNCKJE SZACHOWNICA: Wyświetla planszę do gry
void wyswietlSzachownice(int* szachownica[], int wielkosc) {
    printf("Szachownica (%d na %d): \n\n", wielkosc, wielkosc); // wyświetlenie szachownicy
    for (int i = 0; i < wielkosc; i++)  // petla tworza szachownice o wielkosci podanej przez uzytkownika
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
int wykonajRuch(int* szachownica[], int x, int y, int *nx, int *ny, int wariant) {
    switch (wariant)
    {
    case 0:
        *nx = x+1; // przesuniecie o pozycje w prawo 
        *ny = y+2; // przesuniecie o dwie pozycje do gory
        break;
    case 1:
        *nx = x+2; // przesuniecie o dwie pozycje w prawo   
        *ny = y+1; // przesunicie o dwie pozycje do gory
        break;
    case 2:
        *nx = x+2;  // przesuniecie o dwie pozycje w prawo
        *ny = y-1; // przesuniecie o jedna pozycje w dol
        break;
    case 3:
        *nx = x+1;  // przesuniecie o jedna pozycje w prawo
        *ny = y-2;  // przesuniecie o dwie pozycje w dol
        break;
    case 4:
        *nx = x-1;  // przesunicie o jedna pozycje w lewo   
        *ny = y-2;  // przesuniecie o dwie pozycje w dol
        break;
    case 5:
        *nx = x-2; // przesuniecie o dwie pozycje w lewo
        *ny = y-1; // przesunicie o jedna pozycje w dol 
        break;
    case 6:
        *nx = x-2; // przesuniecie o dwie pozycje w lewo
        *ny = y+1; // przesuniecie o jedna pozycje w gore
        break;
    case 7:
        *nx = x-1; // przesuniecie o jedna pozycje w lewo   
        *ny = y+2; // przesuniecie o dwie pozycje w gore
        break;
    }
    return 0;
}
// ustawia pozycję konika na szachownicy
void ustawPozycje(int* szachownica[], int wielkosc, int *x, int *y, int *ktory, int wariant) {
    int nx, ny;

    if (sprawdzRuch(szachownica, wielkosc, *x, *y, nx, ny, wariant) == 0)
    {  
        szachownica[*y][*x] = ktory;
        wykonajRuch(szachownica, *x, *y, &nx, &ny, wariant); // wykonuje posuniecie konika podany przez uzytkownika
        ustawNaSzachownicy(szachownica, nx, ny); // ustawia na szachownicy konika
        wyswietlSzachownice(szachownica, wielkosc); // wyswietla szachownice o wielkosci podanej przez uzytkownika
        *ktory++;
    } else {
        printf("Ruch niemozliwy!\n\n"); // pokazanie, ze ustawienie jest niemozliwe do wykonania
    }
}

int main()
{
    int wybor, wielkosc=0, ruch=-1, licznik=1;
    int x; // pozycja na osi x
    int y; // pozycja na osi y
    printf("Menu Wyboru\n\n");

    do{
        printf("1. Rozmiar szachownicy\n");
        printf("2. Pozycja konika\n");
        printf("3. Ruch\n");
        printf("4. Wyjscie\n\n");
        printf("Wybierz: ");
        scanf("%d",&wybor);

        switch (wybor)
        {
            case 1:
                // SZACHOWNICA (wygląd)
                printf("Podaj wielkosc szachownicy: ");
                scanf("%d", &wielkosc);
                int szachownica[wielkosc][wielkosc]; // szachownica
                int* szachownicaWSK[wielkosc]; // tablica wskaznikow (uzytkowa)
                for (int i = 0; i < wielkosc; i++) {
                szachownicaWSK[i]= szachownica[i];  
                }
                wyczyscSzachownice(szachownicaWSK, wielkosc);
                wyswietlSzachownice(szachownicaWSK, wielkosc);
                break;
            case 2:
                wpiszPozycje(&x,&y, wielkosc);
                ustawNaSzachownicy(szachownicaWSK, x, y);
                wyswietlSzachownice(szachownicaWSK, wielkosc);//pokazuje widok szachowncy
                break;
            case 3:
                while(ruch<0 || ruch>=8){
                printf("Wybierz ruch (od 0 do 7): ");
                scanf("%d",&ruch);
                if (ruch<0 || ruch>=8){
                    printf("Bledny ruch!");
                }
                }
                ustawPozycje(szachownicaWSK, wielkosc, &x, &y, &licznik, ruch);// ustawienie konika na szchownicy
                break;
            case 4: printf("\nOpuszczono program\n");
                break;

            default:printf("\nWybrano zly numer!\n\n");
        }

    } while(wybor != 4);


    /* SZACHOWNICA (wygląd)
    //int wielkosc; // wielkosc szachownicy
    //printf("Podaj wielkosc szachownicy: ");
    //scanf("%d", &wielkosc);
    //int szachownica[wielkosc][wielkosc]; // szachownica
    
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

    wyswietlSzachownice(szachownicaWSK, wielkosc);//pokazuje widok szachowncy
    
    ustawPozycje(szachownicaWSK, wielkosc, &x, &y, 1, 2);// ustawienie konika na szchownicy
*/
    return 0;
}