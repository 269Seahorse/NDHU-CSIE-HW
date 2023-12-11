#include <stdio.h>

typedef struct {
    float x, y;
} Point;

typedef struct {
    Point point;
    float slope;
} Line;

int main(){
    Line line;
    Point pt;
    scanf("%f, %f, %f", &line.point.x, &line.point.y, &line.slope);
    scanf("%f, %f", &pt.x, &pt.y);
    pt.x -= line.point.x;
    pt.y -= line.point.y;
    if(pt.y / pt.x == line.slope) printf("Yes");
    else printf("No");
}