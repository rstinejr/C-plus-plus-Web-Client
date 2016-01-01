############################
# Makefile for libcurwrap.so
############################

LIB_VERSION = 1
LIB_NAME=libcurlwrap.so.$(LIB_VERSION)

MY_LIB_CFLAGS  = -g -O0 -fPIC -Wl,-export-dynamic

INCS = include
SRC  = src
OBJS = objs/LibCurlWrap.o

.PHONY:	clean test

all:	$(LIB_NAME)

objs:   
	mkdir objs

objs/LibCurlWrap.o:  objs $(SRC)/LibCurlWrap.cpp $(INCS)/LibCurlWrap.hpp
	g++ -Wall -g $(MY_LIB_CFLAGS) -I$(INCS) -c $(SRC)/LibCurlWrap.cpp -o $@

$(LIB_NAME):	$(OBJS)
	g++ -shared -Wl,-soname,$(LIB_NAME) -o $(LIB_NAME) $(OBJS) -lcurl -L/usr/lib/x86_64-linux-gnu -lstdc++ -lrt

test:	$(OBJS)
	make -C test test
		
clean:
	rm -f  $(LIB_NAME) objs/*.o
	make -C test clean
