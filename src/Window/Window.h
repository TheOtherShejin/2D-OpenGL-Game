#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Logger/Logger.h"
#include "../Math/Vector.h"
#include <string>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Window {
private:
	float prevTime = 0.0f;
	float deltaTime = 0.0f;
public:
	GLFWwindow* ID = nullptr;
	int width, height;

	static void Init();

	Window(int width, int height, std::string title);
	void Update();
	void SwapBuffers();
	float GetDeltaTime();
	float GetFPS();
	bool IsOpen() const;
	double GetTime() const;

	void SetWindowShouldClose(bool value);
	void SetWindowOpacity(float value);
	void SetContextCurrent();

	void SetWindowPosition(Vector2 position);
	void SetWindowPosition(int x, int y);
	Vector2 GetWindowPosition() const;

	void SetWindowSize(Vector2 size);
	void SetWindowSize(int width, int height);
	Vector2 GetWindowSize() const;

	void SetWindowTitle(std::string title);
	std::string GetWindowTitle() const;

	~Window();
};