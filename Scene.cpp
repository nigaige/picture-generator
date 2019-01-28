//
// Created by nicol on 25/01/2019.
//


#include "header/Scene.h"
#include "Sphere.h"
#include "header/Bmpfile.h"

Scene::Scene(){
    CRTVector sphere_pos = new CRTVector(5,5,5);
    Sphere boule = new Sphere(sphere_pos, 2);
    addMesh(boule);

}

void Scene::addMesh(Mesh *mesh){
    Meshes.push_back(mesh);

}

CRTColor Scene::test_intersect(Ray & ray){
    int index_mesh = -1;
    float distance_buffer = RT_INFINITE;
    float distance = -1;
    CRTColor color = -1;
    for (unsigned int i = 0; i <meshes.size(); i++){
        distance = meshes[i]->intersect(ray);
        if (distance<distance_buffer){
            distance_buffer = distance;
            index_mesh = i;
        }
    }
    if (index_mesh != -1){
        color = Meshes[index_mesh].get_color();
    }
    return color;
}

Ray Screne::genray(int pixelX,int pixelY, int screenZ, CRTVector camera){
    CRTVector direction = new CRTVector(pixelX/100, pixelY/100,screenZ);
    Ray rayon = new Ray(camera,direction );
    return rayon;
}

void Scene::Render(int ScreenX, int ScreenY){
    Ray pixel;
    const screenZ = 1;
    CRTColor pixelcolor;
    unsigned char * buffer = new unsigned char[width*height*3];
    for (int i =0; i < ScreenX; i++){
            for(int j = 0; j < ScreenY;j++){
                pixel = genray(ScreenX,ScreenY,screenZ, CRTVector(0,0,0));
                pixelcolor = test_intersect();
                buffer[(i*ScreenX+j)*3]=pixelcolor.m_fR;
                buffer[(i*ScreenX+j)*3+1]=pixelcolor.m_fG;
                buffer[(i*ScreenX+j)*3+2]=pixelcolor.m_fB;
            }


    }
    BMPFile::SaveBmp("test.bmp",buffer, ScreenX,ScreenY);
}
