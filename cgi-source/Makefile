# executables
CC=gcc
CXX=g++

OBJDIR=./obj/
OUTDIR=../cgi-bin/
TARGET=$(OUTDIR)timer.cgi

INCDIRS=
CXXFLAGS=-Wall -Os $(INCDIRS)
CFLAGS=-Wall -Os $(INCDIRS)

LDFLAGS=
LDLIBS=-lwiringPi

SOURCES=$(wildcard *.cpp)
SOURCES+=$(wildcard ./http/*.cpp)
SOURCES+=$(wildcard ./util/*.cpp)
HEADERS=$(wildcard *.h)
HEADERS+=$(wildcard ./http/*.h)
HEADERS+=$(wildcard ./util/*.h)

OBJECTS=$(addprefix $(OBJDIR),$(SOURCES:.cpp=.o))
COBJECTS=$(CSOURCES:.c=.o)

$(OBJDIR)%.o: %.cpp $(HEADERS) Makefile
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) -c -o $@ $<;

$(TARGET): $(OBJECTS) $(COBJECTS)
	@mkdir -p $(@D)
	@echo "Linking $@"
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@


.PHONY: all clean install

all: $(TARGET)

install:
	sudo cp $(TARGET) /var/www/cgi-bin
	sudo chmod u+s /var/www/cgi-bin/$(TARGET)
	sudo cp ../ui/*.html /var/www/html
	sudo cp ../ui/js/* /var/www/html/js
	sudo cp ../ui/css/* /var/www/html/css

clean:
	rm -rf $(OBJDIR) $(TARGET)

kunga: clean $(TARGET) install