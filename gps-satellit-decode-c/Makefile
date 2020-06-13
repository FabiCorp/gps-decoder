executable: ChipService.o CalculationService.o GpsDecodingService.o main.o
	gcc ChipService.o CalculationService.o GpsDecodingService.o main.o -o executable
	rm *.o

main.o: main.c
	gcc -c main.c

CalculationService.o: CalculationService.c
	gcc -c CalculationService.c

GpsDecodingService.o: GpsDecodingService.c
	gcc -c GpsDecodingService.c

ChipService.o: ChipService.c
	gcc -c ChipService.c

clean: 
	rm *.o executable