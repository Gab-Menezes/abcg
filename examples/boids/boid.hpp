#ifndef BOID_HPP_
#define BOID_HPP_

#include <vector>
#include "camera.hpp"
#include "abcgOpenGL.hpp"

class Boid {
public:
    //Note: Force = Acceleration, since Mass = 1
    /*
        TODO:
            * Alterar os boids para passaros
                Dica: mexer no setup e shaders
            * Garantir que a parte de frente do passaro esta alinhado com a velocidade
                Dica: mexer no calcModelMatrix e adicionar alguma forma de rotacao
            * Adicionar um slide float para etapa da simulacao (Alignment, Cohesion, Separation), onde o mesmo tem valor default 1 e serve como peso
                Dica: criar umas variaveis estaticas
                Dica: mexer no showUI
                Dica: mexer no simulate (na parte de acumulo da aceleracao)
    */

    Boid(const glm::vec3& pos, const glm::vec3& vel);
    ~Boid();

    //Check if the boid is outside the world and repostion it
    void checkEdge(float worldSize);

    //Simulate the flocking behaviour
    void simulate(const std::vector<Boid>& boids);

    //Update the position and velocity
    void update(float dt);

    //Render
    void show(const Camera& camera);

    //Generate the OpenGL Buffers
    static void setup();

    //Render the ImGui
    static void showUI();
    static float maxVel() { return s_MaxVel_; }
private:
    //Calculate the steering force based on disired target
    glm::vec3 steer(const glm::vec3& desired);

    //Calculate he Model Matrix
    void calcModelMatrix();

    //Boid position in the world
    glm::vec3 m_Pos_;
    //Boid velocity
    glm::vec3 m_Vel_;
    //Boid steering acceleration
    glm::vec3 m_Acc_;
    //Model matrix
    glm::mat4 m_Model_;

    //Maximum velocity all boids in the simulation can go
    static float s_MaxVel_;
    //Perception radius of the boid
    static float s_Perception_;
    //Maximum steering force
    static float s_MaxForce_;

    static unsigned int s_EBOSize_;
    static GLuint s_Shader_;
    static GLuint s_VAO_;
    static GLuint s_VBO_;
    static GLuint s_EBO_;
    static GLint s_ModelLocation_;
    static GLint s_ViewLocation_;
    static GLint s_ProjLocation_;
};

#endif