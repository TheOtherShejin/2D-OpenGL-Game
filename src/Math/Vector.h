#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include <glm/glm.hpp>

glm::vec2 ConvertVecToGLMVec(Vector2 vector);
glm::vec3 ConvertVecToGLMVec(Vector3 vector);
glm::vec4 ConvertVecToGLMVec(Vector4 vector);