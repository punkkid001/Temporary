TARGET= second

all : $(TARGET)

% :%.c
	gcc $< -o $@
	cp $@ pc
	@echo ---------$@-----------
	./$@
