#include "triangle.h"

// ------------- For triangle3d class -------------
triangle3d::triangle3d(){
    //All vertices use vec3d default constructor
    vertices[0] = vec3d();
    vertices[1] = vec3d();
    vertices[2] = vec3d();
}
triangle3d::triangle3d(vec3d a, vec3d b, vec3d c){
    vertices[0] = a;
    vertices[1] = b;
    vertices[2] = c;
}

// ------------- For triangle4d class -------------
triangle4d::triangle4d(){
    vertices[0] = vec4d();
    vertices[1] = vec4d();
    vertices[2] = vec4d();
}
triangle4d::triangle4d(vec4d a, vec4d b, vec4d c){
    vertices[0] = a;
    vertices[1] = b;
    vertices[2] = c;
}

// Other functions
triangle3d tri4d_to_tri3d(triangle4d tri){
    triangle3d res;
    res.vertices[0] = vec4d_to_vec3d(tri.vertices[0]);
    res.vertices[1] = vec4d_to_vec3d(tri.vertices[1]);
    res.vertices[2] = vec4d_to_vec3d(tri.vertices[2]);
    return res;
}