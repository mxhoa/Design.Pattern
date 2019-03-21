CC = g++
CFLAGS = -std=c++11

default: rendererFactory

rendererFactory: RendererFactory.o 
	$(CC) $(CFLAGS) -o rendererFactory RendererFactory.o

RendererFactory.o: RendererFactory.cpp
	$(CC) $(CFLAGS) -c RendererFactory.cpp

clean:
	$(RM) rendererFactory *.o *~