#include <stdio.h>
#include <stdlib.h>

char* to_string(int);
int to_int(char*);
int digit_count(int);
int digit_count_str(char*);
int exponent(int, int);
int char_to_digit(char);
int last_digit(char*);

int is_even(char*);
int div_by_3(char*);
int div_by_4(char*);
int div_by_5(char*);
int div_by_6(char*);
int div_by_7(char*);

int main(void){

  /* TESTS BELOW */
  char* num1 = to_string(405);
  char* num2 = to_string(1146);
  char* num3 = to_string(765048);
  char* num4 = to_string(4700);

  /*
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

  if(div_by_4(num3))
    printf("%s is divisible by 4.\n", num3);

  if(div_by_5(num1))
    printf("%s is divisible by 5.\n", num1);

  if(div_by_5(num4))
    printf("%s is divisible by 5.\n", num4);
    
  printf("Last digit: %d\n", last_digit(num1));
  printf("Last digit: %d\n", last_digit(num2));
  printf("Last digit: %d\n", last_digit(num3));
  printf("Last digit: %d\n", last_digit(num4));
  */



  free(num1);
  free(num2);
  free(num3);
  free(num4);
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

int to_int(char* num){
  int i = 0, new_num = 0, length = digit_count_str(num);
  int length_copy = length;

  for(i = 0; i < length; i++){
    new_num += char_to_digit(num[i])* exponent(10, length_copy - 1);
    length_copy--;
  }
  return new_num;
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
  if(power == 0)
    return 1;
  if(power == 1)
    return base;
  return base * exponent(base, power-1);
}

int char_to_digit(char c){
  return c - '0';
}

int last_digit(char * num){
  while(*(num+1) != '\0')
    num++;

  int last_dig = char_to_digit(*num);
  return last_dig;
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
  for(i = 0; i < length; i++){
    sum += *(num + i) - '0';
  }
  if(sum % 3 ==0)
    return 1;

  return 0;
}

/* just check the last two digits */
int div_by_4(char* num){
  while(*(num + 1) != '\0'){
    num++;
  }
  num--;
  int last_two_digits = to_int(num);
  if(last_two_digits % 4 == 0)
    return 1;
  // printf("%d\n", new_num);
  return 0;
}

/* only check last digit */
// need to update to check last two digits for '0'
int div_by_5(char* num){
  while(*(num + 1) != '\0'){
    num++;
  }
  int length = digit_count_str(num);
  if(*num == '5')
    return 1;

  if(*num == '0') // && length > 1)
    return 1;
  return 0;
}

int div_by_6(char* num){
  if(is_even(num) && div_by_3(num))
    return 1;
  return 0;
}

int div_by_7(char* num){
  int last_dig = last_digit(num);
  printf("%d\n", last_dig);

  return 0;
}
