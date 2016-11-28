CC = g++

all: main
OBJS = main.o module.o
main: $(OBJS)
	$(CC) $(OBJS) -o main
# .o 依赖于.c make会自动推导
# 所以一般情况下只要写清楚 .o文件 对于.h文件的依赖就可以了。
# command 部分也可以直接省略
main.o: module.h

.PHONY: clean
clean:
	rm $(OBJS)
	rm main.exe
