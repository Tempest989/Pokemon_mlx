NAME = Text_Pokemon

SRCS = Battle.c Moves.c Pokemon.c stageMulti.c Trainer.c Turns.c weakness.c main.c

all:		$(NAME)

$(NAME):	$(SRCS)
		gcc $(SRCS) -o $(NAME)

run:		all
		./$(NAME)

rm:
		rm $(NAME)

.PHONY:		all run