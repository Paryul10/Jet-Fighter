#include "main.h"
#include "frustum.h"

#ifndef VOLCANO_H
#define VOLCANO_H


class Volcano {
public:
    Volcano() {}
    Volcano(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speed;
    Frustum ftum[2];
private:
    VAO *object;
};

#endif // Volcano_H
