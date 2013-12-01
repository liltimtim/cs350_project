GPP = g++ -O3 -Wall

UTILS = Utilities
SCANNER = Utilities
SCANLINE = Utilities

M = Main.o
STOP = StopWords.o
P = ParseText.o
DOC = Document.o
SL = ScanLine.o
S = Scanner.o
U = Utils.o

Aprog: $(M) $(SL) $(S) $(U)
	$(GPP) -o Aprog $(M)  $(SL) $(S) $(U) $(TAIL)

Main.o: Main.h Main.cpp
	$(GPP) -o Main.o -c Main.cpp

ScanLine.o: $(SCANLINE)/ScanLine.h $(SCANLINE)/ScanLine.cpp
	$(GPP) -o ScanLine.o -c $(SCANLINE)/ScanLine.cpp

Scanner.o: $(SCANNER)/Scanner.h $(SCANNER)/Scanner.cpp
	$(GPP) -o Scanner.o -c $(SCANNER)/Scanner.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -o Utils.o -c $(UTILS)/Utils.cpp

clean:
	rm Aprog
	rm *.o
	

