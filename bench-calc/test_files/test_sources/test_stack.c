#include "stack.h"
#include <string.h>

int main(int argc, char ** argv) {
  struct double_stack * stack = double_stack_new(argc -1);
  memset(stack->items, 0, (argc -1) * sizeof(double));
  for (int i=1; i<argc; i++) {
    double_stack_push(stack, atof(argv[i]));
  }
  for (int i=argc-1; i>0; i--) {
    if (atof(argv[i]) != double_stack_pop(stack)) exit(-1);
  }
  exit(0);
}
