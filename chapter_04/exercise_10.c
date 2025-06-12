#include <stdio.h>
#include <stdlib.h>

#define MAX_OP_LEN 100 /* max size for operands and operators */
#define NUMBER '0'     /* signal that a number was found */

int get_from_input(char line[], int line_len, char token[]);
int read_line(char line[]);
void push_onto_stack(double val);
double pop_from_stack(void);

int main(void) {
  int c;
  /* This operand is crucial when it comes to non-commutative operators such as
   * '-', '/' and '%'. When dealing with them we must make sure that operands
   * are placed in the correct order. Since we're using a stack, the second
   * operand in these cases is the first value that we pop. */
  double second_operand;
  char token[MAX_OP_LEN];
  char line[MAX_OP_LEN];
  int line_len;

  while ((line_len = read_line(line)) > 0) {
    while ((c = get_from_input(line, line_len, token)) != EOF) {
      switch (c) {
        case NUMBER:
          push_onto_stack(atof(token));
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
          printf("error: unknown command %s\n", token);
          break;
      }
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

int get_from_input(char line[], int line_len, char token[]) {
  static int i = 0;

  int j = 0;
  int c;

  /* If the line index (i) has exceed the length of the line while skipping
   * blank and tab characters, it means that the line was made entirely by
   * blank and tab characters and we should reset it, returning EOF to signal
   * that we should read another line. */
  if (i >= line_len) {
    i = 0;
    return EOF;
  }

  /* Skip all blank and tab characters */
  while (i < line_len && ((c = line[i]) == ' ' || c == '\t')) {
    ++i;
  }

  /* If the line index (i) has exceed the length of the line while skipping
   * blank and tab characters, it means that the line was made entirely by
   * blank and tab characters and we should reset it, returning EOF to signal
   * that we should read another line. */
  if (i >= line_len) {
    i = 0;
    return EOF;
  }

  /* When we break from the while-loop, it means we've read a valid character
   * that is neither a blank or tab. We add the null terminator character to
   * make s a valid string. */
  c = line[i++];
  token[j++] = c;
  token[j] = '\0';

  /* If what we've read is neither a digit nor a decimal point, it must be an
   * operator, in which case we simply return it to the caller. */
  if (!isdigit(c) && c != '.') {
    return c;
  }

  /* If what we've read isn't an operator, it must be an operand, in which case
   * we keep reading the string until we reach the end of the digit, starting
   * from the null terminator character. */
  if (isdigit(c)) {
    while (i < line_len && isdigit(c = line[i])) {
      token[++j] = c;
      ++i;
    }
  }
  if (i < line_len && line[i] == '.') {
    token[j++] = line[i++];
    while (i < line_len && isdigit(c = line[i])) {
      token[j++] = c;
      ++i;
    }
  }
  token[j] = '\0';

  return NUMBER;
}

int read_line(char line[]) {
  int c;
  /* Current position in the line array, which serves as index for storing
   * characters from the line being read. */
  int c_pos = 0;

  /* The reason we don't stop reading the line after we exceed the array size is
   * that we want to prevent leftover characters from being interpreted as part
   * of the next line. */
  while ((c = getchar()) != EOF && c != '\n') {
    if (c_pos < MAX_OP_LEN - 1) {
      line[c_pos++] = c;
    }
  }
  /* Since we do not break out of the above for-loop when the length of the
   * line being scanned is greater than the maximum allowed, the check below
   * is essential in order to know if we can add the newline character we just
   * read into the line. */
  if (c == '\n' && c_pos < MAX_OP_LEN - 1) {
    line[c_pos++] = c;
  }
  line[c_pos] = '\0';

  /* The reason we return the size of everything that fit into our line array
   * rather than the actual length of each input line is that this value isused
   * later by the strip_line function in order to know the length of the line
   * without having to re-compute it. */
  return c_pos;
}
