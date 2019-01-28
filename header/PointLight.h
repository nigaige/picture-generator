//
// Created by nicol on 25/01/2019.
//

#ifndef UNTITLED_POINTLIGHT_H
#define UNTITLED_POINTLIGHT_H

#include "Light.h"
#include "Vector3d.h"


class PointLight: public Light{
public:
    PointLight(CRTVector Position):
        position (Position)
        {}
    CRTVector get_position();

protected:
    CRTVector position;;
};


#endif //UNTITLED_POINTLIGHT_H
