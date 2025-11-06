/*array-a collection of elements of the same type stored in contiguous memory locations 
*/

/*
Name: Wangui James Kahwai 
Reg no:CT101/G/26490/25
Date:6/11/25
Description:A 2D array for scores 
*/
#include <stdio.h>

int main(){
    
    // ii. Declaration and initialization of 2D array with the given values
    int scores[2][2] = {
        {65, 92},
        {84, 72}
    };
    
    // iii. Printing thearray elements using nested for loop
    printf("Elements of the 2D array:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}