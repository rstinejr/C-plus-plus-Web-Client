#include "DCAWeather.hpp"

#include <iostream>

using namespace std;

int main()
{
    cout << "Weather at Washington National Airport:" << endl;

	DCAWeather weather;

	cout << weather.getWeather() << endl;

	return 0;
}
