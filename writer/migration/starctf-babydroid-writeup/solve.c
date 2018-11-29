#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned* getkey(const char *a1)
{
  FILE *v1; // r6
  signed int crc; // r4
  int *pgen1; // r5
  int *pgen2; // r11
  size_t end; // r10
  int i; // r6
  int j; // r9
  unsigned int abyte; // r8
  int v9; // r0
  int v10; // r0
  int v11; // r1
  unsigned *result; // r0
  FILE *stream; // [sp+0h] [bp-8028h]
  char data[32768]; // [sp+4h] [bp-8024h]
  int v15; // [sp+8004h] [bp-24h]

  v1 = fopen(a1, "rb");
  rewind(v1);
  crc = -1;
  stream = v1;
  int gen = 0x4C11DB7;
  pgen1 = &gen;
  pgen2 = &gen;
  // printf("condition = %x\n",(*pgen1) & 1);
  do
  {
    end = fread(data, 1u, 0x8000u, v1);
    if ( end )
    {
      i = 0;
      do
      {
        j = 0;
        abyte = data[i];
        do
        {
          v9 = crc ^ (abyte >> j << 31);
          crc *= 2;
          if ( v9 <= -1 )
          {
            v10 = *pgen1;
            crc ^= v10;
          }
          ++j;
        }
        while ( j != 8 );
        ++i;
      }
      while ( i != end );
    }
    v1 = stream;
  }
  while ( !feof(stream) );
  fclose(stream);
  result = calloc(5u, 1u);
  *result = ~crc;
  return result;
}

void decrypt_jnionload(unsigned key) {
    FILE* fso = fopen("./libb.so", "rb");
    char so[0x40b0];
    memset(so, 0, 0x40b0);

    int cnt = fread(so, 1, 0x40b0, fso);
#ifdef DEBUG
    printf("Read %#x bytes\n", cnt);
    for(int i = 0;i < 0x10; ++i) {
        printf("%x\n",so[i]);
    }
    printf("\n");
#endif

    unsigned* encry = (unsigned*)(so + 0xab8);
    printf("First four bytes: %#x\n", *encry);
    for(unsigned* k = encry; k < encry + 0x420; ++k) {
        /*printf("BEFORE: %x\n", *k);*/
        *k ^= key;
        /*printf("AFTER: %x\n", *k);*/
    }
    fclose(fso);
    FILE* fwso = fopen("./libb-decrypt-jnionload.so", "wb");
    fwrite(so, 1, 0x40b0, fwso);
    fclose(fwso);
}


int main() {
    /*
    // liba.so JNI_OnLoad 方法的前四个字节
    unsigned jniload_sig = 0xAF03b5f0;
    // libb.so JNI_OnLoad 方法的前四个字节
    unsigned encry = 0xc977d6da;
    // 得到解密秘钥
    unsigned key = jniload_sig ^ encry;
    printf("%#x\n", key);
    */

    const char* fname = "./libb.so";
    unsigned *key = getkey(fname);
    printf("Check sum is %#x\n", *key);
    // 通过秘钥解密 libb.so 生成 libb-decrypt-jnionload.so
    decrypt_jnionload(*key);
    return 0;
}
