# Mesh-Renderer-Cpp
Mesh Renderer in C++

## Dependencies
- g++ compiler
- Make
- SDL2 Library

## Usage Instructions
```bash
# Cloning the Repo
git clone https://github.com/edwu0029/Mesh-Renderer-Cpp.git
cd Mesh-Renderer-Cpp
```
To render a mesh `mesh_name.obj`, put `mesh_name.obj` in the `meshes` folder
```bash
# Clean
make clean
# Build using Makefile
make build # Can also just use "make" for build
# Running the code
./main mesh_name.obj
```
For better performance, you can use `make release` instead of `make build` to use more compiler optimizations.

## Todo
[ ] Rasterize triangles instead of just wireframe
[ ] Implement Z-Buffer
[ ] Finalize inputs to control view
[ ] Implement textures
[ ] Use SDL_Texture instead of SDL_Surface for faster Hardware rendering

## Credits
- [Example meshes from Florida State University](https://people.sc.fsu.edu/~jburkardt/data/obj/obj.html)