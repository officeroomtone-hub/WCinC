#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define PROGRAM_NAME "wc-clone"
// copied from core utils implementation
static struct option const longopts[] = 
  {
  {"bytes", no_argument, NULL, 'c'},
  {"chars", no_argument, NULL, 'm'},
  {"lines", no_argument, NULL, 'l'},
  {"words", no_argument, NULL, 'w'},
};

/* void 
usage (int status)
{
if (status != EXIT_SUCCESS){
    printf("fail");
  };
} */

const char *exitmessage = "exited successfully\n";
int sizeofChar = sizeof(char);

int argSize_in_bit(int *argSize){
 return *argSize * 8; 
};

int main(int argc,char *argv[]) {

int argvsize = sizeof(argc)/sizeof(char);
char arg[1024];
fgets(arg, sizeof(arg), stdin);
arg [strcspn(arg, "\n")] = '\0';
int argsize = strlen(arg);

  // start loop if arg is not given
  if (argc <= 1)
  {

    //printf("sizeof(char) = %d\n",sizeofChar );
    printf("wc clone starting up...\n");

    while (1){
    printf("wc clone starting up even though it shouldn't \n");

      if (strcmp(arg, "exit") == 0){
        printf("%s\n", exitmessage);
        exit(0);
      }

      int argsize = strlen(arg);
      printf("size of arg is %d bytes or %d bits\n", argsize, argSize_in_bit(&argsize) );
      }

  } 

    if (argc > 1 && strcmp(argv[1], "arg") == 0){
    printf("%s\n and sizeof %d\n", argv[1], argc - 1);
    }

    else if (argc > 1 && strcmp(argv[1], "-l") == 0){
        int linecount = 0;
        char buffer[1024];

        while (fgets(buffer, sizeof(buffer),stdin) != NULL){
          if (buffer[0] == '\n') {
            // exit the loop for now if no input is given // 
            printf(" input is = %s\n loop ran %d times",buffer,linecount);
            perror("buffer empty, no input recieved");
            exit(1);
        } else {
            linecount++;
            printf(" input is = %s\n loop ran %d times",buffer,linecount);
      } 
    }

  } else {
        printf("%s\n", "Invalid Input: Unsupported Flag");
    }
 
  return 0;
}

