#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------------------------------------

// CALCULATING SINUS VALUE FROM TAYLOR'S PATTERN, INTRODUCTION TO PROGRAMMING EXERCISES TASK, SZYMON SZOŁDRA

//-----------------------------------------------------------------------------------------------------------

//global PI declaration

const double PI = 3.14159265359;

double getNext(double radians, int n) {
    return pow(radians, 2)/(2*n * (2*n + 1));
}

double getSinus(double radians, int steps){
    double sinusValue = radians;
    double expression = radians;

    for(int n = 1; n < steps; n++){
        expression *= -1. *getNext(radians, n);
        sinusValue += expression;
    }
    return sinusValue;
}

int main(){
    int steps;
    float x;
    double radians;
    double answer;

    printf("Enter the angle for the sin(x)\n");
    scanf("%f", &x);

    printf("Enter the number n responsible for the number of steps (suggested precision is > 10)\n");
    scanf("%d", &steps);

    //convert x to radians while skipping the sine period
    if(x>=360) x = (int)x%360;
    radians = x/180 * PI;

    answer = getSinus(radians, steps);

    printf("The answer is %.16f\n", answer);
    printf("math.h sin() value is %.16f\n", sin(radians));
    printf("difference between them is %.16f\n", sin(radians) - answer);

    return 0;
}
