#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_OP_LEN 100 /* max size for operands and operators */

typedef enum {
  TOKEN_NUMBER,
  TOKEN_PLUS,
  TOKEN_MULTIPLY,
  TOKEN_MINUS,
  TOKEN_DIVIDE,
  TOKEN_NEWLINE,
  TOKEN_SIN,
  TOKEN_EXP,
  TOKEN_POW,
  TOKEN_EOF,
} TokenType;

int get_from_input(char s[]);
void push_onto_stack(double val);
double pop_from_stack(void);

int main(void) {
  TokenType c;
  /* This operand is crucial when it comes to non-commutative operators such as
   * '-', '/' and '%'. When dealing with them we must make sure that operands
   * are placed in the correct order. Since we're using a stack, the second
   * operand in these cases is the first value that we pop. */
  double second_operand;
  char s[MAX_OP_LEN];

  while ((c = get_from_input(s)) != TOKEN_EOF) {
    switch (c) {
      case TOKEN_NUMBER:
        push_onto_stack(atof(s));
        break;
      case TOKEN_PLUS:
        push_onto_stack(pop_from_stack() + pop_from_stack());
        break;
      case TOKEN_MULTIPLY:
        push_onto_stack(pop_from_stack() * pop_from_stack());
        break;
      case TOKEN_MINUS:
        second_operand = pop_from_stack();
        push_onto_stack(pop_from_stack() - second_operand);
        break;
      case TOKEN_DIVIDE:
        second_operand = pop_from_stack();
        if (second_operand != 0.0) {
          push_onto_stack(pop_from_stack() / second_operand);
        } else {
          printf("error: zero divisor\n");
        }
        break;
      case TOKEN_SIN:
        push_onto_stack(sin(pop_from_stack()));
        break;
      case TOKEN_EXP:
        push_onto_stack(exp(pop_from_stack()));
        break;
      case TOKEN_POW:
        second_operand = pop_from_stack();
        push_onto_stack(pow(pop_from_stack(), second_operand));
        break;
      case TOKEN_NEWLINE:
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

int get_char(void);
void unget_char(int c);

int get_from_input(char s[]) {
  int i;
  int c;

  /* Skip all blank and tab characters */
  while ((s[0] = c = get_char()) == ' ' || c == '\t') {
    ;
  }
  /* When we break from the while-loop, it means we've read a valid character
   * that is neither a blank or tab. We add the null terminator character to
   * make s a valid string. */
  s[1] = '\0';

  /* If what we've read is neither a digit nor a decimal point, it must be an
   * operator, in which case we simply return it to the caller mapped to the
   * correct enum value. */
  if (!isdigit(c) && c != '.') {
    switch (c) {
      case '+':
        return TOKEN_PLUS;
      case '*':
        return TOKEN_MULTIPLY;
      case '-':
        return TOKEN_MINUS;
      case '/':
        return TOKEN_DIVIDE;
      case '\n':
        return TOKEN_NEWLINE;
      case 's':
        return TOKEN_SIN;
      case 'e':
        return TOKEN_EXP;
      case 'p':
        return TOKEN_POW;
      case EOF:
        return TOKEN_EOF;
      default:
        return c;
    }
  }

  /* If what we've read isn't an operator, it must be an operand, in which case
   * we keep reading the string until we reach the end of the digit, starting
   * from the null terminator character. */
  i = 0;
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = get_char())) {
      ;
    }
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = get_char())) {
      ;
    }
  }
  s[i] = '\0';

  /* This part is crucial: when we finish reading a digit and we haven't reached
   * EOF it means we've actually read one character more than we needed, in
   * which case we "un-read" it by pushing it onto a buffer that is where
   * get_char reads from first before actually reading from input. */
  if (c != EOF) {
    unget_char(c);
  }

  return TOKEN_NUMBER;
}

#define BUFFER_SIZE 100

char char_buffer[BUFFER_SIZE];
int char_buffer_pointer = 0;

int get_char(void) {
  return (char_buffer_pointer > 0) ? char_buffer[--char_buffer_pointer]
                                   : getchar();
}

void unget_char(int c) {
  if (char_buffer_pointer >= BUFFER_SIZE) {
    printf("error: too many characters in buffer\n");
  } else {
    char_buffer[char_buffer_pointer++] = c;
  }
}
