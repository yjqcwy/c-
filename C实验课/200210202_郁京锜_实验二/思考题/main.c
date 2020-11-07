#include <stdio.h>
#include <stdlib.h>
#define LIGHTSPEED 2.99792
int main()
{
    const float ls=2.99792;

    printf("用宏常量算时，E=%.8f\n",1000*LIGHTSPEED*LIGHTSPEED);
    printf("用const常量算时，E=%.8f",1000*ls*ls);

    return 0;
}
