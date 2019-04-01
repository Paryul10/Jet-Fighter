#include "enemy.h"
#include "cuboid.h"
#include "main.h"

Enemy::Enemy(float x, float y, float z)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.01;
    exist = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    

    this->sides[3] = Cuboid(1.2,7.5,-.45,1,1.3,0.3,COLOR_BLACK2);
    this->sides[3].rotation = 60;
    this->sides[3].position += glm::vec3(0,-.8,2.0);

    this->sides[4] = Cuboid(1.2,7.5,0,1,1.3,0.3,COLOR_BLACK2);
    this->sides[4].rotation = 60;
    this->sides[4].position += glm::vec3(0,-.8,2.0);

    this->sides[5] = Cuboid(1.2,7.5,0.45,1,1.3,0.3,COLOR_BLACK2);
    this->sides[5].rotation = 60;
    this->sides[5].position += glm::vec3(0,-.8,2.0);


    this->sides[6] = Cuboid(-1.2,7.5,-.45,1,1.3,0.3,COLOR_BLACK2);
    this->sides[6].rotation = -60;
    this->sides[6].position += glm::vec3(0,-.8,-2.0);

    this->sides[7] = Cuboid(-1.2,7.5,0,1,1.3,0.3,COLOR_BLACK2);
    this->sides[7].rotation = -60;
    this->sides[7].position += glm::vec3(0,-.8,-2.0);

    this->sides[8] = Cuboid(-1.2,7.5,0.45,1,1.3,0.3,COLOR_BLACK2);
    this->sides[8].rotation = -60;
    this->sides[8].position += glm::vec3(0,-.8,-2.0);



    this->sides[9] = Cuboid(1.2,5,0,5,1.5,1.5,COLOR_DARKGREY);
    this->sides[9].rotation = 55;

    this->sides[10] = Cuboid(-1.2,5,0,5,1.5,1.5,COLOR_DARKGREY);
    this->sides[10].rotation = -55;

    this->sides[11] = Cuboid(0,0,0,6,3,4,COLOR_BURLYWOOD);
    
}

void Enemy::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    // glm::mat4 scale = glm::scale(glm::vec3(1,1,1));

    Matrices.model *= (translate * rotate );
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    for(int i=3;i<12;i++)
    {
        // if(i>7)
        {this->sides[i].draw(MVP);
        }
        
    }
}

// void Enemy::set_position(float x, float y, float z)
// {
//     this->position = glm::vec4(x, y, z, 0);
// }

void Enemy::tick()
{
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
    this->position.z -= speed;

}
