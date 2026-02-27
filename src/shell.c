#include "../include/shell.h"

char *get_command(void)
{
    char *cmd = malloc(strlen(input_string) + 1);
    if (!cmd)
        return NULL;

    int i = 0;
    while (input_string[i] != ' ' && input_string[i] != '\0')
    {
        cmd[i] = input_string[i];
        i++;
    }
    cmd[i] = '\0';

    return cmd;
}

int check_command_type(char *command)
{
    if (strcmp(command, "cd") == 0 ||
        strcmp(command, "pwd") == 0 ||
        strcmp(command, "exit") == 0 ||
        strcmp(command, "echo") == 0)
        return 1;

    return 0;
}

void execute_internal_commands(char *cmd)
{
    if (strcmp(cmd, "exit") == 0)
    {
        exit(0);
    }
    else if (strcmp(cmd, "pwd") == 0)
    {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            printf("%s\n", cwd);
    }
    else if (strcmp(cmd, "cd") == 0)
    {
        char *dir = strtok(input_string + 3, " ");
        if (dir == NULL)
            dir = getenv("HOME");

        if (chdir(dir) != 0)
            perror("cd failed");
    }
    else if (strcmp(cmd, "echo") == 0)
    {
        printf("%s\n", input_string + 5);
    }
}

void scan_input(void)
{
    while (1)
    {
        printf("%s ", prompt_string);
        fflush(stdout);

        if (fgets(input_string, sizeof(input_string), stdin) == NULL)
            continue;

        input_string[strcspn(input_string, "\n")] = '\0';

        if (strlen(input_string) == 0)
            continue;

        char *cmd = get_command();
        int type = check_command_type(cmd);

        if (type == 1)
        {
            execute_internal_commands(cmd);
        }
        else
        {
            pid_t pid = fork();

            if (pid == 0)
            {
                char *argv[MAX_ARGS];
                int i = 0;

                char *token = strtok(input_string, " ");
                while (token != NULL && i < MAX_ARGS - 1)
                {
                    argv[i++] = token;
                    token = strtok(NULL, " ");
                }
                argv[i] = NULL;

                execvp(argv[0], argv);
                perror("exec failed");
                exit(1);
            }
            else
            {
                waitpid(pid, &status, 0);
            }
        }

        free(cmd);
    }
}