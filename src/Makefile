

OBJS= uimain.o tokenizer.o history.o

#target
all: tokenizer

#file dependencies
tokenizer.o: tokenizer.h
history.o: history.h
uimain.o: tokenizer.h history.h 

tokenizer: $(OBJS)


clean:
	rm -f *.o uimain

run: tokenizer
	./tokenizer
