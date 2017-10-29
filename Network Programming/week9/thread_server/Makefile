SOURCES=$(shell find . -type f -iname '*.c')
TARGET=201511304_server.out

all: $(TARGET)

$(TARGET): $(SOURCES)
	gcc $(SOURCES) -o $(TARGET) -W -Wall -Wno-unused-parameter -lpthread

clean:
	rm -f $(TARGET)
