#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma warning(disable: 4711 4710 4100)

#include "./common.c"

const unsigned int WIN_W = 300; // window size in pixels, (Width, Height)
const unsigned int WIN_H = 300;
const unsigned int WIN_X = 100; // window position in pixels, (X, Y)
const unsigned int WIN_Y = 100;

const char* vertFileName = "22-colored-tri.vert";
const char* fragFileName = "22-colored-tri.frag";

GLuint vert = 0;
GLuint frag = 0;
GLuint prog = 0;

void initFunc(void)
{
	const char* verSource = loadFile(vertFileName);
	const char* fragSource = loadFile(fragFileName);

	vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert, 1, &verSource, NULL);
	glCompileShader(vert);

	frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag, 1, &fragSource, NULL);
	glCompileShader(frag);

	prog = glCreateProgram();
	glAttachShader(prog, vert);
	glAttachShader(prog, frag);
	glLinkProgram(prog); // link to get .EXE

	glUseProgram(prog);

	free((void*)verSource);
	free((void*)fragSource);
}

GLfloat vertPosFirst[] = {
	-0.5F, -0.5F, 0.0F, 1.0F,
	+0.0F, -0.5F, 0.0F, 1.0F,
	-0.5F, +0.0F, 0.0F, 1.0F,
};

GLfloat vertPosSecond[] = {
	0.0F, 0.0F, 0.0F, 1.0F,
	0.5F, 0.0F, 0.0F, 1.0F,
	0.0F, 0.5F, 0.0F, 1.0F,
};

GLfloat vertColor[] = {
	1.0F, 0.0F, 0.0F, 1.0F, // red
	0.0F, 1.0F, 0.0F, 1.0F, // green
	0.0F, 0.0F, 1.0F, 1.0F, // blue
};

void drawFunc(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	GLuint locPos = glGetAttribLocation(prog, "aPos");
	glEnableVertexAttribArray(locPos);
	glVertexAttribPointer(locPos, 4, GL_FLOAT, GL_FALSE, 0, vertPosFirst);

	GLuint locColor = glGetAttribLocation(prog, "aColor");
	glEnableVertexAttribArray(locColor);
	glVertexAttribPointer(locColor, 4, GL_FLOAT, GL_FALSE, 0, vertColor);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glVertexAttribPointer(locPos, 4, GL_FLOAT, GL_FALSE, 0, vertPosSecond);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glFinish();
}

void refreshFunc(GLFWwindow* window) {
	drawFunc();

	glfwSwapBuffers(window);
}
void keyFunc(GLFWwindow* window, int key, int scancode, int action, int mods) {
	switch (key) {
	case GLFW_KEY_ESCAPE:
		if (action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
		break;
	}
}

int main(int argc, char* argv[])
{
	const char* basename = getBaseName(argv[0]);
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, basename, NULL, NULL);
	glfwSetWindowPos(window, WIN_X, WIN_Y);
	glfwMakeContextCurrent(window);

	glewInit();

	glfwSetWindowRefreshCallback(window, refreshFunc);
	glfwSetKeyCallback(window, keyFunc);

	glClearColor(0.3F, 0.3F, 0.3F, 1.0F);

	initFunc();

	while (! glfwWindowShouldClose(window))
	{
		drawFunc();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
