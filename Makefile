
assign1 : assign1.o
	g++ -o assign1 -Wall -Werror  -g assign1.o

assign1.o : assign1.cc
	g++ -c -Wall -Werror  -g assign1.cc

clean :
	-rm assign1 *.o

