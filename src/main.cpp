#include "main.h"
#include "timer.h"
// #include "ball.h"
#include "bomb.h"
#include "enemy.h"
#include "fobject.h"
#include "jet.h"
#include "missile.h"
#include "ring.h"
#include "volcano.h"
#include "cuboid.h"
#include "water.h"
#include "score.h"
#include "arrow.h"
#include "cone.h"
#include "frustum.h"
#include "fuel.h"
#include "compass.h"

#define PI 3.14159

using namespace std;

GLMatrices Matrices;
GLuint programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/
// ------------DEclarations and definitions-----------------
// Ball ball1;
Jet jet1;
Water water_space;
Cuboid watery, base;
vector<Cuboid> bases;
vector<Score> ssd_static;
vector<Score> ssd_dynamic;
vector<Arrow> arrows;
vector<Cuboid> scene;
vector<Enemy> enemies;
vector<Ring> rings;
vector<Cone> cones;
vector<Frustum> frustums;
vector<Missile> missilese;
vector<Missile> missilesj;
vector<Volcano> volcanoes;
vector<Bomb> bombs;
vector<Fuel> fuelups;
vector<Fobject> fobjects;
Compass cmp;
int vals[15];

int heli_cam_y = 20;

int fp_v, fp_set;
int tower_v, tower_set;
int top_v, top_set;
int follow_v, follow_set;
int heli_v, heli_set;
int ccc = 0;
int ddd = 0;
int mis_count = -1;
int emis_count = 0;
int bom_count = -1;
int launch_mis;
int launch_bom;
long long int timer=0;
double xpos,ypos;
int flag;
int game_won=0;
float theta;
float phi;


int present_pos;

double sea_level;

float screen_zoom = 0.1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
glm::vec3 camera_position, camera_center, camera_up;

VAO *xaxis, *yaxis, *zaxis;

Timer t60(1.0 / 60);

// ------- axis just to ananlyze the space, remove later.-----------


void draw()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(programID);
    if (fp_set)
    {
        // camera_position = glm::vec3(jet1.position.x  , jet1.position.y + 1, jet1.position.z );
        // camera_position = glm::vec3(jet1.position.x - 502*sin((float)(jet1.yrotation * M_PI / 180.0f)), jet1.position.y-10 , jet1.position.z-502* cos((float)(jet1.yrotation * M_PI / 180.0f)));
        // camera_center = glm::vec3(jet1.position.x - 520*sin((float)(jet1.yrotation * M_PI / 180.0f)), jet1.position.y-20  , jet1.position.z- 520* cos((float)(jet1.yrotation * M_PI / 180.0f)));
        
        // // camera_center = glm::vec3(jet1.position.x - sin((float)(jet1.yrotation * M_PI / 180.0f)), jet1.position.y, jet1.position.z - cos((float)(jet1.yrotation * M_PI / 180.0f)) );
        // // camera_center = glm::vec3(jet1.position.x, jet1.position.y, jet1.position.z + 5);
        // camera_up = glm::vec3(0, 1, 0);
        camera_position = glm::vec3(jet1.position.x + 3 * sin((float)(jet1.yrotation * M_PI / 180.0f)), jet1.position.y + 0.25, jet1.position.z + 3 * cos((float)(jet1.yrotation * M_PI / 180.0f)));
        // camera_position = glm::vec3(jet1.position.x - 5 * cos((float)(jet1.yrotation * M_PI / 180.0f)), jet1.position.y + 5 , jet1.position.z + 5 * sin((float)(jet1.yrotation * M_PI / 180.0f)));

        camera_center = glm::vec3(jet1.position.x, jet1.position.y, jet1.position.z);
        camera_up = glm::vec3(0, 1, 0);
    }

    if (top_set)
    {
        // camera_position = glm::vec3(0, 50, 0);a
        camera_position = glm::vec3(jet1.position.x - 5 * sin((float)(jet1.yrotation * M_PI / 180.0f)), jet1.position.y + 90, jet1.position.z + 5 * cos((float)(jet1.yrotation * M_PI / 180.0f)));
        camera_center = glm::vec3(jet1.position.x, jet1.position.y, jet1.position.z);

      
        
        camera_up = glm::vec3(0, 1, 0);
    }

    if (tower_set)
    {
        camera_position = glm::vec3(50, 50, -40);
        camera_center = glm::vec3(jet1.position.x, jet1.position.y + 1, jet1.position.z);
        camera_up = glm::vec3(0, 1, 0);
    }

    if (follow_set)
    {
        // cout << "follow-cam\n";
        camera_position = glm::vec3(jet1.position.x + 20 * sin((float)(jet1.yrotation * M_PI / 180.0f)), jet1.position.y + 5, jet1.position.z + 20 * cos((float)(jet1.yrotation * M_PI / 180.0f)));
        // camera_position = glm::vec3(jet1.position.x - 5 * cos((float)(jet1.yrotation * M_PI / 180.0f)), jet1.position.y + 5 , jet1.position.z + 5 * sin((float)(jet1.yrotation * M_PI / 180.0f)));

        camera_center = glm::vec3(jet1.position.x, jet1.position.y, jet1.position.z);
        camera_up = glm::vec3(0, 1, 0);
    }

    if (heli_set)
    {
        // camera_position = glm::vec3(4*sin(camera_rotation_angle), heli_cam_y , 4*cos(camera_rotation_angle));
        glfwGetCursorPos(window,&xpos,&ypos);

        theta = (360*(xpos/1365) )*M_PI/180;
        phi = (360*((ypos+30)/737))*M_PI/180;

        camera_position = jet1.position - 15.0f* glm::vec3(cos(theta)*sin(phi),cos(phi),sin(theta)*sin(phi));
        
        camera_center = glm::vec3(jet1.position.x, jet1.position.y+ 2, jet1.position.z );
        camera_up = glm::vec3(0, 1, 0);
    }

    Matrices.view = glm::lookAt(camera_position, camera_center, camera_up); // Rotating Camera for 3D

    glm::mat4 VP = Matrices.projection * Matrices.view;
    
    glm::mat4 MVP; // MVP = Projection * View * Model
    Matrices.model = glm::mat4(1.0f);

    base.draw(VP);

   

    for (int i = 0; i < arrows.size(); i++)
    {
        float sf = abs(jet1.position.z - arrows[i].position.z) / (float)5;
        float dz = abs(jet1.position.z - arrows[i].position.z);
        float dy = abs(jet1.position.y - arrows[i].position.y);
        float dx = abs(jet1.position.x - arrows[i].position.x);

        float dist = sqrt(dz * dz + dy * dy + dx * dx);

        sf = (float)dist / (float)4;

        if (sf <= 1.5)
        {
            sf = 1.5;
        }

        if (sf >= 10)
        {
            sf = 10;
        }

        arrows[i].draw(VP, sf);
    }

    for(int i=0;i<bases.size();i++)
    {
        bases[i].draw(VP);
    }

    for (int i = 0; i < enemies.size(); i++)
    {
        if(enemies[i].exist)
        {
            enemies[i].draw(VP);
        }
    }

    for (int i = 0; i < missilese.size(); i++)
    {
        if (missilese[i].exist)
        {
            missilese[i].draw(VP);
        }
    }

    for (int i = 0; i < missilesj.size(); i++)
    {
        if (missilesj[i].exist)
        {
            missilesj[i].draw(VP);
        }
    }

    for (int i = 0; i < volcanoes.size(); i++)
    {
        volcanoes[i].draw(VP);
    }

    for (int i = 0; i < bombs.size(); i++)
    {
        if (bombs[i].exist)
        {
            bombs[i].draw(VP);
        }
    }

    for (int i = 0; i < fuelups.size(); i++)
    {

        if (fuelups[i].exist)
        {
            fuelups[i].draw(VP);
        }
    }

    for (int i = 0; i < rings.size(); i++)
    {
        if (rings[i].exist)
        {
            rings[i].draw(VP);
        }
    }

    for (int i = 0; i < fobjects.size(); i++)
    {
        if (fobjects[i].exist)
        {
            fobjects[i].draw(VP);
        }
    }

    watery.draw(VP);

    jet1.draw(VP);

    Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // ssd_static camera for 2D (ortho) in XY plane

    VP = Matrices.projection1 * Matrices.view;
  
    for (int i = 0; i < ssd_static.size(); i++)
    {
        ssd_static[i].draw(VP);
    }

    for (int i = 0; i < ssd_dynamic.size(); i++)
    {
        ssd_dynamic[i].draw(VP);
    }

    cmp.rotation = jet1.yrotation;
    cmp.position.x = 32;
    cmp.position.y = -34;
    cmp.draw(VP);

}

void tick_input(GLFWwindow *window)
{
    int left = glfwGetKey(window, GLFW_KEY_A);
    int right = glfwGetKey(window, GLFW_KEY_D);
    int forward = glfwGetKey(window, GLFW_KEY_W);
    int backward = glfwGetKey(window, GLFW_KEY_X);

    int up = glfwGetKey(window, GLFW_KEY_Z);
    int down = glfwGetKey(window, GLFW_KEY_C);

    int ccw = glfwGetKey(window, GLFW_KEY_Q);
    int cw = glfwGetKey(window, GLFW_KEY_E);

    fp_v = glfwGetKey(window, GLFW_KEY_Y);
    top_v = glfwGetKey(window, GLFW_KEY_U);
    tower_v = glfwGetKey(window, GLFW_KEY_I);
    follow_v = glfwGetKey(window, GLFW_KEY_O);
    heli_v = glfwGetKey(window, GLFW_KEY_P);

    if (left)
    {
        jet1.tick(0, 0, 0, 0, 1, 0);
    }

    if (right)
    {

        jet1.tick(0, 0, 0, 0, -1, 0);
    }

    if (forward)
    {
        double xc = 0.2 * sin((float)(jet1.yrotation * M_PI / 180.0f));
        double zc = 0.2 * cos((float)(jet1.yrotation * M_PI / 180.0f));
        jet1.tick(-xc, 0, -zc, 0, 0, 0);
        jet1.speed = 688;
    }

    if (backward)
    {
        double xc = 0.2 * sin((float)(jet1.yrotation * M_PI / 180.0f));
        double zc = 0.2 * cos((float)(jet1.yrotation * M_PI / 180.0f));
        jet1.tick(xc, 0, zc, 0, 0, 0);
    }

    if (up)
    {
        jet1.tick(0, 0.2, 0, 0, 0, 0);
    }

    if (down)
    {
        jet1.tick(0, -0.2, 0, 0, 0, 0);
    }

    if (ccw)
    {
        jet1.z_rot_set = 1;
        jet1.tick(0, 0, 0, 2, 0, 0);
    }

    if (cw)
    {
        jet1.z_rot_set = 1;
        jet1.tick(0, 0, 0, -2, 0, 0);
    }

    if (fp_v)
    {
        fp_set = 1;
        top_set = 0;
        tower_set = 0;
        follow_set = 0;
        heli_set = 0;
    }

    if (top_v)
    {
        fp_set = 0;
        top_set = 1;
        tower_set = 0;
        follow_set = 0;
        heli_set = 0;
    }

    if (tower_v)
    {
        fp_set = 0;
        top_set = 0;
        tower_set = 1;
        follow_set = 0;
        heli_set = 0;
    }

    if (follow_v)
    {
        fp_set = 0;
        top_set = 0;
        tower_set = 0;
        follow_set = 1;
        heli_set = 0;
    }

    if (heli_v)
    {
        fp_set = 0;
        top_set = 0;
        tower_set = 0;
        follow_set = 0;
        heli_set = 1;
    }
}

void set_ssd(int i, int value)
{
    if (value == 0)
    {
        ssd_dynamic[i].p1 = 0;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 1;
    }

    if (value == 1)
    {
        ssd_dynamic[i].p1 = 0;
        ssd_dynamic[i].p2 = 0;
        ssd_dynamic[i].p3 = 0;
        ssd_dynamic[i].p4 = 0;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 0;
        ssd_dynamic[i].p7 = 1;
    }

    if (value == 2)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 0;
        ssd_dynamic[i].p6 = 0;
        ssd_dynamic[i].p7 = 1;
    }

    if (value == 3)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 0;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 0;
    }

    if (value == 4)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 0;
        ssd_dynamic[i].p3 = 0;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 0;
    }

    if (value == 5)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 0;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 0;
    }

    if (value == 6)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 0;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 1;
    }

    if (value == 7)
    {
        ssd_dynamic[i].p1 = 0;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 0;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 0;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 0;
    }

    if (value == 8)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 1;
    }

    if (value == 9)
    {
        ssd_dynamic[i].p1 = 1;
        ssd_dynamic[i].p2 = 1;
        ssd_dynamic[i].p3 = 1;
        ssd_dynamic[i].p4 = 1;
        ssd_dynamic[i].p5 = 1;
        ssd_dynamic[i].p6 = 1;
        ssd_dynamic[i].p7 = 0;
    }
}

void tick_elements()
{

    // cout << "Points=" << jet1.points << '\n';

    if(jet1.position.y < -10)
    {
        cout << "Crashed into Water\n";
        cout << "Points= " << jet1.points << '\n';
        quit(window);
    }

    if(jet1.fuel < 0)
    {
        cout << "Crashed : Out of fuel\n";
        cout << "Points= " << jet1.points << '\n';
        quit(window);
    }

    if(game_won==1)
    {
        cout << "You Won\n";
        cout << "Points= " << jet1.points << '\n';
        quit(window);
    }
    
    timer++;
    // cout << timer << '\n';

    
    if (launch_mis == 1)
    {
        // cout << "aaya\n";
        Missile mis;
        if (mis_count <= -1 && ccc == 0)
        {
            // cout << "aaya2\n";
            mis = Missile(jet1.position.x , jet1.position.y - 1, jet1.position.z, COLOR_WHITE);
            // mis.launch_angle = jet1.zrotation;
            missilesj.push_back(mis);
            missilesj[missilesj.size()-1].xrotation = -90;
            missilesj[missilesj.size()-1].yrotation = jet1.yrotation;
            // cout << missilesj[mis_count].launch_angle << '\n';
            mis_count++;
            ccc = 1;
        }
        else
        {
            double dx = abs(jet1.position.x - missilesj[missilesj.size() - 1].position.x);
            double dy = abs(jet1.position.y - missilesj[missilesj.size() - 1].position.y);
            double dz = abs(jet1.position.z - missilesj[missilesj.size() - 1].position.z);

            double dist = sqrt((dx * dx + dy * dy + dz * dz));

            if (dist > 10 && mis_count < 5)
            {
                mis = Missile(jet1.position.x, jet1.position.y - 1, jet1.position.z , COLOR_WHITE);
                missilesj.push_back(mis);
                // mis.launch_angle = jet1.zrotation;
                missilesj[missilesj.size()-1].xrotation = -90;
                missilesj[missilesj.size()-1].yrotation = jet1.yrotation;
            // cout << missilesj[mis_count].launch_angle << '\n';

                mis_count++;
            }
        }
    }

    if (launch_bom == 1)
    {
        // cout << "aaya\n";
        Bomb bom;
        if (bom_count <= -1 && ddd == 0)
        {
            // cout << "aaya2\n";
            bom = Bomb(jet1.position.x, jet1.position.y - 3, jet1.position.z);
            bombs.push_back(bom);
            bom_count++;
            ddd = 1;
        }
        else
        {
            double dx = abs(jet1.position.x - bombs[bombs.size() - 1].position.x);
            double dy = abs(jet1.position.y - bombs[bombs.size() - 1].position.y);
            double dz = abs(jet1.position.z - bombs[bombs.size() - 1].position.z);

            double dist = sqrt((dx * dx + dy * dy + dz * dz));

            if (dist > 10)
            {
                bom =Bomb(jet1.position.x, jet1.position.y - 3, jet1.position.z);
                bombs.push_back(bom);
                bom_count++;
            }
        }
    }

    for(int i=0;i<missilesj.size();i++)
    {
        double sx,sy,sz;
        sx= -0.4 * sin((float)(missilesj[i].yrotation * M_PI / 180.0f));
        sz= -0.4 * cos((float)(missilesj[i].yrotation * M_PI / 180.0f));
        missilesj[i].tick(sx,0,sz);
    }

    for(int i=0;i<missilese.size();i++)
    {
        double sx=0,sy=0,sz=0;
        
       
        if(missilese[i].position.y<jet1.position.y)
        {
            sy = 0.1;
        }

        if(missilese[i].position.y >= jet1.position.y)
        {
            sy = -0.1;
        }
        

        if(missilese[i].position.y > jet1.position.y - 1 && missilese[i].position.y < jet1.position.y +1 && missilese[i].set==0)
        {
            // rotate by 90
            if(jet1.position.x < missilese[i].position.x)
            {
                missilese[i].zrotation = 90;
            }
            if(jet1.position.x >= missilese[i].position.x)
            {
                missilese[i].zrotation = -90;
            }
        }

        if((abs(missilese[i].zrotation) == 90) && missilese[i].set==0)
        {
            // cout << "yes\n";
            int angle ;
            if(jet1.position.x < missilese[i].position.x && jet1.position.z > missilese[i].position.z)
            {
                angle = 45;
            }
            
            if(jet1.position.x < missilese[i].position.x && jet1.position.z < missilese[i].position.z)
            {
                angle = -45;
            }
            if(jet1.position.x > missilese[i].position.x && jet1.position.z < missilese[i].position.z)
            {
                angle = -135;
            }
            if(jet1.position.x > missilese[i].position.x && jet1.position.z > missilese[i].position.z)
            {
                angle = 135;
            }

            // angle =135;
            // set=1;
            missilese[i].set = 1;
            missilese[i].xrotation = angle;
        }

    
        if(missilese[i].set==1)
        {
        // sx = -0.2 * sin((float)(missilese[i].xrotation * M_PI / 180.0f));
        //     sz = -0.2 * cos((float)(missilese[i].xrotation * M_PI / 180.0f));

            // if(missilese[i].xrotation >= 0 && missilese[i].xrotation <90)
            {
                sx = -0.2 * cos((float)(missilese[i].xrotation * M_PI / 180.0f));
                sz = 0.2 * sin((float)(missilese[i].xrotation * M_PI / 180.0f));
            }
        }



        missilese[i].tick(sx,sy,sz);
    }

    for(int i=0;i<bombs.size();i++)
    {
        bombs[i].tick();
    }

    for(int i=0;i<fobjects.size();i++)
    {
        fobjects[i].tick();
    }

    for(int i=0;i<enemies.size();i++)
    {
        double dx = abs(jet1.position.x - enemies[i].position.x);
        double dy = abs(jet1.position.y - enemies[i].position.y);
        double dz = abs(jet1.position.z - enemies[i].position.z);

        double dist = sqrt((dx * dx + dy * dy + dz * dz));

        if(enemies[i].exist)
        {
            if(dist < 30)
            {
                if(emis_count == 0)
                {
                    Missile mis;
                    mis = Missile(enemies[0].position.x,enemies[0].position.y + 4,enemies[0].position.z,COLOR_DARKRED);
                    // mis.rotation = -90;
                    missilese.push_back(mis);
                    missilese[missilese.size()-1].xrotation = 0;
                    emis_count++;
                }
                else
                {
                    double d_x = abs(missilese[missilese.size()-1].position.x - enemies[i].position.x);
                    double d_y = abs(missilese[missilese.size()-1].position.y - enemies[i].position.y);
                    double d_z = abs(missilese[missilese.size()-1].position.z - enemies[i].position.z);

                    double di_st = sqrt((d_x * d_x + d_y * d_y + d_z * d_z));        
                    if(di_st>15)
                    {
                        Missile mis;
                        mis = Missile(enemies[i].position.x,enemies[i].position.y + 4,enemies[i].position.z,COLOR_DARKRED);
                        // mis.rotation = -90;
                        missilese.push_back(mis);
                        missilese[missilese.size()-1].xrotation = 0;
                        emis_count++;    
                    }
                }
            }
        }

        
    }

    flag = 0;
    for(int i=enemies.size()-1;i>=0;i--)
    {
        if(enemies[i].exist)
        {
            present_pos=i;
            flag=1;
        }
    }
    if(flag==0)
    {
        game_won = 1;
    }

    for(int i=0;i<rings.size();i++)
    {
        int count=0;
        int set=0;
        if(jet1.position.x > rings[i].position.x-2 && jet1.position.x < rings[i].position.x + 2)
        {
            count++;
        }
        if(jet1.position.y > rings[i].position.y-4 && jet1.position.y < rings[i].position.y + 4)
        {
            count++;
        }
        if(jet1.position.z > rings[i].position.z-.5 && jet1.position.z < rings[i].position.z + .5)
        {
            count++;
        }

        if(count==3 && set==0 && rings[i].req_col==1)
        {
            set = 1;
            // cout << "prinyt" << i << '\n';
            rings[i].ishot=0;
            rings[i].exist = 0;

            // rings[i].color = COLOR_AQUAMARINE;
            Ring rin;
            rin = Ring(rings[i].position.x,rings[i].position.y,rings[i].position.z,COLOR_CYAN);
            rings.push_back(rin);
            rings[rings.size()-1].req_col  = 0;
            jet1.points += 20;
        }
    }
    // cout << present_pos << '\n';

    arrows[0].position.x = enemies[present_pos].position.x;
    arrows[0].position.y = enemies[present_pos].position.y+25;
    arrows[0].position.z = enemies[present_pos].position.z;



    for(int i=0;i<volcanoes.size();i++)
    {
        int count = 0;
        if(jet1.position.x > volcanoes[i].position.x - 9 && jet1.position.x < volcanoes[i].position.x + 9)
        {
            // cout << "YES1\n";
            count++;
        }
        if(jet1.position.y > volcanoes[i].position.y - 1 && jet1.position.y < volcanoes[i].position.y + 25)
        {
            // cout << "YES2\n";
            count++;
        }
        if(jet1.position.z > volcanoes[i].position.z - 7.5 && jet1.position.z < volcanoes[i].position.z + 7.5)
        {
            // cout << "YES3\n";
            count++;
        }

        if(count==3)
        {
            cout << "GAME OVER:-> NO FLYING ZONE CROSSED\n";
            cout << "Total Points = " << jet1.points << '\n';
            quit(window);
        }
    }


    for (int i = 0; i < fuelups.size(); i++)
    {
        fuelups[i].tick();
    }

    for (int i = 0; i < ssd_static.size(); i++)
    {

        if (i == 0) // A
        {
            // set_ssd(i, vals[i]);
            ssd_static[i].position.x = -38;
            ssd_static[i].position.y = -34;
            ssd_static[i].position.z = 0;
        }
        if (i == 1) //F
        {
            ssd_static[i].position.x = -38;
            ssd_static[i].position.y = -36;
            ssd_static[i].position.z = 0;
        }

        if (i == 2) //H
        {
            ssd_static[i].position.x = -38;
            ssd_static[i].position.y = -38;
            ssd_static[i].position.z = 0;
        }

        if (i == 3)  //P
        {
            ssd_static[i].position.x = -31;
            ssd_static[i].position.y = -36;
            ssd_static[i].position.z = 0;
        }

        if (i == 4) //S
        {
            ssd_static[i].position.x = -31;
            ssd_static[i].position.y = -38;
            ssd_static[i].position.z = 0;
        }

        if (i == 5)
        {
            ssd_static[i].position.x = -37;
            ssd_static[i].position.y = -34;
            ssd_static[i].position.z = 0;
        }

        if (i == 6)
        {
            ssd_static[i].position.x = -37;
            ssd_static[i].position.y = -36;
            ssd_static[i].position.z = 0;
        }

        if (i == 7)
        {
            ssd_static[i].position.x = -37;
            ssd_static[i].position.y = -38;
            ssd_static[i].position.z = 0;
        }

        if (i == 8)
        {
            ssd_static[i].position.x = -30;
            ssd_static[i].position.y = -36;
            ssd_static[i].position.z = 0;
        }

        if (i == 9)
        {
            ssd_static[i].position.x = -30;
            ssd_static[i].position.y = -38;
            ssd_static[i].position.z = 0;
        }

    }

    cmp.position.x = 25;
    cmp.position.y = - 25;



    if(timer>200)
    {
        timer=0;
        jet1.fuel-=3;
        jet1.points+=5;    
    }

    // cout << jet1.position.y << '\n';
    int store1 = 10 * (int)(jet1.position.y+10);
    // cout << "store1 = " << store1 << '\n';
    if(store1>999)
    {
        store1 = 999;
    }
    if(store1 < 0)
    {
        store1=0;
        vals[0]=0;
        vals[1]=0;
        vals[2]=0;
    }
    if(store1<100)
    {
        vals[0]=0;
    }
    int store2 = jet1.fuel;
    if(jet1.fuel<100)
    {
        vals[3]=0;
    }

    if(jet1.fuel<10)
    {
        vals[3]=0;
        vals[4]=0;
    }

    int store3 = jet1.health;
    if(jet1.health<100)
    {
        vals[6]=0;
    }
    if(jet1.health<10)
    {
        vals[6]=0;
        vals[7]=0;
    }

    
    int store4 = jet1.points;
    int store5 = jet1.speed;
    int c1 = 2;
    while (store1 > 0)
    {
        int digit = store1 % 10;
        vals[c1--] = digit;
        store1 /= 10;
    }

    int c2 = 5;
    while (store2 > 0)
    {
        int digit = store2 % 10;
        vals[c2--] = digit;
        store2 /= 10;
    }

    int c3 = 8;
    while (store3 > 0)
    {
        int digit = store3 % 10;
        vals[c3--] = digit;
        store3 /= 10;
    }

    int c4 = 11;
    while (store4 > 0)
    {
        int digit = store4 % 10;
        vals[c4--] = digit;
        store4 /= 10;
    }

    int c5 = 14;
    while (store5 > 0)
    {
        int digit = store5 % 10;
        vals[c5--] = digit;
        store5 /= 10;
    }

    for (int i = 0; i < ssd_dynamic.size(); i++)
    {
        set_ssd(i, vals[i]);
        if (i == 0)
        {
            ssd_dynamic[i].position.x = -36;
            ssd_dynamic[i].position.y = -34;
            ssd_dynamic[i].position.z = 0;
        }
        if (i == 1)
        {
            ssd_dynamic[i].position.x = -34.5;
            ssd_dynamic[i].position.y = -34;
            ssd_dynamic[i].position.z = 0;
        }
        if (i == 2)
        {
            ssd_dynamic[i].position.x = -33;
            ssd_dynamic[i].position.y = -34;
            ssd_dynamic[i].position.z = 0;
        }

        if (i == 3)
        {
            ssd_dynamic[i].position.x = -36;
            ssd_dynamic[i].position.y = -36;
            ssd_dynamic[i].position.z = 0;
        }
        if (i == 4)
        {
            ssd_dynamic[i].position.x = -34.5;
            ssd_dynamic[i].position.y =-36;
            ssd_dynamic[i].position.z = 0;
        }
        if (i == 5)
        {
            ssd_dynamic[i].position.x = -33;
            ssd_dynamic[i].position.y = -36;
            ssd_dynamic[i].position.z = 0;
        }

        if (i == 6)
        {
            ssd_dynamic[i].position.x = -36;
            ssd_dynamic[i].position.y = -38;
            ssd_dynamic[i].position.z = 0;
        }
        if (i == 7)
        {
            ssd_dynamic[i].position.x = -34.5;
            ssd_dynamic[i].position.y = -38;
            ssd_dynamic[i].position.z = 0;
        }
        if (i == 8)
        {
            ssd_dynamic[i].position.x = -33;
            ssd_dynamic[i].position.y = -38;
            ssd_static[i].position.z = 0;
        }

        if (i == 9)
        {
            ssd_dynamic[i].position.x = -29;
            ssd_dynamic[i].position.y = -36;
            ssd_static[i].position.z = 0;
        }
        if (i == 10)
        {
            ssd_dynamic[i].position.x = -27.5;
            ssd_dynamic[i].position.y = -36;
            ssd_static[i].position.z = 0;
        }
        if (i == 11)
        {
            ssd_dynamic[i].position.x = -26;
            ssd_dynamic[i].position.y = -36;
            ssd_static[i].position.z = 0;
        }

        if (i == 12)
        {
            ssd_dynamic[i].position.x = -29;
            ssd_dynamic[i].position.y = -38;
            ssd_static[i].position.z = 0;
        }
        if (i == 13)
        {
            ssd_dynamic[i].position.x = -27.5;
            ssd_dynamic[i].position.y = -38;
            ssd_static[i].position.z = 0;
        }
        if (i == 14)
        {
            ssd_dynamic[i].position.x = -26;
            ssd_dynamic[i].position.y = -38;
            ssd_static[i].position.z = 0;
        }
    }

    double xc = 0.08 * sin((float)(jet1.yrotation * M_PI / 180.0f));
    double zc = 0.08 * cos((float)(jet1.yrotation * M_PI / 180.0f));
    jet1.tick(-xc, 0, -zc, 0, 0, 0);
    jet1.speed = 347;
}

void initGL(GLFWwindow *window, int width, int height)
{ 
    // ------------------------initialize objects------------

    present_pos =0;

    // ball1 = Ball(0, 0, 0, COLOR_RED);
    jet1 = Jet(0, 10, 20, COLOR_RED);
    watery = Cuboid(0, -40, 0, 60, 1600, 1600, COLOR_SEABLUE);
    sea_level = -10;

    cmp = Compass(camera_center.x+25,camera_center.y-25,0,COLOR_AQUAMARINE);

    //enemies
    // base = Cuboid(20, -9.5, -40, 1, 5, 8, COLOR_KHAKHI);
    // Enemy ene;
    // ene = Enemy(20, -8, -40);
    // enemies.push_back(ene);

    //enenmis
    for(int i=0;i<10;i++)
    {
        int ex,ey,ez;

        ex = rand()%140 - 80;
        ey = -8;
        ez = -i*70 - 15;

        base = Cuboid(ex, -9.5, ez, 1, 5, 8, COLOR_KHAKHI);
        bases.push_back(base);
        Enemy ene;
        ene = Enemy(ex, -8, ez);
        enemies.push_back(ene);
    }

    Arrow aro;
    aro = Arrow(enemies[present_pos].position.x, enemies[present_pos].position.y + 25, enemies[present_pos].position.z);
    arrows.push_back(aro);
    
    //rings
    for (int i = 0; i < 10; i++)
    {
        Ring ring;
        int x, y, z;
        float xx, yy, zz;
        x = rand() % 180 - 90;
        y = rand() % 10 - 5;
        z = -i * 70;
        ring = Ring((float)x, (float)y, (float)z, COLOR_DARKRED);
        rings.push_back(ring);
    }

    //volcanoes
    for (int i = 0; i < 5; i++)
    {
        Volcano vol;
        int vx,vy,vz;
        vx = rand()%220 - 130;
        vy = -10;
        vz = -i*80 - 30;
        vol = Volcano(vx, vy, vz);
        volcanoes.push_back(vol);
    }

    //fuelups
    for (int i = 0; i < 5; i++)
    {
        Fuel fue;
        int fx,fy,fz;
        fx = rand()%200 - 100;
        fy = rand()%30 + 15;
        fz = -i*100 - 40;
        fue = Fuel(fx, fy, fz);
        fuelups.push_back(fue);
    }

    //fobjects
    for (int i = 0; i < 20; i++)
    {
        Fobject fo;
        int fox,foy,foz;
        fox = rand()%250 - 125;
        foy =  i*8 + rand()%30 + 20;
        foz = -i*90 - 59;
        fo = Fobject(fox,foy,foz, COLOR_LAVENDER);
        fobjects.push_back(fo);
    }

    follow_set = 1;

    Score inst[10];
    inst[0] = Score(camera_center.x + 12, camera_center.y + 19,0, 1, 1, 0, 1, 1, 1, 1); //A
    inst[1] = Score(camera_center.x + 12, camera_center.y + 16,0, 1, 1, 0, 0, 1, 0, 1); //F
    inst[2] = Score(camera_center.x + 12, camera_center.y + 16,0, 1, 0, 0, 1, 1, 1, 1); //H
    inst[3] = Score(camera_center.x + 12, camera_center.y + 16,0, 1, 1, 0, 1, 1, 0, 1); //P
    inst[4] = Score(camera_center.x + 12, camera_center.y + 16,0, 1, 1, 1, 0, 1, 1, 0); //S

    inst[5] = Score(camera_center.x + 13, camera_center.y + 19, 0, 1, 0, 0, 0, 0, 0, 0);
    inst[6] = Score(camera_center.x + 13, camera_center.y + 16, 0, 1, 0, 0, 0, 0, 0, 0);
    inst[7] = Score(camera_center.x + 13, camera_center.y + 16, 0, 1, 0, 0, 0, 0, 0, 0);
    inst[8] = Score(camera_center.x + 13, camera_center.y + 16, 0, 1, 0, 0, 0, 0, 0, 0);
    inst[9] = Score(camera_center.x + 13, camera_center.y + 16, 0, 1, 0, 0, 0, 0, 0, 0);


    for (int i = 0; i < 10; i++)
    {
        ssd_static.push_back(inst[i]);
    }

    Score inst2[15];

    inst2[0] = Score(camera_center.x + 14.5, camera_center.y + 19, 0, 0, 1, 1, 1, 1, 1, 1);
    inst2[1] = Score(camera_center.x + 16, camera_center.y + 19, 0, 0, 1, 1, 1, 1, 1, 1);
    inst2[2] = Score(camera_center.x + 17.5, camera_center.y + 19, 0, 0, 1, 1, 1, 1, 1, 1);

    inst2[3] = Score(camera_center.x + 14.5, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);
    inst2[4] = Score(camera_center.x + 16, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);
    inst2[5] = Score(camera_center.x + 17.5, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);

    inst2[6] = Score(camera_center.x + 14.5, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);
    inst2[7] = Score(camera_center.x + 16, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);
    inst2[8] = Score(camera_center.x + 17.5, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);

    inst2[9] = Score(camera_center.x + 14.5, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);
    inst2[10] = Score(camera_center.x + 16, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);
    inst2[11] = Score(camera_center.x + 17.5, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);

    inst2[12] = Score(camera_center.x + 14.5, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);
    inst2[13] = Score(camera_center.x + 16, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);
    inst2[14] = Score(camera_center.x + 17.5, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);

    // inst2[15] = Score(camera_center.x + 14.5, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);
    // inst2[16] = Score(camera_center.x + 16, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);
    // inst2[17] = Score(camera_center.x + 17.5, camera_center.y + 16, 0, 0, 1, 1, 1, 1, 1, 1);

    for (int i = 0; i < 15; i++)
    {
        ssd_dynamic.push_back(inst2[i]);
    }

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");

    reshapeWindow(window, width, height);

    // SKYBLUE color of the scene
    glClearColor(COLOR_SKYBLUE.r / 256.0, COLOR_SKYBLUE.g / 256.0, COLOR_SKYBLUE.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    // cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    // cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    // cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

int main(int argc, char **argv)
{
    srand(time(0));
    int width = 1260;
    int height = 1260;
    launch_mis = 0;
    window = initGLFW(width, height);

    initGL(window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window))
    {
        // Process timers

        if (t60.processTick())
        {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            detect_collisions();
            tick_input(window);

        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

void detect_collisions()
{
    for(int i=0;i<bombs.size();i++)
    {
        int count = 0;
        if(enemies[present_pos].exist==1 && bombs[i].exist==1)
        {
            if(bombs[i].position.x > enemies[present_pos].position.x - 1.5 && bombs[i].position.x < enemies[present_pos].position.x + 1.5)
            {
                // ccout << "YES1\n";
                count++;
            }
            if(bombs[i].position.y > enemies[present_pos].position.y - 2 && bombs[i].position.y < enemies[present_pos].position.y + 9)
            {
                // cout << "YES2\n";

                count++;
            }
            if(bombs[i].position.z > enemies[present_pos].position.z - 3 && bombs[i].position.z < enemies[present_pos].position.z + 3)
            {
                // cout << "YES3\n";

                count++;
            }
        
            // cout << count << '\n';
            if(count==3)
            {
                bombs[i].exist=0;
                enemies[present_pos].exist=0;
                jet1.points += 20;
                // cout << i  << "/ " << j << '\n';
                // cout << "Points=" << jet1.points << '\n';
                // cout << bombs[i].position.x << " " << bombs[i].position.y << " " << bombs[i].position.z << "\n"; 
                // cout << enemies[j].position.x << " " << enemies[j].position.y << " " << enemies[j].position.z << "\n"; 
                // cout << "GHusa and maara\n";
            }
        }  
    }

    for(int i=0;i<fuelups.size();i++)
    {

        int count=0;
        if(fuelups[i].exist)
        {
            if(fuelups[i].position.x < jet1.position.x+2.5 && fuelups[i].position.x > jet1.position.x - 2.5)
            {
                count++;
            }
            if(fuelups[i].position.y < jet1.position. y+ 2 && fuelups[i].position.y > jet1.position.y - 2)
            {
                count++;
            }
            if(fuelups[i].position.z < jet1.position.z + 1.5 && fuelups[i].position.x > jet1.position.z - 1.5)
            {
                count++;
            }
        }
        // cout << count << '\n';
        if(count==3)
        {
            fuelups[i].exist=0;
            jet1.fuel += 20;
            if(jet1.fuel>100)
            {
                jet1.fuel=100;
            }
        }
    }

    for(int i=0;i<missilese.size();i++)
    {
        int count=0;
        if(missilese[i].exist)
        {
            if(missilese[i].position.x > jet1.position.x - 3.5 && missilese[i].position.x < jet1.position.x+3.5)
            {
                count++;
            }
            if(missilese[i].position.y > jet1.position.y - 0.8 && missilese[i].position.y < jet1.position.y+ 0.8)
            {
                count++;
            }
            if(missilese[i].position.z > jet1.position.z - 1.5 && missilese[i].position.z < jet1.position.z+1.5)
            {
                count++;
            }
        }
        // cout << count << '\n';
        if(count==3)
        {
            missilese[i].exist=0;
            // jet1.fuel += 20;
            jet1.health -= 10;
            if(jet1.health <0)
            {
                cout << "Game Over : No health\n";
                cout << "Points=" << jet1.points << '\n';
                jet1.health = 0;
                quit(window);
            }
        }
    }

    for(int i=0;i<fobjects.size();i++)
    {
        int count=0;
        for(int j=0;j<missilesj.size();j++)
        {   
            count =0;
            if(missilesj[j].exist && fobjects[i].exist)
            {
                if(missilesj[j].position.x > fobjects[i].position.x - 1.8 && missilesj[j].position.x < fobjects[i].position.x + 1.8)
                {
                    count++;
                }
                if(missilesj[j].position.y > fobjects[i].position.y - 1 && missilesj[j].position.y < fobjects[i].position.y + 6)
                {
                    count++;
                }
                if(missilesj[j].position.z > fobjects[i].position.z - 1 && missilesj[j].position.z < fobjects[i].position.z + 1)
                {
                    count++;
                }
            }
            if(count==3)
            {
                missilesj[j].exist=0;
                fobjects[i].exist = 0;
                jet1.points += 25;
            }
        }
    }

    for(int j=0;j<missilesj.size();j++)
    {
        int count=0;
        if(missilesj[j].exist && enemies[present_pos].exist)
        {
            if(missilesj[j].position.x > enemies[present_pos].position.x - 1.5 && missilesj[j].position.x < enemies[present_pos].position.x + 1.5)
            {
                // cout << "YES1\n";
                count++;
            }
            if(missilesj[j].position.y > enemies[present_pos].position.y - 9 && missilesj[j].position.y < enemies[present_pos].position.y + 9)
            {
                // cout << "YES2\n";

                count++;
            }
            if(missilesj[j].position.z > enemies[present_pos].position.z - 3 && missilesj[j].position.z < enemies[present_pos].position.z + 3)
            {
                // cout << "YES3\n";

                count++;
            }
        }
        // cout << "couhnt= " << count << '\n';
        if(count==3)
        {
            // cout << "NEW\n";
            missilesj[j].exist=0;
            enemies[present_pos].exist = 0;
            jet1.points += 40;
        }
    }
}

bool detect_collision(bounding_box_t a, bounding_box_t b)
{

    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen()
{
    float top = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left = screen_center_x - 4 / screen_zoom;
    float right = screen_center_x + 4 / screen_zoom;
    // Matrices.projection = glm::ortho(left, right, bottom, top, -500.f, 500.0f);
    Matrices.projection = glm::perspective(1.57f,1.0f,10.0f,500.0f);

    Matrices.projection1 = glm::ortho(left, right, bottom, top, -2.1f, 500.0f);
}
