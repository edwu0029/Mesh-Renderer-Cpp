#include "matrix.h"

// ------------- For mat3d class -------------
mat3d::mat3d(){
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            m[i][j] = 0.0;
        }
    }
}
mat3d::mat3d(double in[3][3]){
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            m[i][j] = in[i][j];
        }
    }
}
mat3d mat3d::mat3d_mult(mat3d& a){
    mat3d res;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            res.m[i][j] = 0.0;
            for(int k = 0;k<3;k++){
                res.m[i][j]+=(m[i][k]*a.m[k][j]);
            }
        }
    }
    return res;
}
vec3d mat3d::vec3d_mult(vec3d& a){
    vec3d res;
    for(int i = 0;i<3;i++){
        res.v[i] = (m[i][0]*a.v[0])+(m[i][1]*a.v[1])+(m[i][2]*a.v[2]);
    }
    return res;
}


// ------------- For mat4d class -------------
mat4d::mat4d(){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            m[i][j] = 0.0;
        }
    }
}
mat4d::mat4d(double in[4][4]){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            m[i][j] = in[i][j];
        }
    }
}

mat4d mat4d::mat4d_mult(mat4d& a){
    mat4d res;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            res.m[i][j] = 0.0;
            for(int k = 0;k<4;k++){
                res.m[i][j]+=(m[i][k]*a.m[k][j]);
            }
        }
    }
    return res;
}
vec4d mat4d::vec4d_mult(vec4d& a){
    vec4d res;
    for(int i = 0;i<4;i++){
        res.v[i] = (m[i][0]*a.v[0])+(m[i][1]*a.v[1])+(m[i][2]*a.v[2]);
    }
    return res;
}

// ------------- Functions to create special matricies -------------
mat4d mat4d_create_translation(double translation_x, double translation_y, double translation_z){
    double translation[4][4] = {{1, 0, 0, translation_x},
                                {0, 1, 0, translation_y},
                                {0, 0, 1, translation_z},
                                {0, 0, 0, 1}};
    mat4d res;
    memcpy(res.m, translation, 4*4*sizeof(double));
    return res;
}
mat4d mat4d_create_rotation_x(double theta){
    double a = cosf(theta);
    double b = sinf(theta);
    double rotation_z[4][4] = {{1, 0, 0, 0},
                                {0, a, -b, 0},
                                {0, b, a, 0},
                                {0, 0, 0, 1}};
    mat4d res;
    memcpy(res.m, rotation_z, 4*4*sizeof(double));
    return res;
}
mat4d mat4d_create_rotation_y(double theta){
    double a = cosf(theta);
    double b = sinf(theta);
    double rotation_y[4][4] = {{a, 0, b, 0},
                                {0, 1, 0, 0},
                                {-b, 0, a, 0},
                                {0, 0, 0, 1}};
    mat4d res;
    memcpy(res.m, rotation_y, 4*4*sizeof(double));
    return res;
}
mat4d mat4d_create_rotation_z(double theta){
    double a = cosf(theta);
    double b = sinf(theta);
    double rotation_z[4][4] = {{a, -b, 0, 0},
                                {b, a, 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 1}};
    mat4d res;
    memcpy(res.m, rotation_z, 4*4*sizeof(double));
    return res;
}
mat4d mat4d_create_scale(double scale_x, double scale_y, double scale_z){
    double scale[4][4] = {{scale_x, 0, 0, 0},
                                {0, scale_y, 0, 0},
                                {0, 0, scale_z, 0},
                                {0, 0, 0, 1}};
    mat4d res;
    memcpy(res.m, scale, 4*4*sizeof(double));
    return res;
}