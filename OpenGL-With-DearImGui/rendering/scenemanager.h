#pragma once

#include "../core/singleton_template.h"

#define SCENE MAKE_INSTANCE(CSSceneManager)

class CSSceneManager : public Singleton<CSSceneManager> {

public:

	void Create();
	void Resize(int iWidth, int iHeight);
	void Destroy();
	void Update();
	void Render();
};
