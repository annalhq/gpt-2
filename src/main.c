#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
  size_t offset = 0;
  size_t decoder_offset = offset;
  offset += sizeof(struct decoder);

  char *raw_mem = malloc(offset);
  struct decoder *decoder = (struct decoder *)raw_mem + decoder_offset;

  FILE *f = fopen("enc", "r");
  assert(f);

  unsigned long read = fread(decoder, 1, sizeof(struct decoder), f);
  assert(read == sizeof(struct decoder));

  printf("offset: %us, size: %u\n", decoder->tokens[0].offset,
         decoder->tokens[0].size);

  fclose(f);
  printf("test\n");
}
