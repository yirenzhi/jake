#pragma once
#include <thread>
#include <iostream>
#include <mutex>
using namespace std;
class testThread
{
public:
	testThread(void);
	~testThread(void);
	static void runThread();
	static void hello();

	static void runThread1();
	static void runThread2();

	struct Counter{
		mutex mutex;
		int value;

		Counter():value(0){}

		void increment(){
			//mutex.lock();
			++value;
			//mutex.unlock();
		}
		void decrement(){
			mutex.lock();
			++value;
			mutex.unlock();
		}
	};

	static void runThread3();
};

