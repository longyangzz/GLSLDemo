#include "Display.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

void Display::create(ContextAttri attr)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, attr.major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, attr.minor);
	if (attr.bProfileCore) {
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	mWindow = glfwCreateWindow(mDisplayMode.width, mDisplayMode.height, title, nullptr, nullptr);
	if (!mWindow) {
		std::cout << "create window failed." << std::endl;
		return;
	}
	glfwMakeContextCurrent(mWindow);

	if (!gladLoadGL()) {
		std::cout << "glad init Error." << std::endl;
		destroy();
		return;
	}

	glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCallback);
}

void Display::update()
{
	glfwPollEvents();
	glfwSwapBuffers(mWindow);
	processEvent();
}

void Display::destroy()
{
	glfwDestroyWindow(mWindow);
	glfwTerminate();
	mWindow = nullptr;
}

bool Display::isRequestClosed()
{
	return glfwWindowShouldClose(mWindow);
}

void Display::setDisplayMode(DisplayMode mode)
{
	mDisplayMode = mode;
}

void Display::setTitle(const char* _title)
{
	title = _title;
}

void Display::frameBufferSizeCallback(GLFWwindow* _window, int w, int h)
{
	glViewport(0, 0, w, h);
}

bool Display::isKeyPressed(unsigned int keyCode)
{
    return glfwGetKey(mWindow, keyCode) == GLFW_PRESS;
}

void Display::processEvent()
{
	if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		glfwSetWindowShouldClose(mWindow, true);
	}
}
