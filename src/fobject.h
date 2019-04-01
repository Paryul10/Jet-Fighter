#include "main.h"
#include "frustum.h"
#include "cuboid.h"

#ifndef FOBJECT_H
#define FOBJECT_H


class Fobject {
public:
    Fobject() {}
    Fobject(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speed;
    Frustum frusts[2];
    Cuboid cubes[5];
    int exist;
private:
    VAO *object;
};

#endif // Fobject_H
