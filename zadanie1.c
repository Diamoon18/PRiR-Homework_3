#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <math.h>
#define ROZ 2

double* losujPrzedzialy(int X, int Y){
    double a, b;
    a = X + rand()%(Y - X + 1); 
    b = X + rand()%(Y - X + 1);
    while(a>=b){
        a = X + rand()%(Y - X + 1); 
        b = X + rand()%(Y - X + 1);
    }
    double* tab = (double*)malloc(sizeof(double) * ROZ);
    tab[0] = a;
    tab[1] = b;
    return tab;
}

double funkcja(double x){
    return pow(4, x)-pow(6, x)+5;
}

double mTrapezy(double a, double b, int n){
    double result = 0;
    
    double x[n+1];
    double y[n+1];
    double h = (b-a)/n;

    x[0] = a;
    x[n] = b;
    y[0] = funkcja(a);
    y[n] = funkcja(b);
    
    for(int i = 1; i < n; i++){
        x[i] = a + (i*(b-a))/n;
    }

    double sumaP = 0;
    for(int i = 1; i < n; i++){
        y[i] = funkcja(x[i]);
        sumaP += y[i];
    }

    result = h*(y[0]/2 + sumaP + y[n]/2);
    return result; 
}


double** dane(int n) {
    double **pierwiastki;
    int i;
    switch(n) {
        case 2:
            // 1 - wagi w
            // 2 - t wezly
            pierwiastki = malloc(3 * sizeof(double*));
            if( pierwiastki == NULL){
                printf("Nie mozna przedzielic pamiec!");
            }
            for(i = 0; i < 3; i++){
                pierwiastki[i] = malloc(3 * sizeof(double));
                if( pierwiastki[i] == NULL){
                    printf("Nie mozna przedzielic pamiec!");
                }
            }
            pierwiastki[0][0] = 3; // rozmiar tab

            pierwiastki[1][1] = 1;
            pierwiastki[1][2] = -0.57735;

            pierwiastki[2][1] = 1;
            pierwiastki[2][2] = 0.57735;
            break;
        case 4: // 5 i 3
            pierwiastki = malloc(5 * sizeof(double*));
            if( pierwiastki == NULL){
                printf("Nie mozna przedzielic pamiec!");
            }
            for(i = 0; i < 5; i++){
                pierwiastki[i] = malloc(3 * sizeof(double));
                if( pierwiastki[i] == NULL){
                    printf("Nie mozna przedzielic pamiec!");
                }
            }
            pierwiastki[0][0] = 5; // rozmiar tab

            pierwiastki[1][1] = 0.65214;
            pierwiastki[1][2] = -0.33998;

            pierwiastki[2][1] = 0.65214;
            pierwiastki[2][2] = 0.33998;

            pierwiastki[3][1] = 0.34785;
            pierwiastki[3][2] = -0.86113;

            pierwiastki[4][1] = 0.34785;
            pierwiastki[4][2] = 0.86113;
            break;
        case 6:
            pierwiastki = malloc(7 * sizeof(double*));
            if( pierwiastki == NULL){
                printf("Nie mozna przedzielic pamiec!");
            }
            for(i = 0; i < 7; i++){
                pierwiastki[i] = malloc(3 * sizeof(double));
                if( pierwiastki[i] == NULL){
                    printf("Nie mozna przedzielic pamiec!");
                }
            }
            pierwiastki[0][0] = 7; // rozmiar tab

            pierwiastki[1][1] = 0.36076;
            pierwiastki[1][2] = 0.66120;

            pierwiastki[2][1] = 0.36076;
            pierwiastki[2][2] = -0.66120;

            pierwiastki[3][1] = 0.46791;
            pierwiastki[3][2] = -0.23861;

            pierwiastki[4][1] = 0.46791;
            pierwiastki[4][2] = 0.23861;

            pierwiastki[5][1] = 0.17132;
            pierwiastki[5][2] = -0.93246;

            pierwiastki[6][1] = 0.17132;
            pierwiastki[6][2] = 0.93246;
            break;
        case 8:
            pierwiastki = malloc(9 * sizeof(double*));
            if( pierwiastki == NULL){
                printf("Nie mozna przedzielic pamiec!");
            }
            for(i = 0; i < 9; i++){
                pierwiastki[i] = malloc(3 * sizeof(double));
                if( pierwiastki[i] == NULL){
                    printf("Nie mozna przedzielic pamiec!");
                }
            }
            pierwiastki[0][0] = 9; // rozmiar tab
    
            pierwiastki[1][1] = 0.36268;
            pierwiastki[1][2] = -0.18343;

            pierwiastki[2][1] = 0.36268;
            pierwiastki[2][2] = 0.18343;

            pierwiastki[3][1] = 0.31370;
            pierwiastki[3][2] = -0.52553;

            pierwiastki[4][1] = 0.31370;
            pierwiastki[4][2] = 0.52553;

            pierwiastki[5][1] = 0.22238;
            pierwiastki[5][2] = -0.79666;

            pierwiastki[6][1] = 0.22238;
            pierwiastki[6][2] = 0.79666;

            pierwiastki[7][1] = 0.10122;
            pierwiastki[7][2] = -0.96028;

            pierwiastki[8][1] = 0.10122;
            pierwiastki[8][2] = 0.96028;
            break;
        case 10:
            pierwiastki = malloc(11 * sizeof(double*));
            if( pierwiastki == NULL){
                printf("Nie mozna przedzielic pamiec!");
            }
            for(i = 0; i < 11; i++){
                pierwiastki[i] = malloc(3 * sizeof(double));
                if( pierwiastki[i] == NULL){
                    printf("Nie mozna przedzielic pamiec!");
                }
            }
            pierwiastki[0][0] = 11; // rozmiar tab            

            pierwiastki[1][1] = 0.29552;
            pierwiastki[1][2] = -0.14887;

            pierwiastki[2][1] = 0.29552;
            pierwiastki[2][2] = 0.14887;

            pierwiastki[3][1] = 0.26926;
            pierwiastki[3][2] = -0.43339;

            pierwiastki[4][1] = 0.26926;
            pierwiastki[4][2] = 0.43339;

            pierwiastki[5][1] = 0.21908;
            pierwiastki[5][2] = -0.67940;

            pierwiastki[6][1] = 0.21908;
            pierwiastki[6][2] = 0.67940;

            pierwiastki[7][1] = 0.14945;
            pierwiastki[7][2] = -0.86506;

            pierwiastki[8][1] = 0.14945;
            pierwiastki[8][2] = 0.86506;

            pierwiastki[9][1] = 0.06667;
            pierwiastki[9][2] = -0.97390;

            pierwiastki[10][1] = 0.06667;
            pierwiastki[10][2] = 0.97390;
            break;
        case 16:
            pierwiastki = malloc(17 * sizeof(double*));
            if( pierwiastki == NULL){
                printf("Nie mozna przedzielic pamiec!");
            }
            for(i = 0; i < 17; i++){
                pierwiastki[i] = malloc(3 * sizeof(double));
                if( pierwiastki[i] == NULL){
                    printf("Nie mozna przedzielic pamiec!");
                }
            }
            pierwiastki[0][0] = 17; // rozmiar tab

            pierwiastki[1][1] = 0.18945;
            pierwiastki[1][2] = -0.09501;

            pierwiastki[2][1] = 0.18945;
            pierwiastki[2][2] = 0.09501;

            pierwiastki[3][1] = 0.18260;
            pierwiastki[3][2] = -0.28160;

            pierwiastki[4][1] = 0.18260;
            pierwiastki[4][2] = 0.28160;

            pierwiastki[5][1] = 0.16915;
            pierwiastki[5][2] = -0.45801;

            pierwiastki[6][1] = 0.16915;
            pierwiastki[6][2] = 0.45801;

            pierwiastki[7][1] = 0.14959;
            pierwiastki[7][2] = -0.61787;

            pierwiastki[8][1] = 0.14959;
            pierwiastki[8][2] = 0.61787;

            pierwiastki[9][1] = 0.12462;
            pierwiastki[9][2] = -0.75540;

            pierwiastki[10][1] = 0.12462;
            pierwiastki[10][2] = 0.75540;

            pierwiastki[11][1] = 0.09515;
            pierwiastki[11][2] = -0.86563;

            pierwiastki[12][1] = 0.09515;
            pierwiastki[12][2] = 0.86563;

            pierwiastki[13][1] = 0.06225;
            pierwiastki[13][2] = -0.94457;

            pierwiastki[14][1] = 0.06225;
            pierwiastki[14][2] = 0.94457;

            pierwiastki[15][1] = 0.02715;
            pierwiastki[15][2] = -0.98940;

            pierwiastki[16][1] = 0.02715;
            pierwiastki[16][2] = 0.98940;
            break;
    }
    return pierwiastki;
}

int wylosujN() {
    int mozliweN[6] = {2, 4, 6, 8, 10, 16};
    int n;
    n  = mozliweN[rand()%5];
    return n;
}


double kwadratGauss(double a, double b, int n){
    double result = 0;
    double** tab = dane(n);
    double suma = 0;

    int length_tab = (int)tab[0][0];

    int i;
    for(i = 1; i < length_tab; i++) {
        suma+=tab[i][1]*funkcja(((b-a)/2)*tab[i][2]+(b+a)/2);
    }
    result = ((b-a)/2)*suma;
    return result;
}


void procesy(int number_pr, bool flag){
    srand(time(NULL));
    pid_t pid;
    int i, n;
    double a, b;
    //printf("a = %f; b = %f; n = %d\n", a, b, n); 

    for(i = 1; i <= number_pr; i++){
        double* tablica = losujPrzedzialy(-10, 10);
        a = tablica[0];
        b = tablica[1];
        if(flag){
            n = rand()%100;
        }else{
            n = wylosujN();
        }
        switch(pid = fork()){
            case -1:
                printf("Error in fork!\n");
                break;
            case 0:
                if(flag){
                    printf("Jestem procesem potomnym nr-%d. Moj PID = %d Metoda Trapezow. Parametry: a = %f, b=%f, n=%d Result = %f numer pid = %d\n\n", i, getpid(), a, b, n, mTrapezy(a, b, n), pid);
                } else {
                    printf("Jestem procesem potomnym nr-%d. Moj PID = %d Kwadratury Gaussa. Parametry: a = %f, b=%f, n=%d Result = %f numer pid = %d\n\n", i, getpid(), a, b, n, kwadratGauss(a, b, n), pid);
                }
                break;
            default:
                break;
         }    
    }
    
    for(i = 1; i <= number_pr; i++){
        if(wait(0) == -1){
            printf("Error in wait\n");
        }
    }
}

int main( int argc, char **argv )
{   
    int p;
    printf("Podaj ilosc procesow potomnych:");
    scanf("%d", &p);
    // metoda Trapezow
        procesy(p, true);
    // kwadratury Gaussa
        //procesy(p, false);
    return 0;
}
