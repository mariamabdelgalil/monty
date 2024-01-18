#include "monty.h"
MontyController monty_controller;
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	int fd;

        if (argc != 2)
        {
            fprintf(stderr, "USAGE: monty file\n");
            exit(EXIT_FAILURE);
        }

        fd = open(argv[1], O_RDONLY);
        if (fd == -1) {
            fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        init_controller(fd);
        execute_controller_flow();
/*// Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }*/
	close(monty_controller.current_context.monty_file_descriptor);
    free_stack(monty_controller.monty_stack);
            free(monty_controller.current_context.line_content);


return (0);
}

