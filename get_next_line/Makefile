CC = cc 

SRC = get_next_line.c
OBJ = libft.a
EXEC = gnl

all: $(EXEC)
	./$(EXEC)

$(EXEC): clean $(OBJ) $(SRC)
	$(CC) -o $@ $(OBJ) $(SRC) 

clean:
	rm -rf $(EXEC)