program: program.c
	@gcc -std=gnu99 -Wall program.c -o program

.PHONY: answer
answer: answer.c diameter radius
	@gcc -std=gnu99 -Wall -s -lcrypto answer.c -o answer

.PHONY: debug
debug: answer.c diameter radius
	@gcc -std=gnu99 -Wall -s -lcrypto -DDEBUG answer.c -o answer

flag: program diameter radius
	-@./answer 2>/dev/null || true
	@make -s clean

solution: solution.c sdiameter sradius answer
	@gcc -std=gnu99 -std=gnu99 -Wall -DPT -DAU -DAG solution.c -o solution

sdiameter: solution.c
	@gcc -std=gnu99 -Wall solution.c -o diameter

sradius: solution.c
	@gcc -std=gnu99 -Wall -DRADIUS solution.c -o radius

diameter: program.c
	@gcc -std=gnu99 -Wall program.c -o diameter

radius: program.c
	@gcc -std=gnu99 -Wall -DRADIUS program.c -o radius

test: solution
ifeq ($(tv),)
	@./publish.sh -tv
	@make -s clean
else
	-@./answer 2>/dev/null || true
	@make -s clean
endif

publish: solution
ifeq ($(m),)
	@./publish.sh
else
	@./publish.sh -m "$(m)"
endif

clean: 
	@rm -rf diameter sdiameter radius sradius
