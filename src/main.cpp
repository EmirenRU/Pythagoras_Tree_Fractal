#include "main.hpp"

typedef struct{
    double X,Y;
}Vector2D;

static void DrawRectangle(Vector2D * center, Vector2D *  up, const unsigned long depth);
static void PythagorasTree(Vector2D * center, Vector2D *  up, const unsigned long depth);



int main()
{
   
    GLFWwindow* window;
 
    if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW" << std::endl;
    return -1;
    }

  window = glfwCreateWindow(1280, 800, "Pythagoras Tree", NULL, NULL);

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

		Vector2D center = {width*0.5,height*0.8};
		Vector2D up = {0.0,-50.0};

        PythagorasTree(&center, &up, 5);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}

static void PythagorasTree(Vector2D * center, Vector2D *  up, const unsigned long depth)
{	
	
	if(depth==0||center==0||up==0) return;
	
	DrawRectangle(center,up,depth);
	


};

static void DrawRectangle(Vector2D * center, Vector2D *  up, const unsigned long depth)
{
	Vector2D normaln = {-up->Y,up->X};
	
	glColor3f(((1.0f / 10.0f) * (double)depth),0.3f+((0.7f / 10.0f) * (double)depth),0.0f);
	
	glBegin(GL_QUADS);
		glVertex2d(center->X-up->X-normaln.X,center->Y-up->Y-normaln.Y);
		glVertex2d(center->X-up->X+normaln.X,center->Y-up->Y+normaln.Y);
		glVertex2d(center->X+up->X+normaln.X,center->Y+up->Y+normaln.Y);
		glVertex2d(center->X+up->X-normaln.X,center->Y+up->Y-normaln.Y);
	glEnd();
};