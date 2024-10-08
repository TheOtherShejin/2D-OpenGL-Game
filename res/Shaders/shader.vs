#version 330 core

layout (location = 0) in vec2 aPos;

uniform mat4 proj;
uniform mat4 model;

void main() {
	gl_Position = proj * model * vec4(aPos, 0.0f, 1.0f);
}