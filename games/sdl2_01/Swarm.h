#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace pqsr2 {
    class Swarm
    {
        public:
            const static int NPARTICLES = 50000;
        private:
            Particle * m_pParticles; 
        public:
            Swarm();
            ~Swarm();
            const Particle * getParticle(); //return a constant pointer
    };

}

#endif
