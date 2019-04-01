#include "jet.h"
#include "main.h"
#define PI 3.14159
using namespace std;

Jet::Jet(float x, float y, float z, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->zrotation = 0;
    this->yrotation = 0;
    this->fuel = 100;
    this->health = 100;
    this->points = 0;
    this->speed = 347;
    // speed = 0.01;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    // float vertex_buffer_data_1[]

    float vertex_buffer_data[9 * 20 * 2000];
    float r1 = 0.4;
    long long int count = 0;

    for (int j = -1000; j < 1000; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            vertex_buffer_data[((1000 + j) * 180) + (9 * i)] = 0.0f;
            vertex_buffer_data[((1000 + j) * 180) + (9 * i + 1)] = 0.0f;
            vertex_buffer_data[((1000 + j) * 180) + (9 * i + 2)] = -((float)(j) / 1000);

            vertex_buffer_data[((1000 + j) * 180) + (9 * i + 3)] = r1 * sin((2 * PI * i) / 20);
            vertex_buffer_data[((1000 + j) * 180) + (9 * i + 4)] = r1 * cos((2 * PI * i) / 20);
            vertex_buffer_data[((1000 + j) * 180) + (9 * i + 5)] = -((float)(j) / 1000);

            vertex_buffer_data[((1000 + j) * 180) + (9 * i + 6)] = r1 * sin((2.0 * PI * (i + 1)) / 20);
            vertex_buffer_data[((1000 + j) * 180) + (9 * i + 7)] = r1 * cos((2.0 * PI * (i + 1)) / 20);
            vertex_buffer_data[((1000 + j) * 180) + (9 * i + 8)] = -((float)(j) / 1000);
        }
        // cout << ((float)-j/10) << '\n';
    }

    // float vertex_buffer_data_2[]
    static const GLfloat vertex_buffer_data2[] = {

        //back
        0.4f, -0.2f, 1.0f,
        0.3f, 0.0f, 1.0f,
        1.0f, -0.2f, 1.0f,

        //front
        0.4f, -0.2f, 0.8f,
        0.3f, 0.0f, 0.8f,
        1.0f, -0.2f, 0.8f,

        // //top
        0.4f, 0.0f, 1.0f,
        1.0f, -0.2f, 1.0f,
        1.0f, -0.2f, 0.8f,

        0.4f, 0.0f, 1.0f,
        0.4f, 0.0f, 0.8f,
        1.0f, -0.2f, 0.8f,

        // // bottom
        0.3f, -0.2f, 1.0f,
        1.0f, -0.2f, 1.0f,
        1.0f, -0.2f, 0.8f,

        0.3f, -0.2f, 0.8f,
        0.3f, -0.2f, 1.0f,
        1.0f, -0.2f, 0.8f,

        // left back
        -0.4f, -0.2f, 1.0f,
        -0.3f, 0.0f, 1.0f,
        -1.0f, -0.2f, 1.0f,

        //left front
        -0.4f, -0.2f, 0.8f,
        -0.3f, 0.0f, 0.8f,
        -1.0f, -0.2f, 0.8f,

        // //top
        -0.4f, 0.0f, 1.0f,
        -1.0f, -0.2f, 1.0f,
        -1.0f, -0.2f, 0.8f,

        -0.4f, 0.0f, 1.0f,
        -0.4f, 0.0f, 0.8f,
        -1.0f, -0.2f, 0.8f,

        // // bottom
        -0.3f, -0.2f, 1.0f,
        -1.0f, -0.2f, 1.0f,
        -1.0f, -0.2f, 0.8f,

        -0.3f, -0.2f, 0.8f,
        -0.3f, -0.2f, 1.0f,
        -1.0f, -0.2f, 0.8f};

    static const GLfloat vertex_buffer_data3[] = {

        //back
        0.4f, 0.0f, 0.2f,
        0.3f, 0.2f, 0.2f,
        2.0f, -0.0f, 0.2f,

        //front
        0.4f, -0.0f, -0.1f,
        0.3f, 0.2f, -0.1f,
        2.0f, -0.0f, -0.1f,

        // //top
        0.4f, 0.2f, 0.2f,
        2.0f, -0.0f, 0.2f,
        2.0f, -0.0f, -0.1f,

        0.4f, 0.2f, 0.2f,
        0.4f, 0.2f, -0.1f,
        2.0f, -0.0f, -0.1f,

        // // bottom
        0.3f, -0.0f, 0.2f,
        2.0f, -0.0f, 0.2f,
        2.0f, -0.0f, -0.1f,

        0.3f, -0.0f, -0.1f,
        0.3f, -0.0f, 0.2f,
        2.0f, -0.0f, -0.1f,

        // left back
        -0.4f, -0.0f, 0.2f,
        -0.3f, 0.2f, 0.2f,
        -2.0f, -0.0f, 0.2f,

        //left front
        -0.4f, -0.0f, -0.1f,
        -0.3f, 0.2f, -0.1f,
        -2.0f, -0.0f, -0.1f,

        // //top
        -0.4f, 0.2f, 0.2f,
        -2.0f, -0.0f, 0.2f,
        -2.0f, -0.0f, -0.1f,

        -0.4f, 0.2f, 0.2f,
        -0.4f, 0.2f, -0.1f,
        -2.0f, -0.0f, -0.1f,

        // // bottom
        -0.3f, -0.0f, 0.2f,
        -2.0f, -0.0f, 0.2f,
        -2.0f, -0.0f, -0.1f,

        -0.3f, -0.0f, -0.1f,
        -0.3f, -0.0f, 0.2f,
        -2.0f, -0.0f, -0.1f};

    this->cubes[0] = Cuboid(0,0.5,-0.8,0.25,0.1,0.1,COLOR_INDIGO);
    this->cubes[1] = Cuboid(0.3,0.8,-0.8,0.4,0.05,0.05,COLOR_INDIGO);
    this->cubes[2] = Cuboid(-0.3,0.8,-.8,0.4,0.05,0.05,COLOR_INDIGO);
    this->cubes[3] = Cuboid(0,0.65,-.8,0.05,.6,0.05,COLOR_INDIGO);
    this->cubes[4] = Cuboid(0,1.05,-.8,0.05,0.6,0.05,COLOR_INDIGO);


    this->object1 = create3DObject(GL_TRIANGLES, 20 * 2000 * 3, vertex_buffer_data, COLOR_LIGHT_GREY, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 6 * 3, vertex_buffer_data2, COLOR_WHITE, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 6 * 3, vertex_buffer_data2 + 6 * 9, COLOR_WHITE, GL_FILL);

    this->object3 = create3DObject(GL_TRIANGLES, 12 * 3, vertex_buffer_data3, COLOR_WHITE, GL_FILL);
}

void Jet::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    //  rotate = glm::rotate((float)(0 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // glm::mat4 rotate2;
    glm::mat4 rotate = glm::rotate((float)(this->zrotation * M_PI / 180.0f), glm::vec3(sin((float)(this->yrotation * M_PI / 180.0f)), 0, cos((float)(this->yrotation * M_PI / 180.0f))));
    rotate *= glm::rotate((float)(this->yrotation * M_PI / 180.0f), glm::vec3(0, 1, 0));

    glm::mat4 scale = glm::scale(glm::vec3(2,2,2));
    

    //  cout << this->zrotation << " " << this->yrotation << '\n';
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object4);
    draw3DObject(this->object3);
    draw3DObject(this->object2);
    draw3DObject(this->object1);
    this->cubes[0].draw(MVP);
    this->cubes[1].draw(MVP);
    this->cubes[2].draw(MVP);
    this->cubes[3].draw(MVP);
    this->cubes[4].draw(MVP);


}

// void Jet::set_position(float x, float y, float z)
// {
//     this->position = glm::vec4(x, y, z, 0);
// }

void Jet::tick(double sx, double sy, double sz, int zrot, int yrot, int flag)
{

    this->position.x += sx;
    this->position.y += sy;
    this->zrotation += zrot;
    this->yrotation += yrot;

    // this->yrotation %= 360;
    // this->zrotation %= 360;

    // this->position.x -= speed;
    // this->position.y -= speed;
    this->position.z += sz;
}
