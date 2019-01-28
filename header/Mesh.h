//
// Created by nicol on 25/01/2019.
//

#ifndef UNTITLED_MESH_H
#define UNTITLED_MESH_H

#include "Vector3d.h"
#include "Color.h"
#include "Ray.h"
#define RT_INFINITE 1000000000

class Mesh {
    public:
        Mesh(CRTColor col):
            color (col)
            {};
        virtual float intersect(Ray & ray) = 0;
        virtual ~Mesh();
        CRTColor get_color();
    protected:
        CRTColor color;
        float kr, kt;

    private:
};

#endif //UNTITLED_MESH_H
