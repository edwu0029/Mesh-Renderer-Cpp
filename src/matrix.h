#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"
#include <string.h>

class mat3d{
    public:
        double m[3][3];

        mat3d(); //Default constructor sets all to 0
        mat3d(double in[3][3]);

        mat3d mat3d_mult(mat3d& a); //Perform matrix multiplication of this mat3d x a
        vec3d vec3d_mult(vec3d& a);
};

class mat4d{
    public:
        double m[4][4];
        
        mat4d();
        mat4d(double in[4][4]);

        mat4d mat4d_mult(mat4d& a);
        vec4d vec4d_mult(vec4d& a);
};

//Functions to create special matricies

//Model (Model to World)
mat4d mat4d_create_translation(double translation_x, double translation_y, double translation_z);
mat4d mat4d_create_rotation_x(double theta);
mat4d mat4d_create_rotation_y(double theta);
mat4d mat4d_create_rotation_z(double theta);
mat4d mat4d_create_scale(double scale_x, double scale_y, double scale_z);

#endif