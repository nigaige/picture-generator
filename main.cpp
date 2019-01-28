#include <iostream>

#include "header/Scene.h"
#include "header/Sphere.h"
#include "header/PointLight.h"
int main() {
    Scene place;
    place.addLight(new PointLight(CRTVector(0,0,-250)));
    place.addMesh(new Sphere (CRTVector(5,20,-300),25,CRTColor(0,255,0)));
    place.addMesh(new Sphere (CRTVector(5,-20,-300),25,CRTColor(0,0,255)));
    place.addMesh(new Sphere (CRTVector(-30,0,-300),25,CRTColor(255,0,0)));

    place.Render(500,500);


    return 0;
}
