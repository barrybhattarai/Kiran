
#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 lookingAt, glm::vec3 up) {
    Camera::position = position;
    Camera::lookingAt = lookingAt;
    Camera::up = up;
    setViewMatrix();

}

void Camera::setViewMatrix() {


}

void Camera::move(glm::vec3 anotherLocation) {
    position = anotherLocation;
    setViewMatrix();
}

glm::mat4 Camera::getViewMatrix() {
    return viewMatrix = glm::lookAt(position, lookingAt, up);
}










