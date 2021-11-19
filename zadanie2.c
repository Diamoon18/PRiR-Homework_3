#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <math.h>

double przyblizeniePI(int n){
    double result = 0;
    int i;
    for(i = 1; i <= n; i++){
        result += pow(-1, (n-1))/(2*n-1);   
    }
    return result*4;
}

void procesy(int number_pr){
    pid_t pid;
    int i, n;
    int X = 100, Y = 5000;
    for(i = 1; i <= number_pr; i++){
        n = X + rand()%(Y - X + 1);
        switch(pid = fork()){
            case -1:
                printf("Error in fork!\n");
                break;
            case 0:
                printf("Jestem procesem potomnym nr-%d. Moj PID = %d n=%d Result PI= %f numer pid = %d\n\n", i, getpid(), n, przyblizeniePI(n), pid);
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
    srand(time(NULL));
    procesy(p);
    return 0;
}
