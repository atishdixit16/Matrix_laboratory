CC=g++
DEPS= CMatrix.h
TARGET= CMatrix
OBJS= CMatrix_basic_methods.o main.o CMatrix_op_ovld.o CMatrix_adv_methods.o

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm *.o

cleanAll:
	rm *.o $(TARGET)
