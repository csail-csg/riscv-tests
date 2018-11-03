#include "util.h"

int main( int argc, char* argv[] ) {
  int i = 0;
  int N = 10;
  printf("Security flush for %d times\n", N);

  setStats(1);
  for (i = 0; i < N; i++) {
    asm volatile ("csrwi 0x802, 1"); // FIXME Flush CSR addr may change
  }
  setStats(0);

  return 0;
}
