#pragma once
#include "Display.h"

class DisplayManager
{
private:
	Display mDisplay;

public:
	DisplayManager() {}

	void createDisplay();
	void updateDisplay();
	void closeDisplay();

	bool isRequestClosed();

    bool isKeyPressed(unsigned int keyCode);
};