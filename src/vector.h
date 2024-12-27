#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <math.h>

class vec3d {
    public:
        double v[3]; //In order x, y, z

        vec3d(); //Default Constructor sets all to 0
        vec3d(double x, double y, double z);
        
        double magnitude();
        double dot(vec3d &b); //Returns dot product of this vec3d with b
        vec3d cross(vec3d &b); //Returns this vec3d cross b
        vec3d normalize(); //Returns the normalized version of this vec3d
        void print();
        
        vec3d operator+(vec3d const& b);
        vec3d operator-(vec3d const& b);
        vec3d operator*(const double x);

};

class vec4d{
    public:
        double v[4]; //In order x, y, z, w

        vec4d(); //Default constructor sets all to 0
        vec4d(double x, double y, double z, double w);
        double magnitude();
        double dot(vec4d &b); //Returns dot product of this vec4d with b
        vec4d normalize();
        void print();
        
        vec4d operator+(vec4d const& b);
        vec4d operator-(vec4d const& b);
        vec4d operator*(const double x);
};

//Other functions
vec4d vec3d_to_vec4d(vec3d& a);
vec3d vec4d_to_vec3d(vec4d& a);

#endif