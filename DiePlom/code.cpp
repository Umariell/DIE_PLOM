// Если компилируем под Win32
#ifdef _WIN32
#  include <windows.h>
#endif

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "solver.h"

using namespace std;



template <typename T>
void file_input(ifstream& file, T& x)
{
	string s; file >> s; file >> x;
	if (!file.good())
	{
		cerr << "Error: File incorrect!" << endl; cin.get();
		exit(EXIT_FAILURE);
	}
}



int main()
{
#ifdef _WIN32
	// Кодировка консоли
	// В Visual Studio 2013 не работает
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif

	cout << fixed << left << setprecision(3);
	cerr << setprecision(8);


	// открываем файл для чтения
	ifstream file("../input.txt");
	if (!file.is_open())
	{
		cerr << "Error: Cannot open file!" << endl; cin.get();
		return EXIT_FAILURE;
	}


	size_t K, N;
	file_input(file, K);
	file_input(file, N);

	Solver solver(K, N);

	// Вводим данные из файла в solver
	// Порядок ввода как в файле!
	file_input(file, solver.V);
	file_input(file, solver.Q);
	file_input(file, solver.W);
	file_input(file, solver.w);
	file_input(file, solver.p);

	// Закроем файл - больше не нужен
	file.close();


	// Вычисление
	if (!solver.solve())
	{
		cin.get();
		return EXIT_FAILURE;
	}

	cin.get();
	return 0;
}
