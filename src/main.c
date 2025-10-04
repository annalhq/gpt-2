#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

#define d_vocab 5027

struct token {
  uint32_t offset;
  uint32_t size;
};

struct decoder {
  struct token tokens[d_vocab];
  char raw[321428];
};

int main(void) {
  FILE *f = fopen("enc", "r");
  assert(f);
  fclose(f);
  printf("test\n");
}
