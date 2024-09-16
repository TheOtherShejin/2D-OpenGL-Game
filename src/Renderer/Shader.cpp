#include "Shader.h"

void Shader::Compile(const char* vertexShaderSource, const char* fragmentShaderSource) {
	unsigned int vertexShader, fragmentShader;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	CheckErrors(vertexShader, "Vertex");

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	CheckErrors(fragmentShader, "Fragment");

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	CheckErrors(ID, "Program");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::CheckErrors(GLenum object, std::string type) {
	int success;
	char infoLog[1024];

	if (type != "Program") {
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			Logger::Log("Shader", Logger::CRITICAL, "Failed to compile " + type + " Shader.");
		}
	}
	else {
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(object, 1024, NULL, infoLog);
			Logger::Log("Shader Program", Logger::CRITICAL, "Failed to link Shader Program.");
		}
	}
}

void Shader::Use() {
	glUseProgram(ID);
}

void Shader::SetInt(std::string name, int value) {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::SetFloat(std::string name, float value) {
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::SetBool(std::string name, bool value) {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::SetVec2(std::string name, float v0, float v1) {
	glUniform2f(glGetUniformLocation(ID, name.c_str()), v0, v1);
}
void Shader::SetVec2(std::string name, Vector2 value) {
	glUniform2f(glGetUniformLocation(ID, name.c_str()), value.x, value.y);
}
void Shader::SetVec3(std::string name, float v0, float v1, float v2) {
	glUniform3f(glGetUniformLocation(ID, name.c_str()), v0, v1, v2);
}
void Shader::SetVec3(std::string name, Vector3 value) {
	glUniform3f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z);
}
void Shader::SetVec4(std::string name, float v0, float v1, float v2, float v3) {
	glUniform4f(glGetUniformLocation(ID, name.c_str()), v0, v1, v2, v3);
}
void Shader::SetVec4(std::string name, Vector4 value) {
	glUniform4f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z, value.w);
}
void Shader::SetMat4(std::string name, glm::mat4 value) {
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, false, glm::value_ptr(value));
}

void Shader::Delete() {
	glDeleteProgram(ID);
}