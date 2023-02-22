#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateGrass(const std::string& name, glm::vec3 leftBottomCorner, float heigth, glm::vec3 color);
    Mesh* CreateScore(const std::string& name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateHeart(const std::string& name, glm::vec3 leftBottomCorner, float length);
    Mesh* CreateWireframe(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
    Mesh* CreateWing(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool up = true);
    Mesh* CreateDuck(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);

}
