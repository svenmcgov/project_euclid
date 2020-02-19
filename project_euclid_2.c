#include <stdio.h>
#define UPPERBOUND 4000000

int fibonacci_num(int);
int even_fib_sum(int*, int);

int main(void){

  int i = 0, sum = 0;
  /*
  while(fibonacci_num(i) < UPPERBOUND){
    printf("n = %d \t\t fibonacci = %d\n", i, fibonacci_num(i));
    i++;
  }
  */
  for(i = 2; i < 33; i+=3)
    sum += fibonacci_num(i);
  printf("%d\n", sum);
  return 0;
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

int even_fib_sum(int *arr, int size){
  int sum = 0;

  return sum;
}
