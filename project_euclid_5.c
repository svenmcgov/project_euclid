#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int div_by_n(int, int);

int main(void){
  long found = 0;
  long i = 0;
  long j = 0;
  for(i = 1; i < 10000; i++){
    for(j = 2; j < 11; j++){
      if(!div_by_n(i, j))
        break;
      if(j == 10){
        found = i;
        break;
      }
    }
    if(j == 10){
      break;
    }
  }
  printf("%ld\n", found);
  return 0;
}

/* return 0 if no, 1 if yes */
int div_by_n(int dividend, int n){
  if(dividend % n == 0)
    return 1;
  return 0;
}
