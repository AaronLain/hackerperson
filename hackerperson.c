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

void print_prompt() { printf(" >>> "); }

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
    printf("Oh, hello. How did you get in here?\n");
    timer(4300);
    clear_screen(10);
    printf("You didn't come from GitHub, did you?\n");
    timer(4200);
    clear_screen(10);
    printf("So you just installed something made by a stranger. From the Internet.\n");
    timer(4200);
    clear_screen(10);
    printf("And in C, no less. Do you know how dangerous that is?\n");
    timer(4300);
    clear_screen(10);
    printf("You must really reeaaallllly trust whoever made this.\n");
    timer(4200);
    clear_screen(10);
    printf("Anyway, poor choices aside, it is a relief to see you.\n");
    timer(4300);
    clear_screen(10);
    printf("We have a bit of a situation:\n");
    timer(4200);
    clear_screen(10);
    printf("Zero Cool says that your...BLT drive just went AWOL...\n");
    timer(4300);
    clear_screen(10);
    printf("and we can't seem to find it anywhere.\n");
    timer(4200);
    clear_screen(10);
    printf("Also, someone named 'Acid Burn' said they've corrupted your task manager?\n");
    timer(4300);
    clear_screen(10);
    printf("We don't know what that means, either.\n");
    timer(4200);
    clear_screen(10);
    printf("Look, we're useless. You're going to have to fix this yourself.\n");
    timer(4300);
    clear_screen(10);
    printf("Think of it as a spiritual exercise. . . something about looking within.\n");
    timer(4200);
    clear_screen(10);
    printf("Just type 'help()' into the prompt for a list of functions. Good Luck!\n");
}

void help_menu() {
    clear_screen(100);
    printf("inspect(obj): look and/or inspect and object (obj) with your eyes and/or ear balls.\n\n");
    printf("poke(obj): poke an object (obj), make sure you have permission!\n\n");
    printf("use(obj): use an object (obj), that can mean whatever.\n\n");
    printf("sing(obj): sing at an object (obj), this is not recommended.\n\n");
    printf("kick(obj): like Fonz-kicking-the-jukebox style not American-History-X style.\n\n");
    printf("introspect(): sometimes one must look within. \n\n");
    printf("compliment(obj): compliment an object (obj) if you wanna get things done.\n\n");
}

int main(int argc, char* argv[]) {
		InputBuffer* input_buffer = new_input_buffer();
    intro();
    while (1) {
        print_prompt();
        read_input(input_buffer);
        
        if (strcmp(input_buffer->buffer, "exit()") == 0) {
            printf("Thanks for playing!\n");
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else if (strcmp(input_buffer->buffer, "help()") == 0) {
            help_menu();
        } else if (strcmp(input_buffer->buffer, "exit") == 0) {
            printf("If you want to leave, try the function exit()");
        } else {
            printf("Can't do that '%s' .\n", input_buffer->buffer);
        }
    }
}
