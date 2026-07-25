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

 void 
usage (int status)
{
if (status != EXIT_SUCCESS){
    printf("fail");
  };
} 

const char *exitmessage = "exited successfully\n";
int sizechar = sizeof(char);

int argSize_in_bit(int *argSize){
 return *argSize * 8; 
};

int main(int argc,char *argv[])
{

setbuf(stdout, NULL);

int argvsize = sizeof(argc)/sizeof(char);

char arg[1024];

 // start loop if no arg is given
  if (argc <= 1)
  {

    printf("sizeof(char) = %d\n",sizechar );
    printf("wc clone starting up...\n");

    while (1){

      fgets(arg, sizeof(arg), stdin);

      arg [strcspn(arg, "\n")] = '\0';

        if (strcmp(arg, "exit") == 0){
          printf("%s\n", exitmessage);
          exit(0);
        }

        int argsize = strlen(arg), arg_bit_size= argSize_in_bit(&argsize);
        printf("size of arg is %d bytes or %d bits\n", argsize, arg_bit_size );

      }
  } else 
    {

    if (argc > 1 && strcmp(argv[1], "arg") == 0){
    printf("%s\n and sizeof %d\n", argv[1], argc - 1);
    }

    else if (strcmp(argv[1], "-l") == 0){
        int linecount = 0;
        char buffer[1024];

        while (fgets(buffer, sizeof(buffer),stdin) != NULL){
          if (buffer[0] == '\n') {
         // exit the loop for now if no input is given // 
          perror("buffer empty ");
          exit(1);
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

