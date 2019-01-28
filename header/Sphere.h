//
// Created by nicol on 25/01/2019.
//

#ifndef UNTITLED_SPHERE_H
#define UNTITLED_SPHERE_H

#include "Vector3d.h"
#include "Ray.h"

class Sphere {
public:
    Sphere (CRTVector pos, float r, CRTColor col):
        position    (pos),
        rayon       (r)
        {
            Mesh(col);
        }
    float intersect(const Ray & ray);
protected:
    CRTVector position;
    float rayon;
    float intersect(const Ray & ray){

}
};


#endif //UNTITLED_SPHERE_H
