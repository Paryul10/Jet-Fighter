#include "compass.h"
#include "main.h"
#define PI 3.14159


Compass::Compass(float x, float y, float z, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.01;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    float vertex_buffer_data[20*9];

    float r1= 2;
    for (int i = 0; i < 20; i++)
    {
        vertex_buffer_data[(9 * i)] = 0.0f;
        vertex_buffer_data[(9 * i + 1)] = 0.0f;
        vertex_buffer_data[(9 * i + 2)] = 0;

        vertex_buffer_data[(9 * i + 3)] = r1 * sin((2 * PI * i) / 20);
        vertex_buffer_data[(9 * i + 4)] = r1 * cos((2 * PI * i) / 20);
        vertex_buffer_data[(9 * i + 5)] = 0;

        vertex_buffer_data[(9 * i + 6)] = r1 * sin((2.0 * PI * (i + 1)) / 20);
        vertex_buffer_data[(9 * i + 7)] = r1 * cos((2.0 * PI * (i + 1)) / 20);
        vertex_buffer_data[(9 * i + 8)] = 0;
    }

    // float vertex_buffer_data_2[]={
    //     0.5,0,0,
    //     -0.5,0,0,
    //     0,1.8,0
    // };

    float vertex_buffer_data_2[]={
        0.5,0,0,
        -0.5,0,0,
        0,1.5,0,
    };

    float vertex_buffer_data_3[]={
        0.5,0,0,
        -0.5,0,0,
        0,-1.5,0,  
    };

    float vertex_buffer_data_4[]={
        0.2,1.7,0,
        -0.2,1.7,0,
        0,2,0,  
    };

    this->object1 = create3DObject(GL_TRIANGLES, 20 * 3, vertex_buffer_data, COLOR_BLACK2, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data_2, COLOR_RED, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data_3, COLOR_LIGHT_GREY, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data_4, COLOR_WHITE, GL_FILL);
}

void Compass::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    glm::mat4 scale = glm::scale(glm::vec3(2,2,2));

    Matrices.model *= (translate*scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object4);


    Matrices.model = glm::mat4(1.0f);
    Matrices.model *= (translate * rotate * scale);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    // draw3DObject(this->object4);

}

// void Compass::set_position(float x, float y, float z)
// {
//     this->position = glm::vec4(x, y, z, 0);
// }

void Compass::tick()
{
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
    // this->position.z -= speed;

}
