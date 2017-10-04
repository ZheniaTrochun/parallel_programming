#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>
#include "funcs.h"
#include "printer.h"

using namespace std;

const int default_matrix_size = 5;

DWORD WINAPI ThreadProcFunc1(CONST LPVOID lpParam) {
	CONST HANDLE hMutex = (CONST HANDLE)lpParam;
	WaitForSingleObject(hMutex, INFINITE);
	cout << "Func1 started" << endl;
	ReleaseMutex(hMutex);

	vector* a = new vector(default_matrix_size, false);
	matrix* ma = new matrix(default_matrix_size, false), *md = new matrix(default_matrix_size, false);

	matrix* result = func1(a, ma, md);

	WaitForSingleObject(hMutex, INFINITE);

	cout << "Func1 result: " << endl;
	printer::show(result);
	cout << "Func1 compeleted" << endl;

	ReleaseMutex(hMutex);

	ExitThread(0);
}

DWORD WINAPI ThreadProcFunc2(CONST LPVOID lpParam) {
	CONST HANDLE hMutex = (CONST HANDLE)lpParam;
	WaitForSingleObject(hMutex, INFINITE);
	cout << "Func2 started" << endl;
	ReleaseMutex(hMutex);

	matrix* ma = new matrix(default_matrix_size, false);
	matrix* mb = new matrix(default_matrix_size, false);
	matrix* mm = new matrix(default_matrix_size, false);
	matrix* mx = new matrix(default_matrix_size, false);

	matrix* result = func2(ma, mb, mm, mx);

	WaitForSingleObject(hMutex, INFINITE);

	cout << "Func2 result: " << endl;
	printer::show(result);
	cout << "Func2 compeleted" << endl;

	ReleaseMutex(hMutex);

	ExitThread(0);
}

DWORD WINAPI ThreadProcFunc3(CONST LPVOID lpParam) {
	CONST HANDLE hMutex = (CONST HANDLE)lpParam;

	WaitForSingleObject(hMutex, INFINITE);
	cout << "Func3 started" << endl;
	ReleaseMutex(hMutex);

	vector* p = new vector(default_matrix_size, false);
	matrix* mr = new matrix(default_matrix_size, false), *ms = new matrix(default_matrix_size, false);

	vector* result = func3(p, mr, ms);

	WaitForSingleObject(hMutex, INFINITE);

	cout << "Func3 result: " << endl;
	printer::show(result);
	cout << "Func3 compeleted" << endl;

	ReleaseMutex(hMutex);

	ExitThread(0);
}

void main() {
	srand(time(NULL));

	HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);

	HANDLE hThread1 = CreateThread(NULL, NULL, &ThreadProcFunc1, hMutex, CREATE_SUSPENDED, NULL);
	SetThreadPriority(hThread1, THREAD_PRIORITY_LOWEST);

	HANDLE hThread2 = CreateThread(NULL, NULL, &ThreadProcFunc2, hMutex, CREATE_SUSPENDED, NULL);
	SetThreadPriority(hThread2, THREAD_PRIORITY_NORMAL);

	HANDLE hThread3 = CreateThread(NULL, NULL, &ThreadProcFunc3, hMutex, CREATE_SUSPENDED, NULL);
	SetThreadPriority(hThread3, THREAD_PRIORITY_ABOVE_NORMAL);

	ResumeThread(hThread1);
	ResumeThread(hThread2);
	ResumeThread(hThread3);

	_getch();
}
