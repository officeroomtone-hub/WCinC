#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define PROGRAM_NAME = "wc-clone"

static struct option const longopts[] = 
  {
  {"bytes", no_argument, NULL, 'c'},
  {"chars", no_argument, NULL, 'm'},
  {"lines", no_argument, NULL, 'l'},
  {"words", no_argument, NULL, 'w'},
};

void 
usage (int status)
{
if (status != EXIT_SUCCESS){
    printf("fail");
  };
}

int main(int argc,char *argv[]){

setbuf(stdout, NULL);

int sizechar= sizeof(char);
const char *exitmessage = "exited successfully\n";

char arg[1024];

int argvsize = sizeof(argc)/sizeof(char);
int arg_count= argc;

  if (argc <= 1) {
    printf("sizeof(char) = %d\n",sizechar );
    printf("wc clone starting up...\n");

      while (1){

        fgets(arg, sizeof(arg), stdin);

          arg [strcspn(arg, "\n")] = '\0';

        if (strcmp(arg, "exit") == 0){
          printf("%s\n", exitmessage);
          exit(0);
        }

        int argsize = strlen(arg);
        int arg_in_bits = argsize * 8;

        printf("size of arg is %d bytes or %d bits\n", argsize, arg_in_bits);

      }
  } else {

    if (argc > 1 && strcmp(argv[1], "arg") == 0){
    printf("%s\n and sizeof %d\n", argv[1], arg_count - 1);
    }
    else if (strcmp(argv[1], "-l") == 0){
        int linecount = 0;
        char buffer[1024];

        while (fgets(buffer, sizeof(buffer),stdin) != NULL){
          if (buffer[0] == '\n') {
         // exit the loop for now if no input is given // 
          exit(0);
        }
          linecount++;
          printf(" input is = %s\n loop ran %d times",buffer,linecount);
      }

          printf("linecount: %d\n",linecount); 

    } else {
        printf("%s\n", "Invalid input or unsupported flag");
    }
  }
  return 0;
}

