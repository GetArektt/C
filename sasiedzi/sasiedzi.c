//Dana jest macierz kwadratowa F[n][n] wypełniona liczbami całkowitymi ze zbioru {0, 1}.
//Odległość między dwoma elementami tej macierzy definiujemy jako: d(F[i][j], F[i'][j']) = max (|i − i'|, |j − j'|). Proszę napisać program, który:
//Wczyta ze standardowego wejścia liczby n, r, oraz macierz F.
//Obliczy macierz W taką, że W[i][j] jest sumą wszystkich elementów F[i'][j'] macierzy F leżących w odległości co najwyżej r (r < n) od F[i][j],
//czyli takich, że d(F[i][j], F[i'][j']) ≤ r.
//Wypisze macierz W na standardowe wyjście.
//Wejście:
//W pierwszym wierszu standardowego wejścia znajdują się dwie dodatnie liczby całkowite: 2 ≤ n ≤ 100 i r < n.
//Każdy z kolejnych n wierszy zawiera po n liczb całkowitych ze zbioru {0, 1} stanowiących kolejny wiersz macierzy F.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand( time( NULL ) );
    int N=5, d=1;
    printf("Podaj wymiar tablicy i odległość oddzielone spacja\n");
//    scanf("%d %d", &N, &d);
//    int F[5][5]={{ 1,0,0,1,0},{0,0,1,1,0},{1,1,0,0,1},{1,1,1,0,0},{0,0,0,1,0} }, W[N][N];
//    for(int i=0;i<N;i++){ //wypelnianie macierzy F losowymi liczbami 0 lub 1
//        for(int j=0;j<N;j++){
//            F[i][j] = rand() % 2;
//        }
//    }
    int F[5][5], W[5][5];
    for(int i=0; i<5; i++)
            for(int j=0; j<5; j++) F[i][j]=1;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            W[i][j] = 0;
        }
    }

    for(int poz_i=0;poz_i<N;poz_i++){
        for(int poz_j=0;poz_j<N;poz_j++){ //przemieszczanie sie po macierzy
                for(int a=poz_i-d;a<=poz_i+d;a++){
                    for(int b=poz_j-d;b<=poz_j+d;b++){
                        if(a >= 0 && a < N){
                            if(b >= 0 && b < N){
                                W[poz_i][poz_j] += F[a][b];
                            }
                        }
                    }
                }
            }
        }



    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ", F[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(W[i][j]<10){
            printf("%d ", W[i][j]);}
            else printf("e ");
        }
        printf("\n");
    }
    return 0;
}
