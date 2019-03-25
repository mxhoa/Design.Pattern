CC = g++
CFLAGS = -std=c++11

default: weatherStation

weatherStation: main.o Client.o WeatherData.o
	$(CC) $(CFLAGS) -o weatherStation main.o Client.o WeatherData.o

main.o: main.cpp Client.h WeatherData.h
	$(CC) $(CFLAGS) -c main.cpp
	
WeatherData.o: WeatherData.cpp WeatherData.h Client.h
	$(CC) $(CFLAGS) -c WeatherData.cpp

Client.o: Client.cpp Client.h
	$(CC) $(CFLAGS) -c Client.cpp 

clean:
	$(RM) weatherStation *.o *~