//
// Created by nicol on 25/01/2019.
//

#include "header/Sphere.h"
#include "cmath.h"
#include "Common.h"

float Sphere::intersect(const Ray & ray){
    CRTVector dir = ray.get_direction();
    CRTVector pos = ray.get_position();

    float A = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
    float B = 2 * (dir.x * (pos.x - position.x) + dir.y * (pos.y - position.y) + dir.z * (pos.z - position.z));
    float C = (pos.x - position.x) *(pos.x - position.x)
            +(pos.y - position.y) *(pos.y - position.y)
            +(pos.z - position.z) *(pos.z - position.z);

     float delta = B * B - 4 * A * C;
     float value = (-B - sqrt(delta) / (2 * A));

    if (value>0){
        return value;
    }else{
        return RT_INFINITE;
    }


}
