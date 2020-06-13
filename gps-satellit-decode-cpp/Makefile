executable: ChipService.o CalculationService.o GpsDecodingService.o main.o
	g++ ChipService.o CalculationService.o GpsDecodingService.o main.o -o executable
	rm *.o

main.o: main.cpp
	g++ -c main.cpp

CalculationService.o: CalculationService.cpp
	g++ -c CalculationService.cpp

GpsDecodingService.o: GpsDecodingService.cpp
	g++ -c GpsDecodingService.cpp

ChipService.o: ChipService.cpp
	g++ -c ChipService.cpp

clean: 
	rm *.o executable