#include "Vector.h"

glm::vec2 ConvertVecToGLMVec(Vector2 vector) {
	return glm::vec2(vector.x, vector.y);
}

glm::vec3 ConvertVecToGLMVec(Vector3 vector) {
	return glm::vec3(vector.x, vector.y, vector.z);
}

glm::vec4 ConvertVecToGLMVec(Vector4 vector) {
	return glm::vec4(vector.x, vector.y, vector.z, vector.w);
}