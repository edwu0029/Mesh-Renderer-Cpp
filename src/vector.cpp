#include "vector.h"

// ------------- For vec3d class -------------
vec3d::vec3d(){
    v[0] = v[1] = v[2] = 0;
}
vec3d::vec3d(double x, double y, double z){
    v[0] = x;
    v[1] = y;
    v[2] = z;
}
double vec3d::magnitude(){
    return sqrt((v[0]*v[0])+(v[1]*v[1])+(v[2]*v[2]));
}
double vec3d::dot(vec3d &b){
    return (v[0]*b.v[0])+(v[1]*b.v[1])+(v[2]*b.v[2]);
}
vec3d vec3d::cross(vec3d &b){
    double x = (v[1]*b.v[2])-(v[2]*b.v[1]);
    double y = (v[2]*b.v[0])-(v[0]*b.v[2]);
    double z = (v[0]*b.v[1])-(v[1]*b.v[0]);
    return vec3d(x, y, z);
}
vec3d vec3d::normalize(){
    double mag = magnitude();
    if(abs(mag)<=1E-9){
        return vec3d(v[0], v[1], v[2]); //Magnitude is 0
    }else{
        return vec3d(v[0]/magnitude(), v[1]/magnitude(), v[2]/magnitude());
    }
}
void vec3d::print(){
    printf("%lf %lf %lf\n", v[0], v[1], v[2]);
}


vec3d vec3d::operator+(vec3d const& b){
    return vec3d(v[0]+b.v[0], v[1]+b.v[1], v[2]+b.v[2]);
}
vec3d vec3d::operator-(vec3d const& b){
    return vec3d(v[0]-b.v[0], v[1]-b.v[1], v[2]-b.v[2]);
}
vec3d vec3d::operator*(const double x){
    return vec3d(v[0]*x, v[1]*x, v[2]*x);
}
// Overloading the global operator* for x*vec3d order
vec3d operator*(const double x, vec3d& v){
    return v*x;
}


// ------------- For vec4d class -------------
vec4d::vec4d(){
    v[0] = v[1] = v[2] = v[3] = 0;
}
vec4d::vec4d(double x, double y, double z, double w){
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;
}
double vec4d::magnitude(){
    return sqrt((v[0]*v[0])+(v[1]*v[1])+(v[2]*v[2])+(v[3]*v[3]));
}
double vec4d::dot(vec4d &b){
    return (v[0]*b.v[0])+(v[1]*b.v[1])+(v[2]*b.v[2])+(v[3]*b.v[3]);
}
vec4d vec4d::normalize(){
    return vec4d(v[0]/magnitude(), v[1]/magnitude(), v[2]/magnitude(), v[3]/magnitude());
}
void vec4d::print(){
    printf("%lf %lf %lf %lf\n", v[0], v[1], v[2], v[3]);
}


vec4d vec4d::operator+(vec4d const& b){
    vec4d res(v[0]+b.v[0], v[1]+b.v[1], v[2]+b.v[2], v[3]+b.v[3]);
    return res;
}
vec4d vec4d::operator-(vec4d const& b){
    vec4d res(v[0]-b.v[0], v[1]-b.v[1], v[2]-b.v[2], v[3]-b.v[3]);
    return res;
}
vec4d vec4d::operator*(const double x){
    return vec4d(v[0]*x, v[1]*x, v[2]*x, v[3]*x);
}
// Overloading the global operator* for x*vec4d order
vec4d operator*(const double x, vec4d& v){
    return v*x;
}

//Other functions
vec4d vec3d_to_vec4d(vec3d& a){
    return vec4d(a.v[0], a.v[1], a.v[2], 1);
}
vec3d vec4d_to_vec3d(vec4d& a){
    return vec3d(a.v[0], a.v[1], a.v[2]);
}