#include <stdio.h>
#include <stdlib.h>

const char* mnozenie_pisemne(char arr[], char barr[]){
    int carr[100] = {0}; //tablica wypelniona zerami
    int i,l,j,key,A,B,C;
    for(i = 0; arr[i] != '\0'; i++){}
    A = i;
    for(j = 0; barr[j] != '\0'; j++){}
    B = j;
    for(int a = 0; a <= ((A-1)/2); a++){ //od tylu
        key = arr[a];
        arr[a] = arr[A - a - 1];
        arr[A - a - 1] = key;}
    for(int b = 0; b <= (B-1)/2; b++){
        key = barr[b];
        barr[b] = barr[B - b -1];
        barr[B - b - 1] = key;}
    for(i = 0; i < A; i++){ //dopisywanie do wyniku
        for(j = 0; j < B; j++){
            C = ((int)arr[i] - 48) * ((int)barr[j] - 48);
            key = i + j;
            carr[key] += C;
            C = carr[key];
            for(l = 0; carr[key + l] >= 10; l++){
                carr[key + l] = carr[key + l] % 10;
                carr[key + l + 1] = C / 10 + carr[key + l + 1];
                C = carr[key + l + 1];}}}

    for(i = 99; carr[i] == 0; i--){}

    j = i + 1;

    for(int c = 0; c <= ((j-1)/2); c++){
        key = carr[c];
        carr[c] = carr[j - c - 1];
        carr[j - c - 1] = key;
    }

    char* wynik = (char*)malloc(j + sizeof(char));

    for(int d = 0; d < j; d++){
        wynik[d] = (char)(carr[d] + 48);
    }
    wynik[j] = '\0';
    return wynik;
}

int main() {
    int n, dlugosc;
    printf("Wpisz liczbe n:");
    scanf("%d", &n);
    char warunek_poczatkowy[] = "1";
    char* silnia;
    char* terazniejsza;
    char* poprzednia=warunek_poczatkowy;
    char* str;
    for(int i = 1; i <= n; i++){
        dlugosc = snprintf(NULL, 0, "%d", i );
        str = malloc(dlugosc + 1 );
        snprintf(str, dlugosc + 1, "%d", i ); //zamiana inta na string
        terazniejsza = str;
        silnia = mnozenie_pisemne(poprzednia, terazniejsza);
        poprzednia = silnia;}
    free(str);
    printf("%s", silnia);
    return 0;
}