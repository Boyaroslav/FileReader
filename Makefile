NAME = fr
install :
	gcc -o $(NAME) fr.c
	chmod +x ./$(NAME)
	mv ./$(NAME) /usr/bin/$(NAME)
