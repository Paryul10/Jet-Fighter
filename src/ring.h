#include "main.h"
#include "frustum.h"

#ifndef RING_H
#define RING_H


class Ring {
public:
    Ring() {}
    Ring(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    // color_t color2;
    int ishot;
    int req_col;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double r1,r2;
    int exist;
    Frustum frusts[2];
private:
    VAO *object1;
    VAO *object2;
};

#endif // Ring_H
