#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROGRAM_NAME "wc-clone"
#define exit_message "exited successfully"

static struct option const long_opt[] = {
    {"bytes", no_argument, NULL, 'c'},
    {"chars", no_argument, NULL, 'm'},
    {"lines", no_argument, NULL, 'l'},
    {"words", no_argument, NULL, 'w'},
    {0, 0, 0, 0},
};

void usage(int status);
int argSize_in_bit(int *argSize);
int opt;

int main(int argc, char *argv[]) {
  char arg[1024];

  while ((opt = getopt(argc, argv, "cmlw")) != -1) {
    switch (opt) {
    case 'c':
      printf("lol\n");
      break;
    case 'm':
      break;
    case 'l':
      break;
    }
  }

  // start loop if arg is not given
  if (argc <= 1) {

    // printf("sizeof(char) = %d\n",sizeofChar );
    printf("wc clone starting up...\n");

    while (1) {
      fgets(arg, sizeof(arg), stdin);
      arg[strcspn(arg, "\n")] = '\0';

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

  if (argc > 1 && strcmp(argv[1], "-l") == 0) {
    int linecount = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      if (buffer[0] == '\n') {
        // exit the loop for now if no input is given //
        printf(" input is = %s\n loop ran %d times", buffer, linecount);
        perror("buffer empty, no input recieved");
      } else {
        linecount++;
        printf("-perror input is = %s\n loop ran %d times", buffer, linecount);
        return EXIT_FAILURE;
      }
    }

  } else {
    printf("%s\n", "Invalid Input: Unsupported Flag");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
};
// END OF MAIN

void usage(int status) {
  if (status != EXIT_SUCCESS) {
    printf("fail");
  } else {
    printf("success");
  }
}

int argSize_in_bit(int *argSize) { return *argSize * 8; };
