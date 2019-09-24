/*############## vsh (Shell) ************* Written by Vilas Ninawe ################*/

#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/dir.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>

char *sysname(char **);
void exit(int);
void ls(int);
void hist(int);
void curpid();
void ppid();
void cd();
void quit();
void cat(int);
void help();

struct info {
	int sqno;
	char histstr[128];
};

#define MAX 128

FILE *fp;
char cm[10][MAX] = { }, str[MAX], ch;
static int fd1, fd2, stdi = 0, stdo = 1;
char *intcmds[] = { "ls", "hist", "curpid", "ppid", "cd", "quit", "cat", "calc",
		"cal", "ntow", "style", "wc", "help" };

main(int argc, char*argv[], char*env[]) {
	int seqno = 1, flag6 = -1;
	static int i, j, k, state, state1, flag, flag1, flag2, flag3, flag4, flag5;
	fp = tmpfile();

	NextCmd: if (argc == 1 && flag5 == 0) {
		if (seqno == 1)
			system("clear"), printf("\nWelcome to My Shell - \"vsh\"\n\n");
		printf("[%d %.9s]$ ", seqno, getenv("HOSTNAME"));
		//scanf(" %[^\n]s",str);
		gets(str);
		hist(seqno++);

		/*************** Convertig String to 2D array of Command and its Argument *************/

		i = 0;
		j = 0;
		k = 0;
		state = 1;
		while (1) {
			ch = str[i++];
			if (ch == ' ' || ch == '\t' || ch == '\0') {
				if (ch == '\0') {
					if (k != 0)
						cm[j++][k] = '\0';
					break;
				}
				if (state == 0) {
					cm[j++][k] = '\0';
					k = 0, state = 1;
				}
			} else {
				state = 0;
				cm[j][k++] = ch;
			}
		}
		state = 1;
	} else {
		if (flag5 == 0) {
			if (argc == 2 || strcmp(argv[1], "-c") != 0) {
				printf("Invalid  Arguments\n");
				exit(0);
			} else {
				for (i = 0; i < argc - 2; i++)
					strcpy(cm[i], argv[i + 2]);
				j = i;
			}
		}
	}
	/********************** End of string to 2D array of input ***************************/

	/********************Printing 2D array of commands and arguments *********************
	 for(i=0; i<j; i++)
	 printf("%s ",cm[i]);
	 printf("\n");

	 *************************************************************************************/

	/******************* Code For Setting I/O Redirection   ***********************/
	if (state == 1) {
		state = flag1 = flag2 = flag4 = 0;
		for (i = 0; i < j; i++) {
			if (flag4 == 0 && strcmp(cm[i], ";") == 0)
				flag4 = 1, flag3 = j;
			if (strcmp(cm[i], "<") == 0) {
				if ((fd1 = open(cm[i + 1], O_RDONLY)) == -1) {
					perror("open");
					dup2(stdi, 0);
					dup2(stdo, 1);
					goto NextCmd;
				}
				stdi = dup(0);
				dup2(fd1, 0);
				for (k = i; k < j - 1; k++)
					strcpy(cm[k], cm[k + 1]);
				j--;
				flag1++;
			}

			if (strcmp(cm[i], ">") == 0) {
				if ((fd2 = open(cm[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 0664))
						== -1) {
					perror("open");
					dup2(stdi, 0);
					dup2(stdo, 1);
					goto NextCmd;
				}
				stdo = dup(1);
				dup2(fd2, 1);
				for (k = i; k < j - 1; k++)
					strcpy(cm[k], cm[k + 1]);
				j--;
				flag2++;
			}
		}
		if (flag1 > 1 || flag2 > 1) {
			printf("\nInvalid I/O Redirection");
			goto NextCmd;
			state = 1;
		}
		if (flag4 == 1)
			j = -1;
	}
	/*********************** I/O Redirection Code End ***************************/

	/********************** Code for Multiple Commands *************************/
	if (flag4 == 1) {
		i = 0;
		j = flag6;
		j++;
		while (j < flag3 && strcmp(cm[j], ";") != 0) {
			strcpy(cm[i], cm[j]);
			i++;
			j++;
		}
		if (j != flag3) {
			flag6 = j;
			flag5 = 1;
		} else {
			flag6 = -1;
			flag5 = 0;
		}
		j = i;
	}
	/***********************Multiple Command Code End *************************/

	/************* Find Command is External or Internal  ******************/
	for (i = 0; i < 13; i++) {
		if (strcmp(cm[0], intcmds[i]) == 0) {
			flag = 1;
			break;
		}
	}

	/**************** Executing  Internal  Commands ****************/
	if (flag == 1) {
		flag = 0;
		switch (i) {
		case 0:
			ls(j);
			break;
		case 1:
			hist(0);
			break;
		case 2:
			curpid();
			break;
		case 3:
			ppid();
			break;
		case 4:
			cd(j);
			break;
		case 5:
			quit();
			break;
		case 6:
			cat(j);
			break;
		case 7:
			calc(j);
			break;
		case 8:
			cal(j);
			break;
		case 9:
			ntow(j);
			break;
		case 10:
			style(j);
			break;
		case 11:
			wc(j);
			break;
		case 12:
			help();
			break;
		}

		if (argc == 1) {
			dup2(stdi, 0);
			//close(stdi);
			dup2(stdo, 1);
			//close(stdo);
			goto NextCmd;
		}
	}

	/*************** Executing  External  Commands ******************/
	else {
		if (fork()) {
			wait(0);
			if (argc == 1) {
				dup2(stdi, 0);
				//close(stdi);
				dup2(stdo, 1);
				//close(stdo);
				goto NextCmd;
			}
		} else {
			switch (j) {
			case 1:
				execlp(cm[0], cm[0], 0);
				break;
			case 2:
				execlp(cm[0], cm[0], cm[1], 0);
				break;
			case 3:
				execlp(cm[0], cm[0], cm[1], cm[2], 0);
				break;
			case 4:
				execlp(cm[0], cm[0], cm[1], cm[2], cm[3], 0);
				break;
			case 5:
				execlp(cm[0], cm[0], cm[1], cm[2], cm[3], cm[4], 0);
				break;
			case 6:
				execlp(cm[0], cm[0], cm[1], cm[2], cm[3], cm[4], cm[5], 0);
				break;
			case 7:
				execlp(cm[0], cm[0], cm[1], cm[2], cm[3], cm[4], cm[5], cm[6],
						0);
				break;
			case 8:
				execlp(cm[0], cm[0], cm[1], cm[2], cm[3], cm[4], cm[5], cm[6],
						cm[7], 0);
				break;
			case 9:
				execlp(cm[0], cm[0], cm[1], cm[2], cm[3], cm[4], cm[5], cm[6],
						cm[7], cm[8], 0);
				break;
			case 10:
				execlp(cm[0], cm[0], cm[1], cm[2], cm[3], cm[4], cm[5], cm[6],
						cm[7], cm[8], cm[9], 0);
				break;
			}
			printf("%s: No Such Command...\n", cm[0]);
			printf(
					"Try \'help\' for Internal Commands\nTry \'info\' for External Commands\n");
			_exit(0);
		}
	}
}
/**********************    Main End    ************************/

/***************  Codes for Internal Commands ****************/
void ls(int j) {
	DIR *dp;
	struct dirent *dnt;
	struct stat stbuf;
	if ((dp = opendir(".")) == 0) {
		perror("opendir");
		return;
	}
	if (j != 1) {
		/* if(strcmp(cm[1],"-l")!=0)
		 {
		 printf("Usage: $ ls -l\n");
		 printf("       $ ls\n");
		 return ;
		 }*/
		printf("%9s %8s %3s  %.15s\n", "Inode No.", "Size", "Links",
				"File Name");
	}
	while ((dnt = readdir(dp)) != 0) {
		if (strcmp(dnt->d_name, ".") == 0 || strcmp(dnt->d_name, "..") == 0)
			continue;
		if (j == 1)
			printf("%s   ", dnt->d_name);
		else {
			if (stat(dnt->d_name, &stbuf) == -1)
				perror("stat");
			printf("%9d %8d %4d   %.15s\n", dnt->d_ino, stbuf.st_size,
					stbuf.st_nlink, dnt->d_name);
		}
	}
	printf("\n");
	closedir(dp);
}

calc(int j) {
	if (j != 1) {
		printf("Usage: $calc\n");
		return;
	} else
		system("./calculator");
}

cal(int j) {
	if (j != 1) {
		printf("Usage: $cal\n");
		return;
	} else
		system("./calender");
}

ntow(int j) {
	if (j != 1) {
		printf("Usage: $ntow\n");
		return;
	} else
		system("./n2w");
}

style(int j) {
	if (j != 1) {
		printf("Usage: $style\n");
		return;
	} else
		system("./style");
}

wc(int j) {
	char l[20] = "./wc ";
	int i, len;
	if (j != 2) {
		printf("Usage: $wc filename\n");
		return;
	} else {
		for (i = 0; cm[1][i]; i++)
			; //5
		len = i;
		for (i = 0; i < len; i++)
			l[5 + i] = cm[1][i];
		l[5 + i] = '\0';
		system(l);
	}
}

void hist(int seqno) {
	struct info s;
	if (seqno != 0)      // add to history
			{
		s.sqno = seqno;
		strcpy(s.histstr, str);
		fseek(fp, 0, 2);
		fwrite(&s, sizeof(s), 1, fp);
	} else             // retrieve history
	{
		fseek(fp, 0, 0);
		while (fread(&s, sizeof(s), 1, fp))
			printf("%d %s\n", s.sqno, s.histstr);
	}
}

void curpid() {
	printf("Current Process Id (PID) - %d\n", getpid());
}

void ppid() {
	printf("Parent Process Id (PPID) - %d\n", getppid());
	printf("Process Group Id (PGID)  - %d\n", getpgid(0));
	printf("Session Id (SID)         - %d\n", getsid(0));
}

void cd(int j) {
	if (j != 2)
		printf("Invalid No. of Arguments...\n");
	else if (chdir(cm[1]) == -1)
		perror("chdir");
}

void quit() {
	printf("\nThanks for Using My Shell - \"vsh\"\n\n");
	exit(0);
}

void cat(int j) {
	char c[2];
	char ch;
	FILE *f;
	if (j == 1) {
		printf("Usage: $cat filename\n");
		printf("Usage: $cat < infile > outfile\n");
		printf("Usage: $cat < infile\n");
		printf("Usage: $cat > outfile\n");
		return;
	}
	if (j == 2) {
		if ((f = fopen(cm[1], "a+")) == 0) {
			perror("fopen");
			return;
		}
		fseek(f, 0, 0);
		while ((ch = fgetc(f)) != EOF)
			fputc(ch, stdout);
		while ((ch = fgetc(stdin)) != EOF)
			fputc(ch, f);
		fclose(f);
		return;
	}
	if (j > 5) {
		printf("Invalid No. of Arguments");
		return;
	}
	while (read(0, c, 1) != 0)
		write(1, c, 1);
}

void help() {
	printf(
			"      $ vsh                         - For Starting the vsh Shell\n");
	printf(
			"      $ vsh [-c] [cmdname][args]    - For Executing vsh Shell's Commands\n\n");
	printf("******* Commands of vsh Shell *******\n\n");
	printf(
			"ls     - List the Directory & Files\nhist   - Print History of Commands\n");
	printf(
			"curpid - Print Current Process Id  \nppid   - Print Parent Process Id\n");
	printf("cd     - Change the Directory      \nquit   - To Exit the Shell\n");
	printf(
			"cat    - For File Handling         \ninfo   - Help About External Commands\n");
	printf(
			"calc   - Scientific Calculator     \ncal    - Very Advanced Calender     \n");
	printf(
			"ntow   - Number to Word Convertor  \nstyle  - Print Name in Style   \n");
	printf(
			"wc     - Advanced Word Count       \nhelp   - Help About Internal Commands\n");
}

/********************** End of Codes of Internal Commands ***************/

/**********************  Finding Machine Name  **************************/
char *sysname(char**env) {
	char *p;
	int i = 0;
	static char sname[15] = "HOSTNAME";
	while (env[i]) {
		if ((p = strstr(env[i], sname)) != 0) {
			strncpy(sname, p + 9, 9);
			break;
		}
		i++;
	}
	return sname;
}
/*************************** End of the sysname *************************/
