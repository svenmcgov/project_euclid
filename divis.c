#include <stdio.h>
#include <stdlib.h>

char* to_string(int);
int digit_count(int);
int digit_count_str(char*);
int exponent(int, int);
int char_to_digit(char);


int is_even(char*);
int div_by_3(char*);
int div_by_6(char*);

int main(void){

  /*
  printf("Digit count for 415 is: %d\n", digit_count(415));
  printf("Digit count for 6 is: %d\n", digit_count(6));
  printf("Digit count for 17 is: %d\n", digit_count(17));
  printf("Digit count for 211 is: %d\n", digit_count(211));
  printf("Digit count for 2019394 is: %d\n", digit_count(2019394));
  */
  
  char* num1 = to_string(405);
  char* num2 = to_string(1146);

  // printf("%s\n", num1);
  // printf("10 to the 3 is %d\n", exponent(10, 3));
  if(div_by_3(num1))
    printf("%s is divisible by 3.\n", num1);

  if(is_even(num2))
    printf("%s is divisible by 2.\n", num2);

  if(div_by_3(num2))
    printf("%s is divisible by 3.\n", num2);

  if(is_even(num1))
    printf("%s is divisible by 2.\n", num1);

  if(div_by_6(num2))
    printf("%s is divisible by 6.\n", num2);

  if(div_by_6(num1))
    printf("%s is divisible by 6.\n", num1);

  return 0;
}

char* to_string(int n){
  int length = 0, i = 0, n_copy = n;

  length = digit_count(n);
  int j = exponent(10, length - 1);
  char* n_str = (char*)malloc(length * sizeof(char));

  for(i = 0; i < length - 1; i++){
    *(n_str + i) = (n / j) + '0';
    n %= j;
    j /= 10;
  }
  *(n_str + i) = (n_copy % 10) + '0';

  return n_str;
}

int digit_count(int n){
  int i = 1, length = 0;
  while(n / i != 0){
    i *= 10;
    length++;
  }
  return length;
}

int digit_count_str(char* num){
  int length = 0;
  char * num_copy = num;
  while(*num_copy != '\0'){
    num_copy++;
    length++;
  }
  return length;
}
int exponent(int base, int power){
  if(power == 1)
    return base;
  return base * exponent(base, power-1);
}

int char_to_digit(char c){
  return c - '0';
}

int is_even(char* num){
  while(*(num + 1) != '\0'){
    num++;
  }
  if(*num == '2' || *num == '4' || *num == '6' || *num == '8' || *num == '0')
    return 1;

  return 0;
}

// rough draft -- will try to collapse digits into single digit
int div_by_3(char* num){
  int i = 0, sum = 0, length = digit_count_str(num);
  // int *digits = (int *) malloc(length * sizeof(int));
  for(i = 0; i < length; i++){
    sum += *(num + i) - '0';
    // *(digits + i) = *(num + i) - '0';
  }
  if(sum % 3 ==0)
    return 1;

  return 0;
}

int div_by_6(char* num){
  if(is_even(num) && div_by_3(num))
    return 1;
  return 0;
}
