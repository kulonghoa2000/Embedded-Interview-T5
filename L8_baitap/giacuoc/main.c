#include <stdio.h>

 
int main()
{
    float km;
    float giatien = 0;
    printf("\n Nhap vao so Km: ");
    scanf("%f", &km);
    if(km <= 1)
    {
        giatien = km * 14000;
    }
    else if(km <= 30 && km > 1)
    {
        giatien = (km - 1)*10000 + 1*14000;
    }
    else
    {
        giatien = 1*14000 + 29*10000 + (km - 30)*8000;
    }
    printf("\n So tien phai tra: %0.2f VND", giatien);
    return 0;
}