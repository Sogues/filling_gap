#pragma once
#include <stdio.h>

// ��˻���
void tobin(int a, char* str)
{
    char *p = (char*)&a, c = 0, f = 0, pos = -1;  // pָ��a���׵�ַ
    for (int o = 0; o < 4; ++o)
    {
        // printf("%x ", p[3 - o]);
        for (int i = 0; i < 8; ++i)
        {
            c = p[3 - o] & (1 << (7 - i));
            // if (!f && !(f = c)) continue;
            str[++pos] = c ? '1' : '0';
        }
    }
    // printf("\n");
}
