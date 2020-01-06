gcc -c renderer.cpp
gcc -c main.cpp
g++ main.o renderer.o -framework OpenGL -lglfw -lc++
