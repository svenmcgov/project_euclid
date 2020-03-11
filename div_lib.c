#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* to_string(int);
int to_int(char*);
int digit_count(int);
int digit_count_str(char*);
int exponent(int, int);
int char_to_digit(char);
int last_digit(char*);
void str_drop_last(char*);

int is_even(char*);
int div_by_3(char*);
int div_by_4(char*);
int div_by_5(char*);
int div_by_6(char*);
int div_by_7(char*);
int div_by_8(char*);
int div_by_9(char*);
int div_by_10(char*);


int div_by_12(char*);

int div_by_14(char*);
int div_by_15(char*);
int div_by_18(char*);
int div_by_20(char*);

int main(void){

  /* TESTS BELOW */
  char* num1 = to_string(405);
  char* num2 = to_string(1146);
  char* num3 = to_string(765048);
  char* num4 = to_string(4700);

  char* num5 = to_string(49);
  char* num6 = to_string(21);
  char* num7 = to_string(77);
  char* num8 = to_string(22687);

  char* num9 = to_string(72);
  char* num10 = to_string(1008);


  // printf("%s\n\n", num9);

  if(div_by_18(num9))
    printf("%s is divisible by 18.\n", num9);

  if(div_by_18(num10))
    printf("%s is divisible by 18.\n", num10);

  // printf("%s\n\n", num9);
  if(div_by_10(num9))
    printf("%s is divisible by 10.\n", num9);

  if(div_by_10(num10))
    printf("%s is divisible by 10.\n", num10);

  /*
  if(div_by_7(num5))
    printf("%s is divisible by 7.\n", num5);

  if(div_by_7(num6))
    printf("%s is divisible by 7.\n", num6);

  if(div_by_7(num7))
    printf("%s is divisible by 7.\n", num7);

  if(div_by_7(num8))
    printf("%s is divisible by 7.\n", num8);

  if(is_even(num2))
    printf("%s is divisible by 2.\n", num2);



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

  str_drop_last(num1);
  printf("Drop end test: %s\n", num1);

  */

  free(num1);
  free(num2);
  free(num3);
  free(num4);
  free(num5);
  free(num6);
  free(num7);
  free(num8);
  free(num9);
  free(num10);

  return 0;
}

char* to_string(int n){
  int length = 0, i = 0, n_copy = n;

  length = digit_count(n);
  int j = exponent(10, length - 1);
  char* n_str = (char*)malloc(length * sizeof(char) + sizeof(char));

  for(i = 0; i < length - 1; i++){
    *(n_str + i) = (n / j) + '0';
    n %= j;
    j /= 10;
  }
  *(n_str + i) = (n_copy % 10) + '0';
  *(n_str + i + 1) = '\0';
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
  if(power < 0){
    printf("%s\n", "Power must be positive (returns int not double)");
    return 1;
  }

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

void str_drop_last(char* num){
  while(*(num+1) != '\0')
    num++;
  *num = '\0';
}

int is_even(char* num){
  while(*(num + 1) != '\0')
    num++;

  if(*num == '2' || *num == '4' || *num == '6' || *num == '8' || *num == '0')
    return 1;

  return 0;
}

// collapse into single digit and then comparison check
int div_by_3(char* num){
  int i = 0, sum = 0, length = digit_count_str(num), new_length = length;
  char *new_num = malloc(100 * sizeof(char));
  strcpy(new_num, num);

  while(new_length > 1){
    sum = 0;
    for(i = 0; i < new_length; i++){
      sum += *(new_num + i) - '0';
    }
    strcpy(new_num, to_string(sum));
    new_length = digit_count(sum);
    // printf("\n* new length %d /// new num %s *\n", new_length, new_num);
  }
  free(new_num);
  // printf("\n\nSum reduced to %d\n\n", sum);
  if(sum == 3 || sum == 6 || sum == 9)
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
int div_by_5(char* num){
  while(*(num + 1) != '\0'){
    num++;
  }
  // printf("%c\n", *num);
  int length = digit_count_str(num);
  if(*num == '5')
    return 1;

  if(*num == '0') // && length > 1)
    return 1;
  return 0;
}

/* check if div by 2 and 3*/
int div_by_6(char* num){
  if(is_even(num) && div_by_3(num))
    return 1;
  return 0;
}

/* tricky divisibility test...  */
int div_by_7(char* num){
  char* num_copy = malloc(100 * sizeof(char));
  strcpy(num_copy, num);
  int last_dig = last_digit(num_copy);
  str_drop_last(num_copy);
  int first_digits = to_int(num_copy);
  int new_num = first_digits - 2 * last_dig;;

  while(new_num > 7){
    char* new_num_copy = to_string(new_num);
    last_dig = last_digit(new_num_copy);
    str_drop_last(new_num_copy);
    first_digits = to_int(new_num_copy);
    free(new_num_copy);
    new_num = first_digits - 2 * last_dig;
  }
  free(num_copy);
  // printf("number reduced to: %d\n", new_num);
  if(new_num == 7 || new_num == (-7) || new_num == 0 || new_num == 14 || new_num == (-14))
    return 1;

  return 0;
}

int div_by_8(char* num){
  while(*(num + 3) != '\0')
    num++;

  int last_three_digits = to_int(num);
  if(last_three_digits % 8 == 0)
    return 1;
  return 0;
}

int div_by_9(char* num){
  int i = 0, sum = 0, length = digit_count_str(num), new_length = length;
  char *new_num = malloc(100 * sizeof(char));
  strcpy(new_num, num);

  while(new_length > 1){
    sum = 0;
    for(i = 0; i < new_length; i++){
      sum += *(new_num + i) - '0';
    }
    strcpy(new_num, to_string(sum));
    new_length = digit_count(sum);
    // printf("\n* new length %d /// new num %s *\n", new_length, new_num);
    free(new_num);
    if(sum == 9)
      return 1;
  }
  return 0;
}

int div_by_10(char* num){
  if(is_even(num) && div_by_5(num))
    return 1;
  return 0;
}

int div_by_12(char* num){
  if(div_by_3(num) && div_by_4(num))
    return 1;
  return 0;
}

int div_by_14(char* num){
  if(is_even(num) && div_by_7(num))
    return 1;
  return 0;
}
int div_by_15(char* num){
  if(div_by_3(num) && div_by_5(num))
    return 1;
  return 0;
}

int div_by_18(char* num){
  if(is_even(num) && div_by_9(num))
    return 1;
  return 0;
}

int div_by_20(char* num){
  if(div_by_4(num) && div_by_5(num))
    return 1;
  return 0;
}
