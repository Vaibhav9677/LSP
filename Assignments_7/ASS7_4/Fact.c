#include"Fact_no.h"
#include<stdio.h>

int Fact_Number(int iNo)
{
    if(iNo == 0)
    {
        return 0;
    }
    
    if(iNo == 1)
    {
        return 1;
    }
    else
    {
        return (iNo * Fact_Number(iNo -1));
    }
}

