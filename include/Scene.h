//
// Created by nicol on 25/01/2019.
//




#ifndef UNTITLED_SCENE_H
#define UNTITLED_SCENE_H

using namespace std;
#include "Vector3d.h"
#include "Mesh.h"
#include "vector"
class Scene {

public:
    Scene();
    void addMesh(Mesh *mesh);
    CRTColor test_intersect(Ray & ray);
    void Render(float,float);
    Ray genray(float pixelX,float pixelY, float screenZ, CRTVector camera);
protected:
    vector<Mesh*> Meshes;

};






#endif //UNTITLED_SCENE_H
