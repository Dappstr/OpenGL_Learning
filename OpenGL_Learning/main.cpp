#include <iostream>
#include <stdio.h>
#include <glew.h>
#include <glfw3.h>

int main()
{
	//Set window width and window height
	const GLint wWIDTH = 600, wHEIGHT = 600;

	try
	{
		glfwInit();
	}
	catch (...) {
		std::cout << "GLFW initialization failed.\n";
		glfwTerminate();
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//CORE_PROFILE = No backwards compatible
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(wWIDTH, wHEIGHT, "Title test", NULL, NULL);
	if (window == nullptr) {
		std::cout << "GLFW window creation failed.\n";
		glfwTerminate();
		return 1;
	}

	int buffWidth{}, buffHeight{};

	glfwGetFramebufferSize(window, &buffWidth, &buffHeight);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	GLuint GLEWerror = glewInit();

	if (GLEWerror != GLEW_OK) {
		std::cout << "Error initializing GLEW\n" << glewGetErrorString(GLEWerror);
		glfwDestroyWindow(window);
		glfwTerminate();
		return 1;
	}

	//(0, 0) to begin at the top left, and use the frame buffer size as the width and height to get the actual inner buffer of the app rather than the whole window (WIDTH, HEIGHT)
	glViewport(0, 0, buffWidth, buffHeight);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		//Clear window and set color
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Set the window buffer being drawn to as the displayed window buffer
		glfwSwapBuffers(window);
	}

	return 0;
}