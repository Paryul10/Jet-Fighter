#include "cuboid.h"
#include "main.h"

Cuboid::Cuboid(float x, float y, float z, float hh, float ww, float bb, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;

    float h = hh/2;
    float w = ww/2;
    float b = bb/2;

    //speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A Cuboid has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    const GLfloat vertex_buffer_data[] = {
        //top
        w, h, b,
        w, h, -b,
        -w, h, -b,
        w, h, b,
        -w, h, b,
        -w, h, -b,
        
        //bottom
        w, -h, b,
        w, -h, -b,
        -w, -h, -b,
        w, -h, b,
        -w, -h, b,
        -w, -h, -b,
        
        // front
        w, h, -b,
        w, -h, -b,
        -w, -h, -b,
        w, h, -b,
        -w, h, -b,
        -w, -h, -b,
        
        //back
        w, h, b,
        w,-h, b,
        -w, -h, b,
        w, h, b,
        -w, h, b,
        -w,-h, b,

        // lefy side
         -w, h, b,
        -w, -h, b,
        -w, h, -b,
        -w, h, -b,
        -w, -h, -b,
        -w, -h, b,

        // fight side
         w, h, b,
        w, -h, b,
        w, h, -b,
        w, h, -b,
        w, -h, -b,
        w, -h, b,

    };

    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);
}

void Cuboid::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of Cuboid arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Cuboid::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Cuboid::tick() {
   // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
