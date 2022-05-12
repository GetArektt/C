//Dana jest tablica kwadratowa int t[N][N].
//Proszę napisać funkcję wypełniającą tablicę t liczbami naturalnymi po spirali.
#include <stdio.h>

int main() {
    int szerokosc, wysokosc, N, x = 1, kierunek = 1;
    printf("Podaj rozmiar kwadratowej tablicy:\n");
    scanf("%d", &N);
    if (N < 0) {
        printf("Error");
        return 0;
    }
    int arr[N][N];
    szerokosc = N, wysokosc = N;
    while (x <=
           N * N) {     //pętla trwająca tak długo, aż skończą nam się wszystkie możliwe wartości do wpisania do tablicy
        if (kierunek == 1) { //idziemy w prawo
            int i = N - wysokosc;
            for (int j = N - szerokosc; j < szerokosc; j++) {
                arr[i][j] = x;
                x += 1;
            }
            kierunek = 2;
            wysokosc -= 1; //zmiejszamy rozmiar tablicy do wpisania wartości
        }
        if (kierunek == 2) { //idziemy w dol
            int j = szerokosc - 1;
            for (int i = N - wysokosc; i <= wysokosc; i++) {
                arr[i][j] = x;
                x += 1;
            }
            kierunek = 3;
            szerokosc -= 1; //zmiejszamy rozmiar tablicy do wpisania wartości
        }
        if (kierunek == 3) { //idziemy w lewo
            int i = wysokosc;
            for (int j = szerokosc - 1; j >= N - szerokosc - 1; j -= 1) {
                arr[i][j] = x;
                x += 1;
            }
            kierunek = 4;
        }
        if (kierunek == 4) { //idziemy w gore
            int j = N - szerokosc - 1;
            for (int i = wysokosc - 1; i >= N - wysokosc; i -= 1) {
                arr[i][j] = x;
                x += 1;
            }
            kierunek = 1;
        }
    }

    for (int i = 0; i < N; i++) { //wypisywanie tablicy
        printf("\n");
        for (int j = 0; j < N; j++) {
            printf("%3d ", arr[i][j]);
        }

    }
    return 0;
}
