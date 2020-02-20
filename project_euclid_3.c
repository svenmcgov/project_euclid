#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000000
void prime_sieve(long*, long);
void init_arr(long*, long);
void print_arr(long*, long);

int main(void){
  long primes[LIMIT];
  init_arr(primes, LIMIT);
  long i = 0, j = 0, prime_count = 0;
  prime_sieve(primes, LIMIT);;

  for(i = 0; i < LIMIT; i++){
    if(primes[i] != 0)
      prime_count++;
  }

  long *new_primes = calloc(prime_count, sizeof(long));

  for(i = 0; i < LIMIT; i++){
    if(primes[i] != 0){
      new_primes[j] = primes[i];
      j++;
    }
  }

  i = 2;
  for(i = 2; i < prime_count; i++){
    if(600851475143 % new_primes[i] == 0)
      printf("%ld \n", new_primes[i]);
  }


  /*
  print_arr(primes, LIMIT);
  printf("\n Prime count: %d\n\n", prime_count);
  print_arr(new_primes, prime_count);
  */

  return 0;
}

// build array of primes up to n
void prime_sieve(long * arr, long limit){
  long i = 0, p = 2, count = 1;
  for(p = 2; p * p <= limit; p++){
    if(arr[p]){
      for(i = p * p; i <= limit; i += p)
        arr[i] = 0; // 0 for false
    }
  }
  printf("Eratosthenes complete.\n");
}

void init_arr(long * arr, long n){
  long i = 0;
  for(i = 0; i < n; i++)
    arr[i] = i;
}

void print_arr(long * arr, long n){
  long i = 0;
  for(i = 0; i < n; i++){
      printf("%ld ", arr[i]);
  }
  puts("");
}
