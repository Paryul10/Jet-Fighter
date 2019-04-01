#include "main.h"
#include "frustum.h"
#include "cone.h"
#include "cuboid.h"

#ifndef MISSILE_H
#define MISSILE_H


class Missile {
public:
    Missile() {}
    Missile(float x, float y, float z, color_t color);
    glm::vec3 position;
    float xrotation,yrotation,zrotation;
    void draw(glm::mat4 VP);
    int up;
    void set_position(float x, float y,float z);
    void tick(double sx,double sy,double sz);
    double speed;
    int exist;
    Cuboid fires[6];
    Frustum tail,body;
    Cone head;
    int type;
    int set;
    double launch_angle;
private:
    VAO *object;
};

#endif // Missile_H
