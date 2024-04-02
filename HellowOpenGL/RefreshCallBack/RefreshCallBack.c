#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma warning(disable: 4711 4710 4100)
#include <stdio.h>
#include <string.h> // for strrchr()

const unsigned int WIN_W = 300; // window size in pixels, (Width, Height)
const unsigned int WIN_H = 300;
const unsigned int WIN_X = 100; // window position in pixels, (X, Y) 
const unsigned int WIN_Y = 100;

void refreshFunc(GLFWwindow* window) {
	// refresh
	printf("refresh called\n");
	fflush(stdout);
	glClear(GL_COLOR_BUFFER_BIT);//GL_COLOR_BUFFER_BIT�� ���� ���۸� ������ ������ ��� �ȼ� ���� �����ϰ�, ������ Ŭ���� ����� �����մϴ�.
	glFinish();
	// GLFW action
	glfwSwapBuffers(window);//���� Frame�� �׷��� Buffer�� ���� Frame�� �׷��� buffer�� swap(Double buffer)
}//

int main(int argc, char* argv[]) {
	// get your program name
#if defined(_WIN32) || defined(_WIN64)
	char* win_name = (strrchr(argv[0], '\\') == NULL) ? argv[0] : (strrchr(argv[0], '\\') + 1);//argv[0]�� ���� ���ϰ�� ����.
#else // Unix, Linux, MacOS
	char* win_name = (strrchr(argv[0], '/') == NULL) ? argv[0] : (strrchr(argv[0], '/') + 1);
#endif
	// start GLFW & GLEW
	glfwInit();// glfw�� �ʱ�ȭ
	GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, win_name, NULL, NULL);//������ glfw �������, Window�� ũ�⸦ ���� �� ������ Window ��ȯ�Ͽ� �ش�.
	glfwSetWindowPos(window, WIN_X, WIN_Y);
	glfwMakeContextCurrent(window);//Double Buffer�� ����� Window�� ����ϴ� �Լ��̸�, ��ϵǸ� Thread�� �����Ǿ� ���ȴ�.
	glewInit();
	// prepare
	glfwSetWindowRefreshCallback(window, refreshFunc);//���� ������ �ٽ� �׷��� �� �� ȣ��Ǵ� �ݹ� �Լ��� �����ϴ� �� ���˴ϴ�.
	glClearColor(0.5F, 0.8F, 0.8F, 1.0F);
	// main loop
	while (!glfwWindowShouldClose(window))//���� window�� ����Ǿ����� Ȯ���ϴ� �Լ�
	{
		// draw
		glClear(GL_COLOR_BUFFER_BIT);// OpenGL���� ���� ���۸� ������ ������ Ŭ�����ϴ� �Լ� 
		glFinish();// ��� OpenGL ����� �Ϸ�� ������ ���
		// GLFW actions
		glfwSwapBuffers(window);
		glfwPollEvents();//���� Frame�� �Է� �� ��� �̺�Ʈ�� ��� ó��
	}
	// done
	glfwTerminate();//���� �޸𸮸� �����ϴ� �Լ��� ���α׷� ����Ǳ� ���� �ݵ�� ȣ���ؾ���.
	return 0;
}
