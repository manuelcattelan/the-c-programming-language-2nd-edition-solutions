#include <stdio.h>

int main() {
  int character, parentheses_status, brackets_status, braces_status;
  parentheses_status = brackets_status = braces_status = 0;
  while ((character = getchar()) != EOF) {
    if (character == '(')
      ++parentheses_status;
    else if (character == '[')
      ++brackets_status;
    else if (character == '{')
      ++braces_status;
    else if (character == ')')
      --parentheses_status;
    else if (character == ']')
      --brackets_status;
    else if (character == '}')
      --braces_status;
  }
  if (parentheses_status != 0)
    printf("Unbalanced parenthesis\n");
  if (brackets_status != 0)
    printf("Unbalanced brackes\n");
  if (braces_status != 0)
    printf("Unbalanced braces\n");
  printf("\n");
}
