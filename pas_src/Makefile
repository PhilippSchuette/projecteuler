# Make a pascal program.
PC := fpc
PFLAGS := -TLINUX

SRC := problem001.pas
BIN := prog

.PHONY: test clean

all: $(SRC)
	$(PC) $(PFLAGS) -o$(BIN) $^

test:
	./$(BIN)

clean:
	rm -f *.o $(BIN)
