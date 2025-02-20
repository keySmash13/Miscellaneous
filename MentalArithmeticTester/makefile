compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

ProjectOne : ProjectOne.o
	$(link) $^ -o $@
	./$@

ProjectOne.o : ProjectOne.cc ProjectOne.h
	$(compile) $<

clean :
	rm *.o ProjectOne