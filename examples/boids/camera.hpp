#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "abcgOpenGL.hpp"
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

class Camera {
public:
    /*
        TODO:
            * Adicionar mais alguns sliders no render da UI, como FOV, zNear, zFar
                Dica: Adicionar algumas variaveis e mexer no showUI
                Dica: Lembrar de chamar computeViewMatrix e computeProjectionMatrix
    */
    void onEvent(const SDL_Event& event, float dt);

    void computeViewMatrix();
    void computeProjectionMatrix(glm::vec2 const &size);

    const glm::mat4& getViewMatrix() const { return m_ViewMatrix_; }
    const glm::mat4& getProjMatrix() const { return m_ProjMatrix_; }
    
    void showUI();
private:
    bool m_FirstEvent_ = true;
    float m_LastX_ = 0;
    float m_LastY_ = 0;
    float m_Yaw_ = -90.0f;
    float m_Pitch_ = 0.f;

    glm::vec3 m_Eye_ = glm::vec3(55.f, 154.f, 187.f);    // Camera position
    glm::vec3 m_Front_ = glm::vec3(-0.221404f, -0.61993f, -0.752773f);  // Look-at point
    glm::vec3 m_Up_ = glm::vec3(0.0f, 1.0f, 0.0f);  // "up" direction

    // Matrix to change from world space to camera space
    glm::mat4 m_ViewMatrix_;

    // Matrix to change from camera space to clip space
    glm::mat4 m_ProjMatrix_;
};

#endif
