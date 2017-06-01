TARGET=pthread pt_multi pt_num pt_param sock chat

all: $(TARGET)

%: %.c
    gcc $< -o $@ -pthread
    #@./$@
