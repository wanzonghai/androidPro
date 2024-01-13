//
// Created by ybpcn on 2023/10/8.
//
#include <assert.h>

#include "aes.h"
#include "aes_locl.h"

void AES_ecb_encrypt(const unsigned char *in, unsigned char *out, const AES_KEY *key, const int enc)
{
    assert(in && out && key);
    assert((AES_ENCRYPT == enc) || (AES_DECRYPT == enc));

    if (AES_ENCRYPT == enc)
        AES_encrypt(in, out, key);
    else
        AES_decrypt(in, out, key);
}