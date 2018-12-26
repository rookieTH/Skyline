/**
 * This project (GLSL_Project1) is created by Fahim Hasan Khan (fahimhasan.khan [at] ucalgary.ca)
 * based on the works of Andrew Robert Owens (arowens [at] ucalgary.ca)
 * who is a PhD student at Graphics Jungle, University of Calgary
 *
 * File:	main.cpp
 *
 * Summary:
 *
 * This is a (very) basic program to
 * 1) load shaders from external files, and make a shader program
 * 2) make Vertex Array Object and Vertex Buffer Object for the quad
 *
 **/

#include <iostream>
#include <cmath>
#include <chrono>
#include <limits>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "ShaderTools.h"
#include "Vec3f.h"
#include "Mat4f.h"
#include "OpenGLMatrixTools.h"
#include "Camera.h"

//==================== GLOBAL VARIABLES ====================//
/*	Put here for simplicity. Feel free to restructure into
*	appropriate classes or abstractions.
*/

// Drawing Program
GLuint basicProgramID;
GLuint basicProgramID1;
GLuint basicProgramID2;

// Data needed for Cube
GLuint vaoID;
GLuint vertBufferID;
Mat4f M;

///car
GLuint tr1_vaoID;
GLuint tr1_vertBufferID;
Mat4f tr1_M;
GLuint tr2_vaoID;
GLuint tr2_vertBufferID;
Mat4f tr2_M;
GLuint tr3_vaoID;
GLuint tr3_vertBufferID;
Mat4f tr3_M;
GLuint tr4_vaoID;
GLuint tr4_vertBufferID;
Mat4f tr4_M;


GLuint wheel1_vaoID;
GLuint wheel1_vertBufferID;
Mat4f wheel1_M;

GLuint wheel2_vaoID;
GLuint wheel2_vertBufferID;
Mat4f wheel2_M;


GLuint car1_vaoID;
GLuint car1_vertBufferID;
Mat4f car1_M;
GLuint car2_vaoID;
GLuint car2_vertBufferID;
Mat4f car2_M;
GLuint car3_vaoID;
GLuint car3_vertBufferID;
Mat4f car3_M;

///car window
GLuint carw3_vaoID;
GLuint carw3_vertBufferID;
Mat4f carw3_M;

///ride
GLuint ride_vaoID;
GLuint ride_vertBufferID;
Mat4f ride_M;

///seats
GLuint seat1a_vaoID;
GLuint seat1a_vertBufferID;
Mat4f seat1a_M;

GLuint seat1b_vaoID;
GLuint seat1b_vertBufferID;
Mat4f seat1b_M;

GLuint seat2a_vaoID;
GLuint seat2a_vertBufferID;
Mat4f seat2a_M;

GLuint seat2b_vaoID;
GLuint seat2b_vertBufferID;
Mat4f seat2b_M;

GLuint seat3a_vaoID;
GLuint seat3a_vertBufferID;
Mat4f seat3a_M;

GLuint seat3b_vaoID;
GLuint seat3b_vertBufferID;
Mat4f seat3b_M;

//RIDE QUAD
GLuint ridequad_vaoID;
GLuint ridequad_vertBufferID;
Mat4f ridequad_M;

///quad windows
GLuint quad1_vaoID;
GLuint quad1_vertBufferID;
Mat4f quad1_M;

GLuint quad2_vaoID;
GLuint quad2_vertBufferID;
Mat4f quad2_M;

GLuint quad3_vaoID;
GLuint quad3_vertBufferID;
Mat4f quad3_M;

///Cube1
GLuint cube1_vaoID;
GLuint cube1_vertBufferID;
Mat4f cube1_M;

///Cube2
GLuint cube2_vaoID;
GLuint cube2_vertBufferID;
Mat4f cube2_M;

///Cube3
GLuint cube3_vaoID;
GLuint cube3_vertBufferID;
Mat4f cube3_M;
///cube 3 er jonno windows
GLuint win1_vaoID;
GLuint win1_vertBufferID;
Mat4f win1_M;
GLuint win2_vaoID;
GLuint win2_vertBufferID;
Mat4f win2_M;
GLuint win3_vaoID;
GLuint win3_vertBufferID;
Mat4f win3_M;
GLuint win4_vaoID;
GLuint win4_vertBufferID;
Mat4f win4_M;
GLuint win5_vaoID;
GLuint win5_vertBufferID;
Mat4f win5_M;
GLuint win6_vaoID;
GLuint win6_vertBufferID;
Mat4f win6_M;

///Cube4
GLuint cube4_vaoID;
GLuint cube4_vertBufferID;
Mat4f cube4_M;

///Cube5
GLuint cube5_vaoID;
GLuint cube5_vertBufferID;
Mat4f cube5_M;

///Cube6
GLuint cube6_vaoID;
GLuint cube6_vertBufferID;
Mat4f cube6_M;

///Cube7
GLuint cube7_vaoID;
GLuint cube7_vertBufferID;
Mat4f cube7_M;
///Cube8
GLuint cube8_vaoID;
GLuint cube8_vertBufferID;
Mat4f cube8_M;
///Cube9
GLuint cube9_vaoID;
GLuint cube9_vertBufferID;
Mat4f cube9_M;
///cubez
GLuint cubez_vaoID;
GLuint cubez_vertBufferID;
Mat4f cubez_M;
///rectangle
GLuint rect_vaoID;
GLuint rect_vertBufferID;
Mat4f rect_M;
/// rect Z1 as window
GLuint rectz1_vaoID;
GLuint rectz1_vertBufferID;
Mat4f rectz1_M;
/// rect Z2 as window
GLuint rectz2_vaoID;
GLuint rectz2_vertBufferID;
Mat4f rectz2_M;

///windows cube 5

///horizontal rects

GLuint recthor1_vaoID;
GLuint recthor1_vertBufferID;
Mat4f recthor1_M;
GLuint recthor2_vaoID;
GLuint recthor2_vertBufferID;
Mat4f recthor2_M;
GLuint recthor3_vaoID;
GLuint recthor3_vertBufferID;
Mat4f recthor3_M;
GLuint recthor4_vaoID;
GLuint recthor4_vertBufferID;
Mat4f recthor4_M;
GLuint recthor5_vaoID;
GLuint recthor5_vertBufferID;
Mat4f recthor5_M;
GLuint recthor6_vaoID;
GLuint recthor6_vertBufferID;
Mat4f recthor6_M;



///rectanglesssss
GLuint rect1_vaoID;
GLuint rect1_vertBufferID;
Mat4f rect1_M;

GLuint rect2_vaoID;
GLuint rect2_vertBufferID;
Mat4f rect2_M;

GLuint rect3_vaoID;
GLuint rect3_vertBufferID;
Mat4f rect3_M;

GLuint rect4_vaoID;
GLuint rect4_vertBufferID;
Mat4f rect4_M;



GLuint rect5_vaoID;
GLuint rect5_vertBufferID;
Mat4f rect5_M;

GLuint rect6_vaoID;
GLuint rect6_vertBufferID;
Mat4f rect6_M;

GLuint rect7_vaoID;
GLuint rect7_vertBufferID;
Mat4f rect7_M;

GLuint rect8_vaoID;
GLuint rect8_vertBufferID;
Mat4f rect8_M;

GLuint rect9_vaoID;
GLuint rect9_vertBufferID;
Mat4f rect9_M;

GLuint rect10_vaoID;
GLuint rect10_vertBufferID;
Mat4f rect10_M;

GLuint rect11_vaoID;
GLuint rect11_vertBufferID;
Mat4f rect11_M;

GLuint rect12_vaoID;
GLuint rect12_vertBufferID;
Mat4f rect12_M;

GLuint rect13_vaoID;
GLuint rect13_vertBufferID;
Mat4f rect13_M;

GLuint rect14_vaoID;
GLuint rect14_vertBufferID;
Mat4f rect14_M;

GLuint rect15_vaoID;
GLuint rect15_vertBufferID;
Mat4f rect15_M;

GLuint rect16_vaoID;
GLuint rect16_vertBufferID;
Mat4f rect16_M;

GLuint rect17_vaoID;
GLuint rect17_vertBufferID;
Mat4f rect17_M;

GLuint rect18_vaoID;
GLuint rect18_vertBufferID;
Mat4f rect18_M;

GLuint rect19_vaoID;
GLuint rect19_vertBufferID;
Mat4f rect19_M;

GLuint rect20_vaoID;
GLuint rect20_vertBufferID;
Mat4f rect20_M;

GLuint rect21_vaoID;
GLuint rect21_vertBufferID;
Mat4f rect21_M;

GLuint rect22_vaoID;
GLuint rect22_vertBufferID;
Mat4f rect22_M;

GLuint rect23_vaoID;
GLuint rect23_vertBufferID;
Mat4f rect23_M;

GLuint rect24_vaoID;
GLuint rect24_vertBufferID;
Mat4f rect24_M;

GLuint rect25_vaoID;
GLuint rect25_vertBufferID;
Mat4f rect25_M;

GLuint rect26_vaoID;
GLuint rect26_vertBufferID;
Mat4f rect26_M;

GLuint rect27_vaoID;
GLuint rect27_vertBufferID;
Mat4f rect27_M;

GLuint rect28_vaoID;
GLuint rect28_vertBufferID;
Mat4f rect28_M;

GLuint rect29_vaoID;
GLuint rect29_vertBufferID;
Mat4f rect29_M;

GLuint rect30_vaoID;
GLuint rect30_vertBufferID;
Mat4f rect30_M;

GLuint rect31_vaoID;
GLuint rect31_vertBufferID;
Mat4f rect31_M;

GLuint rect32_vaoID;
GLuint rect32_vertBufferID;
Mat4f rect32_M;

GLuint rect33_vaoID;
GLuint rect33_vertBufferID;
Mat4f rect33_M;
GLuint rect34_vaoID;
GLuint rect34_vertBufferID;
Mat4f rect34_M;

GLuint rect35_vaoID;
GLuint rect35_vertBufferID;
Mat4f rect35_M;

GLuint rect36_vaoID;
GLuint rect36_vertBufferID;
Mat4f rect36_M;

GLuint rect37_vaoID;
GLuint rect37_vertBufferID;
Mat4f rect37_M;

GLuint rect38_vaoID;
GLuint rect38_vertBufferID;
Mat4f rect38_M;

GLuint rect39_vaoID;
GLuint rect39_vertBufferID;
Mat4f rect39_M;

GLuint rect40_vaoID;
GLuint rect40_vertBufferID;
Mat4f rect40_M;

GLuint rect41_vaoID;
GLuint rect41_vertBufferID;
Mat4f rect41_M;

GLuint rect42_vaoID;
GLuint rect42_vertBufferID;
Mat4f rect42_M;


GLuint rect43_vaoID;
GLuint rect43_vertBufferID;
Mat4f rect43_M;
GLuint rect44_vaoID;
GLuint rect44_vertBufferID;
Mat4f rect44_M;
// Data needed for Line
GLuint line_vaoID;
GLuint line_vertBufferID;
Mat4f line_M;
/// Data needed for Parallel Line
GLuint linepara_vaoID;
GLuint linepara_vertBufferID;
Mat4f linepara_M;
/// Data needed for cube5
GLuint linec5_vaoID;
GLuint linec5_vertBufferID;
Mat4f linec5_M;
///cube z line vertical
GLuint linecz1_vaoID;
GLuint linecz1_vertBufferID;
Mat4f linecz1_M;
GLuint linecz2_vaoID;
GLuint linecz2_vertBufferID;
Mat4f linecz2_M;
GLuint linecz3_vaoID;
GLuint linecz3_vertBufferID;
Mat4f linecz3_M;
GLuint linecz4_vaoID;
GLuint linecz4_vertBufferID;
Mat4f linecz4_M;
GLuint linecz5_vaoID;
GLuint linecz5_vertBufferID;
Mat4f linecz5_M;
///vertical
GLuint linecz6_vaoID;
GLuint linecz6_vertBufferID;
Mat4f linecz6_M;

GLuint linecz7_vaoID;
GLuint linecz7_vertBufferID;
Mat4f linecz7_M;
GLuint linecz8_vaoID;
GLuint linecz8_vertBufferID;
Mat4f linecz8_M;
GLuint linecz9_vaoID;
GLuint linecz9_vertBufferID;
Mat4f linecz9_M;
GLuint linecz10_vaoID;
GLuint linecz10_vertBufferID;
Mat4f linecz10_M;
GLuint linecz11_vaoID;
GLuint linecz11_vertBufferID;
Mat4f linecz11_M;
///windows

    GLuint winl1_vaoID; ///window left 1
GLuint winl1_vertBufferID;
Mat4f winl1_M;

 GLuint winr1_vaoID; ///window right 1
GLuint winr1_vertBufferID;
Mat4f winr1_M;


    GLuint winl2_vaoID; ///window left 2
GLuint winl2_vertBufferID;
Mat4f winl2_M;

 GLuint winr2_vaoID; ///window right 2
GLuint winr2_vertBufferID;
Mat4f winr2_M;


    GLuint winl3_vaoID; ///window left 3
GLuint winl3_vertBufferID;
Mat4f winl3_M;

 GLuint winr3_vaoID; ///window right 3
GLuint winr3_vertBufferID;
Mat4f winr3_M;

// Data needed for Pyramid
GLuint P_vaoID;
GLuint P_vertBufferID;
Mat4f P_M;

// Only one camera so only one veiw and perspective matrix are needed.
Mat4f V;
Mat4f P;

// Only one thing is rendered at a time, so only need one MVP
// When drawing different objects, update M and MVP = M * V * P
Mat4f MVP;

// Camera and veiwing Stuff
Camera camera;
int g_moveUpDown = 0;
int g_moveLeftRight = 0;
int g_moveBackForward = 0;
int g_rotateLeftRight = 0;
int g_rotateUpDown = 0;
int g_rotateRoll = 0;
float g_rotationSpeed = 0.015625;
float g_panningSpeed = 0.25;
bool g_cursorLocked;
float g_cursorX, g_cursorY;

///bool g_play = false;
bool g_play = true;

int WIN_WIDTH = 800, WIN_HEIGHT = 600;
int FB_WIDTH = 800, FB_HEIGHT = 600;
float WIN_FOV = 60;
float WIN_NEAR = 0.001;
float WIN_FAR = 1000;

//==================== FUNCTION DECLARATIONS ====================//
void displayFunc();
void resizeFunc();
void init();
void generateIDs();
void deleteIDs();
void setupVAO();
void loadQuadGeometryToGPU();
void loadCube1GeometryToGPU();
void loadCube2GeometryToGPU();
void loadCube3GeometryToGPU();
void loadCube4GeometryToGPU();
void loadCube5GeometryToGPU();
void loadCube6GeometryToGPU();
void loadCube7GeometryToGPU();
void loadCube8GeometryToGPU();
void loadCube9GeometryToGPU();
void loadCubeZGeometryToGPU();
void loadRectangleGeometrytoGPU();
void loadWinr1GeometrytoGPU();
void loadWinl1GeometrytoGPU();
void loadWinr2GeometrytoGPU();
void loadWinl2GeometrytoGPU();
void loadWinr3GeometrytoGPU();
void loadWinl3GeometrytoGPU();
void loadLineC5GeometrytoGPU();
void loadPyramidGeometryToGPU();
void loadLineGeometryToGPU();
void reloadProjectionMatrix();
void loadModelViewMatrix();
void setupModelViewProjectionTransform();

void windowSetSizeFunc();
void windowKeyFunc(GLFWwindow *window, int key, int scancode, int action,
                   int mods);
void windowMouseMotionFunc(GLFWwindow *window, double x, double y);
void windowSetSizeFunc(GLFWwindow *window, int width, int height);
void windowSetFramebufferSizeFunc(GLFWwindow *window, int width, int height);
void windowMouseButtonFunc(GLFWwindow *window, int button, int action,
                           int mods);
void windowMouseMotionFunc(GLFWwindow *window, double x, double y);
void windowKeyFunc(GLFWwindow *window, int key, int scancode, int action,
                   int mods);
void animateQuad(float t);
void moveCamera();
void reloadMVPUniform(GLuint ProgramID);
void reloadColorUniform(float r, float g, float b, GLuint ProgramID);
std::string GL_ERROR();
int main(int, char **);

//==================== FUNCTION DEFINITIONS ====================//

void displayFunc() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Use our shader
  glUseProgram(basicProgramID1);

  // ===== DRAW QUAD ====== //
  MVP = P * V * M;
  reloadMVPUniform(basicProgramID1);
  reloadColorUniform(0.0, 0.0, 1.0, basicProgramID1);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

  ///ride er frame
    MVP = P * V * ride_M;
  reloadMVPUniform(basicProgramID1);
  reloadColorUniform(1.0, 1.0, 1.0, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(ride_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_LINE_LOOP, 0, 8);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

  ///ride er quad
   MVP = P * V * ridequad_M;
  reloadMVPUniform(basicProgramID2);
  reloadColorUniform(1.0, 1.0, 1.0, basicProgramID2);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(ridequad_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  glUseProgram(basicProgramID);


  ///car widnow
     MVP = P * V * carw3_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0, 0.80, 0.0, basicProgramID);
  glBindVertexArray(carw3_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);
  ///ride er seats
   MVP = P * V * seat1a_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.60, 0.20, 0.0, basicProgramID);
  glBindVertexArray(seat1a_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);

   MVP = P * V * seat2a_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.60, 0.20, 0.0, basicProgramID);
  glBindVertexArray(seat2a_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);

   MVP = P * V * seat3a_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.60, 0.20, 0.0, basicProgramID);
  glBindVertexArray(seat3a_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);

   MVP = P * V * seat1b_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.30, 0.10, 0.0, basicProgramID);
  glBindVertexArray(seat1b_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);

   MVP = P * V * seat2b_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.30, 0.10, 0.0, basicProgramID);
  glBindVertexArray(seat2b_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);

   MVP = P * V * seat3b_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.30, 0.10, 0.0, basicProgramID);
  glBindVertexArray(seat3b_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);
  ///car triangle

 MVP = P * V * tr1_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.4,0.4,0.4, basicProgramID);
  glBindVertexArray(tr1_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
  glUseProgram(basicProgramID);

   MVP = P * V * tr2_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.4,0.4,0.4, basicProgramID);
  glBindVertexArray(tr2_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
  glUseProgram(basicProgramID);

   MVP = P * V * tr3_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.4,0.4,0.4, basicProgramID);
  glBindVertexArray(tr3_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
  glUseProgram(basicProgramID);

   MVP = P * V * tr4_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.4,0.4,0.4, basicProgramID);
  glBindVertexArray(tr4_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
  glUseProgram(basicProgramID);

  ///car wheel

 MVP = P * V * wheel1_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.40,0.40,0.4, basicProgramID);
  ///car window


  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(wheel1_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);


  ///wheel2

 MVP = P * V * wheel2_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.40,0.40,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(wheel2_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

  ///car body
    MVP = P * V * car1_M;
  reloadMVPUniform(basicProgramID2);
  reloadColorUniform(1.0, 0.0, 1.0, basicProgramID2);
  glBindVertexArray(car1_vaoID);// 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  glUseProgram(basicProgramID);

  ///car 2
      MVP = P * V * car2_M;
  reloadMVPUniform(basicProgramID2);
  reloadColorUniform(1.0, 0.0, 0.0, basicProgramID2);
  glBindVertexArray(car2_vaoID);// 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  glUseProgram(basicProgramID);
  ///
      MVP = P * V * car3_M;
  reloadMVPUniform(basicProgramID2);
  reloadColorUniform(1.0, 0.0, 0.0, basicProgramID2);
  glBindVertexArray(car3_vaoID);// 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  glUseProgram(basicProgramID);


  ///draw quad windows
  MVP = P * V * quad1_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0, 1.0, 0.0, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(quad1_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
  ///
  MVP = P * V * quad2_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0, 1.0, 0.0, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(quad2_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
  ///
  MVP = P * V * quad3_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0, 1.0, 0.0, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(quad3_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
  ///

///Draw Cube1


  MVP = P * V * cube1_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.30, 0.40, 0.90, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(cube1_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID1);

  ///Draw cube2

  MVP = P * V * cube2_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.0, 0.340, 0.70, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(cube2_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

  ///DRAW CUBE3
  MVP = P * V * cube3_M;
  reloadMVPUniform(basicProgramID1);
  reloadColorUniform(0.0, 1.0, 1.0, basicProgramID1);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(cube3_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
 ///DRAW CUBE4  jeta on top of cube3
  MVP = P * V * cube4_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(01.0, 01.0, 1.0, basicProgramID1);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(cube4_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
  ///cube5
  MVP = P * V * cube5_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.01, 0.20, 0.40, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(cube5_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);

///cube6

  MVP = P * V * cube6_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(.01, 0.30, 0.50, basicProgramID);
  glBindVertexArray(cube6_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
///cube7

  MVP = P * V * cube7_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.04, 0.30, 0.40, basicProgramID);
  glBindVertexArray(cube7_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  ///cube8

  MVP = P * V * cube8_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.14, 0.56, 0.56, basicProgramID);
  glBindVertexArray(cube8_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  ///cube9
   MVP = P * V * cube9_M;
  reloadMVPUniform(basicProgramID);
 /// reloadColorUniform(0.50, 1.0, 0.50, basicProgramID);
  reloadColorUniform(0.517, 0.882, 0.882, basicProgramID);
  glBindVertexArray(cube9_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)

 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

  // ==== DRAW LINE ===== //
  MVP = P * V * line_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0, 0, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(line_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);
  ///cz lines on building
    MVP = P * V * linecz1_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz1_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

    MVP = P * V * linecz2_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz2_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

    MVP = P * V * linecz3_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz3_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

    MVP = P * V * linecz4_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz4_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

    MVP = P * V * linecz5_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz5_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);
  ///horizontal
  MVP = P * V * linecz6_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz6_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

  MVP = P * V * linecz7_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz7_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

    MVP = P * V * linecz8_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz8_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

    MVP = P * V * linecz9_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz9_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

    MVP = P * V * linecz10_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz10_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

    MVP = P * V * linecz11_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linecz11_vaoID);
  //

  ///line for cube5
  MVP = P * V * linec5_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1,1, 1, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linec5_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

  ///cubeZ
    MVP = P * V * cubez_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.50, 0.50, 0.90, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(cubez_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
///Rectangle
    MVP = P * V * rect_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.24,0.36,0.36, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

  ///rect z1
   MVP = P * V * rectz1_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.8,0.8,0.8, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rectz1_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
  ///rect z2
   MVP = P * V * rectz2_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.8,0.8,0.8, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rectz2_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
///* rectangles

 MVP = P * V * rect43_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect43_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

 MVP = P * V * rect44_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect44_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);



    MVP = P * V * rect1_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect1_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

      MVP = P * V * rect2_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect2_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
///
    MVP = P * V * rect3_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect3_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
///
    MVP = P * V * rect4_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect4_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

///
    MVP = P * V * rect5_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect5_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
///
    MVP = P * V * rect6_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect6_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
/// set 2
    MVP = P * V * rect7_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect7_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect8_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect8_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
  //////////////////////////////////////////////////////////////////////////////////////////////////////

    MVP = P * V * rect9_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect9_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

      MVP = P * V * rect10_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect10_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
///
    MVP = P * V * rect11_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect11_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
///
    MVP = P * V * rect12_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect12_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

///
    MVP = P * V * rect13_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect13_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
///
    MVP = P * V * rect14_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect14_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect15_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect15_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect16_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect16_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect17_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect17_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect18_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect18_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);


    MVP = P * V * rect19_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect19_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect20_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect20_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect21_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect21_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
    MVP = P * V * rect22_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect22_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect23_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect23_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
    MVP = P * V * rect24_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect24_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
   MVP = P * V * rect25_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect25_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect26_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect26_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect27_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect27_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
    MVP = P * V * rect28_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect28_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

    MVP = P * V * rect29_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect29_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

      MVP = P * V * rect30_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect30_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
      MVP = P * V * rect31_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect31_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
      MVP = P * V * rect32_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect32_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
      MVP = P * V * rect33_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect33_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
      MVP = P * V * rect34_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect34_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
      MVP = P * V * rect35_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect35_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
      MVP = P * V * rect36_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect36_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
      MVP = P * V * rect37_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect37_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
      MVP = P * V * rect38_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect38_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
      MVP = P * V * rect39_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect39_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
      MVP = P * V * rect40_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect40_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);
   MVP = P * V * rect41_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect41_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
     MVP = P * V * rect42_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect42_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36); MVP = P * V * rect40_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(rect40_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);


///rectangles end

///horizontal rect

 MVP = P * V * recthor1_M;
  reloadMVPUniform(basicProgramID);
 // reloadColorUniform(0.4,0.4,0.4, basicProgramID);
  reloadColorUniform(1,1,0.4, basicProgramID);
  glBindVertexArray(recthor1_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);

///

 MVP = P * V * recthor2_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1,1,0.4, basicProgramID);

  //reloadColorUniform(0.4,0.4,0.4, basicProgramID);
  glBindVertexArray(recthor2_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);
  ///

 MVP = P * V * recthor3_M;
  reloadMVPUniform(basicProgramID);
    //  reloadColorUniform(0.4,0.4,0.4, basicProgramID);
     reloadColorUniform(1,1,0.4, basicProgramID);

  glBindVertexArray(recthor3_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
  ///

 MVP = P * V * recthor4_M;
  reloadMVPUniform(basicProgramID);
 // reloadColorUniform(0.4,0.4,0.4, basicProgramID);
 reloadColorUniform(1,1,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(recthor4_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

  ///

 MVP = P * V * recthor5_M;
  reloadMVPUniform(basicProgramID);
    reloadColorUniform(1,1,0.4, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(recthor5_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
  ///

 MVP = P * V * recthor6_M;
  reloadMVPUniform(basicProgramID);
    reloadColorUniform(1,1,0.4, basicProgramID);
   // reloadColorUniform(0.4,0.4,0.4, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(recthor6_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);

  ///

  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
  ///window left1
   MVP = P * V * winl1_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(winl1_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
  /// window right1
   MVP = P * V * winr1_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(winr1_vaoID);
  // Draw Cube, start at vertex 0, draw 36 of them (for a Cube)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
 //reloadColorUniform(1, 0, 0, basicProgramID);
  //glDrawArrays(GL_LINE_LOOP, 0, 36);

  glUseProgram(basicProgramID);
///window 2
 ///window left2
   MVP = P * V * winl2_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);
  glBindVertexArray(winl2_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);
  /// window right2
   MVP = P * V * winr2_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);
  glBindVertexArray(winr2_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glUseProgram(basicProgramID);
///window3
 ///window left3
   MVP = P * V * winl3_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);
  glBindVertexArray(winl3_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID);
  /// window right3
   MVP = P * V * winr3_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);
  glBindVertexArray(winr3_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glUseProgram(basicProgramID);

   ///==== DRAW Parallel LINE ===== //
  MVP = P * V * linepara_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0, 0.8, 0.0, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(linepara_vaoID);
  // Draw lines
  glDrawArrays(GL_LINES, 0, 2);

    // ==== DRAW PYRAMID ===== //
  MVP = P * V * P_M;

  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.2, 0.8, 0.8, basicProgramID);
  reloadColorUniform(0.2, 0.8, 0.8, basicProgramID);
  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(P_vaoID);
  // Draw lines
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 7);

  reloadColorUniform(1, 0, 0, basicProgramID);
  glDrawArrays(GL_LINE_LOOP, 0, 7);

  ///windows for cube 3
  MVP = P * V * win1_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);
  glBindVertexArray(win1_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glUseProgram(basicProgramID);
   MVP = P * V * win2_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);
  glBindVertexArray(win2_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glUseProgram(basicProgramID);
   MVP = P * V * win3_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);
  glBindVertexArray(win3_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glUseProgram(basicProgramID);
   MVP = P * V * win4_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);
  glBindVertexArray(win4_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glUseProgram(basicProgramID);
  MVP = P * V * win5_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);
  glBindVertexArray(win5_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glUseProgram(basicProgramID);
   MVP = P * V * win6_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0,1.0,0.0, basicProgramID);
  glBindVertexArray(win6_vaoID);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glUseProgram(basicProgramID);

}

void animateQuad(float t) {
 // line_M=RotateAboutZMatrix(500*t); ///ferris wheel ghurabo ebhabe
  //linepara_M=RotateAboutZMatrix(500*t); ///ferris wheel ghurabo ebhabe
///P_M = RotateAboutYMatrix(1000 * t);
//P_M = RotateAboutYMatrix(1000 * t);
  //winr1_M=RotateAboutXMatrix(100*t);

 //cube8_M = RotateAboutXMatrix(100*t);
 // line_M=RotateAboutXMatrix(1000);

///  float s = (std::tan(t) + 1.f) / 2.f;
///  float x = (1 - s) * (20) + s * (-20);

  float s = (std::sin(t) + 1.f) / 2.f;

  float x = (1- s) * (10) + s * (-5);

//P_M=Translate1Matrix(x,0,0) *P_M;
///translate e manipulate kore upor,nich try kore dekho
  ridequad_M = TranslateMatrix(0,x,0 ) * M;
  seat1a_M = TranslateMatrix(0,x,0 ) * M;
  seat1b_M = TranslateMatrix(0,x,0 ) * M;
  seat2a_M = TranslateMatrix(0,x,0 ) * M;
  seat2b_M = TranslateMatrix(0,x,0 ) * M;
  seat3a_M = TranslateMatrix(0,x,0 ) * M;
  seat3b_M = TranslateMatrix(0,x,0 ) * M;
  ///car
  wheel1_M=TranslateMatrix(5*x,0,0)* M;
  wheel2_M=TranslateMatrix(5*x,0,0)* M;
  car1_M=TranslateMatrix(5*x,0,0)* M;
  car2_M=TranslateMatrix(5*x,0,0)* M;
  car3_M=TranslateMatrix(5*x,0,0)* M;
  tr1_M=TranslateMatrix(5*x,0,0)* M;
  tr2_M=TranslateMatrix(5*x,0,0)* M;
  tr3_M=TranslateMatrix(5*x,0,0)* M;
  tr4_M=TranslateMatrix(5*x,0,0)* M;
  carw3_M=TranslateMatrix(5*x,0,0)* M;
 // rect_M=TranslateMatrix(5*x,0,0)* M;
  //cube1_M = TranslateMatrix(x,0,0 ) * M;

  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}
void loadCube1GeometryToGPU(){
  std::vector<Vec3f> verts;

  verts.push_back(Vec3f(-8.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-8.0f,-1.0f, 4.0f));
verts.push_back(Vec3f(-8.0f, 10.0f,4.0f));
verts.push_back(Vec3f(-2.0f, 10.0f, -4.0f));
verts.push_back(Vec3f(-8.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-8.0f, 10.0f, -4.0f));
verts.push_back(Vec3f(-2.0f, -1.0f, 4.0f));
verts.push_back(Vec3f(-8.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-2.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-2.0f, 10.0f, -4.0f));
verts.push_back(Vec3f(-2.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-8.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-8.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-8.0f, 10.0f, 4.0f));
verts.push_back(Vec3f(-8.0f, 10.0f, -4.0f));
verts.push_back(Vec3f(-2.0f, -1.0f, 4.0f));
verts.push_back(Vec3f(-8.0f,-1.0f, 4.0f));
verts.push_back(Vec3f(-8.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-8.0f, 10.0f, 4.0f));
verts.push_back(Vec3f(-8.0f,-1.0f, 4.0f));
verts.push_back(Vec3f(-2.0f, -1.0f, 4.0f));
verts.push_back(Vec3f(-2.0f,  10.0f, 4.0f));
verts.push_back(Vec3f(-2.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-2.0f, 10.0f, -4.0f));
verts.push_back(Vec3f(-2.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-2.0f,  10.0f, 4.0f));
verts.push_back(Vec3f(-2.0f, -1.0f, 4.0f));
verts.push_back(Vec3f(-2.0f,  10.0f, 4.0f));
verts.push_back(Vec3f(-2.0f, 10.0f, -4.0f));
verts.push_back(Vec3f(-8.0f, 10.0f, -4.0f));
verts.push_back(Vec3f(-2.0f,  10.0f, 4.0f));
verts.push_back(Vec3f(-8.0f, 10.0f, -4.0f));
verts.push_back(Vec3f(-8.0f, 10.0f, 4.0f));
verts.push_back(Vec3f(-2.0f,  10.0f, 4.0f));
verts.push_back(Vec3f(-8.0f, 10.0f, 4.0f));
verts.push_back(Vec3f(-2.0f, -1.0f, 4.0f));

  glBindBuffer(GL_ARRAY_BUFFER, cube1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}
void loadCubeZGeometryToGPU(){
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-4.0f,-1.0f,-15.0f));
verts.push_back(Vec3f(-4.0f,-1.0f, -5.0f));
verts.push_back(Vec3f(-4.0f, 15.0f,-5.0f));
verts.push_back(Vec3f(2.0f, 15.0f, -15.0f));
verts.push_back(Vec3f(-4.0f,-1.0f,-15.0f));
verts.push_back(Vec3f(-4.0f, 15.0f, -15.0f));
verts.push_back(Vec3f(2.0f, -1.0f, -5.0f));
verts.push_back(Vec3f(-4.0f,-1.0f,-15.0f));
verts.push_back(Vec3f(2.0f, -1.0f, -15.0f));
verts.push_back(Vec3f(2.0f, 15.0f, -15.0f));
verts.push_back(Vec3f(2.0f, -1.0f, -15.0f));
verts.push_back(Vec3f(-4.0f,-1.0f,-15.0f));
verts.push_back(Vec3f(-4.0f,-1.0f,-15.0f));
verts.push_back(Vec3f(-4.0f, 15.0f, -5.0f));
verts.push_back(Vec3f(-4.0f, 15.0f, -15.0f));
verts.push_back(Vec3f(2.0f, -1.0f, -5.0f));
verts.push_back(Vec3f(-4.0f,-1.0f, -5.0f));
verts.push_back(Vec3f(-4.0f,-1.0f, -15.0f));
verts.push_back(Vec3f(-4.0f, 15.0f, -5.0f));
verts.push_back(Vec3f(-4.0f,-1.0f, -5.0f));
verts.push_back(Vec3f(2.0f, -1.0f, -5.0f));
verts.push_back(Vec3f(2.0f,  15.0f, -5.0f));
verts.push_back(Vec3f(2.0f, -1.0f, -15.0f));
verts.push_back(Vec3f(2.0f, 15.0f, -15.0f));
verts.push_back(Vec3f(2.0f, -1.0f, -15.0f));
verts.push_back(Vec3f(2.0f,  15.0f, -5.0f));
verts.push_back(Vec3f(2.0f, -1.0f, -5.0f));
verts.push_back(Vec3f(2.0f,  15.0f, -5.0f));
verts.push_back(Vec3f(2.0f, 15.0f, -15.0f));
verts.push_back(Vec3f(-4.0f, 15.0f, -15.0f));
verts.push_back(Vec3f(2.0f,  15.0f, -5.0f));
verts.push_back(Vec3f(-4.0f, 15.0f, -15.0f));
verts.push_back(Vec3f(-4.0f, 15.0f, -5.0f));
verts.push_back(Vec3f(2.0f,  15.0f, -5.0f));
verts.push_back(Vec3f(-4.0f, 15.0f, -5.0f));
verts.push_back(Vec3f(2.0f, -1.0f, -5.0f));

  glBindBuffer(GL_ARRAY_BUFFER, cubez_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}

void loadCube2GeometryToGPU(){
  std::vector<Vec3f> verts;


verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-16.0f,-1.0f, 0.0f));
verts.push_back(Vec3f(-16.0f, 16.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, 16.0f, -4.0f));
verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-16.0f, 16.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, 0.0f));
verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, 16.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-16.0f, 16.0f, 0.0f));
verts.push_back(Vec3f(-16.0f, 16.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, 0.0f));
verts.push_back(Vec3f(-16.0f,-1.0f, 0.0f));
verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-16.0f, 16.0f, 0.0f));
verts.push_back(Vec3f(-16.0f,-1.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, 0.0f));
verts.push_back(Vec3f(-9.0f,  16.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, 16.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-9.0f,  16.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, 0.0f));
verts.push_back(Vec3f(-9.0f,  16.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, 16.0f, -4.0f));
verts.push_back(Vec3f(-16.0f, 16.0f, -4.0f));
verts.push_back(Vec3f(-9.0f,  16.0f, 0.0f));
verts.push_back(Vec3f(-16.0f, 16.0f, -4.0f));
verts.push_back(Vec3f(-16.0f, 16.0f, 0.0f));
verts.push_back(Vec3f(-9.0f,  16.0f, 0.0f));
verts.push_back(Vec3f(-16.0f, 16.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, 0.0f));
  glBindBuffer(GL_ARRAY_BUFFER, cube2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}




void loadCube3GeometryToGPU(){
  std::vector<Vec3f> verts;

verts.push_back(Vec3f(2.0f,-1.0f,-2.0f));
verts.push_back(Vec3f(2.0f,-1.0f,4.0f));
verts.push_back(Vec3f(2.0f,10.0f,4.0f));
verts.push_back(Vec3f(8.0f,10.0f,-2.0f));
verts.push_back(Vec3f(2.0f,-1.0f,-2.0f));
verts.push_back(Vec3f(2.0f,10.0f,-2.0f));
verts.push_back(Vec3f(8.0f,-1.0f,4.0f));
verts.push_back(Vec3f(2.0f,-.0f,-2.0f));
verts.push_back(Vec3f(8.0f,-1.0f,-2.0f));
verts.push_back(Vec3f(8.0f,10.0f,-2.0f));
verts.push_back(Vec3f(8.0f,-1.0f,-2.0f));
verts.push_back(Vec3f(2.0f,-1.0f,-2.0f));
verts.push_back(Vec3f(2.0f,-1.0f,-2.0f));
verts.push_back(Vec3f(2.0f,10.0f,4.0f));
verts.push_back(Vec3f(2.0f,10.0f,-2.0f));
verts.push_back(Vec3f(8.0f,-1.0f,4.0f));
verts.push_back(Vec3f(2.0f,-1.0f,4.0f));
verts.push_back(Vec3f(2.0f,-1.0f,-2.0f));
verts.push_back(Vec3f(2.0f,10.0f,4.0f));
verts.push_back(Vec3f(2.0f,-1.0f,4.0f));
verts.push_back(Vec3f(8.0f,-1.0f,4.0f));
verts.push_back(Vec3f(8.0f,10.0f,4.0f));
verts.push_back(Vec3f(8.0f,-1.0f,-2.0f));
verts.push_back(Vec3f(8.0f,10.0f,-2.0f));
verts.push_back(Vec3f(8.0f,-1.0f,-2.0f));
verts.push_back(Vec3f(8.0f,10.0f,4.0f));
verts.push_back(Vec3f(8.0f,-1.0f,4.0f));
verts.push_back(Vec3f(8.0f,10.0f,4.0f));
verts.push_back(Vec3f(8.0f,10.0f,-2.0f));
verts.push_back(Vec3f(2.0f,10.0f,-2.0f));
verts.push_back(Vec3f(8.0f,10.0f,4.0f));
verts.push_back(Vec3f(2.0f,10.0f,-2.0f));
verts.push_back(Vec3f(2.0f,10.0f,4.0f));
verts.push_back(Vec3f(8.0f,10.0f,4.0f));
verts.push_back(Vec3f(2.0f,10.0f,4.0f));
verts.push_back(Vec3f(8.0f,-1.0f,4.0f));

  glBindBuffer(GL_ARRAY_BUFFER, cube3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}

///ride quad

void loadRideQuadGeometryToGPU(){
  std::vector<Vec3f> verts;
verts.push_back(Vec3f(-5.0f,22.0f,-12.0f));
verts.push_back(Vec3f(-5.0f,22.0f,-18.0f));
verts.push_back(Vec3f(-5.0f,26.0f,-18.0f));
verts.push_back(Vec3f(8.0f,26.0f,-12.0f));
verts.push_back(Vec3f(-5.0f,22.0f,-12.0f));
verts.push_back(Vec3f(-5.0f,26.0f,-12.0f));
verts.push_back(Vec3f(8.0f,22.0f,-18.0f));
verts.push_back(Vec3f(-5.0f,22.0f,-12.0f));
verts.push_back(Vec3f(8.0f,22.0f,-12.0f));
verts.push_back(Vec3f(8.0f,26.0f,-12.0f));
verts.push_back(Vec3f(8.0f,22.0f,-12.0f));
verts.push_back(Vec3f(-5.0f,22.0f,-12.0f));
verts.push_back(Vec3f(-5.0f,22.0f,-12.0f));
verts.push_back(Vec3f(-5.0f,26.0f,-18.0f));
verts.push_back(Vec3f(-5.0f,26.0f,-12.0f));
verts.push_back(Vec3f(8.0f,22.0f,-18.0f));
verts.push_back(Vec3f(-5.0f,22.0f,-18.0f));
verts.push_back(Vec3f(-5.0f,22.0f,-12.0f));
verts.push_back(Vec3f(-5.0f,26.0f,-18.0f));
verts.push_back(Vec3f(-5.0f,22.0f,-18.0f));
verts.push_back(Vec3f(8.0f,22.0f,-18.0f));
verts.push_back(Vec3f(8.0f,26.0f,-18.0f));
verts.push_back(Vec3f(8.0f,22.0f,-12.0f));
verts.push_back(Vec3f(8.0f,26.0f,-12.0f));
verts.push_back(Vec3f(8.0f,22.0f,-12.0f));
verts.push_back(Vec3f(8.0f,26.0f,-18.0f));
verts.push_back(Vec3f(8.0f,22.0f,-18.0f));
verts.push_back(Vec3f(8.0f,26.0f,-18.0f));
verts.push_back(Vec3f(8.0f,26.0f,-12.0f));
verts.push_back(Vec3f(-5.0f,26.0f,-12.0f));
verts.push_back(Vec3f(8.0f,26.0f,-18.0f));
verts.push_back(Vec3f(-5.0f,26.0f,-12.0f));
verts.push_back(Vec3f(-5.0f,26.0f,-18.0f));
verts.push_back(Vec3f(8.0f,26.0f,-18.0f));
verts.push_back(Vec3f(-5.0f,26.0f,-18.0f));
verts.push_back(Vec3f(8.0f,22.0f,-18.0f));

  glBindBuffer(GL_ARRAY_BUFFER, ridequad_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}

void loadRectangleGeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-50.0f,-16.0f,-2.0f));
verts.push_back(Vec3f(-50.0f,-1.0f,0.0f));
verts.push_back(Vec3f(50.0f,-16.0f,-2.0f));
verts.push_back(Vec3f(50.0f,-1.0f,0.0f));/*
verts.push_back(Vec3f(-16.0f,-3.0f,-4.0f));
verts.push_back(Vec3f(-16.0f,1.0f,-4.0f));
verts.push_back(Vec3f(-12.0f,-3.0f,-4.0f));
verts.push_back(Vec3f(-12.0f,1.0f,-4.0f));*/
glBindBuffer(GL_ARRAY_BUFFER, rect_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

///ride er frame

void loadRideGeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-1.0f,-2.0f,-15.0f));
verts.push_back(Vec3f(-1.0f,35.0f,-15.0f));
verts.push_back(Vec3f(4.0f,-2.0f,-15.0f));
verts.push_back(Vec3f(4.0f,35.0f,-15.0f));

verts.push_back(Vec3f(-1.0f,35.0f,-15.0f));
verts.push_back(Vec3f(4.0f,-2.0f,-15.0f));
verts.push_back(Vec3f(-1.0f,-2.0f,-15.0f));
verts.push_back(Vec3f(4.0f,35.0f,-15.0f));

glBindBuffer(GL_ARRAY_BUFFER, ride_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 8, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
///ride er seats
void loadSeat1aGeometrytoGPU(){
std::vector<Vec3f> verts;
///seats
verts.push_back(Vec3f(-3.0f,22.0f,-10.50f));
verts.push_back(Vec3f(-3.0f,24.0f,-10.50f));
verts.push_back(Vec3f(-1.0f,22.0f,-10.50f));
verts.push_back(Vec3f(-1.0f,24.0f,-10.50f));


  glBindBuffer(GL_ARRAY_BUFFER, seat1a_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


void loadSeat2aGeometrytoGPU(){
std::vector<Vec3f> verts;
///seats bottom

verts.push_back(Vec3f(1.0f,22.0f,-10.50f));
verts.push_back(Vec3f(1.0f,24.0f,-10.50f));
verts.push_back(Vec3f(3.0f,22.0f,-10.50f));
verts.push_back(Vec3f(3.0f,24.0f,-10.50f));


glBindBuffer(GL_ARRAY_BUFFER, seat2a_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),    GL_STATIC_DRAW);    // pointer (Vec3f*) to contents of verts
  }

  void loadSeat3aGeometrytoGPU(){
std::vector<Vec3f> verts;
///seats bottom
verts.push_back(Vec3f(5.0f,22.0f,-10.50f));
verts.push_back(Vec3f(5.0f,24.0f,-10.50f));
verts.push_back(Vec3f(7.0f,22.0f,-10.50f));
verts.push_back(Vec3f(7.0f,24.0f,-10.50f));


glBindBuffer(GL_ARRAY_BUFFER, seat3a_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),
                 GL_STATIC_DRAW);    // pointer (Vec3f*) to contents of verts
  }

  ///seats top
  void loadSeat1bGeometrytoGPU(){
std::vector<Vec3f> verts;
///seats

verts.push_back(Vec3f(-2.50f,24.0f,-10.50f));
verts.push_back(Vec3f(-2.5f,24.50f,-10.50f));
verts.push_back(Vec3f(-1.5f,24.0f,-10.50f));
verts.push_back(Vec3f(-1.5f,24.50f,-10.50f));

glBindBuffer(GL_ARRAY_BUFFER, seat1b_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


void loadSeat2bGeometrytoGPU(){
std::vector<Vec3f> verts;
///seats top

verts.push_back(Vec3f(1.50f,24.0f,-10.50f));
verts.push_back(Vec3f(1.5f,24.50f,-10.50f));
verts.push_back(Vec3f(2.5f,24.0f,-10.50f));
verts.push_back(Vec3f(2.5f,24.50f,-10.50f));


glBindBuffer(GL_ARRAY_BUFFER, seat2b_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),    GL_STATIC_DRAW);    // pointer (Vec3f*) to contents of verts
  }

  void loadSeat3bGeometrytoGPU(){
std::vector<Vec3f> verts;
///seats top

verts.push_back(Vec3f(5.50f,24.0f,-10.50f));
verts.push_back(Vec3f(5.5f,24.50f,-10.50f));
verts.push_back(Vec3f(6.5f,24.0f,-10.50f));
verts.push_back(Vec3f(6.5f,24.50f,-10.50f));


glBindBuffer(GL_ARRAY_BUFFER, seat3b_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),   GL_STATIC_DRAW);     // pointer (Vec3f*) to contents of verts
  }


  ///window car 3
  void loadCarWindowGeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-15.0f,-3.50f,2.0f));
verts.push_back(Vec3f(-15.0f,-2.750f,2.0f));
verts.push_back(Vec3f(-13.0f,-3.50f,2.0f));
verts.push_back(Vec3f(-13.0f,-2.750f,2.0f));


glBindBuffer(GL_ARRAY_BUFFER, carw3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
///windows for cube3
void loadWindow1GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(3.0f,8.0f,4.05f));
verts.push_back(Vec3f(3.0f,9.0f,4.05f));
verts.push_back(Vec3f(4.0f,8.0f,4.05f));
verts.push_back(Vec3f(4.0f,9.0f,4.05f));


glBindBuffer(GL_ARRAY_BUFFER, win1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadWindow2GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(6.0f,8.0f,4.05f));
verts.push_back(Vec3f(6.0f,9.0f,4.05f));
verts.push_back(Vec3f(7.0f,8.0f,4.05f));
verts.push_back(Vec3f(7.0f,9.0f,4.05f));


glBindBuffer(GL_ARRAY_BUFFER, win2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

///pair 2

void loadWindow3GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(3.0f,4.0f,4.05f));
verts.push_back(Vec3f(3.0f,5.0f,4.05f));
verts.push_back(Vec3f(4.0f,4.0f,4.05f));
verts.push_back(Vec3f(4.0f,5.0f,4.05f));


glBindBuffer(GL_ARRAY_BUFFER, win3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadWindow4GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(6.0f,4.0f,4.05f));
verts.push_back(Vec3f(6.0f,5.0f,4.05f));
verts.push_back(Vec3f(7.0f,4.0f,4.05f));
verts.push_back(Vec3f(7.0f,5.0f,4.05f));


glBindBuffer(GL_ARRAY_BUFFER, win4_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
///pair 3


void loadWindow5GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(3.0f,0.0f,4.05f));
verts.push_back(Vec3f(3.0f,1.0f,4.05f));
verts.push_back(Vec3f(4.0f,0.0f,4.05f));
verts.push_back(Vec3f(4.0f,1.0f,4.05f));


glBindBuffer(GL_ARRAY_BUFFER, win5_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadWindow6GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(6.0f,0.0f,4.05f));
verts.push_back(Vec3f(6.0f,1.0f,4.05f));
verts.push_back(Vec3f(7.0f,0.0f,4.05f));
verts.push_back(Vec3f(7.0f,1.0f,4.05f));


glBindBuffer(GL_ARRAY_BUFFER, win6_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
///windows for cube3 ends
void loadWinl1GeometrytoGPU(){

std::vector<Vec3f> verts;
verts.push_back(Vec3f(-14.0f,2.0f,1.0f));
verts.push_back(Vec3f(-14.0f,4.0f,1.0f));
verts.push_back(Vec3f(-13.0f,2.0f,1.0f));
verts.push_back(Vec3f(-13.0f,4.0f,1.0f));

glBindBuffer(GL_ARRAY_BUFFER, winl1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadWinr1GeometrytoGPU(){

std::vector<Vec3f> verts;
verts.push_back(Vec3f(-11.0f,2.0f,1.0f));
verts.push_back(Vec3f(-11.0f,4.0f,1.0f));
verts.push_back(Vec3f(-10.0f,2.0f,1.0f));
verts.push_back(Vec3f(-10.0f,4.0f,1.0f));


glBindBuffer(GL_ARRAY_BUFFER, winr1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
///windows 2
void loadWinl2GeometrytoGPU(){

std::vector<Vec3f> verts;
verts.push_back(Vec3f(-14.0f,6.0f,1.0f));
verts.push_back(Vec3f(-14.0f,8.0f,1.0f));
verts.push_back(Vec3f(-13.0f,6.0f,1.0f));
verts.push_back(Vec3f(-13.0f,8.0f,1.0f));

glBindBuffer(GL_ARRAY_BUFFER, winl2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadWinr2GeometrytoGPU(){

std::vector<Vec3f> verts;
/*verts.push_back(Vec3f(14.50f,0.0f,-9.0f));
verts.push_back(Vec3f(14.5f,2.0f,-9.0f));
verts.push_back(Vec3f(15.5f,0.0f,-9.0f));
verts.push_back(Vec3f(15.5f,2.0f,-9.0f));
*/
verts.push_back(Vec3f(-11.0f,6.0f,1.0f));
verts.push_back(Vec3f(-11.0f,8.0f,1.0f));
verts.push_back(Vec3f(-10.0f,6.0f,1.0f));
verts.push_back(Vec3f(-10.0f,8.0f,1.0f));


glBindBuffer(GL_ARRAY_BUFFER, winr2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

///windows 3
void loadWinl3GeometrytoGPU(){

std::vector<Vec3f> verts;
verts.push_back(Vec3f(-14.0f,10.0f,1.0f));
verts.push_back(Vec3f(-14.0f,12.0f,1.0f));
verts.push_back(Vec3f(-13.0f,10.0f,1.0f));
verts.push_back(Vec3f(-13.0f,12.0f,1.0f));

glBindBuffer(GL_ARRAY_BUFFER, winl3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadWinr3GeometrytoGPU(){

std::vector<Vec3f> verts;
verts.push_back(Vec3f(-11.0f,10.0f,1.0f));
verts.push_back(Vec3f(-11.0f,12.0f,1.0f));
verts.push_back(Vec3f(-10.0f,10.0f,1.0f));
verts.push_back(Vec3f(-10.0f,12.0f,1.0f));


glBindBuffer(GL_ARRAY_BUFFER, winr3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


void loadCube4GeometryToGPU(){
  std::vector<Vec3f> verts;
verts.push_back(Vec3f(3.0f,10.0f,-2.0f));
verts.push_back(Vec3f(3.0f,10.0f,4.0f));
verts.push_back(Vec3f(3.0f,12.0f,4.0f));
verts.push_back(Vec3f(7.0f,12.0f,-2.0f));
verts.push_back(Vec3f(3.0f,10.0f,-2.0f));
verts.push_back(Vec3f(3.0f,12.0f,-2.0f));
verts.push_back(Vec3f(7.0f,10.0f,4.0f));
verts.push_back(Vec3f(3.0f,10.0f,-2.0f));
verts.push_back(Vec3f(7.0f,10.0f,-2.0f));
verts.push_back(Vec3f(7.0f,12.0f,-2.0f));
verts.push_back(Vec3f(7.0f,10.0f,-2.0f));
verts.push_back(Vec3f(3.0f,10.0f,-2.0f));
verts.push_back(Vec3f(3.0f,10.0f,-2.0f));
verts.push_back(Vec3f(3.0f,12.0f,4.0f));
verts.push_back(Vec3f(3.0f,12.0f,-2.0f));
verts.push_back(Vec3f(7.0f,10.0f,4.0f));
verts.push_back(Vec3f(3.0f,10.0f,4.0f));
verts.push_back(Vec3f(3.0f,10.0f,-2.0f));
verts.push_back(Vec3f(3.0f,12.0f,4.0f));
verts.push_back(Vec3f(3.0f,10.0f,4.0f));
verts.push_back(Vec3f(7.0f,10.0f,4.0f));
verts.push_back(Vec3f(7.0f,12.0f,4.0f));
verts.push_back(Vec3f(7.0f,10.0f,-2.0f));
verts.push_back(Vec3f(7.0f,12.0f,-2.0f));
verts.push_back(Vec3f(7.0f,10.0f,-2.0f));
verts.push_back(Vec3f(7.0f,12.0f,4.0f));
verts.push_back(Vec3f(7.0f,10.0f,4.0f));
verts.push_back(Vec3f(7.0f,12.0f,4.0f));
verts.push_back(Vec3f(7.0f,12.0f,-2.0f));
verts.push_back(Vec3f(3.0f,12.0f,-2.0f));
verts.push_back(Vec3f(7.0f,12.0f,4.0f));
verts.push_back(Vec3f(3.0f,12.0f,-2.0f));
verts.push_back(Vec3f(3.0f,12.0f,4.0f));
verts.push_back(Vec3f(7.0f,12.0f,4.0f));
verts.push_back(Vec3f(3.0f,12.0f,4.0f));
verts.push_back(Vec3f(7.0f,10.0f,4.0f));

  glBindBuffer(GL_ARRAY_BUFFER, cube4_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}


void loadCube5GeometryToGPU(){

 std::vector<Vec3f> verts;
 verts.push_back(Vec3f(8.5f,-1.0f,-2.0f));
verts.push_back(Vec3f(8.5f,-1.0f,4.0f));
verts.push_back(Vec3f(8.5f,13.0f,4.0f));
verts.push_back(Vec3f(16.5f,13.0f,-2.0f));
verts.push_back(Vec3f(8.5f,-1.0f,-2.0f));
verts.push_back(Vec3f(8.5f,13.0f,-2.0f));
verts.push_back(Vec3f(16.5f,-1.0f,4.0f));
verts.push_back(Vec3f(8.5f,-1.0f,-2.0f));
verts.push_back(Vec3f(16.5f,-1.0f,-2.0f));
verts.push_back(Vec3f(16.5f,13.0f,-2.0f));
verts.push_back(Vec3f(16.5f,-1.0f,-2.0f));
verts.push_back(Vec3f(8.5f,-1.0f,-2.0f));
verts.push_back(Vec3f(8.5f,-1.0f,-2.0f));
verts.push_back(Vec3f(8.5f,13.0f,4.0f));
verts.push_back(Vec3f(8.5f,13.0f,-2.0f));
verts.push_back(Vec3f(16.5f,-1.0f,4.0f));
verts.push_back(Vec3f(8.5f,-1.0f,4.0f));
verts.push_back(Vec3f(8.5f,-1.0f,-2.0f));
verts.push_back(Vec3f(8.5f,13.0f,4.0f));
verts.push_back(Vec3f(8.5f,-1.0f,4.0f));
verts.push_back(Vec3f(16.5f,-1.0f,4.0f));
verts.push_back(Vec3f(16.5f,13.0f,4.0f));
verts.push_back(Vec3f(16.5f,-1.0f,-2.0f));
verts.push_back(Vec3f(16.5f,13.0f,-2.0f));
verts.push_back(Vec3f(16.5f,-1.0f,-2.0f));
verts.push_back(Vec3f(16.5f,13.0f,4.0f));
verts.push_back(Vec3f(16.5f,-1.0f,4.0f));
verts.push_back(Vec3f(16.5f,13.0f,4.0f));
verts.push_back(Vec3f(16.5f,13.0f,-2.0f));
verts.push_back(Vec3f(8.5f,13.0f,-2.0f));
verts.push_back(Vec3f(16.5f,13.0f,4.0f));
verts.push_back(Vec3f(8.5f,13.0f,-2.0f));
verts.push_back(Vec3f(8.5f,13.0f,4.0f));
verts.push_back(Vec3f(16.5f,13.0f,4.0f));
verts.push_back(Vec3f(8.5f,13.0f,4.0f));
verts.push_back(Vec3f(16.5f,-1.0f,4.0f));
glBindBuffer(GL_ARRAY_BUFFER, cube5_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}
///

void loadCube6GeometryToGPU(){

 std::vector<Vec3f> verts;

 verts.push_back(Vec3f(9.5f,13.0f,-2.0f));
verts.push_back(Vec3f(9.5f,13.0f,4.0f));
verts.push_back(Vec3f(9.5f,14.0f,4.0f));
verts.push_back(Vec3f(15.5f,14.0f,-2.0f));
verts.push_back(Vec3f(9.5f,13.0f,-2.0f));
verts.push_back(Vec3f(9.5f,14.0f,-2.0f));
verts.push_back(Vec3f(15.5f,13.0f,4.0f));
verts.push_back(Vec3f(9.5f,13.0f,-2.0f));
verts.push_back(Vec3f(15.5f,13.0f,-2.0f));
verts.push_back(Vec3f(15.5f,14.0f,-2.0f));
verts.push_back(Vec3f(15.5f,13.0f,-2.0f));
verts.push_back(Vec3f(9.5f,13.0f,-2.0f));
verts.push_back(Vec3f(9.5f,13.0f,-2.0f));
verts.push_back(Vec3f(9.5f,14.0f,4.0f));
verts.push_back(Vec3f(9.5f,14.0f,-2.0f));
verts.push_back(Vec3f(15.5f,13.0f,4.0f));
verts.push_back(Vec3f(9.5f,13.0f,4.0f));
verts.push_back(Vec3f(9.5f,13.0f,-2.0f));
verts.push_back(Vec3f(9.5f,14.0f,4.0f));
verts.push_back(Vec3f(9.5f,13.0f,4.0f));
verts.push_back(Vec3f(15.5f,13.0f,4.0f));
verts.push_back(Vec3f(15.5f,14.0f,4.0f));
verts.push_back(Vec3f(15.5f,13.0f,-2.0f));
verts.push_back(Vec3f(15.5f,14.0f,-2.0f));
verts.push_back(Vec3f(15.5f,13.0f,-2.0f));
verts.push_back(Vec3f(15.5f,14.0f,4.0f));
verts.push_back(Vec3f(15.5f,13.0f,4.0f));
verts.push_back(Vec3f(15.5f,14.0f,4.0f));
verts.push_back(Vec3f(15.5f,14.0f,-2.0f));
verts.push_back(Vec3f(9.5f,14.0f,-2.0f));
verts.push_back(Vec3f(15.5f,14.0f,4.0f));
verts.push_back(Vec3f(9.5f,14.0f,-2.0f));
verts.push_back(Vec3f(9.5f,14.0f,4.0f));
verts.push_back(Vec3f(15.5f,14.0f,4.0f));
verts.push_back(Vec3f(9.5f,14.0f,4.0f));
verts.push_back(Vec3f(15.5f,13.0f,4.0f));
glBindBuffer(GL_ARRAY_BUFFER, cube6_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}
///
void loadCube7GeometryToGPU(){

 std::vector<Vec3f> verts;

  verts.push_back(Vec3f(10.5f,14.0f,-2.0f));
verts.push_back(Vec3f(10.5f,14.0f,4.0f));
verts.push_back(Vec3f(10.5f,15.0f,4.0f));
verts.push_back(Vec3f(14.5f,15.0f,-2.0f));
verts.push_back(Vec3f(10.5f,14.0f,-2.0f));
verts.push_back(Vec3f(10.5f,15.0f,-2.0f));
verts.push_back(Vec3f(14.5f,14.0f,4.0f));
verts.push_back(Vec3f(10.5f,14.0f,-2.0f));
verts.push_back(Vec3f(14.5f,14.0f,-2.0f));
verts.push_back(Vec3f(14.5f,15.0f,-2.0f));
verts.push_back(Vec3f(14.5f,14.0f,-2.0f));
verts.push_back(Vec3f(10.5f,14.0f,-2.0f));
verts.push_back(Vec3f(10.5f,14.0f,-2.0f));
verts.push_back(Vec3f(10.5f,15.0f,4.0f));
verts.push_back(Vec3f(10.5f,15.0f,-2.0f));
verts.push_back(Vec3f(14.5f,14.0f,4.0f));
verts.push_back(Vec3f(10.5f,14.0f,4.0f));
verts.push_back(Vec3f(10.5f,14.0f,-2.0f));
verts.push_back(Vec3f(10.5f,15.0f,4.0f));
verts.push_back(Vec3f(10.5f,14.0f,4.0f));
verts.push_back(Vec3f(14.5f,14.0f,4.0f));
verts.push_back(Vec3f(14.5f,15.0f,4.0f));
verts.push_back(Vec3f(14.5f,14.0f,-2.0f));
verts.push_back(Vec3f(14.5f,15.0f,-2.0f));
verts.push_back(Vec3f(14.5f,14.0f,-2.0f));
verts.push_back(Vec3f(14.5f,15.0f,4.0f));
verts.push_back(Vec3f(14.5f,14.0f,4.0f));
verts.push_back(Vec3f(14.5f,15.0f,4.0f));
verts.push_back(Vec3f(14.5f,15.0f,-2.0f));
verts.push_back(Vec3f(10.5f,15.0f,-2.0f));
verts.push_back(Vec3f(14.5f,15.0f,4.0f));
verts.push_back(Vec3f(10.5f,15.0f,-2.0f));
verts.push_back(Vec3f(10.5f,15.0f,4.0f));
verts.push_back(Vec3f(14.5f,15.0f,4.0f));
verts.push_back(Vec3f(10.5f,15.0f,4.0f));
verts.push_back(Vec3f(14.5f,14.0f,4.0f));

glBindBuffer(GL_ARRAY_BUFFER, cube7_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}

void loadCube8GeometryToGPU(){

 std::vector<Vec3f> verts;

glBindBuffer(GL_ARRAY_BUFFER, cube8_vertBufferID);


  verts.push_back(Vec3f(11.5f,15.0f,-2.0f));
verts.push_back(Vec3f(11.5f,15.0f,4.0f));
verts.push_back(Vec3f(11.5f,16.0f,4.0f));
verts.push_back(Vec3f(13.5f,16.0f,-2.0f));
verts.push_back(Vec3f(11.5f,15.0f,-2.0f));
verts.push_back(Vec3f(11.5f,16.0f,-2.0f));
verts.push_back(Vec3f(13.5f,15.0f,4.0f));
verts.push_back(Vec3f(11.5f,15.0f,-2.0f));
verts.push_back(Vec3f(13.5f,15.0f,-2.0f));
verts.push_back(Vec3f(13.5f,16.0f,-2.0f));
verts.push_back(Vec3f(13.5f,15.0f,-2.0f));
verts.push_back(Vec3f(11.5f,15.0f,-2.0f));
verts.push_back(Vec3f(11.5f,15.0f,-2.0f));
verts.push_back(Vec3f(11.5f,16.0f,4.0f));
verts.push_back(Vec3f(11.5f,16.0f,-2.0f));
verts.push_back(Vec3f(13.5f,15.0f,4.0f));
verts.push_back(Vec3f(11.5f,15.0f,4.0f));
verts.push_back(Vec3f(11.5f,15.0f,-2.0f));
verts.push_back(Vec3f(11.5f,16.0f,4.0f));
verts.push_back(Vec3f(11.5f,15.0f,4.0f));
verts.push_back(Vec3f(13.5f,15.0f,4.0f));
verts.push_back(Vec3f(13.5f,16.0f,4.0f));
verts.push_back(Vec3f(13.5f,15.0f,-2.0f));
verts.push_back(Vec3f(13.5f,16.0f,-2.0f));
verts.push_back(Vec3f(13.5f,15.0f,-2.0f));
verts.push_back(Vec3f(13.5f,16.0f,4.0f));
verts.push_back(Vec3f(13.5f,15.0f,4.0f));
verts.push_back(Vec3f(13.5f,16.0f,4.0f));
verts.push_back(Vec3f(13.5f,16.0f,-2.0f));
verts.push_back(Vec3f(11.5f,16.0f,-2.0f));
verts.push_back(Vec3f(13.5f,16.0f,4.0f));
verts.push_back(Vec3f(11.5f,16.0f,-2.0f));
verts.push_back(Vec3f(11.5f,16.0f,4.0f));
verts.push_back(Vec3f(13.5f,16.0f,4.0f));
verts.push_back(Vec3f(11.5f,16.0f,4.0f));
verts.push_back(Vec3f(13.5f,15.0f,4.0f));


glBindBuffer(GL_ARRAY_BUFFER, cube8_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}

void loadCube9GeometryToGPU(){

 std::vector<Vec3f> verts;

verts.push_back(Vec3f(-22.50,-1.0f,-2.0f));
verts.push_back(Vec3f(-22.50,-1.0f, 2.0f));
verts.push_back(Vec3f(-22.50, 18.0f, 2.0f));
verts.push_back(Vec3f(-17.00f, 18.0f, -2.0f));
verts.push_back(Vec3f(-22.50,-1.0f,-2.0f));
verts.push_back(Vec3f(-22.50, 18.0f, -2.0f));
verts.push_back(Vec3f(-17.00f, -1.0f, 2.0f));
verts.push_back(Vec3f(-22.50,-1.0f,-2.0f));
verts.push_back(Vec3f(-17.00f, -1.0f, -2.0f));
verts.push_back(Vec3f(-17.00f, 18.0f, -2.0f));
verts.push_back(Vec3f(-17.00f, -1.0f, -2.0f));
verts.push_back(Vec3f(-22.50,-1.0f,-2.0f));
verts.push_back(Vec3f(-22.50,-1.0f,-2.0f));
verts.push_back(Vec3f(-22.50, 1.0f, 2.0f));
verts.push_back(Vec3f(-22.50, 18.0f, -2.0f));
verts.push_back(Vec3f(-17.00f, -1.0f, 2.0f));
verts.push_back(Vec3f(-22.50,-1.0f, 2.0f));
verts.push_back(Vec3f(-22.50,-1.0f,-2.0f));
verts.push_back(Vec3f(-22.50, 18.0f, 2.0f));
verts.push_back(Vec3f(-22.50,-1.0f, 2.0f));
verts.push_back(Vec3f(-17.00f, -1.0f, 2.0f));
verts.push_back(Vec3f(-17.00f,  18.0f, 2.0f));
verts.push_back(Vec3f(-17.00f, -1.0f, -2.0f));
verts.push_back(Vec3f(-17.00f, 18.0f, -2.0f));
verts.push_back(Vec3f(-17.00f, -1.0f, -2.0f));
verts.push_back(Vec3f(-17.00f,  18.0f, 2.0f));
verts.push_back(Vec3f(-17.00f, -1.0f, 2.0f));
verts.push_back(Vec3f(-17.00f,  18.0f, 2.0f));
verts.push_back(Vec3f(-17.00f, 18.0f, -2.0f));
verts.push_back(Vec3f(-22.50, 18.0f, -2.0f));
verts.push_back(Vec3f(-17.00f,  18.0f, 2.0f));
verts.push_back(Vec3f(-22.50, 18.0f, -2.0f));
verts.push_back(Vec3f(-22.50, 18.0f, 2.0f));
verts.push_back(Vec3f(-17.00f,  18.0f, 2.0f));
verts.push_back(Vec3f(-22.50, 18.0f, 2.0f));
verts.push_back(Vec3f(-17.00f, -1.0f, 2.0f));
glBindBuffer(GL_ARRAY_BUFFER, cube9_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}

void loadQuadGeometryToGPU() {
  // Just basic layout of floats, for a cube
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;///

verts.push_back(Vec3f(-2.0f,-1.0f,-1.0f));
verts.push_back(Vec3f(-2.0f,-1.0f, 1.0f));
verts.push_back(Vec3f(-2.0f, 4.0f, 1.0f));
verts.push_back(Vec3f(2.0f, 4.0f,-1.0f));
verts.push_back(Vec3f(-2.0f,-1.0f,-1.0f));
verts.push_back(Vec3f(-2.0f, 4.0f,-1.0f));
verts.push_back(Vec3f(2.0f,-1.0f, 1.0f));
verts.push_back(Vec3f(-2.0f,-1.0f,-1.0f));
verts.push_back(Vec3f(2.0f,-1.0f,-1.0f));
verts.push_back(Vec3f(2.0f, 4.0f,-1.0f));
verts.push_back(Vec3f(2.0f,-1.0f,-1.0f));
verts.push_back(Vec3f(-2.0f,-1.0f,-1.0f));
verts.push_back(Vec3f(-2.0f,-1.0f,-1.0f));
verts.push_back(Vec3f(-2.0f, 4.0f, 1.0f));
verts.push_back(Vec3f(-2.0f, 4.0f,-1.0f));
verts.push_back(Vec3f(2.0f,-1.0f, 1.0f));
verts.push_back(Vec3f(-2.0f,-1.0f, 1.0f));
verts.push_back(Vec3f(-2.0f,-1.0f,-1.0f));
verts.push_back(Vec3f(-2.0f, 4.0f, 1.0f));
verts.push_back(Vec3f(-2.0f,-1.0f, 1.0f));
verts.push_back(Vec3f(2.0f,-1.0f, 1.0f));
verts.push_back(Vec3f(2.0f, 4.0f, 1.0f));
verts.push_back(Vec3f(2.0f,-1.0f,-1.0f));
verts.push_back(Vec3f(2.0f, 4.0f,-1.0f));
verts.push_back(Vec3f(2.0f,-1.0f,-1.0f));
verts.push_back(Vec3f(2.0f, 4.0f, 1.0f));
verts.push_back(Vec3f(2.0f,-1.0f, 1.0f));
verts.push_back(Vec3f(2.0f, 4.0f, 1.0f));
verts.push_back(Vec3f(2.0f, 4.0f,-1.0f));
verts.push_back(Vec3f(-2.0f, 4.0f,-1.0f));
verts.push_back(Vec3f(2.0f, 4.0f, 1.0f));
verts.push_back(Vec3f(-2.0f, 4.0f,-1.0f));
verts.push_back(Vec3f(-2.0f, 4.0f, 1.0f));
verts.push_back(Vec3f(2.0f, 4.0f, 1.0f));
verts.push_back(Vec3f(-2.0f, 4.0f, 1.0f));
verts.push_back(Vec3f(2.0f,-1.0f, 1.0f));
///
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}

void loadLineGeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-40, -1, 0));
  verts.push_back(Vec3f(40, -1, 0));
  //ferris wheel
  //verts.push_back(Vec3f(-25, 10, -25));
  //verts.push_back(Vec3f(25, 10, -25));

 glBindBuffer(GL_ARRAY_BUFFER, line_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
///Parallel line
void loadParallelLineGeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
 verts.push_back(Vec3f(-40, -4, 0));
 verts.push_back(Vec3f(40, -4, 0));
 //ferris wheel
 ///verts.push_back(Vec3f(0, -8, -25));
  ///verts.push_back(Vec3f(0, 35, -25));

  glBindBuffer(GL_ARRAY_BUFFER, linepara_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadLineC5GeometrytoGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(8.5, 13.0, 4.0));
  verts.push_back(Vec3f(8.5, -1.0, 4.0));

  glBindBuffer(GL_ARRAY_BUFFER, linec5_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
///lines for the cz vertical
void loadLineCz1GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-7, 10, 4.5));
  verts.push_back(Vec3f(-7, -0.8, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadLineCz2GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-6, 10, 4.5));
  verts.push_back(Vec3f(-6, -0.8, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadLineCz3GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-5, 10, 4.5));
  verts.push_back(Vec3f(-5, -0.8, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadLineCz4GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-4, 10, 4.5));
  verts.push_back(Vec3f(-4, -0.8, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz4_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadLineCz5GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-3, 10, 4.5));
  verts.push_back(Vec3f(-3, -0.8, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz5_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
///cz horizontal lines
void loadLineCz6GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-8, 8, 4.5));
  verts.push_back(Vec3f(-2, 8, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz6_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadLineCz7GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-8, 7, 4.5));
  verts.push_back(Vec3f(-2, 7, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz7_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadLineCz8GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-8, 5, 4.5));
  verts.push_back(Vec3f(-2, 5, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz8_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}

void loadLineCz9GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-8, 4, 4.5));
  verts.push_back(Vec3f(-2, 4, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz9_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadLineCz10GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-8, 3, 4.5));
  verts.push_back(Vec3f(-2, 3, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz10_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadLineCz11GeometryToGPU() {
    std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-8, 2, 4.5));
  verts.push_back(Vec3f(-2, 2, 4.5));
  glBindBuffer(GL_ARRAY_BUFFER, linecz11_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadPyramidGeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
std::vector<Vec3f> verts;
/* verts.push_back(Vec3f(-5, 6, 5));
  verts.push_back(Vec3f(5, 6, 5));
  verts.push_back(Vec3f(0, 9, 0));
  verts.push_back(Vec3f(5, 6, -5));
  verts.push_back(Vec3f(-5, 6, -5));
  verts.push_back(Vec3f(-5, 6, 5));
  verts.push_back(Vec3f(0, 9, 0));


  */

  verts.push_back(Vec3f(-2, 4, 1));
  verts.push_back(Vec3f(2, 4, 1));
  verts.push_back(Vec3f(0, 8, 0));
  verts.push_back(Vec3f(2, 4, -1));
  verts.push_back(Vec3f(-2, 4, -1));
  verts.push_back(Vec3f(-2, 4, 1));
  verts.push_back(Vec3f(0, 8, 0));

  glBindBuffer(GL_ARRAY_BUFFER, P_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 7, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer


}
/// horizontal rects for leftmost building


void loadRectangleHor1GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-22.50f,16.0f,2.10f));
verts.push_back(Vec3f(-22.50f,17.0f,2.10f));
verts.push_back(Vec3f(-17.0f,16.0f,2.10f));
verts.push_back(Vec3f(-17.00f,17.0f,2.10f));


glBindBuffer(GL_ARRAY_BUFFER, recthor1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


void loadRectangleHor2GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-22.50f,13.0f,2.10f));
verts.push_back(Vec3f(-22.50f,14.0f,2.10f));
verts.push_back(Vec3f(-17.0f,13.0f,2.10f));
verts.push_back(Vec3f(-17.00f,14.0f,2.10f));


glBindBuffer(GL_ARRAY_BUFFER, recthor2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


void loadRectangleHor3GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-22.50f,10.0f,2.10f));
verts.push_back(Vec3f(-22.50f,11.0f,2.10f));
verts.push_back(Vec3f(-17.0f,10.0f,2.10f));
verts.push_back(Vec3f(-17.00f,11.0f,2.10f));


glBindBuffer(GL_ARRAY_BUFFER, recthor3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
            //   sizeof(Vec3f) * 3, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


void loadRectangleHor4GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-22.50f,7.0f,2.10f));
verts.push_back(Vec3f(-22.50f,8.0f,2.10f));
verts.push_back(Vec3f(-17.0f,7.0f,2.10f));
verts.push_back(Vec3f(-17.00f,8.0f,2.10f));

glBindBuffer(GL_ARRAY_BUFFER, recthor4_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangleHor5GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-22.50f,4.0f,2.10f));
verts.push_back(Vec3f(-22.50f,5.0f,2.10f));
verts.push_back(Vec3f(-17.0f,4.0f,2.10f));
verts.push_back(Vec3f(-17.00f,5.0f,2.10f));

glBindBuffer(GL_ARRAY_BUFFER, recthor5_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangleHor6GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-22.50f,1.0f,2.10f));
verts.push_back(Vec3f(-22.50f,2.0f,2.10f));
verts.push_back(Vec3f(-17.0f,1.0f,2.10f));
verts.push_back(Vec3f(-17.00f,2.0f,2.10f));

glBindBuffer(GL_ARRAY_BUFFER, recthor6_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

///horizontal rects shesh
void loadRectanglez1GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-2.50f,0.0f,-0.50f));
verts.push_back(Vec3f(-2.50f,13.0f,-0.50f));
verts.push_back(Vec3f(-1.50f,0.0f,-0.50f));
verts.push_back(Vec3f(-1.50f,13.0f,-0.50f));
glBindBuffer(GL_ARRAY_BUFFER, rectz1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
void loadRectanglez2GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(0.0f,0.0f,-0.50f));
verts.push_back(Vec3f(0.0f,13.0f,-0.50f));
verts.push_back(Vec3f(1.0f,0.0f,-0.50f));
verts.push_back(Vec3f(1.0f,13.0f,-0.50f));
glBindBuffer(GL_ARRAY_BUFFER, rectz2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

///set 1 of rectangles


void loadRectangle1GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(9.50f,11.50f,5.0f));
verts.push_back(Vec3f(9.5f,12.0f,5.0f));
verts.push_back(Vec3f(10.0f,11.50f,5.0f));
verts.push_back(Vec3f(10.0f,12.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle2GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(10.50f,11.50f,5.0f));
verts.push_back(Vec3f(10.50f,12.0f,5.0f));
verts.push_back(Vec3f(11.0f,11.50f,5.0f));
verts.push_back(Vec3f(11.0f,12.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


/// 43 no ta ekhane kortesi
void loadRectangle43GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(10.50f,5.50f,5.0f));
verts.push_back(Vec3f(10.50f,6.0f,5.0f));
verts.push_back(Vec3f(11.0f,5.50f,5.0f));
verts.push_back(Vec3f(11.0f,6.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect43_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle3GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(11.50f,11.50f,5.0f));
verts.push_back(Vec3f(11.50f,12.0f,5.0f));
verts.push_back(Vec3f(12.0f,11.50f,5.0f));
verts.push_back(Vec3f(12.0f,12.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle4GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(12.50f,11.50f,5.0f));
verts.push_back(Vec3f(12.50f,12.0f,5.0f));
verts.push_back(Vec3f(13.0f,11.50f,5.0f));
verts.push_back(Vec3f(13.0f,12.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect4_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle5GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(13.50f,11.50f,5.0f));
verts.push_back(Vec3f(13.50f,12.0f,5.0f));
verts.push_back(Vec3f(14.0f,11.50f,5.0f));
verts.push_back(Vec3f(14.0f,12.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect5_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
void loadRectangle6GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(14.50f,11.50f,5.0f));
verts.push_back(Vec3f(14.50f,12.0f,5.0f));
verts.push_back(Vec3f(15.0f,11.50f,5.0f));
verts.push_back(Vec3f(15.0f,12.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect6_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

///set2 of rectangles
void loadRectangle7GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(9.50f,10.50f,5.0f));
verts.push_back(Vec3f(9.5f,11.0f,5.0f));
verts.push_back(Vec3f(10.0f,10.50f,5.0f));
verts.push_back(Vec3f(10.0f,11.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect7_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle8GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(10.50f,10.50f,5.0f));
verts.push_back(Vec3f(10.50f,11.0f,5.0f));
verts.push_back(Vec3f(11.0f,10.50f,5.0f));
verts.push_back(Vec3f(11.0f,11.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect8_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle9GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(11.50f,10.50f,5.0f));
verts.push_back(Vec3f(11.50f,11.0f,5.0f));
verts.push_back(Vec3f(12.0f,10.50f,5.0f));
verts.push_back(Vec3f(12.0f,11.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect9_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle10GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(12.50f,10.50f,5.0f));
verts.push_back(Vec3f(12.50f,11.0f,5.0f));
verts.push_back(Vec3f(13.0f,10.50f,5.0f));
verts.push_back(Vec3f(13.0f,11.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect10_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle11GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(13.50f,10.50f,5.0f));
verts.push_back(Vec3f(13.50f,11.0f,5.0f));
verts.push_back(Vec3f(14.0f,10.50f,5.0f));
verts.push_back(Vec3f(14.0f,11.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect11_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
void loadRectangle12GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(14.50f,10.50f,5.0f));
verts.push_back(Vec3f(14.50f,11.0f,5.0f));
verts.push_back(Vec3f(15.0f,10.50f,5.0f));
verts.push_back(Vec3f(15.0f,11.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect12_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


///set 3
void loadRectangle13GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(9.50f,9.50f,5.0f));
verts.push_back(Vec3f(9.5f,10.0f,5.0f));
verts.push_back(Vec3f(10.0f,09.50f,5.0f));
verts.push_back(Vec3f(10.0f,10.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect13_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle14GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(10.50f,9.50f,5.0f));
verts.push_back(Vec3f(10.50f,10.0f,5.0f));
verts.push_back(Vec3f(11.0f,9.50f,5.0f));
verts.push_back(Vec3f(11.0f,10.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect14_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle15GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(11.50f,9.50f,5.0f));
verts.push_back(Vec3f(11.50f,10.0f,5.0f));
verts.push_back(Vec3f(12.0f,9.50f,5.0f));
verts.push_back(Vec3f(12.0f,10.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect15_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle16GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(12.50f,9.50f,5.0f));
verts.push_back(Vec3f(12.50f,10.0f,5.0f));
verts.push_back(Vec3f(13.0f,9.50f,5.0f));
verts.push_back(Vec3f(13.0f,10.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect16_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle17GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(13.50f,9.50f,5.0f));
verts.push_back(Vec3f(13.50f,10.0f,5.0f));
verts.push_back(Vec3f(14.0f,9.50f,5.0f));
verts.push_back(Vec3f(14.0f,10.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect17_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
void loadRectangle18GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(14.50f,9.50f,5.0f));
verts.push_back(Vec3f(14.50f,10.0f,5.0f));
verts.push_back(Vec3f(15.0f,9.50f,5.0f));
verts.push_back(Vec3f(15.0f,10.0f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect18_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


///set4
void loadRectangle19GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(9.50f,8.50f,5.0f));
verts.push_back(Vec3f(9.5f,9.0,5.0f));
verts.push_back(Vec3f(10.0f,8.50f,5.0f));
verts.push_back(Vec3f(10.0f,9.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect19_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle20GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(10.50f,8.50f,5.0f));
verts.push_back(Vec3f(10.50f,9.0,5.0f));
verts.push_back(Vec3f(11.0f,8.50f,5.0f));
verts.push_back(Vec3f(11.0f,9.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect20_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle21GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(11.50f,8.50f,5.0f));
verts.push_back(Vec3f(11.50f,9.0,5.0f));
verts.push_back(Vec3f(12.0f,8.50f,5.0f));
verts.push_back(Vec3f(12.0f,9.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect21_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle22GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(12.50f,8.50f,5.0f));
verts.push_back(Vec3f(12.50f,9.0,5.0f));
verts.push_back(Vec3f(13.0f,8.50f,5.0f));
verts.push_back(Vec3f(13.0f,9.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect22_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle23GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(13.50f,8.50f,5.0f));
verts.push_back(Vec3f(13.50f,9.0,5.0f));
verts.push_back(Vec3f(14.0f,8.50f,5.0f));
verts.push_back(Vec3f(14.0f,9.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect23_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
void loadRectangle24GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(14.50f,8.50f,5.0f));
verts.push_back(Vec3f(14.50f,9.0,5.0f));
verts.push_back(Vec3f(15.0f,8.50f,5.0f));
verts.push_back(Vec3f(15.0f,9.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect24_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

///set5

void loadRectangle25GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(9.50f,7.50f,5.0f));
verts.push_back(Vec3f(9.5f,8.0,5.0f));
verts.push_back(Vec3f(10.0f,7.50f,5.0f));
verts.push_back(Vec3f(10.0f,8.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect25_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle26GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(10.50f,7.50f,5.0f));
verts.push_back(Vec3f(10.50f,8.0,5.0f));
verts.push_back(Vec3f(11.0f,7.50f,5.0f));
verts.push_back(Vec3f(11.0f,8.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect26_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle27GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(11.50f,7.50f,5.0f));
verts.push_back(Vec3f(11.50f,8.0,5.0f));
verts.push_back(Vec3f(12.0f,7.50f,5.0f));
verts.push_back(Vec3f(12.0f,8.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect27_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle28GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(12.50f,7.50f,5.0f));
verts.push_back(Vec3f(12.50f,8.0,5.0f));
verts.push_back(Vec3f(13.0f,7.50f,5.0f));
verts.push_back(Vec3f(13.0f,8.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect28_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle29GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(13.50f,7.50f,5.0f));
verts.push_back(Vec3f(13.50f,8.0,5.0f));
verts.push_back(Vec3f(14.0f,7.50f,5.0f));
verts.push_back(Vec3f(14.0f,8.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect29_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
void loadRectangle30GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(14.50f,7.50f,5.0f));
verts.push_back(Vec3f(14.50f,8.0,5.0f));
verts.push_back(Vec3f(15.0f,7.50f,5.0f));
verts.push_back(Vec3f(15.0f,8.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect30_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

///set6

void loadRectangle31GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(9.50f,6.5f,5.0f));
verts.push_back(Vec3f(9.5f,7.0,5.0f));
verts.push_back(Vec3f(10.0f,06.5f,5.0f));
verts.push_back(Vec3f(10.0f,7.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect31_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle32GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(10.50f,6.5f,5.0f));
verts.push_back(Vec3f(10.50f,7.0,5.0f));
verts.push_back(Vec3f(11.0f,6.5f,5.0f));
verts.push_back(Vec3f(11.0f,7.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect32_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle33GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(11.50f,6.5f,5.0f));
verts.push_back(Vec3f(11.50f,7.0,5.0f));
verts.push_back(Vec3f(12.0f,6.5f,5.0f));
verts.push_back(Vec3f(12.0f,7.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect33_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle34GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(12.50f,6.5f,5.0f));
verts.push_back(Vec3f(12.50f,7.0,5.0f));
verts.push_back(Vec3f(13.0f,6.5f,5.0f));
verts.push_back(Vec3f(13.0f,7.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect34_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle35GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(13.50f,6.5f,5.0f));
verts.push_back(Vec3f(13.50f,7.0,5.0f));
verts.push_back(Vec3f(14.0f,6.5f,5.0f));
verts.push_back(Vec3f(14.0f,7.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect35_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
void loadRectangle36GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(14.50f,6.5f,5.0f));
verts.push_back(Vec3f(14.50f,7.0,5.0f));
verts.push_back(Vec3f(15.0f,6.5f,5.0f));
verts.push_back(Vec3f(15.0f,7.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect36_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

///set 7

void loadRectangle37GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(9.50f,5.5f,5.0f));
verts.push_back(Vec3f(9.50f,6.0,5.0f));
verts.push_back(Vec3f(10.0f,5.5f,5.0f));
verts.push_back(Vec3f(10.0f,6.0,5.0f));
glBindBuffer(GL_ARRAY_BUFFER, rect37_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle38GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(10.50f,5.5f,5.0f));
verts.push_back(Vec3f(10.50f,6.0,5.0f));
verts.push_back(Vec3f(11.0f,5.5f,5.0f));
verts.push_back(Vec3f(11.0f,6.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect38_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle39GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(11.50f,5.5f,5.0f));
verts.push_back(Vec3f(11.50f,6.0,5.0f));
verts.push_back(Vec3f(12.0f,5.5f,5.0f));
verts.push_back(Vec3f(12.0f,6.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect39_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle40GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(12.50f,5.5f,5.0f));
verts.push_back(Vec3f(12.50f,6.0,5.0f));
verts.push_back(Vec3f(13.0f,5.5f,5.0f));
verts.push_back(Vec3f(13.0f,6.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect40_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadRectangle41GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(13.50f,5.5f,5.0f));
verts.push_back(Vec3f(13.50f,6.0,5.0f));
verts.push_back(Vec3f(14.0f,5.5f,5.0f));
verts.push_back(Vec3f(14.0f,6.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect41_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
void loadRectangle42GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(14.50f,5.5f,5.0f));
verts.push_back(Vec3f(14.50f,6.0,5.0f));
verts.push_back(Vec3f(15.0f,5.5f,5.0f));
verts.push_back(Vec3f(15.0f,6.0,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect42_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


void loadRectangle44GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(9.50f,2.50f,5.0f));
verts.push_back(Vec3f(9.50f,4.5f,5.0f));
verts.push_back(Vec3f(15.0f,2.50f,5.0f));
verts.push_back(Vec3f(15.0f,4.5f,5.0f));

glBindBuffer(GL_ARRAY_BUFFER, rect44_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

///window for the quad

void loadWindowQuad1GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-1.5f,2.0f,1.1f));
verts.push_back(Vec3f(-1.5f,3.0f,1.1f));
verts.push_back(Vec3f(-0.5f,2.0f,1.1f));
verts.push_back(Vec3f(-0.5f,3.0f,1.1f));


glBindBuffer(GL_ARRAY_BUFFER, quad1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadWindowQuad2GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(0.5f,2.0f,1.10f));
verts.push_back(Vec3f(0.5f,3.0f,1.10f));
verts.push_back(Vec3f(1.5f,2.0f,1.10f));
verts.push_back(Vec3f(1.5f,3.0f,1.10f));


glBindBuffer(GL_ARRAY_BUFFER, quad2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

void loadWindowQuad3GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-0.50f,-0.90f,1.10f));
verts.push_back(Vec3f(-0.50f,1.0f,1.10f));
verts.push_back(Vec3f(0.50f,-0.90f,1.10f));
verts.push_back(Vec3f(0.50f,1.0f,1.1f));


glBindBuffer(GL_ARRAY_BUFFER, quad3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

/// car


  ///load triangle
  void loadTriangle1GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-17.0f,-8.0f,2.0f));
verts.push_back(Vec3f(-17.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-18.0f,-7.0f,2.0f));

glBindBuffer(GL_ARRAY_BUFFER, tr1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 3, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
  void loadTriangle2GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-16.0f,-8.0f,2.0f));
verts.push_back(Vec3f(-16.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-15.0f,-7.0f,2.0f));

glBindBuffer(GL_ARRAY_BUFFER, tr2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 3, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}

  void loadTriangle3GeometrytoGPU(){
std::vector<Vec3f> verts;


verts.push_back(Vec3f(-12.0f,-8.0f,2.0f));
verts.push_back(Vec3f(-12.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-13.0f,-7.0f,2.0f));

glBindBuffer(GL_ARRAY_BUFFER, tr3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 3, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
  void loadTriangle4GeometrytoGPU(){
std::vector<Vec3f> verts;
verts.push_back(Vec3f(-11.0f,-8.0f,2.0f));
verts.push_back(Vec3f(-11.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-10.0f,-7.0f,2.0f));

glBindBuffer(GL_ARRAY_BUFFER, tr4_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 3, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


///car wheel
void loadWheel1GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-12.0f,-8.0f,2.0f));
verts.push_back(Vec3f(-12.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-11.0f,-8.0f,2.0f));
verts.push_back(Vec3f(-11.00f,-6.0f,2.0f));

glBindBuffer(GL_ARRAY_BUFFER, wheel1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


void loadWheel2GeometrytoGPU(){
std::vector<Vec3f> verts;

verts.push_back(Vec3f(-17.0f,-8.0f,2.0f));
verts.push_back(Vec3f(-17.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-16.0f,-8.0f,2.0f));
verts.push_back(Vec3f(-16.00f,-6.0f,2.0f));

glBindBuffer(GL_ARRAY_BUFFER, wheel2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}
void loadCar1GeometryToGPU() {
  // Just basic layout of floats, for a cube
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;///

verts.push_back(Vec3f(-18.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-18.0f,-6.0f,-2.0f));
verts.push_back(Vec3f(-18.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-10.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-18.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-18.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-10.0f,-6.0f,-2.0f));
verts.push_back(Vec3f(-18.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-10.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-10.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-10.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-18.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-18.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-18.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-18.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-10.0f,-6.0f,-2.0f));
verts.push_back(Vec3f(-18.0f,-6.0f,-2.0f));
verts.push_back(Vec3f(-18.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-18.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-18.0f,-6.0f,-2.0f));
verts.push_back(Vec3f(-10.0f,-6.0f,-2.0f));
verts.push_back(Vec3f(-10.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-10.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-10.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-10.0f,-6.0f,2.0f));
verts.push_back(Vec3f(-10.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-10.0f,-6.0f,-2.0f));
verts.push_back(Vec3f(-10.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-10.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-18.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-10.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-18.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-18.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-10.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-18.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-10.0f,-6.0f,-2.0f));


///
  glBindBuffer(GL_ARRAY_BUFFER, car1_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}



void loadCar2GeometryToGPU(){
  std::vector<Vec3f> verts;


verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-16.0f,-1.0f, 0.0f));
verts.push_back(Vec3f(-16.0f, 14.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, 14.0f, -4.0f));
verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-16.0f, 14.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, 0.0f));
verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, 14.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-16.0f, 14.0f, 0.0f));
verts.push_back(Vec3f(-16.0f, 14.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, 0.0f));
verts.push_back(Vec3f(-16.0f,-1.0f, 0.0f));
verts.push_back(Vec3f(-16.0f,-1.0f,-4.0f));
verts.push_back(Vec3f(-16.0f, 14.0f, 0.0f));
verts.push_back(Vec3f(-16.0f,-1.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, 0.0f));
verts.push_back(Vec3f(-9.0f,  14.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, 14.0f, -4.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, -4.0f));
verts.push_back(Vec3f(-9.0f,  14.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, 0.0f));
verts.push_back(Vec3f(-9.0f,  14.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, 14.0f, -4.0f));
verts.push_back(Vec3f(-16.0f, 14.0f, -4.0f));
verts.push_back(Vec3f(-9.0f,  14.0f, 0.0f));
verts.push_back(Vec3f(-16.0f, 14.0f, -4.0f));
verts.push_back(Vec3f(-16.0f, 14.0f, 0.0f));
verts.push_back(Vec3f(-9.0f,  14.0f, 0.0f));
verts.push_back(Vec3f(-16.0f, 14.0f, 0.0f));
verts.push_back(Vec3f(-9.0f, -1.0f, 0.0f));

  glBindBuffer(GL_ARRAY_BUFFER, car2_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}



void loadCar3GeometryToGPU(){
  std::vector<Vec3f> verts;

verts.push_back(Vec3f(-16.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-16.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-16.0f,-2.5f,-2.0f));
verts.push_back(Vec3f(-12.0f,-2.50f,2.0f));
verts.push_back(Vec3f(-16.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-16.0f,-2.50f,2.0f));
verts.push_back(Vec3f(-12.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-16.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-12.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-12.0f,-2.50f,2.0f));
verts.push_back(Vec3f(-12.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-16.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-16.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-16.0f,-2.50f,-2.0f));
verts.push_back(Vec3f(-16.0f,-2.50f,2.0f));
verts.push_back(Vec3f(-12.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-16.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-16.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-16.0f,-2.50f,-2.0f));
verts.push_back(Vec3f(-16.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-12.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-12.0f,-2.50f,-2.0f));
verts.push_back(Vec3f(-12.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-12.0f,-2.50f,2.0f));
verts.push_back(Vec3f(-12.0f,-4.0f,2.0f));
verts.push_back(Vec3f(-12.0f,-2.50f,-2.0f));
verts.push_back(Vec3f(-12.0f,-4.0f,-2.0f));
verts.push_back(Vec3f(-12.0f,-2.50f,-2.0f));
verts.push_back(Vec3f(-12.0f,-2.50f,2.0f));
verts.push_back(Vec3f(-16.0f,-2.50f,2.0f));
verts.push_back(Vec3f(-12.0f,-2.50f,-2.0f));
verts.push_back(Vec3f(-16.0f,-2.50f,2.0f));
verts.push_back(Vec3f(-16.0f,-2.50f,-2.0f));
verts.push_back(Vec3f(-12.0f,-2.50f,-2.0f));
verts.push_back(Vec3f(-16.0f,-2.50f,-2.0f));
verts.push_back(Vec3f(-12.0f,-4.0f,-2.0f));

  glBindBuffer(GL_ARRAY_BUFFER, car3_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer

}


void setupVAO() {

    ///car
      glBindVertexArray(car1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, car1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///
                           glBindVertexArray(car2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, car2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///
                           glBindVertexArray(car3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, car3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                           glBindVertexArray(wheel1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, wheel1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///

                        glBindVertexArray(wheel2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, wheel2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                        glBindVertexArray(tr1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, tr1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                        glBindVertexArray(tr2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, tr2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                        glBindVertexArray(tr3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, tr3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                        glBindVertexArray(tr4_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, tr4_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
  glBindVertexArray(vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///windows for quads
                        glBindVertexArray(quad1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, quad1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        glBindVertexArray(quad2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, quad2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        glBindVertexArray(quad3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, quad3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///cube1
  glBindVertexArray(cube1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,cube1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///cube2
                         glBindVertexArray(cube2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,cube2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                         ///cube3
                         glBindVertexArray(cube3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,cube3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
  ///cube4
                         glBindVertexArray(cube4_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,cube4_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///cube5

                         glBindVertexArray(cube5_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,cube5_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///cube6

                         glBindVertexArray(cube6_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,cube6_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///car window
                               glBindVertexArray(carw3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,carw3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///cube7

                         glBindVertexArray(cube7_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,cube7_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///cube8

                         glBindVertexArray(cube8_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,cube8_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///cube 9


                         glBindVertexArray(cube9_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,cube9_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///cube z
                                              glBindVertexArray(cubez_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,cubez_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

  ///rect
                        glBindVertexArray(rect_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///ride frame
                         glBindVertexArray(ride_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,ride_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

///ride quad

                         glBindVertexArray(ridequad_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,ridequad_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///ride seats
          glBindVertexArray(seat1a_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,seat1a_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

          glBindVertexArray(seat2a_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,seat2a_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

          glBindVertexArray(seat3a_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,seat3a_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

          glBindVertexArray(seat1b_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,seat1b_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

          glBindVertexArray(seat2b_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,seat2b_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

          glBindVertexArray(seat3b_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,seat3b_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        /// rect 43 :@
                          glBindVertexArray(rect43_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect43_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///rect 44
                              glBindVertexArray(rect44_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect44_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///rect z1
                          glBindVertexArray(rectz1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rectz1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///rect z2
                          glBindVertexArray(rectz2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rectz2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///horizontal rects

          glBindVertexArray(recthor1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,recthor1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///
                         glBindVertexArray(recthor2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,recthor2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                         glBindVertexArray(recthor3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,recthor3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                         glBindVertexArray(recthor4_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,recthor4_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                         glBindVertexArray(recthor5_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,recthor5_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                         glBindVertexArray(recthor6_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,recthor6_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///horizontal rects end
///..rectangles start...

                        glBindVertexArray(rect1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                                                glBindVertexArray(rect2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

///
                        glBindVertexArray(rect3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect4_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect4_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect5_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect5_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect6_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect6_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///set 2
                                                glBindVertexArray(rect7_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect7_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

///
 glBindVertexArray(rect8_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect8_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                                                glBindVertexArray(rect9_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect9_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

///
                        glBindVertexArray(rect10_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect10_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect11_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect11_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect12_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect12_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect13_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect13_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

                        ///set 3

                                                glBindVertexArray(rect14_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect14_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

///
 glBindVertexArray(rect15_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect15_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                                                glBindVertexArray(rect16_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect16_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

///
                        glBindVertexArray(rect17_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect17_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect18_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect18_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///set4
///
                        glBindVertexArray(rect19_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect19_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect20_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect20_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                          glBindVertexArray(rect21_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect21_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
  glBindVertexArray(rect22_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect22_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
  glBindVertexArray(rect23_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect23_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect24_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect24_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect25_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect25_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                          glBindVertexArray(rect26_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect26_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
  glBindVertexArray(rect27_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect27_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
  glBindVertexArray(rect28_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect28_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect29_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect29_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect30_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect30_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                          glBindVertexArray(rect31_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect31_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
  glBindVertexArray(rect32_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect32_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
  glBindVertexArray(rect33_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect33_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect34_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect34_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect35_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect35_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                          glBindVertexArray(rect36_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect36_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///  ////////
                              glBindVertexArray(rect37_vaoID);
/// ///
      glBindVertexArray(rect38_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect38_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect37_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
////
  /*glBindVertexArray(rect37_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect37_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
  glBindVertexArray(rect38_vaoID);
 // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect38_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );*/
///
                        glBindVertexArray(rect39_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect39_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
                        glBindVertexArray(rect40_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect40_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                          glBindVertexArray(rect41_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect41_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///
  glBindVertexArray(rect42_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect42_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

  glEnableVertexAttribArray(0);

  glBindVertexArray(rect44_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,rect44_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

  glEnableVertexAttribArray(0);


///rectangles end
                        ///winr1

                        glBindVertexArray(winr1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,winr1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///winl1

                        glBindVertexArray(winl1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,winl1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///win2

                        ///winr2

                        glBindVertexArray(winr2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,winr2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///winl2

                        glBindVertexArray(winl2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,winl2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///win3

                        ///winr3

                        glBindVertexArray(winr3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,winr3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///winl3

                        glBindVertexArray(winl3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER,winl3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );


  glBindVertexArray(line_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, line_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

  glBindVertexArray(P_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, P_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );


                        ///parallel line

  glBindVertexArray(linepara_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linepara_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

///line for cube5
  glBindVertexArray(linec5_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linec5_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///vertical lines cz

  glBindVertexArray(linecz1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );


  glBindVertexArray(linecz2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );


  glBindVertexArray(linecz3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );


  glBindVertexArray(linecz4_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz4_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );


  glBindVertexArray(linecz5_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz5_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
  glBindVertexArray(linecz6_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz6_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
  glBindVertexArray(linecz7_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz7_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
  glBindVertexArray(linecz8_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz8_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
  glBindVertexArray(linecz9_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz9_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
  glBindVertexArray(linecz10_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz10_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
  glBindVertexArray(linecz11_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, linecz11_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///windows cube 3
  glBindVertexArray(win1_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, win1_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                        glBindVertexArray(win2_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, win2_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                         glBindVertexArray(win3_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, win3_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                        glBindVertexArray(win4_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, win4_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                        glBindVertexArray(win5_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, win5_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
                        ///
                         glBindVertexArray(win6_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, win6_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
///windows cube 3 ends


  glBindVertexArray(0); // reset to default
}

void reloadProjectionMatrix() {
  // Perspective Only

  // field of view angle 60 degrees
  // window aspect ratio
  // near Z plane > 0
  // far Z plane

  P = PerspectiveProjection(WIN_FOV, // FOV
                            static_cast<float>(WIN_WIDTH) /
                                WIN_HEIGHT, // Aspect
                            WIN_NEAR,       // near plane
                            WIN_FAR);       // far plane depth
}

void loadModelViewMatrix() {
  M = IdentityMatrix();
  line_M = IdentityMatrix();
  P_M = IdentityMatrix();
  cube1_M=IdentityMatrix();
  cube2_M=IdentityMatrix();
  cube3_M=IdentityMatrix();
  cube4_M=IdentityMatrix();
  cube5_M=IdentityMatrix();
  cube6_M=IdentityMatrix();
  cube7_M=IdentityMatrix();
  cube8_M=IdentityMatrix();
  cube9_M=IdentityMatrix();
  cubez_M=IdentityMatrix();
  winr1_M=IdentityMatrix();
  winl1_M=IdentityMatrix();
  winr2_M=IdentityMatrix();
  winl2_M=IdentityMatrix();
  winr3_M=IdentityMatrix();
  winl3_M=IdentityMatrix();
  win1_M=IdentityMatrix();
  win2_M=IdentityMatrix();
  win3_M=IdentityMatrix();
  win4_M=IdentityMatrix();
  win5_M=IdentityMatrix();
  win6_M=IdentityMatrix();
  ///car
  car1_M=IdentityMatrix();
  car2_M=IdentityMatrix();
  car3_M=IdentityMatrix();
  ///wheel
  wheel1_M=IdentityMatrix();
  wheel2_M=IdentityMatrix();
  ///triangles
  tr1_M=IdentityMatrix();
  tr2_M=IdentityMatrix();
  tr3_M=IdentityMatrix();
  tr4_M=IdentityMatrix();
  ///ride
  ride_M=IdentityMatrix();
  ridequad_M=IdentityMatrix();
  ///ride seats
  seat1a_M=IdentityMatrix();
  seat2a_M=IdentityMatrix();
  seat3a_M=IdentityMatrix();
  seat1b_M=IdentityMatrix();
  seat2b_M=IdentityMatrix();
  seat3b_M=IdentityMatrix();

  ///windows for quad
  quad1_M=IdentityMatrix();
  quad2_M=IdentityMatrix();
  quad3_M=IdentityMatrix();

  linec5_M=IdentityMatrix();
  ///lines cz
  linecz1_M=IdentityMatrix();
  linecz2_M=IdentityMatrix();
  linecz3_M=IdentityMatrix();
  linecz4_M=IdentityMatrix();
  linecz5_M=IdentityMatrix();
  linecz6_M=IdentityMatrix();
  linecz7_M=IdentityMatrix();
  linecz8_M=IdentityMatrix();
  linecz9_M=IdentityMatrix();
  linecz10_M=IdentityMatrix();
  linecz11_M=IdentityMatrix();


  rect_M=IdentityMatrix();
  rectz1_M=IdentityMatrix();
  rectz2_M=IdentityMatrix();
  rect1_M=IdentityMatrix();
  rect2_M=IdentityMatrix();
  rect43_M=IdentityMatrix();
  rect3_M=IdentityMatrix();
  rect4_M=IdentityMatrix();
  rect5_M=IdentityMatrix();
  rect6_M=IdentityMatrix();
  rect7_M=IdentityMatrix();
 rect8_M=IdentityMatrix();
  rect9_M=IdentityMatrix();
  rect10_M=IdentityMatrix();
  rect11_M=IdentityMatrix();
  rect12_M=IdentityMatrix();
  rect13_M=IdentityMatrix();
  rect14_M=IdentityMatrix();
   rect15_M=IdentityMatrix();
  rect16_M=IdentityMatrix();
  rect17_M=IdentityMatrix();
  rect18_M=IdentityMatrix();
  rect19_M=IdentityMatrix();
  rect20_M=IdentityMatrix();
  rect21_M=IdentityMatrix();
  rect22_M=IdentityMatrix();
  rect23_M=IdentityMatrix();
  rect24_M=IdentityMatrix();
  rect25_M=IdentityMatrix();
 rect26_M=IdentityMatrix();
  rect27_M=IdentityMatrix();
  rect28_M=IdentityMatrix();
  rect29_M=IdentityMatrix();
  rect30_M=IdentityMatrix();
  rect31_M=IdentityMatrix();
  rect32_M=IdentityMatrix();
   rect33_M=IdentityMatrix();
  rect34_M=IdentityMatrix();
  rect35_M=IdentityMatrix();
  rect36_M=IdentityMatrix();
  rect37_M=IdentityMatrix();
  rect38_M=IdentityMatrix();
  rect39_M=IdentityMatrix();
   rect40_M=IdentityMatrix();
  rect41_M=IdentityMatrix();
  rect42_M=IdentityMatrix();
  rect44_M=IdentityMatrix();
recthor1_M=IdentityMatrix();
recthor2_M=IdentityMatrix();
recthor3_M=IdentityMatrix();
recthor4_M=IdentityMatrix();
recthor5_M=IdentityMatrix();
recthor6_M=IdentityMatrix();
carw3_M=IdentityMatrix();

//  rect8_M=IdentityMatrix();
  //rect9_M=IdentityMatrix();
  linepara_M=IdentityMatrix();
  // view doesn't change, but if it did you would use this
  V = camera.lookatMatrix();
}

void reloadViewMatrix() { V = camera.lookatMatrix(); }

void setupModelViewProjectionTransform() {
  MVP = P * V * M; // transforms vertices from right to left (odd huh?)
}

void reloadMVPUniform(GLuint ProgramID) {
  GLint id = glGetUniformLocation(ProgramID, "MVP");

  glUseProgram(ProgramID);
  glUniformMatrix4fv(id,        // ID
                     1,         // only 1 matrix
                     GL_TRUE,   // transpose matrix, Mat4f is row major
                     MVP.data() // pointer to data in Mat4f
                     );
}

void reloadColorUniform(float r, float g, float b, GLuint ProgramID) {
  GLint id = glGetUniformLocation(ProgramID, "inputColor");

  glUseProgram(ProgramID);
  glUniform3f(id, // ID in basic_vs.glsl
              r, g, b);
}

void generateIDs() {
  // shader ID from OpenGL
  std::string vsSource = loadShaderStringfromFile("./shaders/basic.vert");
  std::string fsSource = loadShaderStringfromFile("./shaders/basic.frag");
  basicProgramID = CreateShaderProgram(vsSource, fsSource);

  std::string vsSource1 = loadShaderStringfromFile("./shaders/cube.vert");
  std::string fsSource1 = loadShaderStringfromFile("./shaders/cube.frag");
  basicProgramID1 = CreateShaderProgram(vsSource1, fsSource1);

   std::string vsSource2 = loadShaderStringfromFile("./shaders/new.vert");
  std::string fsSource2 = loadShaderStringfromFile("./shaders/new.frag");
  basicProgramID2 = CreateShaderProgram(vsSource2, fsSource2);

  // VAO and buffer IDs given from OpenGL
  glGenVertexArrays(1, &vaoID);
  glGenBuffers(1, &vertBufferID);
  glGenVertexArrays(1, &line_vaoID);
  glGenBuffers(1, &line_vertBufferID);
  glGenVertexArrays(1, &P_vaoID);
  glGenBuffers(1, &P_vertBufferID);
  ///car winodw
  glGenVertexArrays(1, &carw3_vaoID);
  glGenBuffers(1, &carw3_vertBufferID);

  ///car
      glGenVertexArrays(1, &car1_vaoID);
  glGenBuffers(1, &car1_vertBufferID);
      glGenVertexArrays(1, &car2_vaoID);
  glGenBuffers(1, &car2_vertBufferID);
      glGenVertexArrays(1, &car3_vaoID);
  glGenBuffers(1, &car3_vertBufferID);
  ///wheel
      glGenVertexArrays(1, &wheel1_vaoID);
  glGenBuffers(1, &wheel1_vertBufferID);
      glGenVertexArrays(1, &wheel2_vaoID);
  glGenBuffers(1, &wheel2_vertBufferID);
///tringlw
    glGenVertexArrays(1, &tr1_vaoID);
  glGenBuffers(1, &tr1_vertBufferID);
    glGenVertexArrays(1, &tr2_vaoID);
  glGenBuffers(1, &tr2_vertBufferID);
    glGenVertexArrays(1, &tr3_vaoID);
  glGenBuffers(1, &tr3_vertBufferID);
    glGenVertexArrays(1, &tr4_vaoID);
  glGenBuffers(1, &tr4_vertBufferID);
  ///ride frame
    glGenVertexArrays(1, &ride_vaoID);
  glGenBuffers(1, &ride_vertBufferID);
  ///ride quad
     glGenVertexArrays(1, &ridequad_vaoID);
  glGenBuffers(1, &ridequad_vertBufferID);

  ///ride seats
   glGenVertexArrays(1, &seat1a_vaoID);
  glGenBuffers(1, &seat1a_vertBufferID);
   glGenVertexArrays(1, &seat2a_vaoID);
  glGenBuffers(1, &seat2a_vertBufferID);
   glGenVertexArrays(1, &seat3a_vaoID);
  glGenBuffers(1, &seat3a_vertBufferID);
   glGenVertexArrays(1, &seat1b_vaoID);
  glGenBuffers(1, &seat1b_vertBufferID);
   glGenVertexArrays(1, &seat2b_vaoID);
  glGenBuffers(1, &seat2b_vertBufferID);
   glGenVertexArrays(1, &seat3b_vaoID);
  glGenBuffers(1, &seat3b_vertBufferID);
  ///parallel line
  glGenVertexArrays(1, &linepara_vaoID);
  glGenBuffers(1, &linepara_vertBufferID);
  ///line for c5
    glGenVertexArrays(1, &linec5_vaoID);
  glGenBuffers(1, &linec5_vertBufferID);
  ///cube1
  glGenVertexArrays(1, &cube1_vaoID);
  glGenBuffers(1, &cube1_vertBufferID);
  ///cube2
  glGenVertexArrays(1, &cube2_vaoID);
  glGenBuffers(1, &cube2_vertBufferID);
  ///cube3
  glGenVertexArrays(1, &cube3_vaoID);
  glGenBuffers(1, &cube3_vertBufferID);
  ///cube4
  glGenVertexArrays(1, &cube4_vaoID);
  glGenBuffers(1, &cube4_vertBufferID);

   ///cube5
  glGenVertexArrays(1, &cube5_vaoID);
  glGenBuffers(1, &cube5_vertBufferID);
   ///cube6
  glGenVertexArrays(1, &cube6_vaoID);
  glGenBuffers(1, &cube6_vertBufferID);
    ///cube7
  glGenVertexArrays(1, &cube7_vaoID);
  glGenBuffers(1, &cube7_vertBufferID);
     ///cube8
  glGenVertexArrays(1, &cube8_vaoID);
  glGenBuffers(1, &cube8_vertBufferID);
    ///cube9
  glGenVertexArrays(1, &cube9_vaoID);
  glGenBuffers(1, &cube9_vertBufferID);
     ///cube z
  glGenVertexArrays(1, &cubez_vaoID);
  glGenBuffers(1, &cubez_vertBufferID);
  ///rect
  glGenVertexArrays(1, &rect_vaoID);
  glGenBuffers(1, &rect_vertBufferID);
///rect z1
  glGenVertexArrays(1, &rectz1_vaoID);
  glGenBuffers(1, &rectz1_vertBufferID);
///rect z2
  glGenVertexArrays(1, &rectz2_vaoID);
  glGenBuffers(1, &rectz2_vertBufferID);
///window for quad

  glGenVertexArrays(1, &quad1_vaoID);
  glGenBuffers(1, &quad1_vertBufferID);

  glGenVertexArrays(1, &quad2_vaoID);
  glGenBuffers(1, &quad2_vertBufferID);

  glGenVertexArrays(1, &quad3_vaoID);
  glGenBuffers(1, &quad3_vertBufferID);

  ///winr1
  glGenVertexArrays(1, &winr1_vaoID);
  glGenBuffers(1, &winr1_vertBufferID);

  ///winr1
  glGenVertexArrays(1, &winr1_vaoID);
  glGenBuffers(1, &winr1_vertBufferID);

  ///winl1
  glGenVertexArrays(1, &winl1_vaoID);
  glGenBuffers(1, &winl1_vertBufferID);


  ///winr2
  glGenVertexArrays(1, &winr2_vaoID);
  glGenBuffers(1, &winr2_vertBufferID);

  ///winl2
  glGenVertexArrays(1, &winl2_vaoID);
  glGenBuffers(1, &winl2_vertBufferID);


  ///winr3
  glGenVertexArrays(1, &winr3_vaoID);
  glGenBuffers(1, &winr3_vertBufferID);

  ///winl3
  glGenVertexArrays(1, &winl3_vaoID);
  glGenBuffers(1, &winl3_vertBufferID);


  ///for cube 3
   glGenVertexArrays(1, &win1_vaoID);
  glGenBuffers(1, &win1_vertBufferID);
   glGenVertexArrays(1, &win2_vaoID);
  glGenBuffers(1, &win2_vertBufferID);
   glGenVertexArrays(1, &win3_vaoID);
  glGenBuffers(1, &win3_vertBufferID);
   glGenVertexArrays(1, &win4_vaoID);
  glGenBuffers(1, &win4_vertBufferID);
   glGenVertexArrays(1, &win5_vaoID);
  glGenBuffers(1, &win5_vertBufferID);
   glGenVertexArrays(1, &win6_vaoID);
  glGenBuffers(1, &win6_vertBufferID);

  ///rectngles

  glGenVertexArrays(1, &rect43_vaoID);
  glGenBuffers(1, &rect43_vertBufferID);

  glGenVertexArrays(1, &rect1_vaoID);
  glGenBuffers(1, &rect1_vertBufferID);
  glGenVertexArrays(1, &rect2_vaoID);
  glGenBuffers(1, &rect2_vertBufferID);
  glGenVertexArrays(1, &rect3_vaoID);
  glGenBuffers(1, &rect3_vertBufferID);
  glGenVertexArrays(1, &rect4_vaoID);
  glGenBuffers(1, &rect4_vertBufferID);
  glGenVertexArrays(1, &rect5_vaoID);
  glGenBuffers(1, &rect5_vertBufferID);
  glGenVertexArrays(1, &rect6_vaoID);
  glGenBuffers(1, &rect6_vertBufferID);
  glGenVertexArrays(1, &rect7_vaoID);
  glGenBuffers(1, &rect7_vertBufferID);

  glGenVertexArrays(1, &rect8_vaoID);
  glGenBuffers(1, &rect8_vertBufferID);
  glGenVertexArrays(1, &rect9_vaoID);
  glGenBuffers(1, &rect9_vertBufferID);
  glGenVertexArrays(1, &rect10_vaoID);
  glGenBuffers(1, &rect10_vertBufferID);
  glGenVertexArrays(1, &rect11_vaoID);
  glGenBuffers(1, &rect11_vertBufferID);
  glGenVertexArrays(1, &rect12_vaoID);
  glGenBuffers(1, &rect12_vertBufferID);
  glGenVertexArrays(1, &rect13_vaoID);
  glGenBuffers(1, &rect13_vertBufferID);
  glGenVertexArrays(1, &rect14_vaoID);
  glGenBuffers(1, &rect14_vertBufferID);
  glGenVertexArrays(1, &rect15_vaoID);
  glGenBuffers(1, &rect15_vertBufferID);
  glGenVertexArrays(1, &rect16_vaoID);
  glGenBuffers(1, &rect16_vertBufferID);
  glGenVertexArrays(1, &rect17_vaoID);
  glGenBuffers(1, &rect17_vertBufferID);
  glGenVertexArrays(1, &rect18_vaoID);
  glGenBuffers(1, &rect18_vertBufferID);

    glGenVertexArrays(1, &rect19_vaoID);
  glGenBuffers(1, &rect19_vertBufferID);
  glGenVertexArrays(1, &rect20_vaoID);
  glGenBuffers(1, &rect20_vertBufferID);
  glGenVertexArrays(1, &rect21_vaoID);
  glGenBuffers(1, &rect21_vertBufferID);
  glGenVertexArrays(1, &rect22_vaoID);
  glGenBuffers(1, &rect22_vertBufferID);
  glGenVertexArrays(1, &rect23_vaoID);
  glGenBuffers(1, &rect23_vertBufferID);
  glGenVertexArrays(1, &rect24_vaoID);
  glGenBuffers(1, &rect24_vertBufferID);
  glGenVertexArrays(1, &rect25_vaoID);
  glGenBuffers(1, &rect25_vertBufferID);

  glGenVertexArrays(1, &rect26_vaoID);
  glGenBuffers(1, &rect26_vertBufferID);
  glGenVertexArrays(1, &rect27_vaoID);
  glGenBuffers(1, &rect27_vertBufferID);
  glGenVertexArrays(1, &rect28_vaoID);
  glGenBuffers(1, &rect28_vertBufferID);
  glGenVertexArrays(1, &rect29_vaoID);
  glGenBuffers(1, &rect29_vertBufferID);
  glGenVertexArrays(1, &rect30_vaoID);
  glGenBuffers(1, &rect30_vertBufferID);
  glGenVertexArrays(1, &rect31_vaoID);
  glGenBuffers(1, &rect31_vertBufferID);
  glGenVertexArrays(1, &rect32_vaoID);
  glGenBuffers(1, &rect32_vertBufferID);
  glGenVertexArrays(1, &rect33_vaoID);
  glGenBuffers(1, &rect33_vertBufferID);
  glGenVertexArrays(1, &rect34_vaoID);
  glGenBuffers(1, &rect34_vertBufferID);
  glGenVertexArrays(1, &rect35_vaoID);
  glGenBuffers(1, &rect35_vertBufferID);
  glGenVertexArrays(1, &rect36_vaoID);
  glGenBuffers(1, &rect36_vertBufferID);
  glGenVertexArrays(1, &rect37_vaoID);
  glGenBuffers(1, &rect37_vertBufferID);
  glGenVertexArrays(1, &rect38_vaoID);
  glGenBuffers(1, &rect38_vertBufferID);
  glGenVertexArrays(1, &rect39_vaoID);
  glGenBuffers(1, &rect39_vertBufferID);
  glGenVertexArrays(1, &rect40_vaoID);
  glGenBuffers(1, &rect40_vertBufferID);
  glGenVertexArrays(1, &rect41_vaoID);
  glGenBuffers(1, &rect41_vertBufferID);
  glGenVertexArrays(1, &rect42_vaoID);
  glGenBuffers(1, &rect42_vertBufferID);
  glGenVertexArrays(1, &rect44_vaoID);
  glGenBuffers(1, &rect44_vertBufferID);
///horizontal rects
  glGenVertexArrays(1, &recthor1_vaoID);
  glGenBuffers(1, &recthor1_vertBufferID);

  glGenVertexArrays(1, &recthor2_vaoID);
  glGenBuffers(1, &recthor2_vertBufferID);


  glGenVertexArrays(1, &recthor3_vaoID);
  glGenBuffers(1, &recthor3_vertBufferID);

  glGenVertexArrays(1, &recthor4_vaoID);
  glGenBuffers(1, &recthor4_vertBufferID);

  glGenVertexArrays(1, &recthor5_vaoID);
  glGenBuffers(1, &recthor5_vertBufferID);


  glGenVertexArrays(1, &recthor6_vaoID);
  glGenBuffers(1, &recthor6_vertBufferID);

  ///lines for cz

    glGenVertexArrays(1, &linecz1_vaoID);
  glGenBuffers(1, &linecz1_vertBufferID);

    glGenVertexArrays(1, &linecz2_vaoID);
  glGenBuffers(1, &linecz2_vertBufferID);

    glGenVertexArrays(1, &linecz3_vaoID);
  glGenBuffers(1, &linecz3_vertBufferID);

    glGenVertexArrays(1, &linecz4_vaoID);
  glGenBuffers(1, &linecz4_vertBufferID);

    glGenVertexArrays(1, &linecz5_vaoID);
  glGenBuffers(1, &linecz5_vertBufferID);

  glGenVertexArrays(1, &linecz6_vaoID);
  glGenBuffers(1, &linecz6_vertBufferID);

    glGenVertexArrays(1, &linecz7_vaoID);
  glGenBuffers(1, &linecz7_vertBufferID);

    glGenVertexArrays(1, &linecz8_vaoID);
  glGenBuffers(1, &linecz8_vertBufferID);

    glGenVertexArrays(1, &linecz9_vaoID);
  glGenBuffers(1, &linecz9_vertBufferID);

    glGenVertexArrays(1, &linecz10_vaoID);
  glGenBuffers(1, &linecz10_vertBufferID);

    glGenVertexArrays(1, &linecz11_vaoID);
  glGenBuffers(1, &linecz11_vertBufferID);

}

void deleteIDs() {
  glDeleteProgram(basicProgramID);
  glDeleteProgram(basicProgramID1);
  glDeleteProgram(basicProgramID2);

  glDeleteVertexArrays(1, &vaoID);
  glDeleteBuffers(1, &vertBufferID);
  glDeleteVertexArrays(1, &line_vaoID);
  glDeleteBuffers(1, &line_vertBufferID);
  glDeleteVertexArrays(1, &P_vaoID);
  glDeleteBuffers(1, &P_vertBufferID);

  ///parallel
  glDeleteVertexArrays(1, &linepara_vaoID);
  glDeleteBuffers(1, &linepara_vertBufferID);
///line c5
 glDeleteVertexArrays(1, &linec5_vaoID);
  glDeleteBuffers(1, &linec5_vertBufferID);
  ///cube1
  glDeleteVertexArrays(1, &cube1_vaoID);
  glDeleteBuffers(1, &cube1_vertBufferID);
 ///cube2
  glDeleteVertexArrays(1, &cube2_vaoID);
  glDeleteBuffers(1, &cube2_vertBufferID);
  ///cube3
  glDeleteVertexArrays(1, &cube3_vaoID);
  glDeleteBuffers(1, &cube3_vertBufferID);
  ///cube4
   glDeleteVertexArrays(1, &cube4_vaoID);
  glDeleteBuffers(1, &cube4_vertBufferID);

  ///cube5
   glDeleteVertexArrays(1, &cube5_vaoID);
  glDeleteBuffers(1, &cube5_vertBufferID);

    ///cube6
   glDeleteVertexArrays(1, &cube6_vaoID);
  glDeleteBuffers(1, &cube6_vertBufferID);

    ///cube7
   glDeleteVertexArrays(1, &cube7_vaoID);
  glDeleteBuffers(1, &cube7_vertBufferID);

    ///cube8
   glDeleteVertexArrays(1, &cube8_vaoID);
  glDeleteBuffers(1, &cube8_vertBufferID);

    ///cube9
   glDeleteVertexArrays(1, &cube9_vaoID);
  glDeleteBuffers(1, &cube9_vertBufferID);
    ///cube z
   glDeleteVertexArrays(1, &cubez_vaoID);
  glDeleteBuffers(1, &cubez_vertBufferID);


  ///rectangle
   glDeleteVertexArrays(1, &rect_vaoID);
  glDeleteBuffers(1, &rect_vertBufferID);
  glDeleteVertexArrays(1, &rectz1_vaoID);
  glDeleteBuffers(1, &rectz1_vertBufferID);
  glDeleteVertexArrays(1, &rectz2_vaoID);
  glDeleteBuffers(1, &rectz2_vertBufferID);

  ///winr1
     glDeleteVertexArrays(1, &winr1_vaoID);
  glDeleteBuffers(1, &winr1_vertBufferID);
  ///winl1
     glDeleteVertexArrays(1, &winl1_vaoID);
  glDeleteBuffers(1, &winl1_vertBufferID);

  ///winr2
     glDeleteVertexArrays(1, &winr2_vaoID);
  glDeleteBuffers(1, &winr2_vertBufferID);
  ///winl2
     glDeleteVertexArrays(1, &winl2_vaoID);
  glDeleteBuffers(1, &winl2_vertBufferID);

}

void init() {
  glEnable(GL_DEPTH_TEST);
  glPointSize(100);
///camera er parameter change korsi //camera = Camera(Vec3f{0, 30 30}, Vec3f{0, 0, -1}, Vec3f{0, 1, 0});// chilo
  camera = Camera(Vec3f{0, 13, 40}, Vec3f{0,0 , -1}, Vec3f{0, 1, 0});

  // SETUP SHADERS, BUFFERS, VAOs

  generateIDs();
  setupVAO();
  loadQuadGeometryToGPU();
  loadLineGeometryToGPU();
  loadPyramidGeometryToGPU();
  loadParallelLineGeometryToGPU();
  loadCube1GeometryToGPU();
  loadCube2GeometryToGPU();
  loadCube3GeometryToGPU();
  loadCube4GeometryToGPU();
  loadCube5GeometryToGPU();
  loadCube6GeometryToGPU();
  loadCube7GeometryToGPU();
  loadCube8GeometryToGPU();
  loadCube9GeometryToGPU();
  loadCubeZGeometryToGPU();
  loadWinl1GeometrytoGPU();
  loadWinr1GeometrytoGPU();
  loadWinl2GeometrytoGPU();
  loadWinr2GeometrytoGPU();
  loadWinl3GeometrytoGPU();
  loadWinr3GeometrytoGPU();
  loadRectangleGeometrytoGPU();
  loadLineC5GeometrytoGPU();
  loadRectanglez1GeometrytoGPU();
  loadRectanglez2GeometrytoGPU();
  loadRectangle1GeometrytoGPU();
  loadRectangle2GeometrytoGPU();
  loadRectangle3GeometrytoGPU();
  loadRectangle4GeometrytoGPU();
  loadRectangle5GeometrytoGPU();
  loadRectangle6GeometrytoGPU();
  loadRectangle7GeometrytoGPU();
  loadRectangle8GeometrytoGPU();
  loadRectangle9GeometrytoGPU();
  loadRectangle10GeometrytoGPU();
  loadRectangle11GeometrytoGPU();
  loadRectangle12GeometrytoGPU();
  loadRectangle13GeometrytoGPU();
  loadRectangle14GeometrytoGPU();
  loadRectangle15GeometrytoGPU();
  loadRectangle16GeometrytoGPU();
  loadRectangle17GeometrytoGPU();
  loadRectangle18GeometrytoGPU();
  loadRectangle19GeometrytoGPU();
  loadRectangle20GeometrytoGPU();
  loadRectangle21GeometrytoGPU();
  loadRectangle22GeometrytoGPU();
  loadRectangle23GeometrytoGPU();
  loadRectangle24GeometrytoGPU();
  loadRectangle25GeometrytoGPU();
  loadRectangle26GeometrytoGPU();
  loadRectangle27GeometrytoGPU();
  loadRectangle28GeometrytoGPU();
  loadRectangle29GeometrytoGPU();
  loadRectangle30GeometrytoGPU();
  loadRectangle31GeometrytoGPU();
  loadRectangle32GeometrytoGPU();
  loadRectangle33GeometrytoGPU();
  loadRectangle34GeometrytoGPU();
  loadRectangle35GeometrytoGPU();
  loadRectangle36GeometrytoGPU();
  loadRectangle37GeometrytoGPU();
  loadRectangle38GeometrytoGPU();
  loadRectangle39GeometrytoGPU();
  loadRectangle40GeometrytoGPU();
  loadRectangle41GeometrytoGPU();
  loadRectangle42GeometrytoGPU();
  loadRectangle43GeometrytoGPU();
  loadRectangle44GeometrytoGPU();
  loadRectangleHor1GeometrytoGPU();
  loadRectangleHor2GeometrytoGPU();
  loadRectangleHor3GeometrytoGPU();
  loadRectangleHor4GeometrytoGPU();
  loadRectangleHor5GeometrytoGPU();
  loadRectangleHor6GeometrytoGPU();
  ///car
  loadCar1GeometryToGPU();
  //loadCar2GeometryToGPU();
  loadCar3GeometryToGPU();
  loadCarWindowGeometrytoGPU();

  loadWheel1GeometrytoGPU();
  loadWheel2GeometrytoGPU();

  loadTriangle1GeometrytoGPU();
  loadTriangle2GeometrytoGPU();
  loadTriangle3GeometrytoGPU();
  loadTriangle4GeometrytoGPU();

  loadRideGeometrytoGPU();
  loadRideQuadGeometryToGPU();
  loadSeat1aGeometrytoGPU();
  loadSeat2aGeometrytoGPU();
  loadSeat3aGeometrytoGPU();

  loadSeat1bGeometrytoGPU();
  loadSeat2bGeometrytoGPU();
  loadSeat3bGeometrytoGPU();

  loadWindowQuad1GeometrytoGPU();
  loadWindowQuad2GeometrytoGPU();
  loadWindowQuad3GeometrytoGPU();

loadLineCz1GeometryToGPU();
loadLineCz2GeometryToGPU();
loadLineCz3GeometryToGPU();
loadLineCz4GeometryToGPU();
loadLineCz5GeometryToGPU();
loadLineCz6GeometryToGPU();
loadLineCz7GeometryToGPU();
loadLineCz8GeometryToGPU();
loadLineCz9GeometryToGPU();
loadLineCz10GeometryToGPU();
loadLineCz11GeometryToGPU();

loadWindow1GeometrytoGPU();
loadWindow2GeometrytoGPU();
loadWindow3GeometrytoGPU();
loadWindow4GeometrytoGPU();
loadWindow5GeometrytoGPU();
loadWindow6GeometrytoGPU();

  loadModelViewMatrix();
  reloadProjectionMatrix();
  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}

int main(int argc, char **argv) {
  GLFWwindow *window;

  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window =
      glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Tasneea's Skyline", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  glfwSetWindowSizeCallback(window, windowSetSizeFunc);
  glfwSetFramebufferSizeCallback(window, windowSetFramebufferSizeFunc);
  glfwSetKeyCallback(window, windowKeyFunc);
  glfwSetCursorPosCallback(window, windowMouseMotionFunc);
  glfwSetMouseButtonCallback(window, windowMouseButtonFunc);

  glfwGetFramebufferSize(window, &WIN_WIDTH, &WIN_HEIGHT);

  // Initialize glad
  if (!gladLoadGL()) {
    std::cerr << "Failed to initialise GLAD" << std::endl;
    return -1;
  }

  std::cout << "GL Version: :" << glGetString(GL_VERSION) << std::endl;
  std::cout << GL_ERROR() << std::endl;

  // Initialize all the geometry, and load it once to the GPU
  init(); // our own initialize stuff func

  float t = 0;
  float dt = 0.01;

  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
         !glfwWindowShouldClose(window)) {

    if (g_play) {
      t += dt;
      animateQuad(t);
    }

    displayFunc();
    moveCamera();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // clean up after loop
  deleteIDs();

  return 0;
}

//==================== CALLBACK FUNCTIONS ====================//

void windowSetSizeFunc(GLFWwindow *window, int width, int height) {
  WIN_WIDTH = width;
  WIN_HEIGHT = height;

  reloadProjectionMatrix();
  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID1);
}

void windowSetFramebufferSizeFunc(GLFWwindow *window, int width, int height) {
  FB_WIDTH = width;
  FB_HEIGHT = height;

  glViewport(0, 0, FB_WIDTH, FB_HEIGHT);
}

void windowMouseButtonFunc(GLFWwindow *window, int button, int action,
                           int mods) {
  if (button == GLFW_MOUSE_BUTTON_LEFT) {
    if (action == GLFW_PRESS) {
      g_cursorLocked = GL_TRUE;
    } else {
      g_cursorLocked = GL_FALSE;
    }
  }
}

void windowMouseMotionFunc(GLFWwindow *window, double x, double y) {
  if (g_cursorLocked) {
    float deltaX = (x - g_cursorX) * 0.01;
    float deltaY = (y - g_cursorY) * 0.01;
    camera.rotateAroundFocus(deltaX, deltaY);

    reloadViewMatrix();
    setupModelViewProjectionTransform();
    reloadMVPUniform(basicProgramID);
  }

  g_cursorX = x;
  g_cursorY = y;
}

void windowKeyFunc(GLFWwindow *window, int key, int scancode, int action,
                   int mods) {
  bool set = action != GLFW_RELEASE && GLFW_REPEAT;
  switch (key) {
  case GLFW_KEY_ESCAPE:
    glfwSetWindowShouldClose(window, GL_TRUE);
    break;
  case GLFW_KEY_W:
    g_moveBackForward = set ? 1 : 0;
    break;
  case GLFW_KEY_S:
    g_moveBackForward = set ? -1 : 0;
    break;
  case GLFW_KEY_A:
    g_moveLeftRight = set ? 1 : 0;
    break;
  case GLFW_KEY_D:
    g_moveLeftRight = set ? -1 : 0;
    break;
  case GLFW_KEY_Q:
    g_moveUpDown = set ? -1 : 0;
    break;
  case GLFW_KEY_E:
    g_moveUpDown = set ? 1 : 0;
    break;
  case GLFW_KEY_UP:
    g_rotateUpDown = set ? -1 : 0;
    break;
  case GLFW_KEY_DOWN:
    g_rotateUpDown = set ? 1 : 0;
    break;
  case GLFW_KEY_LEFT:
    if (mods == GLFW_MOD_SHIFT)
      g_rotateRoll = set ? -1 : 0;
    else
      g_rotateLeftRight = set ? 1 : 0;
    break;
  case GLFW_KEY_RIGHT:
    if (mods == GLFW_MOD_SHIFT)
      g_rotateRoll = set ? 1 : 0;
    else
      g_rotateLeftRight = set ? -1 : 0;
    break;
  case GLFW_KEY_SPACE:
    g_play = set ? !g_play : g_play;
    break;
  case GLFW_KEY_LEFT_BRACKET:
    if (mods == GLFW_MOD_SHIFT) {
      g_rotationSpeed *= 0.5;
    } else {
      g_panningSpeed *= 0.5;
    }
    break;
  case GLFW_KEY_RIGHT_BRACKET:
    if (mods == GLFW_MOD_SHIFT) {
      g_rotationSpeed *= 1.5;
    } else {
      g_panningSpeed *= 1.5;
    }
    break;
  default:
    break;
  }
}

//==================== OPENGL HELPER FUNCTIONS ====================//

void moveCamera() {
  Vec3f dir;

  if (g_moveBackForward) {
    dir += Vec3f(0, 0, g_moveBackForward * g_panningSpeed);
  }
  if (g_moveLeftRight) {
    dir += Vec3f(g_moveLeftRight * g_panningSpeed, 0, 0);
  }
  if (g_moveUpDown) {
    dir += Vec3f(0, g_moveUpDown * g_panningSpeed, 0);
  }

  if (g_rotateUpDown) {
    camera.rotateUpDown(g_rotateUpDown * g_rotationSpeed);
  }
  if (g_rotateLeftRight) {
    camera.rotateLeftRight(g_rotateLeftRight * g_rotationSpeed);
  }
  if (g_rotateRoll) {
    camera.rotateRoll(g_rotateRoll * g_rotationSpeed);
  }

  if (g_moveUpDown || g_moveLeftRight || g_moveBackForward ||
      g_rotateLeftRight || g_rotateUpDown || g_rotateRoll) {
    camera.move(dir);
    reloadViewMatrix();
    setupModelViewProjectionTransform();
    reloadMVPUniform(basicProgramID1);
  }
}

std::string GL_ERROR() {
  GLenum code = glGetError();

  switch (code) {
  case GL_NO_ERROR:
    return "GL_NO_ERROR";
  case GL_INVALID_ENUM:
    return "GL_INVALID_ENUM";
  case GL_INVALID_VALUE:
    return "GL_INVALID_VALUE";
  case GL_INVALID_OPERATION:
    return "GL_INVALID_OPERATION";
  case GL_INVALID_FRAMEBUFFER_OPERATION:
    return "GL_INVALID_FRAMEBUFFER_OPERATION";
  case GL_OUT_OF_MEMORY:
    return "GL_OUT_OF_MEMORY";
  default:
    return "Non Valid Error Code";
  }
}
