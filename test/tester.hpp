#pragma once

#include <functional>
#include <random>

class tester {
public:
	tester();
	void start(int from, int to, const std::function<void(int)>&) const;
private:
};

int pick(int, int);
std::default_random_engine& global_urng();
void randomize();

