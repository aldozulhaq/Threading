#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

// inisialisasi mutual exclusion (mutex) dan global variable yang akan digunakan
mutex m;
int number = 1;

void print(double time, string type, int limit)
{
	int timems = time * 1000; // merubah second menjadi miliseconds
	for (int i = 0; i < limit; i++)
	{
		m.lock(); // menglock variable number sehingga tidak terdapat thread lain yang dapat mengakses variable tersebut
		if (type == "even" && number % 2 == 0)
		{
			cout << number << " even " << endl;
			number++;
		}
		else if(type == "odd" && number % 2 != 0)
		{
			cout << number << " odd" << endl;
			number++;
		}
		m.unlock(); // mengunlock sehingga thread lain bisa mengakses kembali
		this_thread::sleep_for(chrono::milliseconds(timems)); // memberikan delay sebelum loop selanjutnya
	}
}

int main()
{
	int limit = 10; // limit dari berapa banyak looping yang akan dilakukan

	//inisialisasi thread
	thread odd(print, (1), "odd", (limit));
	thread even(print, (2.5), "even", (limit));

	//
	odd.join();
	even.join();
}