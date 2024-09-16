#include "InputManager.h"

Window* InputManager::window = nullptr;

void InputManager::PollWindow(Window* window) {
	InputManager::window = window;
}
void InputManager::PollEvents() {
	glfwPollEvents();
}

bool InputManager::IsKeyPressed(Key key) {
	return glfwGetKey(window->ID, key);
}
bool InputManager::IsMouseButtonPressed(MouseButton mouseButton) {
	return glfwGetMouseButton(window->ID, mouseButton);
}

void InputManager::SetCursorPos(Vector2 position) {
	glfwSetCursorPos(window->ID, position.x, position.y);
}
void InputManager::SetCursorPos(float x, float y) {
	glfwSetCursorPos(window->ID, x, y);
}
Vector2 InputManager::GetCursorPos() {
	double x, y;
	glfwGetCursorPos(window->ID, &x, &y);
	return Vector2(x, y);
}