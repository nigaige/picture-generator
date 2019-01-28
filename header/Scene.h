//
// Created by nicol on 25/01/2019.
//




#ifndef UNTITLED_SCENE_H
#define UNTITLED_SCENE_H

using namespace std;
#include "Vector3d.h"
#include "Mesh.h"
#include "vector"
#include "Light.h"

class Scene {

public:
    Scene();
    void addMesh(Mesh *mesh);
    void addLight(Light *light);
    CRTColor test_intersect(Ray & ray);
    void Render(float ScreenX, float ScreenY);
    Ray genray(float pixelX,float pixelY, float screenZ, CRTVector camera);
    float calclumiere(Ray & rayon, CRTVector position, float distance);
//    void calclumiere( Ray*,Mesh*,float);
protected:
    vector<Mesh*> Meshes;
    vector<Light*> Lights;

};






#endif //UNTITLED_SCENE_H
