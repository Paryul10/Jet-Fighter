#include "main.h"
#include "cuboid.h"
#include "frustum.h"

#ifndef FUEL_H
#define FUEL_H


class Fuel {
public:
    Fuel() {}
    Fuel(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speed;
    Cuboid cubes[2];
    Frustum frusts[2];
    int exist;

private:
    VAO *object;
};

#endif // Fuel_H
