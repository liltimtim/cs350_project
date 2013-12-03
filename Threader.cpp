#include "Threader.h"

Threader::Threader(){}

void Threader::multithread(){
	thread t1(&Threader::calculation, this);
	t1.join();
}

int Threader::calculation(){
	return 5;
}