#include "arrow.h"
#include "main.h"

Arrow::Arrow(float x, float y, float z)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.01;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data_1[] = {
        
        // top 
        0.0f,-0.1f,0.0f,
        0.3f,0.0f,0.0f,
        0.3f,-0.1f,0.0f,
        0.0f,-0.1f,0.0f,
        -0.3f,0.0f,0.0f,
        -0.3f,-0.1f,0.0f,

        //mig right
        0.0f,-0.1f,0.0f,
        0.0f,-0.5f,0.0f,
        0.3f,-0.1f,0.0f,
        0.3f,-0.5f,0.0f,
        0.0f,-0.5f,0.0f,
        0.3f,-0.1f,0.0f,

        // mid left
        0.0f,-0.1f,0.0f,
        0.0f,-0.5f,0.0f,
        -0.3f,-0.1f,0.0f,
        -0.3f,-0.5f,0.0f,
        0.0f,-0.5f,0.0f,
        -0.3f,-0.1f,0.0f,

        //bottom -arrow-head
        0.0f,-0.5f,0.0f,
        0.4f,-0.5f,0.0f,
        0.0f,-0.9f,0.0f,
        0.0f,-0.5f,0.0f,
        -0.4f,-0.5f,0.0f,
        0.0f,-0.9f,0.0f
    };





    this->object1 = create3DObject(GL_TRIANGLES, 8 * 3, vertex_buffer_data_1, COLOR_ORANGE, GL_FILL);
}

void Arrow::draw(glm::mat4 VP,float sf)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    glm:: mat4 scale = glm::scale(glm::vec3(sf,sf,sf));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
}

// void Arrow::set_position(float x, float y, float z)
// {
//     this->position = glm::vec4(x, y, z, 0);
// }

void Arrow::tick()
{
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
    // this->position.z -= speed;

}
