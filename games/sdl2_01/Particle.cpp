#include "Particle.h"

namespace pqsr2 {
    Particle::Particle(): m_x(0), m_y(0) {
        m_direction = 2* M_PI * rand()/RAND_MAX;
        m_speed = (0.0001 * rand())/RAND_MAX;
    }

    Particle::~Particle(){}

    void Particle::Update(int interval){
        m_x += interval * m_speed * cos(m_direction);
        m_y += interval * m_speed * sin(m_direction);
    }
}