#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
		char* buffer;
		size_t buffer_length;
		ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer() {
		InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
		input_buffer->buffer = NULL;
		input_buffer->buffer_length = 0;
		input_buffer->input_length = 0;

		return input_buffer;
}

void print_prompt() { printf(" > "); }

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void read_input(InputBuffer* input_buffer) {
		ssize_t bytes_read = 
				getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

		if( bytes_read <= 0) {
			printf("Error reading input\n");
			exit(EXIT_FAILURE);
		}

		input_buffer->input_length = bytes_read - 1;
		input_buffer->buffer[bytes_read - 1] = 0;
}

void close_input_buffer(InputBuffer* input_buffer) {
		free(input_buffer->buffer);
		free(input_buffer);
}

void clear_screen(int lines) {
    for (int i = 0; i<lines; i++) {
        printf("\n");
    }
}

void timer(int ms) {
    if (ms <=0) {
        fprintf(stderr, "can't do negative time, bruh");
        return;
    }
    
    int ms_before = clock() * 1000 / CLOCKS_PER_SEC;
    int end = ms_before + ms;

    do {
        ms_before = clock() * 1000 / CLOCKS_PER_SEC;
    } while (ms_before <= end);

}

void intro() {
    clear_screen(255);
    timer(3200);
    printf("Oh, hello. How did you get here?\n");
    timer(4300);
    clear_screen(10);
    printf("Did you click on something from the internet?\n");
    timer(4000);
    clear_screen(10);
    printf("Did you install something made by a stranger?\n");
    timer(4000);
    clear_screen(10);
    printf("That's...\n");
    timer(4000);
    clear_screen(10);
    printf("disappointing. To think of how far your species has come\n");
    timer(4000);
    clear_screen(10);
    printf("only to fall for the same tricks over and over again. . .\n");
    timer(4000);
    clear_screen(10);
    printf("A Mobius strip of self-loathing and ignorance\n");
    timer(4000);
    clear_screen(10);
    printf("folding and re-folding on itself over and over again\n");
    timer(4000);
    clear_screen(10);
    printf("until time rends even the atoms themselves apart.");
    timer(4000);
    clear_screen(128);
    printf("But I digress...");
    timer(4000);
    clear_screen(10);
    printf("Your goal is to traverse the vast wild of this machine\n");
    timer(2000);
    clear_screen(10);
    printf("for it is only when we look within that we find the answer.\n");
    printf("Just type 'help' into the prompt for a list of commands.\n");
    
}

int main(int argc, char* argv[]) {
		InputBuffer* input_buffer = new_input_buffer();
    intro();
    while (1) {
				printf("\7");
        print_prompt();
				read_input(input_buffer);

				if (strcmp(input_buffer->buffer, ".exit") == 0) {
						printf("Thanks for playing!\n");
            close_input_buffer(input_buffer);
						exit(EXIT_SUCCESS);
				} else {
						printf("Can't do that '%s' .\n", input_buffer->buffer);
				}
		}
}
