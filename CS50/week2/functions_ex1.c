#include <stdio.h>
#include<cs50.h>

bool valid_triangle(float x, float y, float z);

int main(void)
{
    float x = get_float("X: ");
    float y = get_float("Y: ");
    float z = get_float("Z: ");

    bool k = valid_triangle(x, y, z);

    printf("%s\n", k ? "true" : "false");

}


bool valid_triangle(float a, float b, float c)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    if((a + b <= c) || (a + c <= b) || (b + c <= a))
    {

        return false;
    }
    return true;
}

