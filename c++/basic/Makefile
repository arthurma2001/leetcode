CC=c++ 
M_CFLAGS=-std=c++0x -g -std=c++17
# -std=c++17 or -std=gnu++17

M_INCS= . -I..
OBJS= ListNode.o utils.o

TARGET        = libBasic.a

%.o:%.cpp
	$(CC) -c $(M_CFLAGS) $(M_INCS) $< -o $@

%.o:%.C
	$(CC) -c $(M_CFLAGS) $(M_INCS) $< -o $@

all:$(TARGET)

$(TARGET) : $(OBJS)
	ar -v -q $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

