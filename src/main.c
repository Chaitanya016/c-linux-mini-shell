	#include "../include/shell.h"

char input_string[MAX_INPUT];
char prompt_string[64] = "minishell:~$";
int status;

int main(void)
{
    scan_input();
    return 0;
}
