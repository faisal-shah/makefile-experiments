#include <stdio.h>
#include <config.h>

#if !defined(INI_STRING)
#define INI_STRING "No include"
#endif

int main(int argc, char * argv[])
{
    printf("Got this from my include: "INI_STRING"\n");
    return 0;
}
