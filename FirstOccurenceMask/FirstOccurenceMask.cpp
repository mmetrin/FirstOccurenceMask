// FirstOccurenceMask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void RecFindOfMask(bool bollres, int i, int j);
void FindOfMask(int i);
void SizeOfMask();
int SizeOfInp(int i);
void Replace();


char newinp[255];
char replace[255];
char mask[255];
char input[255];
int ms;
int res = -1;

	

	int main()
	{
		std::cout << "Hello World!\n";

		std::cout << "Write your string: ";
		std::cin.getline(input, 255);
		std::cout << "Write your mask: ";
		std::cin.getline(mask, 255);
		std::cout << "Replace to: ";
		std::cin.getline(replace, 255);
		SizeOfMask();
		FindOfMask(0);
		Replace();
		std::cout << "Result is " << newinp;
	}

	void RecFindOfMask(bool bollres, int i, int j)
	{
		if (input[i] == '\0' || input[i] == ' ')
		{
			while (mask[j] != '\0')
			{
				if (mask[j] != '*')
				{
					if (input[i] == ' ') FindOfMask(i + 1);
					else res = -1;
				}
				j++;
			}
		}
		else if (mask[j] == '\0')
		{
			if (mask[j - 1] != '*')
			{
				while (input[i] != ' ' && input[i] != '\0') i++;
				if (input[i] == ' ') FindOfMask(i + 1);
				else res = -1;
			}
		}
		else if (mask[j] == '*')
		{
			if (res == -1) res = i;
			RecFindOfMask(true, i, j + 1);
		}
		else if (mask[j] == '?')
		{
			if (bollres)
			{
				if (mask[j + 1] != '\0') RecFindOfMask(true, i + 1, j + 1);
			}
			else
			{
				if (res == -1) res = i;
				RecFindOfMask(false, i + 1, j + 1);
			}
		}
		else if (mask[j] == input[i])
		{
			if (res == -1) res = i;
			RecFindOfMask(false, i + 1, j + 1);
		}
		else if (bollres) RecFindOfMask(true, i + 1, j);
		else
		{
			bool found = false;
			while (j >= 0)
			{
				if (mask[j] == '*')
				{
					found = true;
					break;
				}
				j--;
			}
			if (found) RecFindOfMask(true, i + 1, j + 1);
			else
			{
				while (input[i] != ' ' && input[i] != '\0') i++;
				if (input[i] == ' ') FindOfMask(i + 1);
				else res = -1;
			}
		}
	}

	void FindOfMask(int i)
	{
		int inps = SizeOfInp(i);
		res = -1;
		if (ms > inps)
		{
			if (input[i + inps] == ' ')
			{
				i += inps + 1;
				FindOfMask(i);
			}
		}
		else RecFindOfMask(false, i, 0);
	}

	void SizeOfMask()
	{
		int i = 0;
		while (mask[i] != '\0')
		{
			if (mask[i] != '*')
				ms++;
			i++;
		}
	}


	void Replace()
	{
		if (res != -1)
		{
			int i = 0, j = 0, k = 0;
			while (input[i] != '\0')
			{
				if (i == res)
				{
					int inps = SizeOfInp(i);
					i += inps - 1;
					while (replace[k] != '\0')
					{
						newinp[j] = replace[k];
						k++;
						j++;
					}
					j--;
				}
				else
					newinp[j] = input[i];
				i++;
				j++;
			}
			newinp[j] = '\0';
		}
		else
		{
			int i = 0;
			while (input[i] != '\0')
			{
				newinp[i] = input[i];
				i++;
			}
			newinp[i] = '\0';
		}
	}


	int SizeOfInp(int i)
	{
		int size = 0;
		while (input[i] != ' ' && input[i] != '\0')
		{
			i++;
			size++;
		}
		return size;
	}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
