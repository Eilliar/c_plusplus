#include "Swarm.h"

namespace pqsr2 {
    Swarm::Swarm(int created_at): lastTime(created_at)
    {
        m_pParticles = new Particle[NPARTICLES];
    }
    
    Swarm::~Swarm(){
        delete [] m_pParticles;
    }

    const Particle *Swarm::getParticle(){
        return m_pParticles;
    }

    void Swarm::Update(int tick){
        int interval = tick - lastTime;

        for(int i = 0; i < pqsr2::Swarm::NPARTICLES; i++){

            // Transform from [-1, 1] particle space to screen resolution space
            m_pParticles[i].Update(interval);
        }

        lastTime = tick;
    }
}
