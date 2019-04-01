#include "main.h"
#include "cuboid.h"


#ifndef COMPASS_H
#define COMPASS_H


class Compass {
public:
    Compass() {}
    Compass(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speed;
    Cuboid cubes[3];
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;


};

#endif // Compass_H
