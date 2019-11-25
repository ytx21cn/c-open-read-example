read.out: read.c
	gcc -g -Wall -Werror $^ -o $@

.PHONY = clean
clean:
	rm *.out
