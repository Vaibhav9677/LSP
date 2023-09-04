#include"Numbers.h"
#include<stdbool.h>

bool check_Prime(int iNo)
{
    int i = 0;
    bool bflag = true;

    if(iNo <= 0 || iNo == 1)
    {
        return false;
    }

    for(i = 2; i <= iNo/2; i++)
    {
        if(iNo % i == 0)
        {
            bflag = false;
            break;
        }
    }

    return bflag;
}