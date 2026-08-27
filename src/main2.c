#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define exit_message "exited successfully"

int parse_flags(int);

void byte_count();
void char_count();
void word_count();
void line_count();

void input_flag_c();
void input_flag_m();
void input_flag_l();
void input_flag_w();

int main(int argc, char *argv[]) {
  int input_flags = 0;
  char input_argument[1024];
  int argument_size_in_bits(int *argument_size);

  while ((input_flags = getopt(argc, argv, "cmlw")) != -1) {
    parse_flags(input_flags);
  };
  // interactive mode if no input_flag is specified
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

  if (input_flags == 'l') {

  } else {
    printf("%s\n", "Invalid Input: Unsupported flag");
    return EXIT_SUCCESS;
  }

  return EXIT_SUCCESS;
}
// END OF MAIN

int parse_flags(int input_flags) {
  switch (input_flags) {
  case 'c':
    input_flag_c();
    break;
  case 'm':
    input_flag_m();
    break;
  case 'l':
    input_flag_l();
    break;
  default:
    printf("%s", "no input valid flag recieved. pay a bit more attention\n");
    break;
  }
  return EXIT_SUCCESS;
}

void input_flag_c() { printf("%s\n", "input_flag is -c"); }
void input_flag_m() { printf("%s\n", "input_flag is -m"); }
void input_flag_l() { printf("%s\n", "input_flag is -l"); }
void input_flag_w() { printf("%s\n", "input_flag is -w"); }

int argument_size_in_bits(int *argument_size) { return *argument_size * 8; }
