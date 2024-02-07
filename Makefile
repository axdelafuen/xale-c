CC = gcc
CFLAGS = -Wall -fPIC -pedantic

SRC=$(wildcard src/*.c)

OBJ=$(patsubst src/%.c,src/obj/%.o,$(SRC))

all: create_dirs $(OBJ)
	$(CC) $(OBJ) -o $@

src/obj/%.o: src/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

create_dirs:
	@mkdir -p src/obj

clean:
	rm -rf src/obj/ xale
