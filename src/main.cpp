#include "main.hpp"

typedef struct{
    double x,y;
}Vector2D;

static void DrawRectangle(Vector2D * a, Vector2D * b, const unsigned long depth);

void PythagorasTree(Vector2D *a, Vector2D *b, int depth){
    if(depth==0||a==0||b==0) return;
    DrawRectangle(a,b, depth);

    Vector2D
		newcenter,
		newup,
		normal;

	unsigned char counter = 0;
	
	normal=
			(Vector2D){
				-b->y,
				b->x
			};
			
	for(counter=0;counter<2;counter++)
	{
		newup=
			(Vector2D){
				(b->x + normal.x) * 0.5,
				(b->y + normal.y) * 0.5
			};
			
		newcenter=
			(Vector2D){
				a->x + b->x * 2.0 + normal.x,
				a->y + b->y * 2.0 + normal.y
			};
			
		PythagorasTree(&newcenter,&newup,depth-1);
			
		normal=
			(Vector2D){
				b->y,
				-b->x
			};
	};
}


static void DrawRectangle(Vector2D * a, Vector2D *  b, const unsigned long depth)
{
	Vector2D normaln = {-b->y,b->x};

    cout << " A = " << a->x << " " << a->y << " B = " << b->x << " " << b->y << endl; 
	
	glColor3f(((1.0f / 10.0f) * (double)depth),0.3f+((0.7f / 10.0f) * (double)depth),0.0f);
	
	glBegin(GL_QUADS);
            glVertex2d(a->x-a->x-normaln.x,
                        a->y-b->y-normaln.y);
            glVertex2d(a->x-b->x+normaln.x, a->y-b->y+normaln.y);
            glVertex2d(a->x+b->x+normaln.x,a->y+b->y+normaln.y);
            glVertex2d(a->x+b->x-normaln.x,a->y+b->y-normaln.y);
            // glVertex2d(a->x - b->, a->y);
            // glVertex2d(b->x, b->y);

            // glVertex2d(c.x, c.y);
            // glVertex2d(d.x, d.y);
        glEnd();
};

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