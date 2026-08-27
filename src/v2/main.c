#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int count, new_line;
  char *input_arg;

  fgets(input_arg, sizeof(input_arg), stdin);

  new_line = 0;
  int *new_line_ptr = &new_line;
  while ((count = getchar()) != EOF) {
    if (strcmp(input_arg, "exit") == 0) {
      exit(0);
    }
    if (count == '\n') {
      *new_line_ptr += 1;
    }
    printf("%d\n", new_line);
  }
}
