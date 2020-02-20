#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rand_lim(int);
int* gen_rand_arr(int);
void print_arr(int *, int);

int main(void){
    srand(time(NULL));   // Initialization, should only be called once.
    int *arr1 = gen_rand_arr(25);
    print_arr(arr1, 25);
    free(arr1);
    return 0;
}

int rand_lim(int limit) {
/* return a random number between 0 and limit inclusive. */
    int divisor = RAND_MAX/(limit+1);
    int retval;

    do {
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}

// each number between 0 and 10
int* gen_rand_arr(int n){
    int *arr = calloc(n, sizeof(int));
    int i = 0;
    for(i = 0; i < n; i++){
        arr[i] = rand_lim(10);
    }
    return arr;
}

void print_arr(int * arr, int n){
    int i = 0;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    puts("");
}
