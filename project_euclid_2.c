#include <stdio.h>
#define UPPERBOUND 100000
#define SIZE 24
#define SEED1 1
#define SEED2 2

void generate_partial_seq(int *, int, int, int);
void print_arr(int *, int);
int even_fib_sum(int*, int);
int fibonacci_num(int);

int main(void){

  int i = 0, sum = 0;
  int fib_arr[SIZE];
  generate_partial_seq(fib_arr, SEED1, SEED2, SIZE);
  printf("%d\n", even_fib_sum(fib_arr, SIZE));

  /*
  // print_arr(fib_arr, SIZE);
  // test
  while(fibonacci_num(i) < UPPERBOUND){
    printf("n = %d \t\t fibonacci = %d\n", i, fibonacci_num(i));
    i++;
  }
  */
  return 0;
}

// return the nth fib num
void generate_partial_seq(int *  arr, int n_minus_2, int n_minus_1, int size){
  int i = 0;

  if(size == 0 || size < 0)
    return;
  if(size == 1)
    return;
  if(size == 2)
    return;

  arr[0] = n_minus_2;
  arr[1] = n_minus_1;
  for(i=2; i<size; i++){
    arr[i] = n_minus_1 + n_minus_2;
    n_minus_2 = n_minus_1;
    n_minus_1 = arr[i];
  }
}

// return the nth fib num
int fibonacci_num(int n){
  int i = 0, sub_n_minus_2 = 1, sub_n_minus_1 = 2, sub_n = 0;

  if(n == 0 || n < 0)
    return 0;
  if(n == 1)
    return 1;
  if(n == 2)
    return 2;

  for(i=0; i<n-2; i++){
    sub_n = sub_n_minus_1 + sub_n_minus_2;
    sub_n_minus_2 = sub_n_minus_1;
    sub_n_minus_1 = sub_n;
  }
  return sub_n;
}

void print_arr(int * arr, int size){
  int i = 0;
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
  puts("");
}

int even_fib_sum(int *arr, int size){
  int i = 0, sum = 0;
  // assuming SEED1 = 1 and SEED2 = 2
  for(i = 1; i < size; i+=3){
    sum += arr[i];
  }
  return sum;
}
