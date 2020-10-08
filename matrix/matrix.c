#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable: 4996)

#define N 5
#define MATRIX_FROM -5
#define MATRIX_TO 5


int checkCorrectness(int l) {
	if (l < 1 || l > N) {
		return 0;
	}
	return 1;
}


int countVectorCoordinates(double vector[], int n) {
	double from = -1.5;
	double to = 3.5;
	int counter = 0;
	
	for (int i = 0; i < n; i++) {
		if (vector[i] >= from && vector[i] <= to) {
			counter++;
		}
	}

	return counter;
}


void countInLRow(double matrix[N][N], int l ) {

	if (checkCorrectness(l)) {
		double tempVect[N];
	
		for (int i = 0; i < N; i++) {
			tempVect[i] = matrix[l-1][i];
		}

		int counter = countVectorCoordinates(tempVect, N);
		printf("Ilosc elementow w wierszu %d mieszczacych sie w przedziale [-1.5 , 3.5] to %d\n", l, counter);

	}
	else {
		printf("Podany wiersz nie miesci sie w rozmiarze macierzy!\n");
	}
}


void countInLCollumn(double matrix[N][N], int l) {

	if (checkCorrectness(l)) {
		double tempVect[N];

		for (int i = 0; i < N; i++) {
			tempVect[i] = matrix[i][l - 1];
		}

		int counter = countVectorCoordinates(tempVect, N);
		printf("Ilosc elementow w kolumnie %d mieszczacych sie w przedziale [-1.5 , 3.5] to %d\n", l, counter);
	}
	else {
		printf("Podany wiersz nie miesci sie w rozmiarze macierzy!\n");
	}

}

void countOnMainDiagonal(double matrix[N][N]) {

	double tempVect[N];

	for (int i = 0; i < N; i++) {
		tempVect[i] = matrix[i][i];
	}

	int counter = countVectorCoordinates(tempVect, N);
	printf("Ilosc elementow na glownej przekatnej mieszczacych sie w przedziale [-1.5 , 3.5] to %d\n", counter);
}

void countOnSecondDiagonal(double matrix[N][N]) {

	double tempVect[N];

	for (int i = 0; i < N; i++) {
		tempVect[i] = matrix[i][N - 1 - i];
	}

	int counter = countVectorCoordinates(tempVect, N);
	printf("Ilosc elementow na drugiej przekatnej mieszczacych sie w przedziale [-1.5 , 3.5] to %d\n", counter);
}

void countUnderMainDiagonal(double matrix[N][N]) {

	int elementsUnder = 0;
	double *tempVect;

	for (int i = N-1; i > 0; i--) {
		elementsUnder += i;
	}

	tempVect = malloc(sizeof(double) * elementsUnder);
	int k = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			tempVect[k] = matrix[i][j];
			k++;
		}
	}

	int counter = countVectorCoordinates(tempVect, k);
	printf("Ilosc elementow pod glowna przekatna mieszczacych sie w przedziale [-1.5 , 3.5] to %d\n", counter);
}

int main() {
	//generate random matrix and display it
	
	double matrix[N][N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			double range = MATRIX_TO - MATRIX_FROM;
			matrix[i][j] = ((double)rand() * (range)) / (double)RAND_MAX + MATRIX_FROM;
			printf("%lf ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//place for l-row and l-collumn
	int row = 3;
	int collumn = 3;

	countInLRow(matrix, row);
	countInLCollumn(matrix, collumn);
	countOnMainDiagonal(matrix);
	countUnderMainDiagonal(matrix);
	countOnSecondDiagonal(matrix);


	return 0;
}