CC=g++
CFLAGS=-lgmp -lboost_program_options


all: wlg

wlg: wlg.cpp
	$(CC) -o wlg wlg.cpp $(CFLAGS)
	
clean:
	rm wlg
