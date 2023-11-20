CC = gcc
CFLAGS = -Wall -Werror -std=c11

# Source and Object Files
SRC = adt/mesinkarakter/charmachine.c \
      adt/mesinkata/wordmachine.c \
      adt/liststatik/listpengguna.c \
      kicauan/kicauan.c \
      adt/graf/graf.c \
      adt/stack/drafStack.c \
      primitif/primitif.c \
      utas/utas.c \
      adt/tree/tree.c \
      adt/listdin/listdin.c \
      adt/listlinier/listlinier.c \
      adt/matriks/foto.c \
      adt/datetime/datetime.c \
      adt/datetime/time.c \
      teman/teman.c \
      draf/draf.c \
      balasan/balasan.c \
      data/data.c \
      main.c \
      adt/queue/prioqueue.c \
      adt/pcolor/pcolor.c \
      permintaan/requests.c \
      profil/profil.c \
      adt/mesinkata/mesinkalimat.c
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
