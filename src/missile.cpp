#include "missile.h"
#include "main.h"
#define PI 3.14159


Missile::Missile(float x, float y, float z, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->xrotation = 0;
    this->yrotation = 0;
    this->zrotation = 0;
    up = 1;
    // cout << color << '\n';
    if(color.r == 255 && color.g == 255 && color.b == 255)
    {
        this->type = 1;
    }
    else
    {
        this->type = 2;
    }
    
    speed = 0.01;
    exist = 1;
    set=0;
    // sx=0;sy=0;sz=0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    this->body = Frustum(0, 0, 0, 0.5, 0.5, 2, COLOR_DARKGREEN);
    this->head = Cone(0, 2, 0, .5, 1, color);
    this->tail = Frustum(0, -0.7, 0, .5, 0.8, 0.7, COLOR_BLACK2);
    this->fires[0] = Cuboid(-.6,-0.9,0,0.4,0.2,0.2,COLOR_ORANGERED);
    this->fires[1] = Cuboid(-.3,-0.9,0,0.4,0.2,0.2,COLOR_ORANGERED);
    this->fires[2] = Cuboid(-0,-0.9,0,0.4,0.2,0.2,COLOR_ORANGERED);
    this->fires[3] = Cuboid(.3,-0.9,0,0.4,0.2,0.2,COLOR_ORANGERED);
    this->fires[4] = Cuboid(.6,-0.9,0,0.4,0.2,0.2,COLOR_ORANGERED);



    float vertex_buffer_data[20*9];


    for(int i=0;i<20;i++)
    {
        vertex_buffer_data[9*i]=0.0f;
        vertex_buffer_data[9*i+1]=1.5;
        vertex_buffer_data[9*i+2]=0.0f;

        vertex_buffer_data[9*i+3]=.5*sin((2.0*PI*i)/20);
        vertex_buffer_data[9*i+4]=1.5f;
        vertex_buffer_data[9*i+5]=0.5*cos((2.0*PI*i)/20);

        vertex_buffer_data[9*i+6]=0.5*sin((2.0*PI*(i+1))/20);
        vertex_buffer_data[9*i+7]=1.5;
        vertex_buffer_data[9*i+8]=0.5*cos((2.0*PI*(i+1))/20);
    }

    this->object = create3DObject(GL_TRIANGLES, 20 * 3, vertex_buffer_data, COLOR_DARKGREEN, GL_FILL);
}

void Missile::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate1 = glm::rotate((float)(this->xrotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    glm::mat4 rotate2 = glm::rotate((float)(this->yrotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotate3 = glm::rotate((float)(this->zrotation * M_PI / 180.0f), glm::vec3(0, 0, 1));

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    // glm::mat4 scale = glm::scale(glm::vec3(0.5,0.5,0.5));
    Matrices.model *= (translate * rotate3 * rotate2 * rotate1);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    this->fires[0].draw(MVP);
    this->fires[1].draw(MVP);
    this->fires[2].draw(MVP);
    this->fires[3].draw(MVP);
    this->fires[4].draw(MVP);
    
    this->body.draw(MVP);
    this->head.draw(MVP);
    this->tail.draw(MVP);
    draw3DObject(this->object);
}

// void Missile::set_position(float x, float y, float z)
// {
//     this->position = glm::vec4(x, y, z, 0);
// }

void Missile::tick(double sx,double sy,double sz)
{
    // this->rotation += speed;
    this->position.x += sx;
    this->position.y += sy;
    this->position.z += sz;
    
    
}
