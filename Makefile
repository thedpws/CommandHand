CC = g++
CFLAGS = -g -Wall
SRCS = main.cpp
PROG = cmdhand.exe

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = C:\Users\azvas\Documents\opencv2\opencv\sources\include\opencv2

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
