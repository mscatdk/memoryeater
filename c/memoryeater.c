#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(int argc, char** argv) {

  int step_size = 1;
  int max_allocation = INT_MAX;
  int allocated=0;
  bool wait = false;
  char* data;

  int opt;
  while ((opt = getopt(argc, argv, "s:m:w")) != -1) {
    switch (opt) {
    case 's': step_size = atoi(optarg); break;
    case 'm': max_allocation = atoi(optarg); break;
    case 'w': wait = true; break;
    default:
      printf("Usgae: %s [-w] [-s ..] [-m ...] \n", argv[0]);
      printf("-w to wait for input before allocation start \n");
      printf("-s to provide step input in MB. Default: 1 MB \n");
      printf("-m to provide max allocation. Default: unlimited \n");
      exit(-1);
    }

   }

   printf("%d %d %d \n", step_size, max_allocation, wait);

  if (wait) {
    printf("Press Any Key to start memory allocation\n");
    getchar();
  }


  int allocation_size = step_size*1024*1024;
  while ((data=malloc(allocation_size)) != NULL && allocated + step_size <= max_allocation) {
    memset(data, 0, allocation_size);
    allocated += step_size;
    printf("Allocated %d MB\n", allocated);
    sleep(1);
  }

  return 0;
}
