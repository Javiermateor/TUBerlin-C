#include <stdio.h>

int main() {
    typedef struct Point3d_ {
    float x;
    float y;
    float z;
    } Point3d;

    // Point3d my_point; // eine Variable vom Typ Point3d
    // Point3d *p;       // ein Zeiger auf einen Typ Point3d
    // p = &my_point;

    Point3d my_point = {.x = 0.5, .y = 3.14, .z = -123.4};
    Point3d *p = &my_point;
    printf("x: %f, y: %f, z: %f\n", my_point.x, my_point.y, my_point.z);
    printf("x: %f, y: %f, z: %f\n", p->x, p->y, p->z);
    return 0;
}
