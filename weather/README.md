# weather

This program queries a weather-feed web-site at Washington National Airport and displays the results.

The code has been developed on 64-bit Linux Mint, a variant of the Ubuntu Linux distro,
with g++ (Ubuntu 4.9.2-0ubuntu1~14.04) 4.9.2

Exotic libraries:

* libcurl (referenced by libcurlwrap.so)
* libxml++

It uses dynamic libray libcurlwrap.so, which is a thin wrapper around libcurl.  Instructions for installing
libcurl are in ../curlwrap/README.md.
 
Install libxml++ with apt-get:
```
sudo apt-get install libxml++2.6-dev
```

To find the compiler and linker options you will need in order to use libxml++, enter the following commmand

```
pkg-config libxml++-2.6 --cflags --libs
```

Test the connection and data received from the site by using curl:
```
curl https://w1.weather.gov/xml/current_obs/KDCA.xml
```

The program can be built and run from the makefile:

```
make     # default target is "all""
make run # will build, if necessary.
```

For *weather* to run from the commandline, the loader will need to find libcurl.so.  One way to do this is 
with environment variable *LD_LIBRARY_PATH*, as follows:

```
LD_LIBRARY_PATH=../curlwrap ./weather
```
