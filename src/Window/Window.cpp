#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void Window::Init() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif 
}

Window::Window(int width, int height, std::string title) : width(width), height(height) {
	ID = glfwCreateWindow(width, height, "2D OpenGL Game", NULL, NULL);
	if (ID == nullptr) {
		Logger::Log("Window", Logger::LEVEL::CRITICAL, "Failed to create Window.");
		glfwTerminate();
	}
	glfwMakeContextCurrent(ID);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		Logger::Log("Window", Logger::LEVEL::CRITICAL, "Failed to load GLAD.");
	}

	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(ID, framebuffer_size_callback);
}

void Window::Update() {
	float crntTime = glfwGetTime();
	deltaTime = crntTime - prevTime;
	prevTime = crntTime;
}
float Window::GetDeltaTime() {
	return deltaTime;
}
float Window::GetFPS() {
	return 1.0f / deltaTime;
}
void Window::SwapBuffers() {
	glfwSwapBuffers(ID);
}
bool Window::IsOpen() const {
	return glfwWindowShouldClose(ID);
}
double Window::GetTime() const {
	return glfwGetTime();
}

void Window::SetWindowShouldClose(bool value) {
	glfwSetWindowShouldClose(ID, value);
}
void Window::SetWindowOpacity(float value) {
	glfwSetWindowOpacity(ID, value);
}
void Window::SetContextCurrent() {
	glfwMakeContextCurrent(ID);
}

void Window::SetWindowPosition(Vector2 position) {
	glfwSetWindowPos(ID, position.x, position.y);
}
void Window::SetWindowPosition(int x, int y) {
	glfwSetWindowPos(ID, x, y);
}
Vector2 Window::GetWindowPosition() const {
	int x, y;
	glfwGetWindowPos(ID, &x, &y);
	return Vector2(x, y);
}

void Window::SetWindowSize(Vector2 size) {
	glfwSetWindowSize(ID, size.x, size.y);
}
void Window::SetWindowSize(int width, int height) {
	this->width = width;
	this->height = height;
	glfwSetWindowSize(ID, width, height);
}
Vector2 Window::GetWindowSize() const {
	int x, y;
	glfwGetWindowSize(ID, &x, &y);
	return Vector2(x, y);
}

void Window::SetWindowTitle(std::string title) {
	glfwSetWindowTitle(ID, title.c_str());
}
std::string Window::GetWindowTitle() const {
	return glfwGetWindowTitle(ID);
}

Window::~Window() {
	glfwTerminate();
}