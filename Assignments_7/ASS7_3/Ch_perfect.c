#include"Numbers.h"
#include<stdbool.h>

bool check_Perfect(int iNo)
{
    int i = 0;
    int sum = 0;

    if(iNo <= 0 || iNo == 1)
    {
        return false;
    }

    for(i = 1; i <= iNo/2; i++)
    {
        if(iNo % i == 0)
        {
            sum = sum + i;
        }
    }

    if(iNo == sum)
    {
        return true;
    }
    else
    {
        return false;
    }

}
