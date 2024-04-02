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
	glClear(GL_COLOR_BUFFER_BIT);//GL_COLOR_BUFFER_BIT은 색상 버퍼를 지워서 이전의 모든 픽셀 값을 삭제하고, 현재의 클리어 색깔로 설정합니다.
	glFinish();
	// GLFW action
	glfwSwapBuffers(window);//현재 Frame에 그려진 Buffer와 현재 Frame에 그려진 buffer를 swap(Double buffer)
}//

int main(int argc, char* argv[]) {
	// get your program name
#if defined(_WIN32) || defined(_WIN64)
	char* win_name = (strrchr(argv[0], '\\') == NULL) ? argv[0] : (strrchr(argv[0], '\\') + 1);//argv[0]에 실행 파일경로 들어옴.
#else // Unix, Linux, MacOS
	char* win_name = (strrchr(argv[0], '/') == NULL) ? argv[0] : (strrchr(argv[0], '/') + 1);
#endif
	// start GLFW & GLEW
	glfwInit();// glfw를 초기화
	GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, win_name, NULL, NULL);//설정된 glfw 기반으로, Window의 크기를 설정 및 생성한 Window 반환하여 준다.
	glfwSetWindowPos(window, WIN_X, WIN_Y);
	glfwMakeContextCurrent(window);//Double Buffer로 사용할 Window를 등록하는 함수이며, 등록되면 Thread로 설정되어 사용된다.
	glewInit();
	// prepare
	glfwSetWindowRefreshCallback(window, refreshFunc);//도우 내용을 다시 그려야 할 때 호출되는 콜백 함수를 설정하는 데 사용됩니다.
	glClearColor(0.5F, 0.8F, 0.8F, 1.0F);
	// main loop
	while (!glfwWindowShouldClose(window))//현재 window가 종료되었는지 확인하는 함수
	{
		// draw
		glClear(GL_COLOR_BUFFER_BIT);// OpenGL에서 현재 버퍼를 지정된 값으로 클리어하는 함수 
		glFinish();// 모든 OpenGL 명령이 완료될 때까지 대기
		// GLFW actions
		glfwSwapBuffers(window);
		glfwPollEvents();//현재 Frame의 입력 및 출력 이벤트를 모두 처리
	}
	// done
	glfwTerminate();//사용된 메모리를 삭제하는 함수로 프로그램 종료되기 직전 반드시 호출해야함.
	return 0;
}
