a.out:
	gcc -g add.c dice.c people.h search_ppl_or_city.c sort.c main.c
clean:
	rm a.out *.o