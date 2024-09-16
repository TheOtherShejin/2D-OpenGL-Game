#include "ResourceManager.h"

std::unordered_map<std::string, Shader> ResourceManager::shaders;

Shader ResourceManager::AddShader(const char* vertexShaderPath, const char* fragmentShaderPath, std::string name) {
	shaders[name] = LoadShaderFromFile(vertexShaderPath, fragmentShaderPath);
	return shaders[name];
}

Shader ResourceManager::GetShader(std::string name) {
	return shaders[name];
}

void ResourceManager::RemoveShader(std::string name) {
	shaders[name].Delete();
	shaders.erase(name);
}

Shader ResourceManager::LoadShaderFromFile(const char* vertexShaderPath, const char* fragmentShaderPath) {
	std::string vertexShaderCode, fragmentShaderCode;
	vertexShaderCode = ReadFile(vertexShaderPath);
	fragmentShaderCode = ReadFile(fragmentShaderPath);
	Shader shader;
	shader.Compile(vertexShaderCode.c_str(), fragmentShaderCode.c_str());
	return shader;
}

std::string ResourceManager::ReadFile(const char* filePath) {
	std::ifstream file;
	std::string content;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		std::stringstream fileStream;
		file.open(filePath);
		fileStream << file.rdbuf();
		file.close();
		content = fileStream.str();
	}
	catch (std::ifstream::failure e) {
		Logger::Log("File Reader", Logger::CRITICAL, "Failed to open file at path: " + (std::string)filePath);
	}

	return content;
}

void ResourceManager::Clear() {
	for (auto& shader : shaders) {
		shader.second.Delete();
	}
}