// Multithreading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <mutex>
#include <thread>

using namespace std;

string message = "";
const int num_threads = 10;
mutex mtx;

// Add to global string
void call_from_thread(int tid)
{
	// Critical Section
	mtx.lock();
	message.append("Thread #").append(to_string(tid)).append(" ");
	mtx.unlock();
}

int main()
{
	thread t[num_threads];

	// Create 10 threads
	for (int i = 0; i < num_threads; i++)
	{
		t[i] = thread(call_from_thread, i + 1);
	}
	// join all threads
	for (int i = 0; i<num_threads; i++)
	{
		t[i].join();
	}
	// print the global string to console
	cout << message;

	system("pause");
	return 0;
}
