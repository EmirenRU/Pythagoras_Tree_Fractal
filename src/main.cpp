#include "main.hpp"

typedef struct{
    double x,y;
}Vector2D;

static void line(Vector2D * start, Vector2D * end);
static void PythagorasTree(Vector2D * start, const unsigned long depth, 
                            const unsigned long len, const double fi, const double alpha);

const double pi6 = pi / 6;
const double pi3 = pi / 3;
const double pi2 = pi / 2;
const double pi4 = pi / 4;


int main()
{
   
    GLFWwindow* window;
 
    if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW" << std::endl;
    return -1;
    }

  window = glfwCreateWindow(800, 800, "Pythagoras Tree", NULL, NULL);

  if (!window) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

    glfwSetWindowPos(window,50,50);

    glfwMakeContextCurrent(window);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    glViewport(0,0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,width,height, 0.0, 0.0, 1.0);

    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
    

    while (!glfwWindowShouldClose(window)) {
      int width, height;
      
      glfwGetFramebufferSize(window, &width, &height);

      glClear( GL_COLOR_BUFFER_BIT);

      Vector2D start = {width*0.49f,height*0.49f};

      PythagorasTree(&start, 10, width * 0.2, pi3, pi6);

      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}

static void PythagorasTree(Vector2D * start, const unsigned long depth, 
                            const unsigned long len, const double fi, const double alpha)
{	
	if(depth==0||start==0||len==0) return;
	
  Vector2D a,b,c,d;

  float scale = 1.0f;

  // a = {scale * (cos(alpha) * len - sin(alpha) * len) + start->x,
  //      start->y + scale * (sin(alpha) * len + cos(alpha) * len)};
    
  // b = {start->x - scale * (cos(alpha) * len - sin(alpha) * len) ,
  //      start->y + scale * (sin(alpha) * len + cos(alpha) * len)};

  // c = {b.x - scale * (cos(alpha) * len - sin(alpha) * len) ,
  //      b.y - scale * (sin(alpha) * len + cos(alpha) * len)};
  
  
  a = { 
        start->x + scale * len * cos(alpha), 
        start->y + scale * len * sin(alpha)
      };
  
  
  b = { 
        start->x + scale * len * cos(-( pi - (pi2 + alpha))), 
        start->y + scale * len * sin(-( pi - (pi2 + alpha)))
      };
  
  c = {
        b.x + scale * len * cos( pi alpha) ,      
        b.y + scale * len * sin(alpha)  
      };


  // d = {      b.x + scale * (len * sin(fi) * sin(alpha + fi)),         b.y + scale * len * cos(alpha + fi) * sin(fi)};

  line(start, &a);
  line(start, &b);
  line(   &b, &c);
  line(   &a, &c);
  
  // line(   &c, &d);
  // line(   &b, &d);

  // PythagorasTree(&d, depth - 1, len, fi, alpha);
};

static void line(Vector2D * start, Vector2D * end)
{
  glColor3d(0.5f, 0.3f, 0.6f);
  glBegin(GL_LINES);
    glVertex2d(start->x, start->y);
    glVertex2d(  end->x,   end->y);
  glEnd();
};