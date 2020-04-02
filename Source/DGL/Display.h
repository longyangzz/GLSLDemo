#pragma once

class DisplayMode
{
public:
	int width;
	int height;

	DisplayMode() : width(0), height(0) {}

	DisplayMode(int w, int h) : width(w), height(h) {}
};

class ContextAttri
{
public:
	int major;
	int minor;
	bool bProfileCore;

	ContextAttri() : major(0), minor(0), bProfileCore(false) {}

	ContextAttri(int _major, int _minor) : major(_major), minor(_minor), bProfileCore(false) {}

	void withProfileCore(bool bUseProfile) { bProfileCore = bUseProfile; }
};

class Display
{
private:
	DisplayMode mDisplayMode;
	const char* title;
	struct GLFWwindow* mWindow;

public:
	Display() : title(""), mWindow(nullptr){}

	void create(ContextAttri attr);
	void update();
	void destroy();

	bool isRequestClosed();

	void setDisplayMode(DisplayMode mode);
	void setTitle(const char* _title);

	static void frameBufferSizeCallback(GLFWwindow*, int, int);

    bool isKeyPressed(unsigned int keyCode);

private:
	void processEvent();
};