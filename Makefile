CC = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude -pg

all: bin/tp1.out
teste: bin/gerador

bin/gerador:
	$(CC) src/gerador.cpp -o bin/gerador

bin/tp1.out: obj/main.o obj/Acao.o obj/Cliente.o obj/Metricas.o obj/Sistema.o
	$(CC) $(CXXFLAGS) obj/main.o obj/Acao.o obj/Cliente.o obj/Metricas.o obj/Sistema.o -o bin/tp1.out

obj/main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

obj/Acao.o: src/Acao.cpp
	$(CC) $(CXXFLAGS) -c src/Acao.cpp -o obj/Acao.o

obj/Cliente.o: src/Cliente.cpp
	$(CC) $(CXXFLAGS) -c src/Cliente.cpp -o obj/Cliente.o

obj/Metricas.o: src/Metricas.cpp
	$(CC) $(CXXFLAGS) -c src/Metricas.cpp -o obj/Metricas.o

obj/Sistema.o: src/Sistema.cpp
	$(CC) $(CXXFLAGS) -c src/Sistema.cpp -o obj/Sistema.o

clean:
	rm -f obj/*.o bin/tp1.out bin/gerador gmon.out