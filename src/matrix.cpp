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
        res.v[i] = (m[i][0]*a.v[0])+(m[i][1]*a.v[1])+(m[i][2]*a.v[2])+(m[i][3]*a.v[3]);
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
    double scale_mat[4][4] = {{scale_x, 0, 0, 0},
                                {0, scale_y, 0, 0},
                                {0, 0, scale_z, 0},
                                {0, 0, 0, 1}};
    mat4d res;
    memcpy(res.m, scale_mat, 4*4*sizeof(double));
    return res;
}

mat4d mat4d_create_view(vec3d& camera_pos, vec3d& target, vec3d& up){
    //Normalize all vectors for orthonormal basis
    vec3d zaxis = (camera_pos-target).normalize(); //Z-axis in view coordinates
    vec3d xaxis = (up.cross(zaxis)).normalize(); //X-axis in view coordinates
    vec3d yaxis = up;

    //View matrix is composed of the orientation and translation matricies (orientation for rotation of camera)

    //NOTE: using column-major version of view matrix
    double view_mat[4][4] = {{xaxis.v[0], xaxis.v[1], xaxis.v[2], -xaxis.dot(camera_pos)},
                             {yaxis.v[0], yaxis.v[1], yaxis.v[2], -yaxis.dot(camera_pos)},
                             {zaxis.v[0], zaxis.v[1], zaxis.v[2], -zaxis.dot(camera_pos)},
                             {0, 0, 0, 1}};
    mat4d res;
    memcpy(res.m, view_mat, 4*4*sizeof(double));
    return res;
}

mat4d mat4d_create_perspective(double fov, double aspect_ratio, 
                            double near, double far){
    double t = tanf(fov/2.0);
    double m[4][4] = {{1/(aspect_ratio*t), 0, 0, 0},
                      {0, 1/t, 0, 0},
                      {0, 0, far/(far-near), (-2*far*near)/(far-near)},
                      {0, 0, 1, 0}};
    mat4d res;
    memcpy(res.m, m, 4*4*sizeof(double));
    return res;
}

vec4d apply_perspective(mat4d& perspective_mat, vec4d& a){
    vec4d res = perspective_mat.vec4d_mult(a);
    double w = res.v[3];
    res = res*(1/w);
    return res;
}