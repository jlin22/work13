#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
  int d[2], e[2];
  pipe(d);
  pipe(e);
  int f = fork();
  if (f!=0){
    close(d[0]);
    int i = 15;
    write(d[1], &i, sizeof(i));
    printf("Parent sending %d\n", i);
  }
  if (f==0){
    close(d[1]);
    int j;
    read(d[0],&j, 16);
    printf("Child doing math on %d\n", j);
    close(e[0]);
    write(e[1], &j, sizeof(j));
  }
  if (f!=0){
    close(e[1]);
    int x;
    read(e[0],&x, 16);
    printf("Parent recieved %d\n", x*x);
  }
  return 0;
}
