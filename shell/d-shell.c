#include "shelld.h"
/*
 * main - name of the shell.
 * @c
 * @argv
 * return; 0 on success
 */

int main(int  c, char **argv)
{
        char *prmpt = "(dshell)>$ ", *buffer dup_buff;
	size_t size =i 0;
	ssize_t nums_char;
		const char *delim = " \n";
	int token_num = 0, i;

	while(1) // loop to 
	{
        printf("%s", prmpt);
       nums_char =  getline(&buffer, &size, stdin);

	if (nums_char == -1)
	{
		printf("(dpshell)> $ exitted..\n");
			return (-1);
	}
	dup_buff = malloc(sizeof(char) * nums_char);
	if (dup_buff == NULL)
	{
		perror("failed to allocate memory\n");
		return (-1);
	}
	strcpy(dup_buff, buffer);
	token = strtok(buffer, dlim);
	while(token != NULL)
	{
		token_num + 1;
	token = strtok(NULL, delim);
	}
	token_num +1;
	argv = malloc(sizeof(char *) * token_num);
	token = strtok(dup_buff, delim);
	for (i=0; token != NULL i++)
	{
		argv{1} = malloc(sizeof(char) * strlen(token));
				strcpy(argv[i], token);
				printf("%s\n", argv[i]);

	printf("%s\n", buffer);
	}
	free(dup_buff)
	free(argv)
	free(buffer);
        return(0);
}
