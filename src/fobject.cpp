#include "fobject.h"
#include "main.h"

Fobject::Fobject(float x, float y, float z, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 90;
    speed = 0.005;
    exist = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    cubes[0] = Cuboid(0,0,0,1,1,1,color);
    frusts[0] = Frustum(0,3,0,3,2,2,COLOR_CADETBLUE);  
    frusts[1] = Frustum(0,3,0,2,3,2,COLOR_CADETBLUE); 
    cubes[1] = Cuboid(0.5,2,0.5,3.1,0.1,0.1,COLOR_SILVER);
    cubes[1].rotation = 10;
    cubes[2] = Cuboid(-0.5,2,-0.5,3.1,0.1,0.1,COLOR_SILVER); 
    cubes[2].rotation = -10;

    cubes[3] = Cuboid(0.5,2,-0.5,3.1,0.1,0.1,COLOR_SILVER); 
    cubes[3].rotation = -10;

    cubes[4] = Cuboid(-0.5,2,0.5,3.1,0.1,0.1,COLOR_SILVER); 
    cubes[4].rotation = 10;



}

void Fobject::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    cubes[0].draw(MVP);
    frusts[0].draw(MVP);
    frusts[1].draw(MVP);
    cubes[1].draw(MVP);
    cubes[2].draw(MVP);
    cubes[3].draw(MVP);
    cubes[4].draw(MVP);


}

// void Fobject::set_position(float x, float y, float z)
// {
//     this->position = glm::vec4(x, y, z, 0);
// }

void Fobject::tick()
{
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
    this->position.y -= speed;

}
