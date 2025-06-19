.PHONY: clean

app: main.o class.o csvReaderWriter.o generateData.o
	g++ -o app main.o class.o csvReaderWriter.o generateData.o

main.o: main.cpp class.h csvReaderWriter.h algs.h generateData.h
	g++ -c main.cpp

class.o: class.cpp class.h
	g++ -c class.cpp

csvReaderWriter.o: csvReaderWriter.cpp csvReaderWriter.h class.h
	g++ -c csvReaderWriter.cpp

generateData.o: generateData.cpp generateData.h class.h csvReaderWriter.h
	g++ -c generateData.cpp

clean:
	del /A : *.o 
