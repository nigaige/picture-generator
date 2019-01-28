//
// Created by nicol on 25/01/2019.
//

#include "../header/Sphere.h"
#include "math.h"
#include "iostream"

float Sphere::intersect(Ray & ray){

    CRTVector dir = ray.get_direction();
    CRTVector pos = ray.get_position();
/*
    float A = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
    float B = 2 * (dir.x * (pos.x - position.x) + dir.y * (pos.y - position.y) + dir.z * (pos.z - position.z));
    float C = (pos.x - position.x) *(pos.x - position.x)
            +(pos.y - position.y) *(pos.y - position.y)
            +(pos.z - position.z) *(pos.z - position.z);

     float delta = -B * B + 4 * A * C;
     float value = (-B - sqrt(delta) / (2 * A));
       // std::cout <<delta<<std::endl;
*/
    CRTVector oc = ray.get_position() - position;
    float A = ray.get_direction().Dot(ray.get_direction());
    float B = 2.0f * oc.Dot(ray.get_direction());
    float C = oc.Dot(oc) - rayon * rayon;
    float delta = B * B - 4 * A * C;

    if (delta < 0){
        return RT_INFINITE;
    }else{
        return (-B-float(sqrt(delta)))/(2.0f * A);
    }

}

CRTVector Sphere::get_position(){
    return position;
}
