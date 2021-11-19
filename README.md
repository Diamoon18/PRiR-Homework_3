# PRiR-Homework_3_UNIX
## Zadanie 1 - Trapezoidal method and Gauss quadrature.
### Main 
*p - number of child processes.\
Method selection using a bool variable:\
*true - trapezoidal method,\
*false - gauss quadrature
```c
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
```
### Main part in Function ```procesy(int p, bool flag)```
1. Randomizes the range <a,b> with the function ```losujPrzedzialy(-10, 10)```
2. Depending on the ```bool flag``` variable, randomizes the value of n
3. Creating child processes with ```fork()``` function
4. Depending on the ```bool flag``` variable, print the processes with the appropriate integration method\
```mTrapezy(double a, double b, int n)``` - trapezoidal method\
```kwadratGauss(double a, double b, int n)``` - gauss quadrature
```c
   ...
   srand(time(NULL)); // different rand() results
   ...
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
    ...
```
### Function ```losujPrzedzialy(double x, double y)```
1. Randomizes values a, b from the interval <x,y>
2. Do 1 as long as variable a will not be smaller than b
3. Writes the results to an array ```tab```
```c
    ...
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
    ...
```
### Function ```mTrapezy(double a, double b, int n)```
1. Auxiliary arrays for the values of x and y
2. h - The length of the division
3. Write to the arrays the beginning (a) of the interval and the end (b)
4. Count the values of x in the created intervals
5. Count the values of y in the created intervals and sum them
6. Count the result
```c
double result = 0;
// 1
double x[n+1];
double y[n+1];
// 2
double h = (b-a)/n;
// 3
x[0] = a;
x[n] = b;
y[0] = funkcja(a);
y[n] = funkcja(b);
// 4
for(int i = 1; i < n; i++){
    x[i] = a + (i*(b-a))/n;
}
// 5
double sumaP = 0;
for(int i = 1; i < n; i++){
    y[i] = funkcja(x[i]);
    sumaP += y[i];
}
// 6
result = h*(y[0]/2 + sumaP + y[n]/2);
return result; 
...
double funkcja(double x){
    return pow(4, x)-pow(6, x)+5;
}
```
### Function ```kwadratGauss(double a, double b, int n)```
1. Fill the table ```tab``` depending on the given value of n using the function ```dane(int n)```
2. The first element is the number of rows in the array
3. Calculate the sum using the quadrature formula
4. Count the result
```c
    double result = 0;
    // 1
    double** tab = dane(n);
    double suma = 0;
    // 2
    int length_tab = (int)tab[0][0];
    // 3
    int i;
    for(i = 1; i < length_tab; i++) {
        suma+=tab[i][1]*funkcja(((b-a)/2)*tab[i][2]+(b+a)/2);
    }
    // 4
    result = ((b-a)/2)*suma;
    return result;
```
### Function ```dane(int n)```
Fill table ```pierwiastki``` depending on the n variable.\
```c
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
        ...
```
Random value of n from array - ```wylosujN()```
```c
    int mozliweN[6] = {2, 4, 6, 8, 10, 16};
    int n;
    n  = mozliweN[rand()%5];
    return n;
```
### Results
![z1](https://user-images.githubusercontent.com/72127610/142624594-79844419-ef71-4ae3-aa4d-a697a608b25f.png)
![z1_2](https://user-images.githubusercontent.com/72127610/142624635-33e6fa51-5420-41b4-9609-95cc309db1ee.png)
## Zadanie 2 - approximation of the value of PI
The implementation of this task is very similar to task 1.\
Difference:
Another function ```przyblizeniePI(int n)```in creating processes
```c
    double result = 0;
    int i;
    for(i = 1; i <= n; i++){
        result += pow(-1, (n-1))/(2*n-1);   
    }
    return result*4;
```
```c
    ...
    switch(pid = fork()){
        case -1:
            printf("Error in fork!\n");
            break;
        case 0:
            printf("Jestem procesem potomnym nr-%d. Moj PID = %d n=%d Result PI= %f numer pid = %d\n\n", i, getpid(), n, przyblizeniePI(n), pid);
            break;
    ...
```
### Results
![z2](https://user-images.githubusercontent.com/72127610/142624657-1af74f8d-d29f-450a-9e24-fd8edbea2753.png)
