NAME = libaoc.a
EXE = exe.out
HEADER = Includes/aoc.h
UTILS = Utils/*.c
OBJECTS = *.o

run:
	@./a.out

1: fclean
	@gcc -g $(HEADER) $(UTILS) Sources/d1.c
	@echo "Compiled 'Day 1, Exercise 1 and 2'!"
	@./a.out

2e1:
	@gcc -g $(HEADER) $(UTILS) Sources/d2e1.c
	@echo "Compiled 'Day 2, Exercise 1'!"
	@./a.out

2e2:
	@gcc -g $(HEADER) $(UTILS) Sources/d2e2.c
	@echo "Compiled 'Day 2, Exercise 2'!"
	@./a.out

clean:
	@/bin/rm -f $(OBJECTS)
	@echo "Objects are gone!"

fclean: clean
	@/bin/rm -f $(NAME) a.out
	@echo "All clean!"

re: fclean run
.PHONY: run