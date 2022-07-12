.PHONY:	all run clean

NAME = Text_Pokemon

SRCS = Battle.c Moves.c Pokemon.c stageMulti.c Trainer.c Turns.c weakness.c main.c

all:		$(NAME)

$(NAME):	$(SRCS)
		gcc $(SRCS) -o $(NAME)

run:		all
		./$(NAME)

clean:
	@if [ -f "$(NAME)" ]; then\
		rm $(NAME);\
		printf "rm $(NAME)\n";\
	else\
		printf "$(NAME) Doesn't Exist so It Cannot Be Removed\n";\
	fi
