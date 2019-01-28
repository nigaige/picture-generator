//
// Created by nicol on 25/01/2019.
//

#ifndef UNTITLED_POINTLIGHT_H
#define UNTITLED_POINTLIGHT_H


class PointLight public Light{
public:
    Light(CRTVector A):
        point (A)
        {}

protected:
CRTVector point;
};


#endif //UNTITLED_POINTLIGHT_H
