#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>

inline SDL_Window* window;
inline SDL_Surface* surface;
inline uint32_t* pixel_buffer; //each pixel represented by a uint32_t (8 bits each for r, g, b, a)

inline int window_width;
inline int window_height;

uint32_t rgba_to_uint32(uint8_t r, uint8_t g, uint8_t b, uint8_t a); //Convert rgba to a 32 bit value. Note that a = 255 is opaque
void set_pixel(int x, int y, uint32_t colour); //Sets a pixel at (x, y) in the surface
void draw_line(int x1, int y1, int x2, int y2, uint32_t colour); //Draws line from (x1, y1) to (x2, y2) with colour
                                                                 //No particular ordering of points needed

bool display_init();
void display_quit();
void display_present();
void set_blackout();

#endif