"# tp1-cg"

compile:
windows, todo
g++ pongho.cpp barra.cpp bola.cpp placar.cpp functions.cpp -o pongho.exe -LE:\Linguagens\freeglut\lib E:\Linguagens\soil\libSOIL.a -lglew32 -lfreeglut -lopengl32 -lglu32
pongho.exe

linux:
g++ pongho.cpp barra.cpp bola.cpp placar.cpp functions.cpp -o pongho -lglut -lGLU -lGL -lGLEW -lSOIL
./pongho
