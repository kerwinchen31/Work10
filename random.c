#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int rand_int(){
  int x = open("/dev/random", O_RDONLY);
  int *p;
  read(x, p, sizeof(p));
  close(x);
  return *p;
}

int main(){
  int r[10], s[10];
  for (int i = 0; i < 10; i++){
    r[i] = rand_int();
    printf("r[%d]: %d\n", i, r[i]);
  }
  printf("writing num to file.txt\n");
  int xw = open("file.txt", O_CREAT | O_WRONLY, 777);
  write(xw, &r, sizeof(r));
  close(xw);
  
  printf("reading num from file.txt\n");
  int xr = open("file.txt", O_RDONLY);
  read(xr, &s, sizeof(s));
  close(xr);

  printf("verifying same num\n");
  for (int i = 0; i < 10; i++){
    printf("s[%d]: %d\n", i, s[i]);
  }
  
}
