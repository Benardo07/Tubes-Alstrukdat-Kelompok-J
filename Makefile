CC = gcc
CFLAGS = -Wall -Werror -std=c11

# Source and Object Files
SRC = ADT/mesinkarakter/charmachine.c \
      ADT/mesinkata/wordmachine.c \
      ADT/liststatik/listpengguna.c \
      kicauan/kicauan.c \
      ADT/graf/graf.c \
      ADT/stack/drafStack.c \
      primitif/primitif.c \
      utas/utas.c \
      ADT/tree/tree.c \
      ADT/listdin/listdin.c \
      ADT/listlinier/listlinier.c \
      ADT/matriks/foto.c \
      ADT/datetime/datetime.c \
      ADT/datetime/time.c \
      teman/teman.c \
      draf/draf.c \
      balasan/balasan.c \
      data/data.c \
      main.c \
      ADT/queue/prioqueue.c \
      ADT/pcolor/pcolor.c \
      permintaan/requests.c \
      profil/profil.c \
      ADT/mesinkata/mesinkalimat.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean

# Main Target
all: main

# Linking
main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compiling
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean
clean:
	rm -f main $(OBJ)

# Add any other rules or targets as necessary
