#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector.h"

class triangle3d{
    public:
        triangle3d();
        triangle3d(vec3d a, vec3d b, vec3d c);
        vec3d vertices[3];
};

class triangle4d{
    public:
        triangle4d();
        triangle4d(vec4d a, vec4d b, vec4d c);
        vec4d vertices[3];
};

triangle3d tri4d_to_tri3d(triangle4d tri);

#endif