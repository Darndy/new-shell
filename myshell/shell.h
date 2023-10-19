#ifndef SHELL_H
#define SHELL_H

void displayPrompt(void);
char *readInput();
void executeCommand(char *command, char *args[]);
void programArg(char input, char **args);
void handleCommand(char *command, char *args[]);
int main(void);
extern int commandError;
void handleExitCommand(char *command);
void handleEnvCommand();

#endif
