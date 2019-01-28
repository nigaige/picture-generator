//
// Created by nicol on 25/01/2019.
//

#ifndef UNTITLED_SPHERE_H
#define UNTITLED_SPHERE_H

#include "Vector3d.h"
#include "Ray.h"
#include "Color.h"
#include "Mesh.h"

class Sphere : public Mesh{
public:
    Sphere (CRTVector pos, float r, CRTColor col):
        Mesh(col),
        position    (pos),
        rayon       (r)
        {}
    float intersect(Ray & ray);
    CRTVector get_position();
protected:
    CRTVector position;
    float rayon;

};

#endif //UNTITLED_SPHERE_H
