#include "Particle.h"

namespace pqsr2 {
    Particle::Particle(){
        // [-1, 1] cartesian space
        m_x = (2.0*rand()/RAND_MAX) - 1.0;
        m_y = (2.0*rand()/RAND_MAX) - 1.0;
    }

    Particle::~Particle(){}
}