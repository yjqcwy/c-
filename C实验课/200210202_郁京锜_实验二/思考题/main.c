#include <stdio.h>
#include <stdlib.h>
#define LIGHTSPEED 2.99792
int main()
{
    const float ls=2.99792;

    printf("�ú곣����ʱ��E=%.8f\n",1000*LIGHTSPEED*LIGHTSPEED);
    printf("��const������ʱ��E=%.8f",1000*ls*ls);

    return 0;
}
