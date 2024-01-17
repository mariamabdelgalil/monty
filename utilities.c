#include "monty.h"
/**
 * readline - Read a line from a stream.
 * @lineptr: Pointer to the buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 * @stream: File descriptor for the stream to read from.
 *
 * Description: Reads a line from the specified stream into the buffer pointed
 * to by lineptr. If lineptr is NULL or n is 0, a new buffer is allocated.
 * The buffer is reallocated if its size is not sufficient.
 *
 * Return: The number of characters read, or -1 on failure.
 */
ssize_t readline(char **lineptr, size_t *n, int stream)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index, buffer_size;
	size_t size = 0, old_size, i;
	char c;

	if (!lineptr || !n)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 256, *lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
		for (i = 0; i < *n; i++)
			(*lineptr)[i] = '\0';
	}
	while (1)
	{
		if (buffer_index >= buffer_size)
		{
			buffer_size = read(stream, buffer, BUFFER_SIZE);
			if (buffer_size <= 0)
				break;
			buffer_index = 0;
		}
		c = buffer[buffer_index++];
		if (size + 1 >= *n)
		{
			old_size = *n, *n *= 2;
			*lineptr = (char *)_realloc(*lineptr, old_size, *n);
			for (i = old_size; i < *n; i++)
				(*lineptr)[i] = '\0';
		}
		(*lineptr)[size++] = c;
		if (c == '\n' || c == EOF)
			break;
	}
	if (size == 0 || c == EOF)
		return (-1);
	(*lineptr)[size] = '\0', *n = size;
	return (size);
}


/**
 * _realloc - Reallocate memory block
 * @ptr: Pointer to the previously allocated memory block.
 * @old_size: Size of the old memory block.
 * @new_size: Size of the new memory block.
 *
 * Description: Reallocates a memory block. If @ptr is NULL, works like malloc.
 * If @new_size is 0,works like free.If reallocation fails, the original block
 * is unchanged.
 *
 * Return: Pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (new_ptr);
}

/**
 * init_controller - init data of monty controller
 * @monty_file_descriptor: file descriptor of input monty file to the run.
 * Description: Initialize the data in the controller that is responsible
 * for controlling flow of the monty program
 * Return: Void
 */
void init_controller(int monty_file_descriptor)
{
    monty_controller.monty_stack = NULL;
    monty_controller.current_context.current_arg = NULL;
    monty_controller.current_context.operation = NULL;
    monty_controller.current_context.line_content = NULL;
    monty_controller.current_context.line_number = 0;
    monty_controller.current_context.line_size = 0;
    monty_controller.current_context.monty_file_descriptor = monty_file_descriptor;
    monty_controller.current_context.readline = 1;
    monty_controller.current_context.stack_or_queue = STACK_FLAG;
}

/**
 * exit_program - do necessary work before closing program
 * Return: Void
 */
void exit_program()
{
    close(monty_controller.current_context.monty_file_descriptor);
    free(monty_controller.current_context.line_content);
    free_stack(monty_controller.monty_stack);
    exit(EXIT_FAILURE);
}

