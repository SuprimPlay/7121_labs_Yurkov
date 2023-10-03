// Вариант 42
#include <iostream>
#include <ctime>
int main()
{
	int const LENGTH_0 = 1000;
	double arr[LENGTH_0] = {};
	int n = 10000;
	while (n > 1001)
	{
		std::cout << "Input number of real numbers: ";
		std::cin >> n;
	}
	int input_method;
	std::cout << "Choose input method:" << '\n' << "1.From keyboard" << '\n' << "2.Random numbers" << '\n';
	std::cin >> input_method;
	--input_method;
	if (input_method)
	{
		double a, b;
		std::cout << "Input interval" << '\n' << "Input a: ";
		std::cin >> a;
		std::cout << "Input b: ";
		std::cin >> b;
		if (a > b) { std::swap(a, b); }
		for (int i = 0; i < n; ++i)
		{
			arr[i] = a + rand()*(b-a)/RAND_MAX;
		}
	}
	else 
	{
		std::cout << "Input " << n << " real numbers" << '\n';
		for (int i = 0; i < n; ++i)
		{
			std::cin >> arr[i];
		}
	}
	// Цепочка максимальной длины
	int chain_max_length = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[i] == arr[j])
			{
				chain_max_length = std::max(chain_max_length, i - j);
				break;
			}
		}
	}
	if (chain_max_length == 0)
	{
		chain_max_length = n;
	}
	std::cout << "Max lenght of chain = " << chain_max_length << '\n';
	// Сумма между нулями
	double sum = 0;
	int start_0 = -1, end_0 = -1;
	for (int i = 0; i < n; ++i)
	{
		if (!arr[i])
		{
			start_0 = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; --i)
	{
		if (!arr[i])
		{
			end_0 = i;
			break;
		}
	}
	if (start_0 == -1 or end_0 == -1)
	{
		std::cout << "Not enough zeros!!!" << '\n';
	}
	else
	{
		for (int i = start_0 + 1; i < end_0; ++i)
		{
			sum += arr[i];
		}
		std::cout << "Sum of numbers between zeros = " << sum << '\n';
	}
	// Упорядочивание
	for (int i = 0; i < n; i += 2)
	{
		for (int j = i + 2; j < n; j += 2)
		{
			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
	for (int i = 1; i < n; i += 2)
	{
		for (int j = i + 2; j < n; j += 2)
		{
			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
	std::cout << "array:" << '\n';
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << '\n';
	}
	EXIT_SUCCESS;
}