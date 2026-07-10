#include <stdio.h>
#include <string.h>



int main(int argc,char *argv[]){

setbuf(stdout, NULL);

int sizechar= sizeof(char);
const char *exitmessage = "exited successfully\n";

int argvsize = sizeof(argc)/sizeof(char);
int arg_count= argc;
if (argc <= 1) {

  printf("sizeof(char) = %d\n",sizechar );
  printf("wc clone starting up...\n");

  while (1){
    char arg[1024];
    fgets(arg, sizeof(arg), stdin);

    arg [strcspn(arg, "\n")] = '\0';

    int argsize = strlen(arg);
      int arg_in_bits = argsize * 8;

    if (strcmp(arg, "exit") == 0){
      printf("%s\n", exitmessage);
      return 0;
      }

    if (strcmp(arg, "hello") == 0) {
      printf("arg is hello\n size of arg is %d bytes or %d bits\n", argsize, arg_in_bits);
      } else {
      printf("arg is not hello\n size of arg is %d bytes or %d bits\n", argsize, arg_in_bits);
      }
    }
  } else {


  if (argc > 1 && strcmp(argv[1], "arg") == 0){
    printf("%s\n and sizeof %d\n", argv[1], arg_count - 1);
    }
  else if (strcmp(argv[1], "-l") == 0){
        int linecount = 0;
        char buffer[1024];
        buffer [strcspn(buffer, "\n")] = '\0';
        while (fgets(buffer, sizeof(buffer),stdin) != NULL){
          linecount++;
          printf("loop ran %d times", linecount);
        setbuf(stdin, NULL);
      }
        printf("linecount: %d\n",linecount); 
    } else {
        printf("%s\n", "Invalid input or unsupported flag");
    }
  }
  return 0;
}














