compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

MathTester : MathTester.o
	$(link) $^ -o $@
	./$@

MathTester.o : MathTester.cc MathTester.h
	$(compile) $<

clean :
	rm *.o MathTester