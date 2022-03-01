#pragma once

#include <glm/matrix.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
public:
    glm::vec3 position;
    glm::mat4 viewMatrix;

    glm::mat4 getViewMatrix();

    glm::vec3 up; //direction of the up  of a camera
    glm::vec3 lookingAt;

    Camera(glm::vec3 position, glm::vec3 lookingAt, glm::vec3 up);

    void setViewMatrix();


    void move(glm::vec3 anotherLocation);

};



