#include <stdio.h>
#include <string.h>

int is_palindrome(char*);
int two_int_product_palindrome();
void to_string(char*, int);

int main(void){

  char new_num[50];
  char num1[50], num2[50], num3[50];
  to_string(new_num, 990009);
  to_string(num1, 1009);
  to_string(num2, 1101011);
  to_string(num3, 110017);
  // is_palindrome(new_num);
  /*
  char numbers[4][50];
  strcpy(numbers[0], new_num);
  strcpy(numbers[1], num1);
  strcpy(numbers[2], num2);
  strcpy(numbers[3], num3);
  int i = 0;

  for(i = 0; i < 4; i++){
    if(is_palindrome(numbers[i]))
      printf("%s is a palindrome.\n", numbers[i]);
  }
  */

  two_int_product_palindrome();

  return 0;
}

int is_palindrome(char *num){
  int i = 0, digits = 0, result = 1;

  while(num[i] != '\0'){
    digits++;
    i++;
  }

  for(i = 0 ; i < digits / 2; i++){
    if(num[i] != num[digits - 1 - i]){
      // printf("%c is not equal to %c\n", num[i], num[digits - 1 - i]);
      result = 0;
    }
  }
  /*
  if(result){
    printf("%s is a palindrome.\n", num);
  }
  */
  return result;
}

int two_int_product_palindrome(){
  int pair_key[] = {0, 0};
  int i = 0, j = 0, largest_product = 0;
  char num[50];
  for(i = 100; i < 1000; i++){
    for(j = 100; j < 1000; j++){
      to_string(num, i * j);
      if(is_palindrome(num) && (i * j) > (pair_key[0] * pair_key[1])){
        largest_product = i * j;
        pair_key[0] = i;
        pair_key[1] = j;
      }
    }
  }
  printf("i is %d and j is %d\n", pair_key[0], pair_key[1]);
  printf("largest product is %d\n", largest_product);
  return largest_product;
}

void to_string(char* str, int n){
  int i = 0, j = 10, N = 0, n_copy = n;

  while(n / j != 0){
    j *= 10;
    N++;
  }

  j /= 10;

  for(i = 0; i < N; i++){
    str[i] = (n / j) + '0';
    n %= j;
    j /= 10;
  }
  str[i] = (n_copy % 10) + '0';
  str[i+1] = '\0';
  // printf("read %s\n", str);
}
