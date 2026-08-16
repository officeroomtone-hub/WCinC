#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define exit_message "exited successfully"

void flag_c();
void flag_m();
void flag_l();
void flag_w();

typedef struct {
  void *flag_c;
  void *flag_m;
  void *flag_l;
  void *flag_w;
} flags;

int main(int argc, char *argv[]) {
  int argument_size_in_bits(int *argument_size);
  int option;
  char input_argument[1024];

  while ((option = getopt(argc, argv, "cmlw")) != -1) {
    switch (option) {
    case 'c':
      flag_c();
      break;
    case 'm':
      flag_m();
      break;
    case 'l':
      flag_l();
      break;
    }
    return EXIT_SUCCESS;
    ;
  }

  // interactive mode if no flag is specified
  if (argc <= 1) {

    // printf("sizeof(char) = %d\n",sizeofChar );
    printf("wc clone starting up...\n");

    fgets(input_argument, sizeof(input_argument), stdin);
    input_argument[strcspn(input_argument, "\n")] = '\0';

    while (1) {

      if (strcmp(input_argument, "exit") == 0) {
        printf(exit_message);
        return EXIT_SUCCESS;
      }

      int argument_size = strlen(input_argument);
      printf("size of arg is %d bytes or %d bits\n", argument_size,
             argument_size_in_bits(&argument_size));
    }
  }

  if (argc > 1 && strcmp(argv[1], "arg") == 0) {
    printf("%s\n and sizeof %d\n", argv[1], argc - 1);
  }

  if (option == 'l') {

  } else {
    printf("%s\n", "Invalid Input: Unsupported Flag");
    return EXIT_SUCCESS;
  }

  return EXIT_SUCCESS;
}
// END OF MAIN

void flag_c() { printf("%s\n", "flag is -c"); }
void flag_m() { printf("%s\n", "flag is -m"); }
void flag_l() { printf("%s\n", "flag is -l"); }
void flag_w() { printf("%s\n", "flag is -w"); }

int argument_size_in_bits(int *argument_size) { return *argument_size * 8; }
