#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <iostream>
#include <stdlib.h>

namespace pqsr2 {
    class Particle {
        public:
            double m_x;
            double m_y;
        public:
            Particle();
            ~Particle();
    };
}

#endif
