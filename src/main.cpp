#include "main.hpp"
using namespace std;

const GLint WIDTH = 800, HEIGHT = 600;

// Function to handle keyboard events
void handleKeyboard(GLFWwindow* window, int key, int code, int action, int mode);

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        printf("GLFW initialization failed!");
        glfwTerminate();
        return 1;
    }
    
    // Set OpenGL version and profile to use
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    // Create a GLFW window
    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Pythagorean Theorem", nullptr, nullptr);
    if (!mainWindow)
    {
        printf("GLFW window creation failed!");
        glfwTerminate();
        return 1;
    }
    
    // Get the buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
    
    // Set the context for GLEW 
    glfwMakeContextCurrent(mainWindow);
    
    // Handle keyboard input
    glfwSetKeyCallback(mainWindow, handleKeyboard);
    
    // Loop until window is closed
    while (!glfwWindowShouldClose(mainWindow))
    {
        // Get and handle events
        glfwPollEvents();
        
        // Clear window
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Draw your shapes or perform calculations here
        
        // Swap buffers
        glfwSwapBuffers(mainWindow);
    }
    
    return 0;
}

void handleKeyboard(GLFWwindow* window, int key, int code, int action, int mode)
{
    // Check if ESC key was pressed
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE); // Close the window
    }
}