#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int N1, N2;

void sort(int n, int tab[]) {
    int t;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tab[j] < tab[i]) {
                t = tab[i];
                tab[i] = tab[j];
                tab[j] = t;
            }
        }
    }
}

int merge(const int tab1[], int n1, const int tab2[], int n2){
    int T[11];
    for(int i=0; i<10; i++){
        T[i] = 0;
    }
    for(int c=0; c<n1; c++){
        T[tab1[c]] = 1;
    }
    for(int a=0; a<n2; a++){
        T[tab2[a]] = 1;
    }
    int n3 = 0;
    for(int i=0; i<10; i++){
        n3 += T[i];
    }
    int T3[n3];
    for(int i=0, j=0; i<10; i++){
        if(T[i] == 1){
            T3[j] = T[i];
            j ++;
        }
    }
    return n3;
}

int main() {

    srand(time(NULL));
    printf("Podaj rozmiar tablicy t1:\n");
    scanf("%d", &N1);
    int t1[N1];
    for(int i=0;i<N1;i++){
        t1[i]= rand() % 11;
    }
    sort(N1, t1);
    for(int a=0;a<N1;a++){
        printf("%d ", t1[a]);
    }
    printf("Podaj rozmiar tablicy t2:\n");
    scanf("%d", &N2);
    int t2[N2];
    for(int a=0;a<N2;a++){
        t2[a]= rand() % 11;
    }
    sort(N2, t2);
    for(int a=0;a<N2;a++){
        printf("%d ", t2[a]);
    }
    printf("\nDlugosc ostatecznej tablicy wynosi: %d", merge(t1,N1,t2,N2));
    return 0;
}
