#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "prompt.c"
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "path.c"

#define delimiter " \n\t\r"
char st[1024][1024];
int idx;

void execute_cd(char **array)
{
	if (array[1] != NULL && strcmp(array[1], "~") == 0)
	{
		chdir("C:\\Users\\Antriksh");
	}
	else if (array[1] != NULL && strcmp(array[1], "/") == 0)
	{
		chdir("/");
	}
	else if (array[1] == NULL)
	{
		chdir("C:\\Users\\Antriksh");
	}
	else if (strcmp(array[1], "..") == 0)
		chdir(array[1]);
	else
	{
		struct stat buf;
		stat(("%s/%s", path(), array[1]), &buf);

		if (chdir(array[1]) == 0)
			chdir(array[1]);
		else if (chdir(array[1]) == -1)
		{
			if (S_ISREG(buf.st_mode))
			{
				printf("%s %s\n", array[1], ": Not a directory");
			}
			else
			{
				printf("%s %s\n", array[1], ": No such file or directory present");
			}
		}
	}
}

void execute_exit()
{
	exit(1);
}

int print_printf(char **array)
{
	int k;
	if (array[1] != NULL && strcmp(array[1], "-n") == 0)
	{
		k = 2;
	}
	else
		k = 1;
	if (array[1] != NULL && strcmp(array[1], "-E") == 0)
	{
		k = 2;
	}
	int count1 = 0;
	int idxex1 = 0;
	if (idx != 0)
		k = 0;
	while (array[k] != NULL)
	{
		idxex1 = 0;
		for (int t = 0; t < strlen(array[k]); t++)
		{
			if (((array[k])[t]) != '"')
			{
				st[idx][idxex1] = array[k][t];
				idxex1++;
			}
			else
			{
				count1 += 1;
			}
		}
		st[idx][idxex1] = '\0';

		idx++;
		k++;
	}

	return count1;
}

void execute_echo(char **array)
{
	idx = 0;
	int count = print_printf(array);

	if (count % 2 != 0)
	{
		char inst[1024];

		while (count % 2 != 0)
		{
			printf("%c", '>');

			fgets(inst, 1024, stdin);
			char *ptr;

			if ((ptr = strchr(inst, '\n')) != NULL)
			{
				*ptr = '\0';
			}

			int m = 0;
			char **arr = malloc(1024 * sizeof(char *));
			char *c = strtok(inst, delimiter);
			arr[m] = c;
			m++;

			while (c != NULL)
			{
				c = strtok(NULL, delimiter);
				arr[m] = c;
				m++;
			}

			arr[m] = NULL;
			st[idx][0] = '\n';
			idx++;
			count += print_printf(arr);
		}
	}
	for (int y = 0; y < idx; y++)
	{
		if (st[y][0] != '\n')
		{
			printf("%s ", st[y]);
		}
		else
		{
			printf("%s", st[y]);
		}
		memset(st[y], '\0', strlen(st[y]));
	}

	if (strcmp(array[1], "-n") != 0)
	{
		printf("\n");
	}
}

void execute_pwd()
{
	char directory[1024];

	if (getcwd(directory, sizeof(directory)) == NULL)
	{
		perror("Error ");
	}
	else
	{
		printf("%s\n", directory);
	}
}

int main(int argc, char const *argv[])
{
	char cmd[1024];

	FILE *f_in;
	int i;
	int flag = 0;
	printf("****Welcome to Byteshell****\n");
	while (True)
	{
		print_prompt1();
		fgets(cmd, 1024, stdin);
		if (strcmp(cmd, "\n") == 0)
		{
			continue;
		}
		char *pointer;
		if ((pointer = strchr(cmd, '\n')) != NULL)
		{
			*pointer = '\0';
		}

		int i = 0;
		char **array = malloc(1024 * sizeof(char *));
		char *ch = strtok(cmd, delimiter);
		array[i] = ch;
		i++;

		while (ch != NULL)
		{
			ch = strtok(NULL, delimiter);
			array[i] = ch;
			i++;
		}

		array[i] = NULL;

		if (strcmp(array[0], "cd") == 0)
		{
			execute_cd(array);
		}
		else if (strcmp(array[0], "exit") == 0)
		{
			execute_exit();
		}
		else if (strcmp(array[0], "echo") == 0)
		{
			execute_echo(array);
		}
		else if (strcmp(array[0], "pwd") == 0)
		{
			execute_pwd();
		}
		else
		{
			printf("%s %s\n", cmd, ": command not found");
			exit(1);
		}
	}
	return 0;
}
