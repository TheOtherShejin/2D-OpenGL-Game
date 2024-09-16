#include "Engine/Engine.h"

const int WIDTH = 800, HEIGHT = 600;
const std::string title = "2D OpenGL Game";

int main() {
	Window::Init();
	Window window(WIDTH, HEIGHT, title);
	InputManager::PollWindow(&window);

	Renderer renderer;
	Shader shader = ResourceManager::AddShader("res/Shaders/shader.vs", "res/Shaders/shader.fs", "default");
	renderer.UseShader(&shader);

	Camera camera;
	camera.SetViewPort(0.0f, (float)WIDTH, (float)HEIGHT, 0.0f);
	camera.SetProjectionMatrix(&shader);

	GameObject paddle1({ 50, HEIGHT/2});
	paddle1.sprite = RectSprite(paddle1.position, { 40, 0.25f * HEIGHT });
	paddle1.rigidBody.collision = AABBCollision2D(paddle1.position, paddle1.sprite.size);

	GameObject paddle2({ WIDTH-50, HEIGHT / 2 });
	paddle2.sprite = RectSprite(paddle2.position, { 40, 0.25f * HEIGHT });
	paddle2.rigidBody.collision = AABBCollision2D(paddle2.position, paddle2.sprite.size);

	GameObject ball({ WIDTH / 2, HEIGHT / 2 });
	ball.sprite = CircleSprite(ball.position, 10.0f, 16);
	ball.rigidBody.collision = AABBCollision2D(ball.position - ball.sprite.size * 0.5f, ball.sprite.size);

	Vector2 velocity(0.0f, 250.0f);
	while (!window.IsOpen()) {
		InputManager::PollEvents();

		if (InputManager::IsKeyPressed(KEY_ESCAPE)) {
			window.SetWindowShouldClose(true);
		}

		Vector2 displacement = velocity * window.GetDeltaTime();

		if (InputManager::IsKeyPressed(KEY_W)) paddle1.position -= displacement;
		else if (InputManager::IsKeyPressed(KEY_S)) paddle1.position += displacement;
		if (InputManager::IsKeyPressed(KEY_UP)) paddle2.position -= displacement;
		else if (InputManager::IsKeyPressed(KEY_DOWN)) paddle2.position += displacement;

		if (ball.rigidBody.collision.Intersects()) {

		}

		renderer.Clear(0.0f, 0.0f, 0.0f);
		paddle1.Draw(&renderer);
		paddle2.Draw(&renderer);
		ball.Draw(&renderer);
		window.SwapBuffers();
		window.Update();
	}

	return 0;
}