all: const noconst testapp

const: test.cpp
	g++ -DDOCONSTPLZ -fPIC -c test.cpp -o testconst.o
	g++ -shared -Wl,-soname,libtestconst.so -o libtestconst.so testconst.o

noconst: test.cpp
	g++ -fPIC -c test.cpp -o testnoconst.o
	g++ -shared -Wl,-soname,libtestnoconst.so -o libtestnoconst.so testnoconst.o

testapp: main.cpp
	g++ -DDOCONSTPLZ -o testconst -ltestconst -I. -L. main.cpp
	g++ -o testnoconst -ltestconst -I. -L. main.cpp

clean:
	rm -rf *.o *.so testconst testnoconst
