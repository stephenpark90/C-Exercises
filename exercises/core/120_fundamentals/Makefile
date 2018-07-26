.PHONY: all
all: answer
	@./answer $(flag)

.PHONY: answer
answer: 
	@gcc -std=gnu99 -Wall -s -lm -lcrypto -DNDEBUG answer.c -o answer

.PHONY: debug
debug: answer.c
	@gcc -std=gnu99 -Wall -s -lm -lcrypto -DDEBUG answer.c -o answer

solution: solution.c
	@gcc -std=gnu99 -Wall solution.c -o solution

test: answer solution
ifeq ($(tv),)
	@./publish.sh -tv
else
	@./solution
endif

publish: answer
ifeq ($(m),)
	@./publish.sh
else
	@./publish.sh -m "$(m)"
endif

clean:
	@rm -rf program solution answer
