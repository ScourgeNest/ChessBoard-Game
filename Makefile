#Niculici Mihai-Daniel 315 CA
# compiler setup
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# define targets
TARGETS = gigel_and_the_checkboard

build: $(TARGETS)

gigel_and_the_checkboard: gigel_and_the_checkboard.c
	$(CC) $(CFLAGS) gigel_and_the_checkboard.c -o gigel_and_the_checkboard

pack:
	zip -FSr 315CA_NiculiciMihai-Daniel_Tema1.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean