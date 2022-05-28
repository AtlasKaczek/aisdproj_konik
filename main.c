#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funkcje.h"

int main()
{
    int wybor = -1, wielkosc=0, ruch=-1, licznik=1;
    int x; // pozycja na osi x
    int y; // pozycja na osi y

    clock_t start, end;

    // SZACHOWNICA (wygląd)
    printf("PROBLEM KONIKA SZACHOWEGO\nPodaj wielkosc szachownicy: ");
    scanf("%d", &wielkosc);
    int szachownica[wielkosc][wielkosc]; // szachownica
    int* szachownicaWSK[wielkosc]; // tablica wskaznikow (uzytkowa)
    for (int i = 0; i < wielkosc; i++) {
        szachownicaWSK[i]= szachownica[i];  
    }
    wyczyscSzachownice(szachownicaWSK, wielkosc);
    wyswietlSzachownice(szachownicaWSK, wielkosc);


    do{
        printf("Menu Wyboru\n\n1. Pozycja konika\n2. Ruch\n3. Wyswietl szachownice\n4. Wyczysc szachownice\n5. Symuluj\n0. Wyjdz\n\n");
        
        printf("Wybierz: ");
        scanf(" %d",&wybor);

        switch (wybor)
        {
            case 1:
                szachownica[y][x] = 0; // Podnosi konika
                wpiszPozycje(&x,&y, wielkosc);
                ustawNaSzachownicy(szachownicaWSK, x, y);
                wyswietlSzachownice(szachownicaWSK, wielkosc);//pokazuje widok szachowncy
                break;
            case 2:
                while(ruch<0 || ruch>=8){
                    printf("Wybierz ruch (od 0 do 7): ");
                    scanf("%d",&ruch);
                    if (ruch<0 || ruch>=8){
                     printf("Bledny ruch!\n");
                    }
                }
                ustawPozycje(szachownicaWSK, wielkosc, &x, &y, &licznik, ruch);// ustawienie konika na szchownicy
                ruch = -1;
                break;
            case 3:
                wyswietlSzachownice(szachownicaWSK, wielkosc);
                break;
            case 4:
                printf("Czyszczene szachownicy...\n\n");
                wyczyscSzachownice(szachownicaWSK, wielkosc);
                x = 0;
                y = 0;
                licznik = 1;
                wyswietlSzachownice(szachownicaWSK, wielkosc);
                break;
            case 5:
                start = clock();
                printf("Symuluje...\n\nWynik: \n");
                if (symuluj(szachownicaWSK, wielkosc, &x, &y, licznik) == 1)
                {
                    printf("    Brak wyniku :(\n\n");
                }
                end = clock();
                printf("Czas wykonania symulacji: %f [s]\n", ((double) (end - start)) / CLOCKS_PER_SEC);         
                break;
            case 0:
                printf("\nOpuszczono program\n");
                break;
            default:
                printf("\nWybrano zly numer!\n\n");
        }

    } while(wybor != 0);

    return 0;
}