#include <stdio.h>
#include <ctype.h>
int main() {
  char c;
  int omitir = 1;
  while (1)
  { c = getchar();
    if (c == '(' || c == '[' || c == '{' || c == '"'){
    omitir = 0;
    }
    if(c == ')' || c == ']' || c == '}' || c == '"'){
    omitir = 1;
    }
    if ((isdigit(c)) && omitir == 1){putchar ('X');}
    if (!(isdigit(c))){
putchar(c);}
    }
    return 0;
}
