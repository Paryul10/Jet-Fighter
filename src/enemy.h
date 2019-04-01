#include "main.h"
#include "cuboid.h"

#ifndef ENEMY_H
#define ENEMY_H


class Enemy {
public:
    Enemy() {}
    Enemy(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speed;
    int exist ;
    Cuboid sides[15];

private:
    VAO *object;
};

#endif // Enemy_H
