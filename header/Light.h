//
// Created by nicol on 25/01/2019.
//

#ifndef UNTITLED_LIGHT_H
#define UNTITLED_LIGHT_H

#include "Vector3d.h"
#include "Ray.h"
class Light {
public:
    virtual CRTVector get_position() = 0;
protected:
};


#endif //UNTITLED_LIGHT_H
