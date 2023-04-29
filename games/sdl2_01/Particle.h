#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <iostream>
#include <stdlib.h>
#include <math.h>

namespace pqsr2 {
    class Particle {
        public:
            double m_x;
            double m_y;
            double m_speed;
            double m_direction; // angle
        private:
            void init();
        public:
            Particle();
            ~Particle();
            void Update(int interval);
    };
}

#endif
