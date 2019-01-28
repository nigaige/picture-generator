#include "Ray.h"

/*
void Ray::genRay(CRTVector pos, CRTVector dir){
    position = pos;
    direction = dir;
}

*/

CRTVector Ray::get_position(){
    return position;
}
CRTVector Ray::get_direction(){
    return direction;
}
