#include "SceneController.h"
#include <Windows.h> 

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ukr");
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	SceneController* controller = SceneController::get_instance(argv[1]);
	controller->start();
}