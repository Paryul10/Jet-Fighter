#include "main.h"
#include "cuboid.h"

#ifndef BOMB_H
#define BOMB_H


class Bomb {
public:
    Bomb() {}
    Bomb(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speed;
    int exist;
    Cuboid cubes[3];
private:
    VAO *object;
};

#endif // Bomb_H
