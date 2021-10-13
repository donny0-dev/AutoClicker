#include <Windows.h>
#include <iostream>
#include <thread>

float random_number(float min, float max)
{
	float r = (float)rand() / (float)RAND_MAX;
	return min + r * (max - min);
}

void sendleftclick()
{
	INPUT input = { 0 };
	// left down 
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &input, sizeof(INPUT));

	Sleep(1);

	// left up
	::ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &input, sizeof(INPUT));
}

void sendrightclick()
{
	INPUT input = { 0 };
	// right down 
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	::SendInput(1, &input, sizeof(INPUT));

	Sleep(1);

	// right up
	::ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	::SendInput(1, &input, sizeof(INPUT));
}

void leftclick()
{
	if (GetAsyncKeyState(VK_XBUTTON2))
	{
		switch (rand() % 5)
		{
		case 0:
			sendleftclick();
			Sleep(random_number(63, 66));
			break;
		case 1:
			sendleftclick();
			Sleep(random_number(38, 46));
			break;
		case 2:
			sendleftclick();
			Sleep(random_number(66, 70));
			break;
		case 3:
			sendleftclick();
			Sleep(random_number(38, 46));
			break;
		case 4:
			sendleftclick();
			Sleep(random_number(58, 59));
			break;
		}
	}
}

void rightclick()
{
	if (GetAsyncKeyState(VK_XBUTTON1))
	{
		switch (rand() % 5)
		{
		case 0:
			sendrightclick();
			Sleep(random_number(73, 76));
			break;
		case 1:
			sendrightclick();
			Sleep(random_number(58, 66));
			break;
		case 2:
			sendrightclick();
			Sleep(random_number(66, 70));
			break;
		case 3:
			sendrightclick();
			Sleep(random_number(78, 80));
			break;
		case 4:
			sendrightclick();
			Sleep(random_number(82, 83));
			break;
		}
	}
}

int main()
{
	std::cout << "press end to close \n";

	while (!GetAsyncKeyState(VK_END))
	{
		std::thread t1(leftclick);
		std::thread t2(rightclick);

		t1.join();
		t2.join();
	}

	std::cin.ignore();
	return NULL;
}