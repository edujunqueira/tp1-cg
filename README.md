"# tp1-cg"

compile:
windows
g++ -o pongho.exe pongho.cpp barra.cpp bola.cpp botao.cpp menu.cpp placar.cpp functions.cpp records.cpp pause.cpp config.cpp -Llib\freeglut lib\soil\libSOIL.a -lglew32 -lfreeglut -lopengl32 -lglu32
pongho.exe

linux:
g++ -o pongho pongho.cpp barra.cpp bola.cpp botao.cpp menu.cpp placar.cpp functions.cpp records.cpp pause.cpp config.cpp -lSOIL -lglut -lGLEW -lGL -lGLU -std=c++11
./pongho
