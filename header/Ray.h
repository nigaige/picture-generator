#ifndef RAY_H
#define RAY_H
#include "Vector3d.h"
#

class Ray {
    public:
        Ray(CRTVector pos, CRTVector dir):
        position    (pos),
        direction   (dir)
        {};
        //virtual ~Ray();
        //genRay(CRTVector pos, CRTVector dir);
        CRTVector get_position();
        CRTVector get_direction();

    protected:
        CRTVector position;
        CRTVector direction;

    private:
};

#endif // RAY_H
