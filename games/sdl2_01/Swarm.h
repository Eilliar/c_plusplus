#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace pqsr2 {
    class Swarm
    {
        public:
            const static int NPARTICLES = 1000;
        private:
            Particle * m_pParticles; 
            int lastTime;
        public:
            Swarm(int created_at);
            ~Swarm();
            const Particle * getParticle(); //return a constant pointer
            void Update(int tick);
    };

}

#endif
