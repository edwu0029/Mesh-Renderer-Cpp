#ifndef GLOBALS_H
#define GLOBALS_H

#include <math.h>

//Mesh variables
inline double mesh_translation_x = 0;
inline double mesh_translation_y = 0;
inline double mesh_translation_z = 10;

inline double mesh_scale;

inline double mesh_angle_x = 0;
inline double mesh_angle_y = 0;
inline double mesh_angle_z = 0;

//Perspective/Projection variab;es
inline double far = 20;
inline double near = 1;
inline double fov = M_PI/2;


#endif