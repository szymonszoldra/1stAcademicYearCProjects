#include <stdio.h>
#include <stdlib.h>

void spiral(int **arr, int x, int y)
{
    int counter = 1;    //What number should the spiral begin with. It is always 1
    int max_counter = (x * y) + 1;  //Max number plus 1
    int x_min, x_max;
    int y_min, y_max;

    x_min = 0;
    x_max = x;
    y_min = 0;
    y_max = y;
    
    while(counter != max_counter){
    
        //Upper row
        for (int j = x_min; j < x_max && counter != max_counter; j++){                                       
            arr[j][y_min] = counter;
            counter++;
        }
        //----------------------

        //Right column
        y_min++;   
        for (int j = y_min; j < y_max && counter != max_counter; j++){
            arr[x_max-1][j] = counter;
            counter++;
        }
        //----------------------

        //Lower row from right to left
        x_max--;
        for (int j = x_max - 1; j >= x_min && counter != max_counter; j--){
            arr[j][y_max-1] = counter;
            counter++;
        }
        //----------------------

        //Left column from bottop to top
        y_max--; 
        for (int j = y_max - 1; j >= y_min && counter != max_counter; j--){
            arr[x_min][j] = counter;
            counter++;
        }
        //----------------------

        x_min++;
    }
}

int main(){
    int x, y;

    printf("Enter the size of the array: ");
    scanf("%d%d", &x, &y);

    //Memory allocation
    int **arr;
    arr = malloc(x*sizeof(int*));
    for (int i = 0; i < x; i++){
        arr[i] = malloc(y*sizeof(int));
    }
    //--------------------------

    spiral(arr, x, y);

    //Display the array
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            printf("[%d]\t", arr[j][i]);
        }
        printf("\n");
    }
    //--------------------------
    
    free(arr);  //Clear memory.

    return 0;
}
