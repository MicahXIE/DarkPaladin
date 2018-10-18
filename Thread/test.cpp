#include<iostream>
#include<thread>
using namespace std;

void thread_task(){
	cout << "hello thread" << endl;
}

int main(){
	thread t(thread_task);
	t.join();

	return EXIT_SUCCESS;
}