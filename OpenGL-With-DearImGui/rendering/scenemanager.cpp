#include "scenemanager.h"
#include <GL/glew.h>

void CSSceneManager::Create() {

	// Scene initialization...
	// Initialize shaders, model instances, vertex objects, etc.
	// ...
}

void CSSceneManager::Resize(int iWidth, int iHeight) {

	// Window resize within the scene class
	// ...
}

void CSSceneManager::Destroy() {

	// Clean up instances, buffers, etc.
	// ...
}

void CSSceneManager::Update() {

	// Constant loop per defined tickrate
	// ...
}

void CSSceneManager::Render() {

	// Render loop per refresh rate if VSync is on, otherwise unlimited
	// ...

	// Here's a little Hello Triangle render test using fixed-pipeline rendering with no transformations
	glColor3f(1.f, 0.5f, 0.f);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
}
