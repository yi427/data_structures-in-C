#include "tester.hpp"

std::default_random_engine& global_urng(){
    static std::default_random_engine u{};
    return u;
}

void randomize() {
    static std::random_device rd{};
    global_urng().seed(rd());
}

int pick(int from, int to) {
    static std::uniform_int_distribution<> d{};
    using parm_t = decltype(d)::param_type;
    return d(global_urng(), parm_t{from, to});
}

tester::tester() {
    randomize();
}

void tester::start(int from, int to, const std::function<void(int)>& fun) const {
	int pos = pick(from, to); // random to select a number and exec the function
	fun(pos);
}

