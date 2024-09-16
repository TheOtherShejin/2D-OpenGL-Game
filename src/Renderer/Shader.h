#pragma once

#include <glad/glad.h>
#include "../Logger/Logger.h"
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Math/Vector.h"
#include "Color.h"

class Shader {
public:
	unsigned int ID;

	void Compile(const char* vertexShaderSource, const char* fragmentShaderSource);
	void Use();

	void SetInt(std::string name, int value);
	void SetFloat(std::string name, float value);
	void SetBool(std::string name, bool value);
	void SetVec2(std::string name, float v0, float v1);
	void SetVec2(std::string name, Vector2 value);
	void SetVec3(std::string name, float v0, float v1, float v2);
	void SetVec3(std::string name, Vector3 value);
	void SetVec4(std::string name, float v0, float v1, float v2, float v3);
	void SetVec4(std::string name, Vector4 value);
	void SetMat4(std::string name, glm::mat4 value);

	void Delete();
private:
	void CheckErrors(GLenum object, std::string type);
};