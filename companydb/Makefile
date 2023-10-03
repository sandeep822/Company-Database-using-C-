# Build Options
CXX=clang++
CXXFLAGS=-g

BIN=companydb

# targets
all: $(BIN)

companydb: companydb.o Company.o Customer.o Employee.o Person.o Purchase.o
	$(CXX) $(CXXFLAGS) -o $@ $^

#meta-target
clean:
	rm -f $(BIN) *.o
