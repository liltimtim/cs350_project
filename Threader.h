#include <thread>
#include <vector>
#include <functional>
using namespace std;

class Threader{

public:
	Threader();

	void multithread();
	int calculation(int a);

private:
	// vector<thread> threads;

};