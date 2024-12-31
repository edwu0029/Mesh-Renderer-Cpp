#include "rasterization.h"

vec4d perspective_divide(vec4d& a){
    vec4d res;

    double w = a.v[3];
    if(abs(w)>1E-9){ //Check not dividing by 0
        res.v[0] = a.v[0]/w;
        res.v[1] = a.v[1]/w;
        res.v[2] = a.v[2]/w;
    }
    return res;
}