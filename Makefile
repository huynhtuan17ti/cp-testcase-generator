CXXFLAGS = -std=c++17
OBJDIR = obj
TEMP = temp

OBJ_RUN = $(OBJDIR)/run.o
OBJ_RAND = $(OBJDIR)/gen.o

all: gentest

gentest: $(OBJ_RUN)
	mkdir -p $(OBJDIR)
	$(CXX) $(OBJ_RUN) -o gentest

$(OBJDIR)/random.o:
	mkdir -p $(OBJDIR)
	$(CXX) -g -c $(CXXFLAGS) rand.cpp

$(OBJDIR)/%.o: run.cpp
	mkdir -p $(OBJDIR)
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm $(OBJDIR)/* gentest

install:
	sudo mkdir -p /usr/bin/gen_temp
	sudo cp $(TEMP)/rand.cpp  /usr/bin/gen_temp/rand.cpp
	sudo cp $(TEMP)/random.h  /usr/bin/gen_temp/random.h
	sudo cp gentest /usr/bin/

uninstall:
	sudo rm /usr/bin/gentest
	sudo rm -r /usr/bin/gen_temp