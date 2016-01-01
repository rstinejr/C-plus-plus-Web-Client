##############
# Makfile for "weather" program, which parses the XHMTL response from
# www.weather.gov.
##############


############################################
# libxml++
############################################

XML2_INCS = -I/usr/include/libxml2 \
            -I/usr/include/glibmm-2.4 \
            -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include \
            -I/usr/include/sigc++-2.0 \
            -I/usr/lib/x86_64-linux-gnu/sigc++-2.0/include \
            -I/usr/include/glib-2.0 \
            -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
            -I/usr/include/libxml++-2.6 \
            -I/usr/lib/libxml++-2.6/include  

XML2_LIBS = -lxml++-2.6 -lxml2 -lglibmm-2.4 -lgobject-2.0 \
            -lsigc-2.0 -lglib-2.0  

############################################

MY_LIB     = ../curlwrap/libcurlwrap.so.1  
MY_CFLAGS  = -g -O0
MY_LDFLAGS = $(MY_LIB) $(XML2_LIBS) -L/usr/lib/x86_64-linux-gnu -lstdc++ -lrt

PGM  = weather

OBJS = objs/main.o objs/DCAWeather.o

.PHONY:	clean run 

all:	$(PGM)

$(MY_LIB):
	make -C ../curlwrap

objs:   
	mkdir objs

objs/main.o:	src/main.cpp src/DCAWeather.hpp
	g++ -Wall -c src/main.cpp -o $@ $(MY_CFLAGS) \
                                    -I../curlwrap/include \
                                    $(XML2_INCS)

objs/DCAWeather.o:	src/DCAWeather.cpp 
	g++ -Wall -c src/DCAWeather.cpp -o $@ $(MY_CFLAGS) \
                                    -I../curlwrap/include \
                                    $(XML2_INCS)

$(PGM):	objs $(OBJS) $(MY_LIB) 
	g++ -o $@ $(OBJS) $(LIB_OBJS) $(MY_LDFLAGS)

clean:
	rm -rf $(PGM) objs/*
		
run:	$(PGM) $(MY_LIB)
	LD_LIBRARY_PATH=../curlwrap ./$(PGM)
