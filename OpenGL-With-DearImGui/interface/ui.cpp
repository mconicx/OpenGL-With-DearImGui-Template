#include "ui.h"

#include <GLFW/glfw3.h>
#include <Windows.h>
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

void CSInterface::Create(GLFWwindow* pGLWindow) {

	pGLWindowHandle = pGLWindow;

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.IniFilename = NULL;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(pGLWindow, true);
	ImGui_ImplOpenGL3_Init("#version 150"); // For OpenGL 3.2, change whenever

	// Init UI element classes, instances, etc. etc.
	// ...
}

void CSInterface::Destroy() {

	// Destroy UI element classes, instances, etc, etc.
	// ...

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void CSInterface::Prepare() {

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void CSInterface::Render() {

	ImVec2 vViewport = ImGui::GetMainViewport()->Size;

	// Draw windows, panels, etc.
	// ...
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(vViewport.x, 40));
	ImGui::Begin("##TestWindow", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

	ImGui::Text("Test ImGui text");
	ImGui::SameLine();
	if (ImGui::Button("Test Button##TestBtn")) {

		MessageBox(NULL, L"Test ImGui button!", L"Test ImGui", MB_OK | MB_ICONINFORMATION);
	}

	ImGui::End();
	// ...

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
