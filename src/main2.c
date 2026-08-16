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
  int argSize_in_bit(int *argSize);
  int opt;
  char arg[1024];

  while ((opt = getopt(argc, argv, "cmlw")) != -1) {
    switch (opt) {
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

    fgets(arg, sizeof(arg), stdin);
    arg[strcspn(arg, "\n")] = '\0';

    while (1) {

      if (strcmp(arg, "exit") == 0) {
        printf(exit_message);
        return EXIT_SUCCESS;
      }

      int argsize = strlen(arg);
      printf("size of arg is %d bytes or %d bits\n", argsize,
             argSize_in_bit(&argsize));
    }
  }

  if (argc > 1 && strcmp(argv[1], "arg") == 0) {
    printf("%s\n and sizeof %d\n", argv[1], argc - 1);
  }

  if (opt == 'l') {

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

int argSize_in_bit(int *argSize) { return *argSize * 8; }
