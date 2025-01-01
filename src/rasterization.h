#ifndef RASTERIZATION_H
#define RASTERIZATION_H

#include <vector>
#include "vector.h"
#include "matrix.h"
#include "triangle.h"

#define W_CLIPPING_PLANE 0.00001

vec4d perspective_divide(vec4d& a); //Performs the perspective divide on vector a, and returns the result

//Clipping in homogenous coordinates (Clip space, before perspective divide)
void clip_waxis(std::vector<vec4d>& vertices, std::vector<vec4d>& new_vertices); //clip against waxis, so only positive w values allowed
void clip_axis(int axis, std::vector<vec4d>& vertices, std::vector<vec4d>& new_vertices); //clip against selected axis planes (-w<=x, y, z<=w)
                                                                                          //x=0, y=1, z=2
void get_triangles_from_vertices(std::vector<vec4d>& vertices, std::vector<triangle4d>& tris);

#endif