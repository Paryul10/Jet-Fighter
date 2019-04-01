#include "main.h"

#ifndef ARROW_H
#define ARROW_H


class Arrow {
public:
    Arrow() {}
    Arrow(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP,float sf);
    void set_position(float x, float y,float z);
    void tick();
    double speed;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;

};

#endif // Arrow_H
