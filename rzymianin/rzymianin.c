#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void do_arabskiej(int, int *, int);
int suma(char *, char *);
void do_rzymskiej(int, int *);

int main(void) {
    char liczba_1[15];
    char liczba_2[15];
    printf("Podaj liczby w postaci rzymskiej oddzielone spacja:");
    scanf("%s %s", &liczba_1, &liczba_2);

    int rzymska_suma = suma(liczba_1, liczba_2);
    printf("Suma wynosi: %d\n", rzymska_suma);

    int length = (int)floor(log10((float)rzymska_suma)) + 1;
    int T[length];

    do_rzymskiej(rzymska_suma, T);
    do_arabskiej(rzymska_suma, T, length);
    return 0;
}

int suma(char *X, char *Y) {
    int len_liczba_1 = strlen(X);
    int len_liczba_2 = strlen(Y);
    int i = 0, j = 0, x=0, y=0;
    int num_x[len_liczba_1], num_y[len_liczba_2];
    for (j; j < len_liczba_1; j++) {
        if (X[j] == 'I') num_x[j] = 1;
        else if (X[j] == 'V') num_x[j] = 5;
        else if (X[j] == 'X') num_x[j] = 10;
        else if (X[j] == 'L') num_x[j] = 50;
        else if (X[j] == 'C') num_x[j] = 100;
        else if (X[j] == 'D') num_x[j] = 500;
        else if (X[j] == 'M') num_x[j] = 1000;
    }
    j = 0;
    for (j; j < len_liczba_2; j++) {
        if (Y[j] == 'I') num_y[j] = 1;
        else if (Y[j] == 'V') num_y[j] = 5;
        else if (Y[j] == 'X') num_y[j] = 10;
        else if (Y[j] == 'L') num_y[j] = 50;
        else if (Y[j] == 'C') num_y[j] = 100;
        else if (Y[j] == 'D') num_y[j] = 500;
        else if (Y[j] == 'M') num_y[j] = 1000;
    }
    while (i != len_liczba_1) {
        if (i == 0) x += num_x[0];
        else {
            x += num_x[i];
            if (num_x[i] > num_x[i-1]) x -= 2 * num_x[i - 1];
        }
        i++;
    }
    i = 0;
    while (i != len_liczba_2) {
        if (i == 0) y += num_y[0];
        else {
            y += num_y[i];
            if (num_y[i] > num_y[i-1]) y -= 2 * num_y[i - 1];
        }
        i++;
    }
    return x + y;
}

void do_rzymskiej(int x, int * arr) {
    int length = (int)floor(log10((float)x)) + 1;
    int i = 0;
    do {
        arr[i] = x % 10;
        x /= 10;
        i++;
    } while (x != 0);
    int temp_arr[length];
    int temp;
    for(int j = 0; j < length; j++) {
        temp_arr[j] = arr[j];
    }
    for(int j = 0; j < length; j++) {
        temp = arr[length - j-1];
        temp_arr[j] = temp;
    }
    for(int j = 0; j < length; j++) {
        arr[j] = temp_arr[j];
    }
}

void do_arabskiej(int sum, int * arr, int length) {
    char roman[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M', '\0'};
    char wynik[15];
    int i = 0;
    if (length == 4) {
        for (i; i + 1 <= arr[length-4]; i++) {
            wynik[i] = 'M';
        }
    }
    if (length >= 3) {
        if (arr[length-3] == 0) goto teleport_1;
        else if (arr[length-3] <= 3) {
            for(int j = 0; j + 1 <= arr[length-3]; j++) {
                wynik[i] = 'C';
                i++;
            }
        }
        else if (arr[length-3] == 4) {
            wynik[i] = 'C';
            i++;
            wynik[i] = 'D';
            i++;
        }
        else if (arr[length-3] <= 8) {
            wynik[i] = 'D';
            i++;
            for (int j = 5; j + 1 <= arr[length-3]; j++) {
                wynik[i] = 'C';
                i++;
            }
        }
        else {
            wynik[i] = 'C';
            i++;
            wynik[i] = 'M';
            i++;
        }

    }
    teleport_1:
    if (length >= 2) {
        if (arr[length-2] == 0) goto teleport_2;
        else if (arr[length-2] <= 3) {
            for(int j = 0; j + 1 <= arr[length-2]; j++) {
                wynik[i] = 'X';
                i++;
            }
        }
        else if (arr[length-2] == 4) {
            wynik[i] = 'X';
            i++;
            wynik[i] = 'L';
            i++;
        }
        else if (arr[length-2] <= 8) {
            wynik[i] = 'L';
            i++;
            for (int j = 5; j + 1 <= arr[length-2]; j++) {
                wynik[i] = 'X';
                i++;
            }
        }
        else {
            wynik[i] = 'X';
            i++;
            wynik[i] = 'C';
            i++;
        }

    }
    teleport_2:
    if (arr[length-1] == 0) goto teleport_3;
    else if (arr[length-1] <= 3) {
        for(int j = 0; j + 1 <= arr[length-2]; j++) {
            wynik[i] = 'I';
            i++;
        }
    }
    else if (arr[length-1] == 4) {
        wynik[i] = 'I';
        i++;
        wynik[i] = 'V';
        i++;
    }
    else if (arr[length-1] <= 8) {
        wynik[i] = 'V';
        i++;
        for (int j = 5; j + 1 <= arr[length-1]; j++) {
            wynik[i] = 'I';
            i++;
        }
    }
    else {
        wynik[i] = 'I';
        i++;
        wynik[i] = 'X';
        i++;
    }
    teleport_3:
    wynik[i] = '\0';
    printf("Suma wynosi: %s\n", wynik);
}