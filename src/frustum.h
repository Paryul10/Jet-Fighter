#include "main.h"

#ifndef FRUSTUM_H
#define FRUSTUM_H


class Frustum {
public:
    Frustum() {}
    Frustum(float x, float y, float z, float r1,float r2,float h, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speed;
private:
    VAO *object;
};

#endif // Frustum_H
