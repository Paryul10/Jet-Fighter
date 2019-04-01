#include "main.h"
#include "cuboid.h"

#ifndef JET_H
#define JET_H


class Jet {
public:
    Jet() {}
    Jet(float x, float y, float z, color_t color);
    glm::vec3 position;
    int zrotation;
    int yrotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick(double sx,double sy,double sz,int zrot,int yrot,int flag);
    int z_rot_set;
    int y_rot_set;
    int health;
    int fuel;
    int points;
    double speed;
    Cuboid cubes[5];
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;

};

#endif // Jet_H
