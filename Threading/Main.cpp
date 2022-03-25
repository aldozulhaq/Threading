#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

// inisialisasi mutual exclusion (mutex) dan global variable yang akan digunakan
mutex m;
// menggunakan global variable untuk angka yang akan digunakan
// supaya angka yang akan di print berurutan
int number = 1;

// function untuk thread
// dengan parameter sebagai berikut
// time -> waktu
// type -> tipe (ganjil atau genap)
// limit -> jumlah looping yang akan dilakukan
void print(double time, string type, int limit)
{
	// merubah second menjadi miliseconds
	int timems = time * 1000; 

	// looping output thread
	for (int i = 0; i < limit; i++)
	{
		// menglock mutex m dan variable number sehingga tidak terdapat thread lain yang dapat mengakses variable tersebut
		m.lock(); 

		// print angka genap apabila thread bertipe "even"
		if (type == "even" && number % 2 == 0)
		{
			// print angka genap + " even "
			cout << number << " even " << endl;
			// increment variable number
			number++;
		}
		// print angka ganjil apabila thread bertipe "odd"
		else if(type == "odd" && number % 2 != 0)
		{
			// print angka ganjil + " odd "
			cout << number << " odd" << endl;
			// increment variable number
			number++;
		}
		// mengunlock mutex m sehingga thread lain bisa mengakses kembali
		m.unlock(); 
		// memberikan delay sebelum loop selanjutnya
		this_thread::sleep_for(chrono::milliseconds(timems)); 
	}
}

int main()
{
	// limit dari berapa banyak looping yang akan dilakukan
	int limit = 10; 

	// Memulai thread odd
	thread odd(print, (1), "odd", (limit));
	// Memulai thread odd
	thread even(print, (2.5), "even", (limit));

	// Menunggu thread odd untuk selesai
	odd.join();
	// Menunggu thread even untuk selesai
	even.join();
}