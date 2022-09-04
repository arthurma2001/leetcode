CC=c++ 
M_CFLAGS=-std=c++0x -g -std=c++17
# -std=c++17 or -std=gnu++17

M_INCS= . -I..
OBJS= main.o testMain.o 399.o \
   1.o 3.o 11.o 15.o 22.o

App=test

%.o:%.cpp
	$(CC) -c $(M_CFLAGS) $(M_INCS) $< -o $@

%.o:%.C
	$(CC) -c $(M_CFLAGS) $(M_INCS) $< -o $@

all:$(App)
$(App) : $(OBJS)
	$(CC) $(OBJS)  -lstdc++  -o $(App)
clean:
	rm -f $(OBJS)
	rm -f $(App)

