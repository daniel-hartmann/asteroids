PROJ_NAME=asteroids
CPP_SOURCE=$(wildcard *.cpp)
H_SOURCE=$(wildcard *.h)
OBJ=$(CPP_SOURCE:.c=.o)
CC=g++
CC_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system


all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CC_FLAGS)

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm *.o $(PROJ_NAME) *~
