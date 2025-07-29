#include <stdio.h>
#include <math.h>
typedef struct
{
    int x, y; // similar datatype
} point;

int main()
{
    float d;
    point p, q;
    printf("Co-ordinate 1: ");
    scanf("%d", &p.x);
    scanf("%d", &p.y);
    printf("Co-ordinate 2: ");
    scanf("%d", &q.x);
    scanf("%d", &q.y);
    d = sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
    printf("Distance: %g\n", d);
    return 0;
}