##############

MY_BIN_CFLAGS  = -g -O0
MY_BIN_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lcurl -lstdc++ -lrt -lboost_unit_test_framework

PGM  = test_get
INCS = ../include
OBJS = $(PGM).o ../objs/LibCurlWrap.o

.PHONY:	clean run 

all:	$(PGM)

$(PGM).o:	$(PGM).cpp $(INCS)/LibCurlWrap.hpp
	g++ -Wall -g $(MY_BIN_CFLAGS) -I$(INCS) -c $(PGM).cpp -o $@

$(PGM): $(PGM).o ../objs/LibCurlWrap.o
	g++ -o $@ $(OBJS) $(MY_BIN_LDFLAGS)

clean:
	rm -f  $(PGM) *.o

test:	$(PGM)
	./$(PGM)
