//#include <iostream>
//#include <thread>
//#include <chrono>
//
//using namespace std;
//
//#define limit 10
//
//void odd()
//{
//	for (int i = 0; i < limit; i++)
//	{
//		if (i % 2 != 0)
//			cout << i << endl;
//		this_thread::sleep_for(chrono::milliseconds(1000));
//	}
//}
//
//void even()
//{
//	for (int i = 0; i < limit; i++)
//	{
//		if (i % 2 == 0)
//			cout << i << endl;
//		this_thread::sleep_for(chrono::milliseconds(2500));
//	}
//}
//
//int main()
//{
//	thread Odd(odd);
//	thread Even(even);
//
//	Odd.join();
//	Even.join();
//}