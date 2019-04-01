#include "volcano.h"
#include "main.h"

Volcano::Volcano(float x, float y, float z)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.01;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    
    ftum[0] = Frustum(0,0,0,4,6,2,COLOR_MAROON);
    ftum[1] = Frustum(0,2,0,1.5,4,4,COLOR_MAROON);
    

}

void Volcano::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    this->ftum[0].draw(MVP);
    this->ftum[1].draw(MVP);

}

// void Volcano::set_position(float x, float y, float z)
// {
//     this->position = glm::vec4(x, y, z, 0);
// }

void Volcano::tick()
{
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
    // this->position.z -= speed;
}
