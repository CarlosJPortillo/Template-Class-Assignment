#include <iostream>
#include <tuple>
#include <math.h>
using namespace std;

const int SIZE = 10;

template<class T>
tuple<T, T, double, double> GetData(const T* Tarray)
{
	T sum = GetSum(Tarray);
	T max = Highest(Tarray);
	T min = Lowest(Tarray);
	double average = double(sum)/double(SIZE);
	double SD = StandardDeviation(average, Tarray);
	return make_tuple(max, min, average, SD);
}
template<class T>
T GetSum(const T* Tarray)
{
	T sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum = sum + Tarray[i];
	}
	return sum;
	
}
template<class T>
T Highest(const T* Tarray)
{
	T max = Tarray[0];
	for (int i = 0; i<SIZE; i++)
	{
		if (Tarray[i]>max)
			max = Tarray[i];
	}
	return max;
}
template<class T>
T Lowest(const T* Tarray)
{
	T min = Tarray[0];
	for (int i = 0; i<SIZE; i++)
	{
		if (Tarray[i]<min)
			min = Tarray[i];
	}
	return min;
}

template<class T>
const T * GetInput()
{
	static T Input[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Please enter numbers to work with" << endl;
		cin >> Input[i];
	}
	const T* Tarray = Input;
	return Tarray;
	
}
template<class T>
double StandardDeviation(double average, const T* Tarray)
{
	double summation = 0;
	double x;
	for (int i = 0; i < SIZE; i++)
	{
		x = pow((double(Tarray[i]) - average), 2.0);
		summation = summation + x;
	}
	return sqrt(summation / (SIZE - 1));
	
}

int main()
{
	//working with ints in this example, change template arguement to double and numbers variable to double pointer to work with doubles
	const int* numbers = GetInput<int>();
	auto DataObj = GetData(numbers);
	cout << "Highest Number:    " << get<0>(DataObj)
		<< "\nLowest Number:     " << get<1>(DataObj)
		<< "\nAverage:           " << get<2>(DataObj)
		<< "\nStandard Devation: " << get<3>(DataObj) << endl;

	system("pause");
	
}