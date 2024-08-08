#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int main() {

        int * ptr;          // Pointer variable
        int n, index = 1;
        printf("Enter the range of array : ");
        scanf("%d", &n);

        int original = n;
        printf("The total length of array is : %d\n", n);        // total length of array

        ptr = (int*) calloc(n, sizeof(int));            // using dynamic allocation " Calloc "
        for(int i = 0; i < n; i++) {                    // taking input of all the elements inside the allocated memory
            printf("Enter the %dth number : ", index);
            scanf("%d", &ptr[i]);
            index++;
        }

        char input;        // Asking user to want to add more or not
        printf("\nWant to add more : ");
        scanf("%s", &input);
    
        if(input == 'y') {         // if yes then write 'y' else 'n'
            int howMuch;
            printf("Enter how more you want : ");       // How much more you want to add in the array
            scanf("%d", &howMuch);
            int newSize = original + howMuch;           // New final size of allocated memory

            ptr = (int*) realloc(ptr, newSize);   // New size was given to the array   // the point on file was made

            printf("\nThe total length of array is : %d\n", newSize); // Total final size
            
            for(int l = original; l < newSize; l++) {           // taking the new elements from user
                printf("Enter the %dth element : ", index);
                scanf("%d", &ptr[l]);
                index++;
            }

            for(int k = 0; k < newSize; k++) {      // Printing the whole elements
                printf("[%d] ", ptr[k]);
            }

        } else if(input == 'n') {       /* if user write No as 'n' then printing the elements was assigned before adding more size*/
            printf("Total length of array is : %d", ++original);
            for(int i = 0; i < original; i++) {
                printf("[%d],", ptr[i]);
            }
        }

    free(ptr);
    return 0;
}