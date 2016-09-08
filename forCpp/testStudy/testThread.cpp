#include "testThread.h"
#include <vector>

testThread::testThread(void)
{
}


testThread::~testThread(void)
{
}
void testThread::hello()
{
	cout<<"Hello from thread"<<endl;
}

void testThread::runThread()
{
	thread t1(&testThread::hello);
	t1.join();
	cout<<"Main thread"<<endl;
	
}

void testThread::runThread1()
{
	vector<thread> threads;
	for (int i=0;i<5;i++)
	{
		threads.push_back(thread([](){
			cout<<"from lambda thread"<<this_thread::get_id()<<endl;
		}));
	}
	for (auto& thread : threads)
	{
		thread.join();
	}
	cout<<"Main thread"<<"\t"<<this_thread::get_id()<<endl;
}


void testThread::runThread2()
{
	mutex m;
	thread t1([&m](){
		this_thread::sleep_for(chrono::seconds(10));
		for (int i=0;i<10;i++)
		{
			m.lock();
				cout<<"In t1 ThreadID:"<<this_thread::get_id()<<":"<<i<<endl;
			m.unlock();
		}
	});

	thread t2([&m]()
	{
		this_thread::sleep_for(chrono::seconds(1));
		for (int i=0;i<10;i++)
		{
			m.lock();
			cout<<"In t2 ThreadID:"<<this_thread::get_id()<<":"<<i<<endl;
			m.unlock();
		}
	});

	t1.join();
	t2.join();

	cout<<"Main thread"<<endl;
}


void testThread::runThread3()
{
	Counter counter;
	vector<thread> threads;
	for (int i=0;i<5;i++)
	{
		threads.push_back(thread([&](){
			for (int i=0;i<10000;i++)
			{
				counter.increment();
			}
		}));
	}
	for (auto &thread:threads)
	{
		thread.join();
	}

	cout<<counter.value<<endl;

	Counter counter1;
	vector<thread> threads1;
	for (int i=0;i<5;i++)
	{
		threads1.push_back(thread([&](){
			for (int i=0;i<10000;i++)
			{
				counter1.decrement();
			}
		}));
	}
	for (auto &thread:threads1)
	{
		thread.join();
	}
	cout<<counter1.value<<endl;

}
