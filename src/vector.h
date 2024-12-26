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
        
        vec4d operator+(vec4d const& b);
        vec4d operator-(vec4d const& b);
        vec4d operator*(const double x);
        
    
};



// typedef struct{
//     double v[3]; // from index 0 to 2: x, y, z
// } vec3d;

// typedef struct{
//     double v[4]; // from index 0 to 3: x, y, z, w
// } vec4d;






// vec3d vec3_add(vec3d* a, vec3d* b); //Perform a+b
// vec3d vec3_sub(vec3d* a, vec3d* b); //Perform a-b
// void vec3d_scale(double scale, vec3d* a); //Multiply vector a by scalar scale
// double vec3d_dot(vec3d* a, vec3d* b); //Perform dot product of a and b
// vec3d vec3d_cross(vec3d* a, vec3d* b); //Perform axb
// double vec3_norm(vec3d* a); //Returns the magnitude of vector A
// vec3d vec3_normalize(vec3d* a); //Returns a normalized version of a
// void print_vec3d(vec3d* a); //Print vector contents for debugging

// vec4d vec4_add(vec4d* a, vec4d* b);
// vec4d vec4_sub(vec4d* a, vec4d* b);
// void vec4d_scale(double scale, vec4d* a);
// double vec4_dot(vec4d* a, vec4d* b);
// void print_vec4d(vec4d* a);

// vec4d vec3d_to_vec4d(vec3d* a); //Convert a vec3d to vec4d by setting w = 1
// vec3d vec4d_to_vec3d(vec4d* a); //Convert a vec4d to vec3d by simplying removing w coordinate

#endif