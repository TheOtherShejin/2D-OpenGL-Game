#pragma once

#include "../Renderer/Shader.h"
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

class ResourceManager {
public:
	static std::unordered_map<std::string, Shader> shaders;

	static Shader AddShader(const char* vertexShaderPath, const char* fragmentShaderPath, std::string name);
	static Shader GetShader(std::string name);
	static void RemoveShader(std::string name);

	static void Clear();
private:
	ResourceManager() {}

	static Shader LoadShaderFromFile(const char* vertexShaderPath, const char* fragmentShaderPath);
	static std::string ReadFile(const char* filePath);
};