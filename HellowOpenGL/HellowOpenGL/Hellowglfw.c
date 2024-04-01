#include <GLFW/glfw3.h>
#pragma comment(lib, "glfw3.lib")

const unsigned int WIN_W = 300;
const unsigned int WIN_H = 300;
int main(void) {
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, "Hello GLFW", NULL, NULL);
	glfwSetWindowPos(window, WIN_W, WIN_H);
	glfwMakeContextCurrent(window);//실제 출력

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}