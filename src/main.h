#ifndef MAIN_H
#define MAIN_H

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


extern int launch_mis;
extern int launch_bom;


struct color_t {
    int r;
    int g;
    int b;
};

// nonedit.cpp
GLFWwindow *initGLFW(int width, int height);
GLuint     LoadShaders(const char *vertex_file_path, const char *fragment_file_path);
struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, const GLfloat *color_buffer_data, GLenum fill_mode = GL_FILL);
struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode = GL_FILL);
struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, const color_t color, GLenum fill_mode = GL_FILL);
void       draw3DObject(struct VAO *vao);

// input.cpp
void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods);
void keyboardChar(GLFWwindow *window, unsigned int key);
void mouseButton(GLFWwindow *window, int button, int action, int mods);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

// other_handlers.cpp
void error_callback(int error, const char *description);
void quit(GLFWwindow *window);
void reshapeWindow(GLFWwindow *window, int width, int height);

// Types
struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int    NumVertices;
};
typedef struct VAO VAO;

struct GLMatrices {
    glm::mat4 projection;
    glm::mat4 projection1;

    glm::mat4 model;
    glm::mat4 view;
    GLuint    MatrixID;
};

extern GLMatrices Matrices;

// ---- Logic ----

enum direction_t { DIR_UP, DIR_RIGHT, DIR_DOWN, DIR_LEFT };

struct bounding_box_t {
    float x;
    float y;
    float width;
    float height;
};

bool detect_collision(bounding_box_t a, bounding_box_t b);

void detect_collisions();

extern float screen_zoom, screen_center_x, screen_center_y;
void reset_screen();

// ---- Colors ----
extern const color_t COLOR_RED;
extern const color_t COLOR_YELLOW;
extern const color_t COLOR_CYAN;

extern const color_t COLOR_GOLDEN;

extern const color_t COLOR_PINK;
extern const color_t COLOR_LAVENDER;
extern const color_t COLOR_WHITE;

extern const color_t COLOR_FORESTGREEN;
extern const color_t COLOR_AQUAMARINE;
extern const color_t COLOR_MAROON;

extern const color_t COLOR_DARKRED;
extern const color_t COLOR_CRIMSON;
extern const color_t COLOR_ORANGERED;

extern const color_t COLOR_ORANGE;
extern const color_t COLOR_KHAKHI;
extern const color_t COLOR_LIGHTYELLOW;

extern const color_t COLOR_LAWNGREEN;
extern const color_t COLOR_GREENYELLOW;
extern const color_t COLOR_OLIVE;


extern const color_t COLOR_TURQUOISE;
extern const color_t COLOR_TEAL;
extern const color_t COLOR_DEEPSKYBLUE;

extern const color_t COLOR_CADETBLUE;
extern const color_t COLOR_SLATEBLUE;
extern const color_t COLOR_NAVY;

extern const color_t COLOR_VIOLET;
extern const color_t COLOR_DARKVIOLET;
extern const color_t COLOR_INDIGO;


extern const color_t COLOR_GREEN;
extern const color_t COLOR_DARKGREEN;

extern const color_t COLOR_BLUE;
extern const color_t COLOR_BLACK;
extern const color_t COLOR_BLACK2;
extern const color_t COLOR_SEABLUE;
extern const color_t COLOR_SKYBLUE;


extern const color_t COLOR_BACKGROUND;
extern const color_t COLOR_LIGHT_GREY;
extern const color_t COLOR_DARKGREY;
extern const color_t COLOR_SILVER;
extern const color_t COLOR_BURLYWOOD;
extern const color_t COLOR_SADDLEBROWN;
extern const color_t COLOR_SIENNA;


#endif
