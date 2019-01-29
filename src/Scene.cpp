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

using namespace std;

void Scene::addMesh(Mesh *mesh){
    Meshes.push_back(mesh);
}
void Scene::addLight(Light *light){
    Lights.push_back(light);
}

Scene::Scene(){

}


float Scene::calclumiere(Ray & rayon,CRTVector position, float distance,int index){
    float lumiere = 0;

    CRTVector ptimpact(rayon.get_direction() * distance + rayon.get_position());

    CRTVector N(ptimpact - position);//normal a sphere au point
    N.Normalize();
    for (int i =0; i <Lights.size(); i++){
        CRTVector Li(ptimpact - Lights[i]->get_position());//vecteur entre point et lumière
        Li.Normalize();
        float pdscl = Li.Dot(N);
        int bufferclose = index;
        int bufferdist = RT_INFINITE;
        for(int j=0;j<Meshes.size();j++){
                Ray rayoflight(Lights[i]->get_position(), -Li);
                float impact = Meshes[j]->intersect(rayoflight);
                if (impact < bufferdist){
                    bufferclose = j;
                    bufferdist = impact;
                }
        }
        if (pdscl>0 && bufferclose == index){
            lumiere += pdscl;
        }

    }
    if (lumiere > 1){
        lumiere = 1;
    }
    return lumiere;
}

CRTColor Scene::test_intersect(Ray & ray){
    int index_mesh = -1;
    float distance_buffer = RT_INFINITE;
    float distance = -1;
    float lumiere = 0;
    CRTColor color(0,0,0);

    for (unsigned int i = 0; i <Meshes.size(); i++){
        distance = Meshes[i]->intersect(ray);

        if (distance<distance_buffer){
            distance_buffer = distance;
            index_mesh = i;
        }
    }
    if (index_mesh != -1){
        lumiere = calclumiere(ray,Meshes[index_mesh]->get_position(), distance_buffer, index_mesh);

        color = Meshes[index_mesh]->get_color();
        color *= lumiere;
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
            //cout<<"ligne:"<<i;
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
