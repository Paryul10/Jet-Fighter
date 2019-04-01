#include "main.h"
#include "cuboid.h"

#ifndef WATER_H
#define WATER_H


class Water {
public:
    Water() {}
    Water(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speed;
    Cuboid pieces[1];
private:
    VAO *object;
};

#endif // Water_H
