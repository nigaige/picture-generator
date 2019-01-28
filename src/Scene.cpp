//
// Created by nicol on 25/01/2019.
//


#include "../header/Light.h"
#include "../header/Sphere.h"
#include "../header/Bmpfile.h"
#include "../header/Mesh.h"
#include "../header/Ray.h"
#include "../header/Scene.h"
#include "iostream"

void Scene::addMesh(Mesh *mesh){
    Meshes.push_back(mesh);
}
void Scene::addLight(Light *light){
    Lights.push_back(light);
}

Scene::Scene(){

}



CRTColor Scene::test_intersect(Ray & ray){
    int index_mesh = -1;
    float distance_buffer = RT_INFINITE;
    float distance = -1;
    CRTColor color(0,0,0);

    for (unsigned int i = 0; i <Meshes.size(); i++){
        distance = Meshes[i]->intersect(ray);

        if (distance<distance_buffer){
            distance_buffer = distance;
            index_mesh = i;
        }
    }
    if (index_mesh != -1){
        color = Meshes[index_mesh]->get_color();
    }
    return color;
}

Ray Scene::genray(float pixelX,float pixelY, float screenZ, CRTVector camera){
    Ray rayon(camera,CRTVector(pixelX,pixelY,screenZ) );
    return rayon;
}

void Scene::Render(float ScreenX, float ScreenY){
    //Ray pixel;
    const int screenZ = 5;
    CRTColor pixelcolor;
    unsigned char * buffer = new unsigned char[(int)ScreenX*(int)ScreenY*3];

    for (int i =0; i < ScreenX; i++){
            cout<<"ligne:"<<i;
            for(int j = 0; j < ScreenY;j++){
                //Ray pixel = genray(ScreenX/i,ScreenY/j,0, CRTVector(0,0,0));

                float fov = 90;// champs de vue (fielad of view)
                float r = ScreenX / ScreenY; // largeur image/hauteur image
                float s = tan(fov / 2 * 3.14 / 180);
                float px = (2 * (i + 0.5) / ScreenX - 1) * r * s; // ray.x dir
                float py = (1 - 2 * (j + 0.5) / ScreenY) * s; // ray.y dir

                Ray pixel( CRTVector(0,0,0), CRTVector(px, py,screenZ));
                pixelcolor = test_intersect(pixel);
                buffer[(i*(int)ScreenX+j)*3]=pixelcolor.m_fR;
                buffer[(i*(int)ScreenX+j)*3+1]=pixelcolor.m_fG;
                buffer[(i*(int)ScreenX+j)*3+2]=pixelcolor.m_fB;

            }


    }
    BMPFile::SaveBmp("test.bmp",buffer, ScreenX,ScreenY);
}
