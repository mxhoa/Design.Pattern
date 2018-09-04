CC = g++
CFLAGS = -std=c++11

default: document_framework

document_framework: main.o MyApplication.o Application.o Document.o MyDocument.o
	$(CC) $(CFLAGS) -o document_framework main.o MyApplication.o Application.o Document.o MyDocument.o

main.o: main.cpp MyApplication.h
	$(CC) $(CFLAGS) -c main.cpp 

MyApplication.o: MyApplication.cpp MyApplication.h Document.h MyDocument.h
	$(CC) $(CFLAGS) -c MyApplication.cpp

Application.o: Application.cpp Application.h Document.h
	$(CC) $(CFLAGS) -c Application.cpp

MyDocument.o: MyDocument.cpp MyDocument.h Document.h
	$(CC) $(CFLAGS) -c MyDocument.cpp 

Document.o: Document.cpp Document.h
	$(CC) $(CFLAGS) -c Document.cpp

clean:
	$(RM) document_framework *.o *~

