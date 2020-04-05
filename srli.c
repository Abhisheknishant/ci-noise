#include <immintrin.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  __m512i v = _mm512_set1_epi64(~INT64_C(0));
  __m512i r1 = _mm512_srli_epi64(v, 0x042a);
  __m512i r2 = _mm512_srli_epi64(v, 0x042a & 0xff);

  printf("0x%016" PRIx64 "\n", *((int64_t*) (&r1)));
  printf("0x%016" PRIx64 "\n", *((int64_t*) (&r2)));

  return EXIT_SUCCESS;
}
