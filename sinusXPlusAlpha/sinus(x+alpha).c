#pragma warning (disable: 4996)  
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

FILE* fw;

double getValueFromTaylorSeries(double x, double delta, int *wsteps, int M, double alpha) {

    double seriesValue = sin(alpha);
    double expression = 1;
    do {
       
        double factorialExpression = *wsteps;
        expression *= x / factorialExpression;

        if (*wsteps % 4 == 1)
            seriesValue += cos(alpha) * expression;
        else if (*wsteps % 4 == 2)
            seriesValue -= sin(alpha) * expression;
        else if (*wsteps % 4 == 3)
            seriesValue -= cos(alpha) * expression;
        else
            seriesValue += sin(alpha) * expression;

        *wsteps = *wsteps + 1;
    } while (fabs(expression) > delta || fabs(expression) > delta && *wsteps < M);

    return seriesValue;
}

int main() {

    double a, b, dx, delta, x, alpha, value, controlValue;
    int M, steps = 1;
    
    int* wsteps;
    wsteps = &steps;

    printf("Podaj przedzial [a,b], krok dx, dokladnosc, maksymalna liczbe wyrazow szeregu oraz stala alpha: \n");

    if (scanf("%lf %lf %lf %lf %d %lf", &a, &b, &dx, &delta, &M, &alpha) != 6) {

        printf("Blad danych\n");
        system("pause");
        exit(1);
    }

    if (!(fw = fopen("wyniki.txt", "w"))) {

        printf("Blad otwarcia zbioru\n");
        exit(2);
    }

    printf("\t\tx \t\t| f_szereg(x) \t\t| f_scisle(x) \t\t| liczba wyrazow szeregu \t\t| warunek stopu\n ");
    fprintf(fw,"\t\tx \t\t| f_szereg(x) \t\t| f_scisle(x) \t\t| liczba wyrazow szeregu \t\t| warunek stopu\n ");

    for (x = a; x <= b + 0.5 * dx; x += dx) {

        value = getValueFromTaylorSeries(x, delta, wsteps, M, alpha);
        controlValue = sin(x+alpha);

        if (*wsteps == M) {

            fprintf(fw, "\t%10.2lf\t\t%15.4le\t\t%15.4le\t\t\t %d\t\t\t Przekroczono liczbe wyrazow ciagu\n", x, value, controlValue, *wsteps);
            printf("\t%10.2lf\t\t%15.4le\t\t%15.4le\t\t\t %d\t\t\t Przekroczono liczbe wyrazow ciagu\n", x, value, controlValue, *wsteps);

        }
        else {

            fprintf(fw, "\t%10.2lf\t\t%15.4le\t\t%15.4le\t\t\t %d\t\t\t Osiagnieta dokladnosc\n", x, value, controlValue, *wsteps);
            printf("\t%10.2lf\t\t%15.4le\t\t%15.4le\t\t\t %d\t\t\t Osiagnieta dokladnosc\n", x, value, controlValue, *wsteps);
        }

        *wsteps = 1;
    }


    return 0;
}
