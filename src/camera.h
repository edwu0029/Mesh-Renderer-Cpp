#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"
class camera{
    public:
        vec3d position; //In world space
        vec3d u, v, w; //Basis vectors of the camera with:
                       //u = right
                       //v = up
                       //w = backwards (-w is forwards, to maintain right hand coordinate system)
};
#endif