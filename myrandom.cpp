#include <random>
#include <ctime>

namespace MyRandom
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int getRandomInteger(int min, int max)
{
	std::uniform_int_distribution<> number{ min, max };
	return number(MyRandom::mersenne);
}