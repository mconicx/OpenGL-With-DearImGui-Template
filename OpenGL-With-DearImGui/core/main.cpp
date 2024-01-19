#include "../interface/window.h"

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {

	// Console window
	//::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);

	WindowExitReason windowResult = WINDOW.Begin();
	switch (windowResult) {

	default:

		cout << "The window closed unexpectedly for an unknown reason...\n";
		return 1;
	case WindowExitReason::WindowInitFail:

		cout << "Could not initialize window handle...\n";
		return 1;
	case WindowExitReason::GLFWInitFail:

		cout << "Could not initialize GLFW...\n";
		return 1;
	case WindowExitReason::GLEWInitFail:

		cout << "Could not initialize GLEW...\n";
		return 1;
	case WindowExitReason::ClosedByUser:

		cout << "Done.\n";
		break;
	}

	return 0;
}
