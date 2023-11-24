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

.PHONY: all clean test drivers driver_graf driver_drafstack driver_tree driver_listdin driver_listlinier driver_foto driver_datetime driver_time driver_prioqueue driver_listpengguna driver_pcolor driver_mesinkalimat driver_charmachine driver_wordmachine

# Main Target
all: main drivers

# Linking
main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compiling
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

drivers: driver_graf driver_drafstack driver_tree driver_listdin driver_listlinier driver_foto driver_datetime driver_time driver_prioqueue driver_listpengguna driver_pcolor driver_mesinkalimat driver_charmachine driver_wordmachine

driver_graf:
	$(CC) $(CFLAGS) -o $@ $^ ADT/graf/driver_graf.c ADT/graf/graf.c ADT/queue/prioqueue.c 

driver_drafstack:
	$(CC) $(CFLAGS) -o $@ $^ ADT/stack/driver_drafStack.c ADT/stack/drafStack.c ADT/datetime/datetime.c primitif/primitif.c ADT/mesinkata/wordmachine.c ADT/mesinkarakter/charmachine.c ADT/datetime/time.c

driver_tree:
	$(CC) $(CFLAGS) -o $@ $^ ADT/tree/driver_tree.c ADT/tree/tree.c ADT/listdin/listdin.c ADT/datetime/datetime.c primitif/primitif.c ADT/datetime/time.c

driver_listdin:
	$(CC) $(CFLAGS) -o $@ $^ ADT/listdin/driver_listdin.c ADT/listdin/listdin.c ADT/tree/tree.c ADT/datetime/datetime.c ADT/datetime/time.c primitif/primitif.c

driver_foto:
	$(CC) $(CFLAGS) -o $@ $^ ADT/matriks/driverfoto.c ADT/matriks/foto.c ADT/pcolor/pcolor.c

driver_datetime: 
	$(CC) $(CFLAGS) -o $@ $^ ADT/datetime/driverdatetime.c ADT/datetime/datetime.c ADT/datetime/time.c

driver_time:
	$(CC) $(CFLAGS) -o $@ $^ ADT/datetime/drivertime.c ADT/datetime/time.c

driver_prioqueue:
	$(CC) $(CFLAGS) -o $@ $^ ADT/queue/driverPrio.c ADT/queue/prioqueue.c

driver_listpengguna:
	$(CC) $(CFLAGS) -o $@ $^ ADT/liststatik/driverlistpengguna.c ADT/liststatik/listpengguna.c ADT/mesinkata/wordmachine.c ADT/datetime/datetime.c ADT/listdin/listdin.c ADT/tree/tree.c ADT/mesinkarakter/charmachine.c ADT/datetime/time.c primitif/primitif.c ADT/matriks/foto.c ADT/queue/prioqueue.c ADT/stack/drafStack.c ADT/graf/graf.c ADT/pcolor/pcolor.c ADT/mesinkata/mesinkalimat.c profil/profil.c permintaan/requests.c utas/utas.c balasan/balasan.c draf/draf.c data/data.c teman/teman.c kicauan/kicauan.c ADT/listlinier/listlinier.c

driver_listlinier:
	$(CC) $(CFLAGS) -o $@ $^ ADT/listlinier/driverlistlinier.c ADT/listlinier/listlinier.c kicauan/kicauan.c ADT/mesinkata/wordmachine.c ADT/datetime/datetime.c ADT/listdin/listdin.c ADT/tree/tree.c ADT/mesinkarakter/charmachine.c ADT/datetime/time.c primitif/primitif.c ADT/liststatik/listpengguna.c teman/teman.c ADT/matriks/foto.c ADT/queue/prioqueue.c ADT/stack/drafStack.c ADT/graf/graf.c ADT/pcolor/pcolor.c data/data.c ADT/mesinkata/mesinkalimat.c profil/profil.c permintaan/requests.c utas/utas.c balasan/balasan.c draf/draf.c

driver_pcolor:
	$(CC) $(CFLAGS) -o $@ $^ ADT/pcolor/driver_pcolor.c ADT/pcolor/pcolor.c

driver_charmachine:
	$(CC) $(CFLAGS) -o $@ $^ ADT/mesinkarakter/drivercharmachine.c ADT/mesinkarakter/charmachine.c

driver_wordmachine:
	$(CC) $(CFLAGS) -o $@ $^ ADT/mesinkata/driverwordmachine.c ADT/mesinkarakter/charmachine.c ADT/mesinkata/wordmachine.c

driver_mesinkalimat:
	$(CC) $(CFLAGS) -o $@ $^ ADT/mesinkata/drivermesinkalimat.c ADT/mesinkarakter/charmachine.c ADT/mesinkata/wordmachine.c ADT/mesinkata/mesinkalimat.c

# Clean
clean:
	rm -f main $(OBJ) ADT/graf/driver_graf ADT/stack/driver_drafStack ADT/tree/driver_tree ADT/listdin/driver_listdin ADT/listlinier/driverlistlinier ADT/matriks/driverFoto ADT/datetime/driverdatetime ADT/datetime/drivertime ADT/queue/driverPrio primitif/primitif kicauan/kicauan teman/teman profil/profil primitif/primitif permintaan/requests teman/teman utas/utas draf/draf balasan/balasan ADT/liststatik/driverlistpengguna ADT/pcolor/driver_pcolor ADT/mesinkarakter/drivercharmachine ADT/mesinkata/driverwordmachine ADT/mesinkata/drivermesinkalimat

# Add any other rules or targets as necessary
