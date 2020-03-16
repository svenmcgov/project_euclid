#include <stdio.h>
#include <stdlib.h>

void ptr_test(char*);

int main(void){
  char* str1;
  scanf("%s", str1);

  ptr_test(str1);
  char name[] = "Petra";
  printf("%s\n", name);
  printf("in main: %s\n", str1);
  // free(str1);
  return 0;
}

// return last char
void ptr_test(char* str){
  while(*(str + 1) != '\0'){
    str++;
  }

  printf("in the function: %s\n", str);
}
