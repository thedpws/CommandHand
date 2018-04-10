//for system
#include <stdlib.h>

//for SetCursorPos(x,y)
#include <Windows.h>

int main() {
	//system("cmd.exe");
	for (int i = 0; i < 1000; i++) {
		SetCursorPos(i, i);
		Sleep(1);
	}
	return 0;
}