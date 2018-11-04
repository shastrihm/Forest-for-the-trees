#Name: Hrishee Shastri.

CXX=g++-7
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17 
OPTFLAGS=-O3
LDFLAGS=$(CXXFLAGS) 
#$(OPTFLAGS)

all: test_htree test_hforest

# this is a "Suffix Rule" - how to create a .o from a .cpp file
.cpp.o:
	$(CXX) $(CCFLAGS) -c $<

test_htree: test_htree.o
	$(CXX) -o test_htree test_htree.o

test_hforest: test_hforest.o
	$(CXX) -o test_hforest test_hforest.o

clean:
	rm -f *.o
