#include <math.h>
#include <float.h>
#include "Utils.h"

namespace Utils
{
void PrintDivider(wchar_t Divider, int Count)
{
    printf("\n");
    for (int i = 0; i < Count; i++)
    {
        printf("%lc", Divider);
    }
    printf("\n\n");
}

bool IsFloatEqual(float Num1, float Num2)
{
    return fabsf(Num1 - Num2) <= 0.001f;
}
}
