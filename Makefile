HOST_SYSTEM = $(shell uname | cut -f 1 -d_)
SYSTEM ?= $(HOST_SYSTEM)
CXX = g++

all: digester

digester:
	$(CXX) src/c_tokenizer.c src/c_tokenizer.h src/SpookyV2.cpp src/SpookyV2.h src/proxysql.h src/main.cpp $(LDFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -rf *.o digester