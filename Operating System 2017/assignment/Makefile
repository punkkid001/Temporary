TARGET= third

all: $(TARGET)

% :%.c
	gcc $< -o $@
	cp $@ fc
	@echo -------------$@--------------
	echo ls -l + ps + who | ./fc
