#pragma once

#include "..\core\singleton_template.h"

#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>

#define UI MAKE_INSTANCE(CSInterface)

class CSInterface : public Singleton<CSInterface> {

private:

	GLFWwindow* pGLWindowHandle{ nullptr };
public:

	void Create(GLFWwindow* pGLWindow);
	void Destroy();
	void Prepare();
	void Render();
};
