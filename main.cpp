#include <iostream>

#include "Scene.h"
#include "Sphere.h"
int main() {
    Scene place;
    place.addMesh(new Sphere (CRTVector(-30,0,-300),25,CRTColor(255,0,0)));
    place.addMesh(new Sphere (CRTVector(5,20,-300),25,CRTColor(0,255,0)));
    place.addMesh(new Sphere (CRTVector(5,-20,-300),25,CRTColor(0,0,255)));

    place.Render(500,500);


    return 0;
}
