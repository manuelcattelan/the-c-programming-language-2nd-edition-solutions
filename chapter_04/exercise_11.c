#include <stdio.h>
#include <stdlib.h>

#define MAX_OP_LEN 100 /* max size for operands and operators */
#define NUMBER '0'     /* signal that a number was found */

int get_from_input(char s[]);
void push_onto_stack(double val);
double pop_from_stack(void);

int main(void) {
  int c;
  /* This operand is crucial when it comes to non-commutative operators such as
   * '-', '/' and '%'. When dealing with them we must make sure that operands
   * are placed in the correct order. Since we're using a stack, the second
   * operand in these cases is the first value that we pop. */
  double second_operand;
  char s[MAX_OP_LEN];

  while ((c = get_from_input(s)) != EOF) {
    switch (c) {
      case NUMBER:
        push_onto_stack(atof(s));
        break;
      case '+':
        push_onto_stack(pop_from_stack() + pop_from_stack());
        break;
      case '*':
        push_onto_stack(pop_from_stack() * pop_from_stack());
        break;
      case '-':
        second_operand = pop_from_stack();
        push_onto_stack(pop_from_stack() - second_operand);
        break;
      case '/':
        second_operand = pop_from_stack();
        if (second_operand != 0.0) {
          push_onto_stack(pop_from_stack() / second_operand);
        } else {
          printf("error: zero divisor\n");
        }
        break;
      case '\n':
        printf("\t%.8g\n", pop_from_stack());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }

  return EXIT_SUCCESS;
}

#define STACK_SIZE 100

double stack[STACK_SIZE];
int stack_pointer = 0;

void push_onto_stack(double val) {
  if (stack_pointer < STACK_SIZE) {
    stack[stack_pointer++] = val;
  } else {
    printf("error: stack full, can't push %g\n", val);
  }
}

double pop_from_stack(void) {
  if (stack_pointer > 0) {
    return stack[--stack_pointer];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int get_from_input(char s[]) {
  static int c_prev = EOF;

  int i;
  int c;

  if (c_prev == EOF) {
    c = getchar();
  } else {
    c = c_prev;
    c_prev = EOF;
  }

  /* Skip all blank and tab characters */
  while ((s[0] = c) == ' ' || c == '\t') {
    c = getchar();
  }
  /* When we break from the while-loop, it means we've read a valid character
   * that is neither a blank or tab. We add the null terminator character to
   * make s a valid string. */
  s[1] = '\0';

  /* If what we've read is neither a digit nor a decimal point, it must be an
   * operator, in which case we simply return it to the caller. */
  if (!isdigit(c) && c != '.') {
    return c;
  }

  /* If what we've read isn't an operator, it must be an operand, in which case
   * we keep reading the string until we reach the end of the digit, starting
   * from the null terminator character. */
  i = 0;
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getchar())) {
      ;
    }
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getchar())) {
      ;
    }
  }
  s[i] = '\0';

  /* This part is crucial: when we finish reading a digit and we haven't reached
   * EOF it means we've actually read one character more than we needed, in
   * which case we "un-read" it by setting the last read character to the
   * current one, so that the next call to this function will read that instead
   * of a new one. */
  if (c != EOF) {
    c_prev = c;
  }

  return NUMBER;
}
