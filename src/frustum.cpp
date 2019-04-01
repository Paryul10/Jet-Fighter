#include "frustum.h"
#include "main.h"
#define PI 3.14159

Frustum::Frustum(float x, float y, float z, float r1, float r2, float h, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.01;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    float vertex_buffer_data[9 * 2 * 20];

    for (int i = 0; i < 20; i++)
    {
        vertex_buffer_data[18 * i + 3] = r1 * sin((2.0 * PI * i) / 20);
        vertex_buffer_data[18 * i + 4] = h;
        vertex_buffer_data[18 * i + 5] = r1 * cos((2.0 * PI * i) / 20);

        vertex_buffer_data[18 * i + 6] = r1 * sin((2.0 * PI * (i + 1)) / 20);
        vertex_buffer_data[18 * i + 7] = h;
        vertex_buffer_data[18 * i + 8] = r1 * cos((2.0 * PI * (i + 1)) / 20);

        vertex_buffer_data[18 * i + 0] = r2 * sin((2.0 * PI * (i + 1)) / 20);
        vertex_buffer_data[18 * i + 1] = 0;
        vertex_buffer_data[18 * i + 2] = r2 * cos((2.0 * PI * (i + 1)) / 20);



        vertex_buffer_data[18 * i + 9] = r2 * sin((2.0 * PI * (i + 1)) / 20);
        vertex_buffer_data[18 * i + 10] = 0;
        vertex_buffer_data[18 * i + 11] = r2 * cos((2.0 * PI * (i + 1)) / 20);

        vertex_buffer_data[18 * i + 12] = r1 * sin((2.0 * PI * i) / 20);
        vertex_buffer_data[18 * i + 13] = h;
        vertex_buffer_data[18 * i + 14] = r1 * cos((2.0 * PI * i) / 20);

        vertex_buffer_data[18 * i + 15] = r2 * sin((2.0 * PI * (i)) / 20);
        vertex_buffer_data[18 * i + 16] = 0;
        vertex_buffer_data[18 * i + 17] = r2 * cos((2.0 * PI * (i)) / 20);
    }

    this->object = create3DObject(GL_TRIANGLES, 20 * 2 * 3, vertex_buffer_data, color, GL_FILL);
}

void Frustum::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

// void Frustum::set_position(float x, float y, float z)
// {
//     this->position = glm::vec4(x, y, z, 0);
// }

void Frustum::tick()
{
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
    // this->position.z -= speed;
}
