#include "bomb.h"
#include "main.h"

Bomb::Bomb(float x, float y, float z)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.0;
    exist = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    cubes[0] = Cuboid(0,0,0,0.6,2,0.4,COLOR_CRIMSON);
    cubes[1] = Cuboid(1.4,0,0,1,0.8,0.6,COLOR_SILVER);
    cubes[2] = Cuboid(-1.4,0,0,1,0.8,0.6,COLOR_SILVER);

    
}

void Bomb::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

    cubes[0].draw(MVP);
    cubes[1].draw(MVP);
    cubes[2].draw(MVP);

}

// void Bomb::set_position(float x, float y, float z)
// {
//     this->position = glm::vec4(x, y, z, 0);
// }

void Bomb::tick()
{
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
    speed += 0.01;
    this->position.y -= speed;

}
