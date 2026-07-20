#include <stdio.h>

int main(int argc, char *argv[]) {
int count, nl;

nl = 0;
int *nl_ptr = & nl;
while((count = getchar()) != EOF){
    if( count == '\n'){
      *nl_ptr+= 1;
    }
  printf("%d\n", nl);
  }
}
