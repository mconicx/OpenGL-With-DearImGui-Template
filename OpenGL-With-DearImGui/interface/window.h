#include "../core/singleton_template.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define WINDOW MAKE_INSTANCE(CSWindow)

// Custom defined program exit flags
enum class WindowExitReason {

	ClosedByUser,
	WindowInitFail,
	GLFWInitFail,
	GLEWInitFail
};

class CSWindow : public Singleton<CSWindow> {

private:
	// Initial window size
	// Set BOTH to -1 to go fullscreen
	const int iStartWidth = { 800 };
	const int iStartHeight = { 600 };

	// Window (program) title
	const char* szTitle = { "OpenGL-With-DearImGui" };

	GLFWwindow* pGLWindowHandle{ nullptr };
	int iFrameRate{ 0 };

	void OnStart();
	void OnEnd();
	void OnResize(int iWidth, int iHeight);
	void OnScroll(double dXOffset, double dYOffset);
	void OnMouseMove(long iPosX, long iPosY);
	void OnMouseButton(int iBtn, int iAction, int iMods);
	void OnKey(int iKey, int iAction);
	void OnUpdate(float fTime);
	void OnRender();
public:

	WindowExitReason Begin();
};
