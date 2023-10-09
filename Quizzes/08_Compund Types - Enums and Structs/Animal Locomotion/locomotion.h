#ifndef LOCOMOTION_H
#define LOCOMOTION_H

namespace Locomotion
{
    enum Legs
    {   
        apod = 0,
        biped = 2,
        quadruped = 4,
        hexaped = 6,
        octoped = 8
    };
}


int operator+(Locomotion::Legs l);
int getValue(Locomotion::Legs l);

#endif
