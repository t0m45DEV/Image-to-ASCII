CC=g++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

EXECUTABLE=ImgToASCII


main: main.cpp
	@$(CC) $^ -o $(EXECUTABLE) $(CFLAGS)


.PHONY: clean
clean:
	@rm -f ./$(EXECUTABLE)
