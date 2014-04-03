// g++ DynUseShObj.cpp -ldl

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main()
{
    const char *home = getenv("HOME");
    const char *cppDir = "Desktop/Source/CPP";
    char path2ShObj[256];
    sprintf(path2ShObj, "%s/%s/%s", home, cppDir, "libHiShObj.so");

    void *hShObj = dlopen(path2ShObj, RTLD_NOW);
    if (hShObj == NULL) { printf("hShObj NULL: %s\n", dlerror()); return -1; }

    const void (*hFunc)() = (const void(*)()) dlsym(hShObj, "hello");
    if (hFunc == NULL) { printf("hFunc NULL: %s\n", dlerror()); return -2; }

    if (hFunc != NULL) hFunc();

    if (hShObj != NULL) dlclose(hShObj);
    return 0;
}
