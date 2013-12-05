GPP = g++ -O3 -Wall

UTILS = Utilities
SCANNER = Utilities
SCANLINE = Utilities
TIMER = Utilities

M = Main.o
DS = DoStuff.o
FI = FileIterator.o
TS = Templates.o
T = Template.o
SL = ScanLine.o
S = Scanner.o
U = Utils.o
# TI = Timer.o

#FaceRecognition: $(M) $(DS) $(FI) $(TS) $(T) $(SL) $(S) $(U)
#	$(GPP) -o FaceRecognition $(M) $(DS) $(FI) $(SL) $(S) $(U) $(TAIL)

# FaceRecognition: $(M) $(DS) $(FI) $(TS) $(T) $(SL) $(S) $(U) $(TI) $(THR)
# 	$(GPP) -o FaceRecognition $(M) $(DS) $(FI) $(TS) $(T) $(SL) $(S) $(U) $(TI) $(THR) $(TAIL)

FaceRecognition: $(M) $(DS) $(FI) $(TS) $(T) $(SL) $(S) $(U)
	$(GPP) -o FaceRecognition $(M) $(DS) $(FI) $(TS) $(T) $(SL) $(S) $(U) $(TAIL)

Main.o: Main.h Main.cpp
	$(GPP) -o Main.o -c Main.cpp

DoStuff.o: DoStuff.h DoStuff.cpp
	$(GPP) -o DoStuff.o -c DoStuff.cpp

FileIterator.o: FileIterator.h FileIterator.cpp
	$(GPP) -o FileIterator.o -c FileIterator.cpp

Templates.o: Templates.h Templates.cpp
	$(GPP) -o Templates.o -c Templates.cpp

Template.o: Template.h Template.cpp
	$(GPP) -o Template.o -c Template.cpp

ScanLine.o: $(SCANLINE)/ScanLine.h $(SCANLINE)/ScanLine.cpp
	$(GPP) -o ScanLine.o -c $(SCANLINE)/ScanLine.cpp

Scanner.o: $(SCANNER)/Scanner.h $(SCANNER)/Scanner.cpp
	$(GPP) -o Scanner.o -c $(SCANNER)/Scanner.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -o Utils.o -c $(UTILS)/Utils.cpp

# Timer.o: $(TIMER)/Timer.h $(TIMER)/Timer.cpp
# 	$(GPP) -o Timer.o -c $(TIMER)/Timer.cpp
clean:
	rm *.o
	rm FaceRecognition
	

