a.out: main.o renderer.o
	g++ main.o renderer.o -framework OpenGL -lglfw -lc++

main.o: main.cpp renderer.cpp renderer.h
	gcc -c main.cpp -o main.o
	
renderer.o:renderer.cpp renderer.h 
	gcc-c renderer.cpp -o main.o