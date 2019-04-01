#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define GLM_ENABLE_EXPERIMENTAL

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "main.h"

bool cannon_keyboard_input = true;
bool drag_pan = false, old_cki;
double drag_oldx = -1, drag_oldy = -1;
// int launch_mis;

using namespace std;

/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE)
    {
        // switch (key) {
        // case GLFW_KEY_C:
        // rectangle_rot_status = !rectangle_rot_status;
        // break;
        // case GLFW_KEY_P:
        // triangle_rot_status = !triangle_rot_status;
        // break;
        // case GLFW_KEY_X:
        //// do something ..
        // break;
        // default:
        // break;
        // }
    }
    else if (action == GLFW_PRESS)
    {
        switch (key)
        {
        case GLFW_KEY_ESCAPE:
            quit(window);
            break;
        default:
            break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar(GLFWwindow *window, unsigned int key)
{
    switch (key)
    {
    case 'L':
    case 'l':
        quit(window);
        break;
    default:
        break;
    }
}

/* Executed when a mouse button is pressed/released */
void mouseButton(GLFWwindow *window, int button, int action, int mods)
{
    switch (button)
    {
    case GLFW_MOUSE_BUTTON_LEFT:
        if (action == GLFW_PRESS)
        {
            // Do something
            // cout << "left:\n";
            launch_mis = 1;
            return;
        }
        else if (action == GLFW_RELEASE)
        {
            // cout << "left-released\n";
            launch_mis = 0;
            // Do something
        }
        break;
    case GLFW_MOUSE_BUTTON_RIGHT:
        if (action == GLFW_PRESS) {
            // cout << "right\n";
            launch_bom =1;
            return;
        }
        else if(action == GLFW_RELEASE)
        {
            // cout << "right released\n";
            launch_bom =0;
            // return;
        }
        break;
    default:
        break;
    }
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    // Do something
    // if (screen_zoom <= 0.1)
    // {
    //     screen_zoom = 0.1;
    //     // return;
    // }

    // if (screen_zoom >= 3.3)
    // {
    //     screen_zoom = 3.3;
    //     // return;
    // }

    // // cout << yoffset << '\n';
    // screen_zoom += yoffset / 10;
    // reset_screen();
}
