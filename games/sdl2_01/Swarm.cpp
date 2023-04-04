#include "Swarm.h"

namespace pqsr2 {
    Swarm::Swarm()
    {
        m_pParticles = new Particle[NPARTICLES];
    }
    
    Swarm::~Swarm(){
        delete [] m_pParticles;
    }

    const Particle *Swarm::getParticle(){
        return m_pParticles;
    }
}
