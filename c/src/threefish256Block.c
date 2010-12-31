#include <threefishApi.h>
#include <stdint.h>
#include <string.h>

void threefishEncrypt256(ThreefishKey_t* keyCtx, uint64_t* input, uint64_t* output)
  {
    uint64_t b[4];
    uint64_t* k = keyCtx->key;
    uint64_t* t = keyCtx->tweak;

    memcpy(b, input, 4 * sizeof(uint64_t));

    b[1] += k[1] + t[0]; b[0] += b[1] + k[0]; b[1] = ((b[1] << 14) | (b[1] >> (64 - 14))) ^ b[0];
    b[3] += k[3]; b[2] += b[3] + k[2] + t[1]; b[3] = ((b[3] << 16) | (b[3] >> (64 - 16))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 52) | (b[3] >> (64 - 52))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 57) | (b[1] >> (64 - 57))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 23) | (b[1] >> (64 - 23))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 40) | (b[3] >> (64 - 40))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 5) | (b[3] >> (64 - 5))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 37) | (b[1] >> (64 - 37))) ^ b[2];
    b[1] += k[2] + t[1]; b[0] += b[1] + k[1]; b[1] = ((b[1] << 25) | (b[1] >> (64 - 25))) ^ b[0];
    b[3] += k[4] + 1; b[2] += b[3] + k[3] + t[2]; b[3] = ((b[3] << 33) | (b[3] >> (64 - 33))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 46) | (b[3] >> (64 - 46))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 12) | (b[1] >> (64 - 12))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 58) | (b[1] >> (64 - 58))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 22) | (b[3] >> (64 - 22))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 32) | (b[3] >> (64 - 32))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 32) | (b[1] >> (64 - 32))) ^ b[2];

    b[1] += k[3] + t[2]; b[0] += b[1] + k[2]; b[1] = ((b[1] << 14) | (b[1] >> (64 - 14))) ^ b[0];
    b[3] += k[0] + 2; b[2] += b[3] + k[4] + t[0]; b[3] = ((b[3] << 16) | (b[3] >> (64 - 16))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 52) | (b[3] >> (64 - 52))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 57) | (b[1] >> (64 - 57))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 23) | (b[1] >> (64 - 23))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 40) | (b[3] >> (64 - 40))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 5) | (b[3] >> (64 - 5))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 37) | (b[1] >> (64 - 37))) ^ b[2];
    b[1] += k[4] + t[0]; b[0] += b[1] + k[3]; b[1] = ((b[1] << 25) | (b[1] >> (64 - 25))) ^ b[0];
    b[3] += k[1] + 3; b[2] += b[3] + k[0] + t[1]; b[3] = ((b[3] << 33) | (b[3] >> (64 - 33))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 46) | (b[3] >> (64 - 46))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 12) | (b[1] >> (64 - 12))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 58) | (b[1] >> (64 - 58))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 22) | (b[3] >> (64 - 22))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 32) | (b[3] >> (64 - 32))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 32) | (b[1] >> (64 - 32))) ^ b[2];

    b[1] += k[0] + t[1]; b[0] += b[1] + k[4]; b[1] = ((b[1] << 14) | (b[1] >> (64 - 14))) ^ b[0];
    b[3] += k[2] + 4; b[2] += b[3] + k[1] + t[2]; b[3] = ((b[3] << 16) | (b[3] >> (64 - 16))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 52) | (b[3] >> (64 - 52))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 57) | (b[1] >> (64 - 57))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 23) | (b[1] >> (64 - 23))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 40) | (b[3] >> (64 - 40))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 5) | (b[3] >> (64 - 5))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 37) | (b[1] >> (64 - 37))) ^ b[2];
    b[1] += k[1] + t[2]; b[0] += b[1] + k[0]; b[1] = ((b[1] << 25) | (b[1] >> (64 - 25))) ^ b[0];
    b[3] += k[3] + 5; b[2] += b[3] + k[2] + t[0]; b[3] = ((b[3] << 33) | (b[3] >> (64 - 33))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 46) | (b[3] >> (64 - 46))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 12) | (b[1] >> (64 - 12))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 58) | (b[1] >> (64 - 58))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 22) | (b[3] >> (64 - 22))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 32) | (b[3] >> (64 - 32))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 32) | (b[1] >> (64 - 32))) ^ b[2];

    b[1] += k[2] + t[0]; b[0] += b[1] + k[1]; b[1] = ((b[1] << 14) | (b[1] >> (64 - 14))) ^ b[0];
    b[3] += k[4] + 6; b[2] += b[3] + k[3] + t[1]; b[3] = ((b[3] << 16) | (b[3] >> (64 - 16))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 52) | (b[3] >> (64 - 52))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 57) | (b[1] >> (64 - 57))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 23) | (b[1] >> (64 - 23))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 40) | (b[3] >> (64 - 40))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 5) | (b[3] >> (64 - 5))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 37) | (b[1] >> (64 - 37))) ^ b[2];
    b[1] += k[3] + t[1]; b[0] += b[1] + k[2]; b[1] = ((b[1] << 25) | (b[1] >> (64 - 25))) ^ b[0];
    b[3] += k[0] + 7; b[2] += b[3] + k[4] + t[2]; b[3] = ((b[3] << 33) | (b[3] >> (64 - 33))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 46) | (b[3] >> (64 - 46))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 12) | (b[1] >> (64 - 12))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 58) | (b[1] >> (64 - 58))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 22) | (b[3] >> (64 - 22))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 32) | (b[3] >> (64 - 32))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 32) | (b[1] >> (64 - 32))) ^ b[2];

    b[1] += k[4] + t[2]; b[0] += b[1] + k[3]; b[1] = ((b[1] << 14) | (b[1] >> (64 - 14))) ^ b[0];
    b[3] += k[1] + 8; b[2] += b[3] + k[0] + t[0]; b[3] = ((b[3] << 16) | (b[3] >> (64 - 16))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 52) | (b[3] >> (64 - 52))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 57) | (b[1] >> (64 - 57))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 23) | (b[1] >> (64 - 23))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 40) | (b[3] >> (64 - 40))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 5) | (b[3] >> (64 - 5))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 37) | (b[1] >> (64 - 37))) ^ b[2];
    b[1] += k[0] + t[0]; b[0] += b[1] + k[4]; b[1] = ((b[1] << 25) | (b[1] >> (64 - 25))) ^ b[0];
    b[3] += k[2] + 9; b[2] += b[3] + k[1] + t[1]; b[3] = ((b[3] << 33) | (b[3] >> (64 - 33))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 46) | (b[3] >> (64 - 46))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 12) | (b[1] >> (64 - 12))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 58) | (b[1] >> (64 - 58))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 22) | (b[3] >> (64 - 22))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 32) | (b[3] >> (64 - 32))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 32) | (b[1] >> (64 - 32))) ^ b[2];

    b[1] += k[1] + t[1]; b[0] += b[1] + k[0]; b[1] = ((b[1] << 14) | (b[1] >> (64 - 14))) ^ b[0];
    b[3] += k[3] + 10; b[2] += b[3] + k[2] + t[2]; b[3] = ((b[3] << 16) | (b[3] >> (64 - 16))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 52) | (b[3] >> (64 - 52))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 57) | (b[1] >> (64 - 57))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 23) | (b[1] >> (64 - 23))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 40) | (b[3] >> (64 - 40))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 5) | (b[3] >> (64 - 5))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 37) | (b[1] >> (64 - 37))) ^ b[2];
    b[1] += k[2] + t[2]; b[0] += b[1] + k[1]; b[1] = ((b[1] << 25) | (b[1] >> (64 - 25))) ^ b[0];
    b[3] += k[4] + 11; b[2] += b[3] + k[3] + t[0]; b[3] = ((b[3] << 33) | (b[3] >> (64 - 33))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 46) | (b[3] >> (64 - 46))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 12) | (b[1] >> (64 - 12))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 58) | (b[1] >> (64 - 58))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 22) | (b[3] >> (64 - 22))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 32) | (b[3] >> (64 - 32))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 32) | (b[1] >> (64 - 32))) ^ b[2];

    b[1] += k[3] + t[0]; b[0] += b[1] + k[2]; b[1] = ((b[1] << 14) | (b[1] >> (64 - 14))) ^ b[0];
    b[3] += k[0] + 12; b[2] += b[3] + k[4] + t[1]; b[3] = ((b[3] << 16) | (b[3] >> (64 - 16))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 52) | (b[3] >> (64 - 52))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 57) | (b[1] >> (64 - 57))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 23) | (b[1] >> (64 - 23))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 40) | (b[3] >> (64 - 40))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 5) | (b[3] >> (64 - 5))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 37) | (b[1] >> (64 - 37))) ^ b[2];
    b[1] += k[4] + t[1]; b[0] += b[1] + k[3]; b[1] = ((b[1] << 25) | (b[1] >> (64 - 25))) ^ b[0];
    b[3] += k[1] + 13; b[2] += b[3] + k[0] + t[2]; b[3] = ((b[3] << 33) | (b[3] >> (64 - 33))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 46) | (b[3] >> (64 - 46))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 12) | (b[1] >> (64 - 12))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 58) | (b[1] >> (64 - 58))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 22) | (b[3] >> (64 - 22))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 32) | (b[3] >> (64 - 32))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 32) | (b[1] >> (64 - 32))) ^ b[2];

    b[1] += k[0] + t[2]; b[0] += b[1] + k[4]; b[1] = ((b[1] << 14) | (b[1] >> (64 - 14))) ^ b[0];
    b[3] += k[2] + 14; b[2] += b[3] + k[1] + t[0]; b[3] = ((b[3] << 16) | (b[3] >> (64 - 16))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 52) | (b[3] >> (64 - 52))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 57) | (b[1] >> (64 - 57))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 23) | (b[1] >> (64 - 23))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 40) | (b[3] >> (64 - 40))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 5) | (b[3] >> (64 - 5))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 37) | (b[1] >> (64 - 37))) ^ b[2];
    b[1] += k[1] + t[0]; b[0] += b[1] + k[0]; b[1] = ((b[1] << 25) | (b[1] >> (64 - 25))) ^ b[0];
    b[3] += k[3] + 15; b[2] += b[3] + k[2] + t[1]; b[3] = ((b[3] << 33) | (b[3] >> (64 - 33))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 46) | (b[3] >> (64 - 46))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 12) | (b[1] >> (64 - 12))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 58) | (b[1] >> (64 - 58))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 22) | (b[3] >> (64 - 22))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 32) | (b[3] >> (64 - 32))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 32) | (b[1] >> (64 - 32))) ^ b[2];

    b[1] += k[2] + t[1]; b[0] += b[1] + k[1]; b[1] = ((b[1] << 14) | (b[1] >> (64 - 14))) ^ b[0];
    b[3] += k[4] + 16; b[2] += b[3] + k[3] + t[2]; b[3] = ((b[3] << 16) | (b[3] >> (64 - 16))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 52) | (b[3] >> (64 - 52))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 57) | (b[1] >> (64 - 57))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 23) | (b[1] >> (64 - 23))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 40) | (b[3] >> (64 - 40))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 5) | (b[3] >> (64 - 5))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 37) | (b[1] >> (64 - 37))) ^ b[2];
    b[1] += k[3] + t[2]; b[0] += b[1] + k[2]; b[1] = ((b[1] << 25) | (b[1] >> (64 - 25))) ^ b[0];
    b[3] += k[0] + 17; b[2] += b[3] + k[4] + t[0]; b[3] = ((b[3] << 33) | (b[3] >> (64 - 33))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 46) | (b[3] >> (64 - 46))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 12) | (b[1] >> (64 - 12))) ^ b[2];
    b[0] += b[1]; b[1] = ((b[1] << 58) | (b[1] >> (64 - 58))) ^ b[0];
    b[2] += b[3]; b[3] = ((b[3] << 22) | (b[3] >> (64 - 22))) ^ b[2];
    b[0] += b[3]; b[3] = ((b[3] << 32) | (b[3] >> (64 - 32))) ^ b[0];
    b[2] += b[1]; b[1] = ((b[1] << 32) | (b[1] >> (64 - 32))) ^ b[2];

    output[0] = b[0] + k[3];
    output[1] = b[1] + k[4] + t[0];
    output[2] = b[2] + k[0] + t[1];
    output[3] = b[3] + k[1] + 18;
  }

void threefishDecrypt256(ThreefishKey_t* keyCtx, uint64_t* input, uint64_t* output)
  {

    uint64_t b[4];
    uint64_t* k = keyCtx->key;
    uint64_t* t = keyCtx->tweak;
    uint64_t tmp;

    memcpy(b, input, 4 * sizeof(uint64_t));

    b[0] -= k[3];
    b[1] -= k[4] + t[0];
    b[2] -= k[0] + t[1];
    b[3] -= k[1] + 18;
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 32) | (tmp << (64 - 32)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 32) | (tmp << (64 - 32)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 58) | (tmp << (64 - 58)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 22) | (tmp << (64 - 22)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 46) | (tmp << (64 - 46)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 12) | (tmp << (64 - 12)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 25) | (tmp << (64 - 25)); b[0] -= b[1] + k[2]; b[1] -= k[3] + t[2];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 33) | (tmp << (64 - 33)); b[2] -= b[3] + k[4] + t[0]; b[3] -= k[0] + 17;
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 5) | (tmp << (64 - 5)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 37) | (tmp << (64 - 37)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 23) | (tmp << (64 - 23)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 40) | (tmp << (64 - 40)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 52) | (tmp << (64 - 52)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 57) | (tmp << (64 - 57)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 14) | (tmp << (64 - 14)); b[0] -= b[1] + k[1]; b[1] -= k[2] + t[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 16) | (tmp << (64 - 16)); b[2] -= b[3] + k[3] + t[2]; b[3] -= k[4] + 16;

    tmp = b[3] ^ b[0]; b[3] = (tmp >> 32) | (tmp << (64 - 32)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 32) | (tmp << (64 - 32)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 58) | (tmp << (64 - 58)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 22) | (tmp << (64 - 22)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 46) | (tmp << (64 - 46)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 12) | (tmp << (64 - 12)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 25) | (tmp << (64 - 25)); b[0] -= b[1] + k[0]; b[1] -= k[1] + t[0];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 33) | (tmp << (64 - 33)); b[2] -= b[3] + k[2] + t[1]; b[3] -= k[3] + 15;
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 5) | (tmp << (64 - 5)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 37) | (tmp << (64 - 37)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 23) | (tmp << (64 - 23)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 40) | (tmp << (64 - 40)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 52) | (tmp << (64 - 52)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 57) | (tmp << (64 - 57)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 14) | (tmp << (64 - 14)); b[0] -= b[1] + k[4]; b[1] -= k[0] + t[2];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 16) | (tmp << (64 - 16)); b[2] -= b[3] + k[1] + t[0]; b[3] -= k[2] + 14;

    tmp = b[3] ^ b[0]; b[3] = (tmp >> 32) | (tmp << (64 - 32)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 32) | (tmp << (64 - 32)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 58) | (tmp << (64 - 58)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 22) | (tmp << (64 - 22)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 46) | (tmp << (64 - 46)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 12) | (tmp << (64 - 12)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 25) | (tmp << (64 - 25)); b[0] -= b[1] + k[3]; b[1] -= k[4] + t[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 33) | (tmp << (64 - 33)); b[2] -= b[3] + k[0] + t[2]; b[3] -= k[1] + 13;
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 5) | (tmp << (64 - 5)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 37) | (tmp << (64 - 37)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 23) | (tmp << (64 - 23)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 40) | (tmp << (64 - 40)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 52) | (tmp << (64 - 52)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 57) | (tmp << (64 - 57)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 14) | (tmp << (64 - 14)); b[0] -= b[1] + k[2]; b[1] -= k[3] + t[0];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 16) | (tmp << (64 - 16)); b[2] -= b[3] + k[4] + t[1]; b[3] -= k[0] + 12;

    tmp = b[3] ^ b[0]; b[3] = (tmp >> 32) | (tmp << (64 - 32)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 32) | (tmp << (64 - 32)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 58) | (tmp << (64 - 58)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 22) | (tmp << (64 - 22)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 46) | (tmp << (64 - 46)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 12) | (tmp << (64 - 12)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 25) | (tmp << (64 - 25)); b[0] -= b[1] + k[1]; b[1] -= k[2] + t[2];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 33) | (tmp << (64 - 33)); b[2] -= b[3] + k[3] + t[0]; b[3] -= k[4] + 11;
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 5) | (tmp << (64 - 5)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 37) | (tmp << (64 - 37)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 23) | (tmp << (64 - 23)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 40) | (tmp << (64 - 40)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 52) | (tmp << (64 - 52)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 57) | (tmp << (64 - 57)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 14) | (tmp << (64 - 14)); b[0] -= b[1] + k[0]; b[1] -= k[1] + t[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 16) | (tmp << (64 - 16)); b[2] -= b[3] + k[2] + t[2]; b[3] -= k[3] + 10;

    tmp = b[3] ^ b[0]; b[3] = (tmp >> 32) | (tmp << (64 - 32)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 32) | (tmp << (64 - 32)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 58) | (tmp << (64 - 58)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 22) | (tmp << (64 - 22)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 46) | (tmp << (64 - 46)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 12) | (tmp << (64 - 12)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 25) | (tmp << (64 - 25)); b[0] -= b[1] + k[4]; b[1] -= k[0] + t[0];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 33) | (tmp << (64 - 33)); b[2] -= b[3] + k[1] + t[1]; b[3] -= k[2] + 9;
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 5) | (tmp << (64 - 5)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 37) | (tmp << (64 - 37)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 23) | (tmp << (64 - 23)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 40) | (tmp << (64 - 40)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 52) | (tmp << (64 - 52)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 57) | (tmp << (64 - 57)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 14) | (tmp << (64 - 14)); b[0] -= b[1] + k[3]; b[1] -= k[4] + t[2];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 16) | (tmp << (64 - 16)); b[2] -= b[3] + k[0] + t[0]; b[3] -= k[1] + 8;

    tmp = b[3] ^ b[0]; b[3] = (tmp >> 32) | (tmp << (64 - 32)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 32) | (tmp << (64 - 32)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 58) | (tmp << (64 - 58)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 22) | (tmp << (64 - 22)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 46) | (tmp << (64 - 46)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 12) | (tmp << (64 - 12)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 25) | (tmp << (64 - 25)); b[0] -= b[1] + k[2]; b[1] -= k[3] + t[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 33) | (tmp << (64 - 33)); b[2] -= b[3] + k[4] + t[2]; b[3] -= k[0] + 7;
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 5) | (tmp << (64 - 5)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 37) | (tmp << (64 - 37)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 23) | (tmp << (64 - 23)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 40) | (tmp << (64 - 40)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 52) | (tmp << (64 - 52)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 57) | (tmp << (64 - 57)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 14) | (tmp << (64 - 14)); b[0] -= b[1] + k[1]; b[1] -= k[2] + t[0];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 16) | (tmp << (64 - 16)); b[2] -= b[3] + k[3] + t[1]; b[3] -= k[4] + 6;

    tmp = b[3] ^ b[0]; b[3] = (tmp >> 32) | (tmp << (64 - 32)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 32) | (tmp << (64 - 32)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 58) | (tmp << (64 - 58)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 22) | (tmp << (64 - 22)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 46) | (tmp << (64 - 46)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 12) | (tmp << (64 - 12)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 25) | (tmp << (64 - 25)); b[0] -= b[1] + k[0]; b[1] -= k[1] + t[2];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 33) | (tmp << (64 - 33)); b[2] -= b[3] + k[2] + t[0]; b[3] -= k[3] + 5;
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 5) | (tmp << (64 - 5)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 37) | (tmp << (64 - 37)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 23) | (tmp << (64 - 23)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 40) | (tmp << (64 - 40)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 52) | (tmp << (64 - 52)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 57) | (tmp << (64 - 57)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 14) | (tmp << (64 - 14)); b[0] -= b[1] + k[4]; b[1] -= k[0] + t[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 16) | (tmp << (64 - 16)); b[2] -= b[3] + k[1] + t[2]; b[3] -= k[2] + 4;

    tmp = b[3] ^ b[0]; b[3] = (tmp >> 32) | (tmp << (64 - 32)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 32) | (tmp << (64 - 32)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 58) | (tmp << (64 - 58)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 22) | (tmp << (64 - 22)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 46) | (tmp << (64 - 46)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 12) | (tmp << (64 - 12)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 25) | (tmp << (64 - 25)); b[0] -= b[1] + k[3]; b[1] -= k[4] + t[0];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 33) | (tmp << (64 - 33)); b[2] -= b[3] + k[0] + t[1]; b[3] -= k[1] + 3;
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 5) | (tmp << (64 - 5)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 37) | (tmp << (64 - 37)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 23) | (tmp << (64 - 23)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 40) | (tmp << (64 - 40)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 52) | (tmp << (64 - 52)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 57) | (tmp << (64 - 57)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 14) | (tmp << (64 - 14)); b[0] -= b[1] + k[2]; b[1] -= k[3] + t[2];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 16) | (tmp << (64 - 16)); b[2] -= b[3] + k[4] + t[0]; b[3] -= k[0] + 2;

    tmp = b[3] ^ b[0]; b[3] = (tmp >> 32) | (tmp << (64 - 32)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 32) | (tmp << (64 - 32)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 58) | (tmp << (64 - 58)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 22) | (tmp << (64 - 22)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 46) | (tmp << (64 - 46)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 12) | (tmp << (64 - 12)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 25) | (tmp << (64 - 25)); b[0] -= b[1] + k[1]; b[1] -= k[2] + t[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 33) | (tmp << (64 - 33)); b[2] -= b[3] + k[3] + t[2]; b[3] -= k[4] + 1;
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 5) | (tmp << (64 - 5)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 37) | (tmp << (64 - 37)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 23) | (tmp << (64 - 23)); b[0] -= b[1];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 40) | (tmp << (64 - 40)); b[2] -= b[3];
    tmp = b[3] ^ b[0]; b[3] = (tmp >> 52) | (tmp << (64 - 52)); b[0] -= b[3];
    tmp = b[1] ^ b[2]; b[1] = (tmp >> 57) | (tmp << (64 - 57)); b[2] -= b[1];
    tmp = b[1] ^ b[0]; b[1] = (tmp >> 14) | (tmp << (64 - 14)); b[0] -= b[1] + k[0]; b[1] -= k[1] + t[0];
    tmp = b[3] ^ b[2]; b[3] = (tmp >> 16) | (tmp << (64 - 16)); b[2] -= b[3] + k[2] + t[1]; b[3] -= k[3];

    output[0] = b[0];
    output[1] = b[1];
    output[2] = b[2];
    output[3] = b[3];
  }