
all:
	clear
	@echo "compil : "
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 main.c get_next_line.c get_next_line_utils.c
	@echo "done"
	@echo "exec :"
	./a.out

debug:
	clear
	@echo "compil : "
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=32 main.c get_next_line.c get_next_line_utils.c
	@echo "done"
	@echo "debug :"
	lldb ./a.out
