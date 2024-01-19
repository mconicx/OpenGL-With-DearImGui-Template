#include "window.h"
#include "ui.h"
#include "../rendering/scenemanager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define VSYNC // Comment to disable VSync
#define TICKRATE 60.f // Use float

// Window initialization
WindowExitReason CSWindow::Begin() {

	// Initialize GLFW
	if (!glfwInit())
		return WindowExitReason::GLFWInitFail;

	// Check is fullscreen
	if (iStartWidth < 0 || iStartHeight < 0) {

		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
		pGLWindowHandle = glfwCreateWindow(vidmode->width, vidmode->height, szTitle, monitor, nullptr);
	}
	else
		pGLWindowHandle = glfwCreateWindow(iStartWidth, iStartHeight, szTitle, nullptr, nullptr);

	// Error handling for GLFW
	if (pGLWindowHandle == NULL) {

		glfwTerminate();
		return WindowExitReason::WindowInitFail;
	}

	glfwMakeContextCurrent(pGLWindowHandle);
	glfwSetWindowUserPointer(pGLWindowHandle, this);

	// Some sample window events
	auto _on_resize = [](GLFWwindow* pGLWindow, int iWidth, int iHeight) {

		static_cast<CSWindow*>(glfwGetWindowUserPointer(pGLWindow))->OnResize(iWidth, iHeight);
	};
	glfwSetFramebufferSizeCallback(pGLWindowHandle, _on_resize);

	auto _on_scroll = [](GLFWwindow* pGLWindow, double dXOffset, double dYOffset) {

		static_cast<CSWindow*>(glfwGetWindowUserPointer(pGLWindow))->OnScroll(dXOffset, dYOffset);
	};
	glfwSetScrollCallback(pGLWindowHandle, _on_scroll);

	auto _on_mouse_move = [](GLFWwindow* pGLWindow, double dPosX, double dPosY) {

		static_cast<CSWindow*>(glfwGetWindowUserPointer(pGLWindow))->OnMouseMove(static_cast<long>(dPosX), static_cast<long>(dPosY));
	};
	glfwSetCursorPosCallback(pGLWindowHandle, _on_mouse_move);

	auto _on_mouse_click = [](GLFWwindow* pGLWindow, int iBtn, int iAction, int iMods) {

		static_cast<CSWindow*>(glfwGetWindowUserPointer(pGLWindow))->OnMouseButton(iBtn, iAction, iMods);
	};
	glfwSetMouseButtonCallback(pGLWindowHandle, _on_mouse_click);
	auto _on_key_press = [](GLFWwindow* w, int k, int sc, int a, int mods) {

		static_cast<CSWindow*>(glfwGetWindowUserPointer(w))->OnKey(k, a);
	};
	glfwSetKeyCallback(pGLWindowHandle, _on_key_press);

#ifdef VSYNC
	glfwSwapInterval(1);
#endif

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {

		glfwTerminate();
		return WindowExitReason::GLEWInitFail;
	}

	OnStart();

	double dLastTime = glfwGetTime(), dTimer = dLastTime;
	double dDeltaTime = 0, dNowTime = 0;
	int iFrames = 0, iUpdates = 0;

	while (!glfwWindowShouldClose(pGLWindowHandle)) {

		dNowTime = glfwGetTime();
		dDeltaTime += (dNowTime - dLastTime) / (1.f / TICKRATE);
		dLastTime = dNowTime;

		while (dDeltaTime >= 1.0) {

			OnUpdate((float)dNowTime);
			iUpdates++;
			dDeltaTime--;
		}

		OnRender();
		iFrames++;

		if (glfwGetTime() - dTimer > 1.0) {

			dTimer++;
			iFrameRate = iFrames;
			iUpdates = 0, iFrames = 0;
		}
	}

	OnEnd();

	glfwDestroyWindow(pGLWindowHandle);
	glfwTerminate();

	return WindowExitReason::ClosedByUser;
}

void CSWindow::OnStart() {

	// Initialize user-made ImGui class wrapper
	UI.Create(pGLWindowHandle);

	glClearColor(0.25f, 0.25f, 0.25f, 1.f);

	// Initialize user-made rendering class
	SCENE.Create();

	OnResize(iStartWidth, iStartHeight);
}

void CSWindow::OnEnd() {

	SCENE.Destroy();
	UI.Destroy();
}

void CSWindow::OnResize(int iWidth, int iHeight) {

	glViewport(0, 0, iWidth, iHeight);
	SCENE.Resize(iWidth, iHeight); // Useful to have
}

void CSWindow::OnScroll(double dXOffset, double dYOffset) {

	// ...
}

void CSWindow::OnMouseMove(long iPosX, long iPosY) {

	// ...
}

void CSWindow::OnMouseButton(int iBtn, int iAction, int iMods) {

	// ...
}

void CSWindow::OnKey(int iKey, int iAction) {

	// On ESC key, exit app
	if (iKey == GLFW_KEY_ESCAPE && iAction == GLFW_PRESS)
		glfwSetWindowShouldClose(pGLWindowHandle, 1);
}

void CSWindow::OnUpdate(float fTime) {

	SCENE.Update();
}

void CSWindow::OnRender() {

	UI.Prepare(); // Call this before everything else
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	SCENE.Render();
	UI.Render();

	glfwSwapBuffers(pGLWindowHandle);
	glfwPollEvents();
}
