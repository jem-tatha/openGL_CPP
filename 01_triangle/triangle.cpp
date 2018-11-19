#include <iostream>
//#include <GL/gl.h>
//#include <GL/glext.h>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>

using namespace std;

void display()
{
	static const float red[] = {1.0f, 0.0f, 0.0f, 0.0f};
	glClearBufferfv(GL_COLOR, 0, red);

}

int main()
{
    GLFWwindow* window;

    glfwInit();

    window = glfwCreateWindow(400, 400, "Hello, Triangle", NULL, NULL);

    glfwMakeContextCurrent(window);

	gl3wInit();

    while (!glfwWindowShouldClose(window))
    {
        display();
		glfwSwapBuffers(window);
        glfwPollEvents();
    }

	glfwDestroyWindow(window);

    glfwTerminate();

    exit(EXIT_SUCCESS);	
}
