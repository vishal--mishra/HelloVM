// g++ -fPIC -shared HiShObj.c -o libHiShObj.so

#include <stdio.h>

#ifdef __cplusplus
    extern "C" void hello();
#endif

void hello()
{
    printf("Hello\n");
}
