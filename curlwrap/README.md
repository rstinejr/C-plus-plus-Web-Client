# Library curlwrap

As you might surmise from the name, this project is a wrapper around libcurl.  
More acccurately, it's a minimal wrapper.

This code has been developed on 64-bit Linux Mint, a variant of the Ubuntu Linux distro.
with g++ (Ubuntu 4.9.2-0ubuntu1~14.04) 4.9.2

## Installing libcurl

```
sudo apt-get install libcurl4-openssl-dev
```

See [libcurl programming tutorial](http://curl.haxx.se/libcurl/c/libcurl-tutorial.html)

To determine the compile-time arguments needed for the curl header, enter

```
curl-config --cflags
```

On my system, the curl header file is in the default search path.

For the library directive needed to link libcurl, enter

```
curl-config --libs
```

On my system, the library specification is

```
-L/usr/lib/x86_64-linux-gun -lcurl
```

This project uses the Boost Unit Test Framework for testing.
Install the UTF with:

```
sudo apt-get install libboost-test-dev
```

The makefile can be used to build and test the library.

```
make      # default target is "all", which compiles the code and creates or updates the library.
make test # 
```
