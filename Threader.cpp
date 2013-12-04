#include "Threader.h"

Threader::Threader(){}

void Threader::multithread(){
	thread t1(calculation);
	t1.join();
}

int Threader::calculation(int a){
	return 5;
}