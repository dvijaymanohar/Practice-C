#include <stdio.h>

int main(int argc, char *argv[]) {
  for (unsigned int i = 0; i < 8; i++) {
    printf("\rVijay Manohar");
    fflush(stdout);
  }

  return 0;
}