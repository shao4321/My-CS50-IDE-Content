#include <stdio.h>


int cal_perimeter(int h, int w);
int cal_area(int h, int w);


int main(void)
{
    int height, width, perimeter, area;

    printf("Height: ");
    scanf("%d", &height);

    printf("Width: ");
    scanf("%d", &width);

    perimeter = cal_perimeter(height, width);
    area = cal_area(height, width);

    printf("Perimeter of the rectangle = %d\n", perimeter);
    printf("Area of the rectangle = %d\n", area);
    printf("\n");

}

int cal_perimeter(int h, int w)
{
    int peri;
    peri = 2*h + 2*w;
    return peri;
}

int cal_area(int h, int w)
{
    int ar;
    ar = h * w;
    return ar;
}