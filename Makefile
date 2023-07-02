PUGI=pugixml/src/pugixml.o

all: parser

parser: $(PUGI)
	g++ parser.cpp $(PUGI) -o main 

pugi.o: pugixml/src/pugixml.cpp
	g++ -c pugixml/src/pugixml.cpp -o $(PUGI)
