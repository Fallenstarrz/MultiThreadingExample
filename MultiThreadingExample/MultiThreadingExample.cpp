// Multithreading.cpp : Defines the entry point for the console application.
//
// Assignment Requirements:
// Start, manage and execute 10 threads
// Each thread will append some thread specific information (Thread #X) to a shared string
// A mutex will need to be added to manage the execution of the threads and prevent them from interleaving.
// Zip Submission with debugger

#include "stdafx.h"
#include <iostream>
#include <string>
#include <mutex>
#include <thread>

using namespace std;

// Global Variables
string message = "";
const int threadCount = 10;
mutex mtx;

// Add to global string
void threadBody(int tid)
{
	// Critical Section
	mtx.lock();
	message.append("Thread #").append(to_string(tid)).append(" ");
	mtx.unlock();
}

int main()
{
	thread t[threadCount];

	// Create 10 threads
	for (int i = 0; i < threadCount; i++)
	{
		t[i] = thread(threadBody, i + 1);
	}
	// join all threads
	for (int i = 0; i < threadCount; i++)
	{
		t[i].join();
	}
	// print the global string to console
	cout << message;

	system("pause");
	return 0;
}
