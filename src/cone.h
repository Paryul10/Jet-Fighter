#include "main.h"

#ifndef CONE_H
#define CONE_H


class Cone {
public:
    Cone() {}
    Cone(float x, float y, float z, float r, float h, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speed;
private:
    VAO *object;
};

#endif // Cone_H
