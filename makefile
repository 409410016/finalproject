all:
	make test
test: main.c add.o dice.o search_ppl_or_city.o sort.o
	gcc -g -o test main.c add.o dice.o search_ppl_or_city.o sort.o
add.o: add.c people.h
	gcc -g -c add.c people.h
dice.o: dice.c people.h
	gcc -g -c dice.c people.h
search_ppl_or_city.o:search_ppl_or_city.c people.h 
	gcc -g -c search_ppl_or_city.c people.h 
sort.o:sort.c people.h
	gcc -g  -c sort.c people.h
clean:
	rm test *.o