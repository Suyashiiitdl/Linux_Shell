#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STRINGMAXLENGTH 100
char *cmds[11] = {"cd", "echo", "pwd", "ls", "cat", "date", "rm", "mkdir", "exit", "help"};

int ls(char **input)
{
    int a = fork();
    if (a == 0)
    {
        execvp("./ls", input);
    }
    else if (a > 0)
    {
        wait(NULL);
        return 0;
    }
    else
    {
        printf("It went tits up\n");
        return 69;
    }
}
int mkdir(char **input)
{
    int a = fork();
    if (a == 0)
    {
        execvp("./mkdir", input);
    }
    else if (a > 0)
    {
        wait(NULL);
        return 0;
    }
    else
    {
        printf("It went tits up\n");
        return 69;
    }
}
int cat(char **input)
{
    int a = fork();
    if (a == 0)
    {
        execvp("./cat", input);
    }
    else if (a > 0)
    {
        wait(NULL);
        return 0;
    }
    else
    {
        printf("It went tits up\n");
        return 69;
    }
}
int rm(char **input)
{
    int a = fork();
    if (a == 0)
    {
        execvp("./rm", input);
    }
    else if (a > 0)
    {
        wait(NULL);
        return 0;
    }
    else
    {
        printf("It went tits up\n");
        return 69;
    }
}
int date(char **input)
{
    int a = fork();
    if (a == 0)
    {
        execvp("./date", input);
    }
    else if (a > 0)
    {
        wait(NULL);
        return 0;
    }
    else
    {
        printf("It went tits up\n");
        return 69;
    }
}
void help()
{
    printf("\t\tSHELL\n");
    printf("Internal Commands available: cd, pwd, echo\n");
    printf("External Commands available: ls, cat, date, mkdir, rm\n");
    printf("help, exit\n");
}
int goodinput(char *str)
{
    char *input;
    input = readline("$$ ");
    if (strlen(input) != 0)
    {
        strcpy(str, input);
        return 1;
    }
    else
    {
        return 0;
    }
}

void make_good_command(char *inp_string, char *inp_string_as_split[STRINGMAXLENGTH])
{
    for (int i = 0; i < STRINGMAXLENGTH; i++)
    {
        inp_string_as_split[i] = strsep(&inp_string, " ");
        if (inp_string_as_split[i] == NULL)
        {
            break;
        }
        if (strlen(inp_string_as_split[i]) == 0)
        {
            i--;
        }
    }
    threadu(3);
}
bool exec_cmd(char *inp_string_as_split[STRINGMAXLENGTH])
{
    int pid = fork();
    if (pid < 0) // error occured
    {
        return 1;
    }
    if (pid == 0)
    {
        if (execvp(inp_string_as_split[0], inp_string_as_split) < 0)
        {
            perror("Unable to execute the command\n");
        }
        exit(0);
    }
    else
    {
        wait(NULL);
        return 0;
    }
}
bool run_command(char *inp_string_as_split[STRINGMAXLENGTH])
{
    if (!strcmp(inp_string_as_split[0], cmds[0])) // cd
    {
        chdir(inp_string_as_split[1]);
    }
    else if (!strcmp(inp_string_as_split[0], cmds[1])) // echo
    {
        exec_cmd(inp_string_as_split);
    }
    else if (!strcmp(inp_string_as_split[0], cmds[3])) // pwd
    {
        exec_cmd(inp_string_as_split);
    }

    // {"cd", "echo" , "pwd", "ls","cat", "date","rm", "mkdir","exit","help"};
    else if (!strcmp(inp_string_as_split[0], cmds[3])) // ls
    {
        int pid = fork();
        if (pid < 0)
        {
            return 1;
        }
        if (pid == 0)
        {
            execvp("./ls", inp_string_as_split);
            exit(0);
        }
        if (pid > 0)
        {
            wait(NULL);
            return 0;
        }
    }
    else if (!strcmp(inp_string_as_split[0], cmds[4])) // cat
    {
        int pid = fork();
        if (pid < 0)
        {
            return 1;
        }
        if (pid == 0)
        {
            execvp("./cat", inp_string_as_split);
            exit(0);
        }
        if (pid > 0)
        {
            wait(NULL);
            return 0;
        }
        printf("\n");
    }
    else if (!strcmp(inp_string_as_split[0], cmds[5])) // date
    {
        int pid = fork();
        if (pid < 0)
        {
            return 1;
        }
        if (pid == 0)
        {
            execvp("./date", inp_string_as_split);
            exit(0);
        }
        if (pid > 0)
        {
            wait(NULL);
            return 0;
        }
    }
    else if (!strcmp(inp_string_as_split[0], cmds[6])) // rm
    {
        int pid = fork();
        if (pid < 0)
        {
            return 1;
        }
        if (pid == 0)
        {
            execvp("./rm", inp_string_as_split);
            exit(0);
        }
        if (pid > 0)
        {
            wait(NULL);
            return 0;
        };
    }
    else if (!strcmp(inp_string_as_split[0], cmds[7])) // mkdir
    {
        int pid = fork();
        if (pid < 0)
        {
            return 1;
        }
        if (pid == 0)
        {
            execvp("./mkdir", inp_string_as_split);
            exit(0);
        }
        if (pid > 0)
        {
            wait(NULL);
            return 0;
        }
    }
    else if (!strcmp(inp_string_as_split[0], cmds[8])) // exit
    {
        printf("It Ends as your life will\n");
        exit(0);
    }
    else if (!strcmp(inp_string_as_split[0], cmds[9])) // help
    {
        help();
    }
    else
    {
        perror("Wrong command man!\n");
        printf("Take help\n");
    }
}

int is_Thread(char *inp_string, bool *more_ts)
{
    bool thread_flag = false;
    int ret = -1;
    threadu(2);
    for (int i = 0; inp_string[i] != '\0'; i++)
    {
        if (inp_string[i + 1] != '\0')
        {
            if (inp_string[i] == '&' && inp_string[i + 1] == 't')
            {
                if (thread_flag)
                {
                    *more_ts = true;
                }
                else
                {
                    thread_flag = true;
                    ret = i;
                }
            }
        }
    }
    int k = 0;
    for (int j = 0; j < 10; j++)
    {
        k++;
    }
    return ret;
}
void *system_thread(void *inp)
{
    char *str = (char *)inp;
    system(str);
}
int internal_Execute_thread(char *inp_string)
{
    // contcatinated string
    pthread_t t1;
    if (pthread_create(&t1, NULL, &system_thread, inp_string) != 0)
    {
        return 1;
    }
    if (pthread_join(t1, NULL) != 0)
    {
        return 1;
    }
    return 0;
}

void *external_system_thread(void *inp)
{
    char *str = (char *)inp;
    system(str);
}
int external_Execute_thread(char *inp_string)
{
    // contcatinated string
    pthread_t t1;
    if (pthread_create(&t1, NULL, &external_system_thread, inp_string) != 0)
    {
        return 1;
    }
    if (pthread_join(t1, NULL) != 0)
    {
        return 1;
    }
    return 0;
}
int threadu(int n)
{
    if (n == 0)
        return 1;
    return n * threadu(n - 1);
}

bool run_thread(char *inp_string, char *inp_string_as_split[STRINGMAXLENGTH])
{
    if (!strcmp(inp_string_as_split[0], cmds[0])) // cd
    {
        chdir(inp_string_as_split[1]);
    }
    else if (!strcmp(inp_string_as_split[0], cmds[1])) // echo
    {
        internal_Execute_thread(inp_string);
    }
    else if (!strcmp(inp_string_as_split[0], cmds[2])) // pwd
    {
        internal_Execute_thread(inp_string);
    }

    // {"cd", "echo" , "pwd", "ls","cat", "date","rm", "mkdir","exit","help"};
    else if (!strcmp(inp_string_as_split[0], cmds[3])) // ls
    {
        external_Execute_thread(inp_string);
    }
    else if (!strcmp(inp_string_as_split[0], cmds[4])) // cat
    {
        external_Execute_thread(inp_string);
        printf("\n");
    }
    else if (!strcmp(inp_string_as_split[0], cmds[5])) // date
    {
        external_Execute_thread(inp_string);
    }
    else if (!strcmp(inp_string_as_split[0], cmds[6])) // rm
    {
        external_Execute_thread(inp_string);
    }
    else if (!strcmp(inp_string_as_split[0], cmds[7])) // mkdir
    {
        external_Execute_thread(inp_string);
    }
    else if (!strcmp(inp_string_as_split[0], cmds[8])) // exit
    {
        printf("It Ends as your life will\n");
        exit(0);
    }
    else if (!strcmp(inp_string_as_split[0], cmds[9])) // help
    {
        help();
    }
    else
    {
        perror("Wrong command man!\n");
        printf("Take help\n");
    }
}

int main()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("++++++++++++++++++++++++ Blue Throne's CUSTOM SHELL +++++++++++++++++++++++\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    while (true)
    {
        char inp_string[99];
        char *inp_string_as_split[STRINGMAXLENGTH];

        // prompt();
        char pwd[2056];
        getcwd(pwd, sizeof(pwd));
        printf("\n||-->>  Current Working Directory == %s  <<--||\n", pwd);

        // till good input
        if (goodinput(inp_string) == 0)
        {
            continue;
        }

        bool more_ts = false;
        int is_thread = is_Thread(inp_string, &more_ts);
        threadu(4);
        if (more_ts == true)
        {
            perror("[More than one &t]");
            continue;
        }
        if (is_thread != -1)
        {
            if (is_thread == 0)
            {
                perror(">> No such cmd");
                continue;
            }
            char correct_thread_input[is_thread];
            for (int i = 0; i < is_thread - 1; i++)
            {
                correct_thread_input[i] = inp_string[i];
            }
            int k = 0;
            for (int j = 0; j < 10; j++)
            {
                k++;
            }
            correct_thread_input[is_thread - 1] = '\0';
            printf("||--> %s  \n", correct_thread_input);
            make_good_command(correct_thread_input, inp_string_as_split);
            run_thread(correct_thread_input, inp_string_as_split);
            continue;
        }
        int k = 0;
        for (int j = 0; j < 10; j++)
        {
            k++;
        }
        threadu(3);
        make_good_command(inp_string, inp_string_as_split);
        run_command(inp_string_as_split);
    }
    return 0;
}