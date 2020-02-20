#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100

void prime_sieve(int*, int);
void init_arr(int*, int);
void print_arr(int*, int);

int main(void){
  int primes[LIMIT];
  init_arr(primes, LIMIT);
  int i = 0, j = 0, prime_count = 0;
  prime_sieve(primes, LIMIT);;

  for(i = 0; i < LIMIT; i++){
    if(primes[i] != 0)
      prime_count++;
  }

  // make a new array and filter out the 0's
  int *new_primes = calloc(prime_count, sizeof(int));

  for(i = 0; i < LIMIT; i++){
    if(primes[i] != 0){
      new_primes[j] = primes[i];
      j++;
    }
  }

  // print_arr(primes, LIMIT);
  printf("\nPrime count: %d\n\n", prime_count);
  print_arr(new_primes, prime_count);
  free(new_primes);
  return 0;
}

void prime_sieve(int * arr, int limit){
  int i = 0, p = 2, count = 1;
  for(p = 2; p * p <= limit; p++){
    if(arr[p]){
      for(i = p * p; i <= limit; i += p)
        arr[i] = 0; // 0 for false
    }
  }
  printf("\nSieve of Eratosthenes complete.\n");
}

void init_arr(int * arr, int n){
  int i = 0;
  for(i = 0; i < n; i++)
    arr[i] = i;
}

void print_arr(int * arr, int n){
  int i = 0;
  for(i = 0; i < n; i++){
      printf("%d ", arr[i]);
  }
  puts("\n");
}
