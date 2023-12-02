#include "main.hpp"

typedef struct{
    double x,y;
}Vector2D;

typedef std::pair<double, double> v2d;

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

      Vector2D start = {width*0.45f,height*0.7f};

      // PythagorasTree(&start, 15, width * 0.2,  pi3, pi + pi6 - .52f);
      // PythagorasTree(&start, 15, width * 0.2,  pi4, pi + pi6 - .52f);
      PythagorasTree(&start, 15, width * 0.2,  pi6, pi + pi6 - .52f);

      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}

static void PythagorasTree(Vector2D * start, const unsigned long depth, 
                            const unsigned long len, const double alpha, const double fi)
{	
	if(depth==0||start==0||len==0) return;
	
  Vector2D a,b,c,d;

  float scale = 0.65f;
  
  a = { 
        start->x - scale * len * sin(fi), 
        start->y + scale * len * cos(fi)
      };
  
  
  b = { 
        start->x + scale * len * cos(fi), 
        start->y + scale * len * sin(fi)
      };
  
  c = {
        a.x + scale * len * cos(fi), 
        a.y + scale * len * sin(fi)
    };


  d = { 
        c.x - scale * len * sin(alpha) * sin(alpha + fi),
        c.y + scale * len * sin(alpha) * cos(alpha + fi)
      };

  line(start, &a);
  line(start, &b);
  line(   &b, &c);
  line(   &a, &c);
  
  // line(   &a, &d);
  // line(start, &d);

  PythagorasTree(&a, depth - 1, len * cos(alpha), alpha, fi + alpha);
  PythagorasTree(&d, depth - 1, len * sin(alpha), alpha, fi + alpha - pi2);

};

static void line(Vector2D * start, Vector2D * end)
{
  glColor3d(0.5f, 0.3f, 0.6f);
#ifdef ORIGINAL
 glBegin(GL_LINES);
    glVertex2d(start->x, start->y);
    glVertex2d(  end->x,   end->y);
  glEnd();
#endif // ORIGINAL

#ifdef ANTIALIASING
  glBegin(GL_POINTS);
    float dx = end->x-start->x;
    float dy = end->y-start->y;

    int sx = (dx>=0) ? 1 : (-1);
    int sy = (dy>=0) ? 1 : (-1);

    float x = start->x;
    float y = start->y;

    int isSwaped = 0;

    if(abs(dy) > abs(dx))
    {
        float tdx = dx;
        dx =dy;
        dy = tdx;

        isSwaped = 1;
    }

    float p = 2*(abs(dy)) - abs(dx);

    glVertex2i(x,y);

    for(int i = 0; i<= abs(dx);i++)
    {
        if(p < 0)
        {
            if(isSwaped == 0){
                x = x + sx;
                glVertex2i(x,y);
            }
            else{
                y = y+sy;
                glVertex2i(x,y);
            }
            p = p + 2*abs(dy);
        }
        else
        {
            x = x+sx;
            y = y+sy;
            glVertex2i(x,y);
            p = p + 2*abs(dy) - 2*abs(dx);
        }
    }



  glEnd();
#endif
};