#include <stdlib.h>
#include <stdio.h>

typedef void (*fptrSet)(void*,int);
typedef int (*fptrGet)(void*);
typedef void (*fptrDisplay)();

typedef struct _function {
    fptrSet setX;
    fptrGet getX;
    fptrSet setY;
    fptrGet getY;
    fptrDisplay display;
} vFunctions;

typedef struct _shape {
    vFunctions functions;
    // Base variables
    int x;
    int y;
} Shape;

void shapeDisplay(Shape *shape) { printf("Shape\n");}
void shapeSetX(Shape *shape, int x) {shape->x=x;}
void shapeSetY(Shape *shape, int y) {shape->y=y;}
int shapeGetX(Shape *shape) { return shape->x;}
int shapeGetY(Shape *shape) { return shape->y;}

Shape* getShapeInstance() {
    Shape *shape = (Shape*)malloc(sizeof(Shape));
    shape->functions.display = shapeDisplay;
    shape->functions.setX = shapeSetX;
    shape->functions.getX = shapeGetX;
    shape->functions.setY = shapeSetY;
    shape->functions.getY = shapeGetY;
    shape->x = 100;
    shape->y = 100;
    return shape;
}

int main() {

    Shape *sptr = getShapeInstance();
    sptr->functions.setX(sptr,35);
    sptr->functions.display();
    printf("%d\n",sptr->functions.getX(sptr));
    return EXIT_SUCCESS;
}
