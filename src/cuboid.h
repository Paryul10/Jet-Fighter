#include "main.h"

#ifndef CUBOID_H
#define CUBOID_H


class Cuboid {
public:
    Cuboid() {}
    Cuboid(float x, float y, float z, float w, float h, float b, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
private:
    VAO *object;
};

#endif // CUBOID_H
