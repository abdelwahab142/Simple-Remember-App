#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>
#include <locale>
#include <codecvt>


using namespace std;



int main()
{
	tm* tm_;
	time_t i;
	vector<int> hour_inp;
	vector<string> Comm_inp;
	int int_Read = TRUE;
	string string_Read;
	int Mess_Ret;
	int flag = 0;
	wstring Assemb = L"Time For ";

	cout << "\t\tIf You Want Exit Just Put 0|\n\n";
	while (1) {
		cout << "Whats The Time You Want To  Remember You: ";
		cin >> int_Read;
		if (!int_Read)
			break;
		cout << "Enter The Comment Of this Time: ";
		cin >> string_Read;
		hour_inp.push_back(int_Read);
		Comm_inp.push_back(string_Read);
	}

	FreeConsole();
	while (1) {
	    i = time(0);
		tm_ = localtime(&i);

		for (int i = 0; i < hour_inp.size(); i++) {

			if (hour_inp[i] == tm_->tm_min) {
				std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
				Assemb += converter.from_bytes(Comm_inp[i]);

				Mess_Ret = MessageBox(0, L"Do You Want Another Warning After 3 Minuts", Assemb.c_str(), MB_YESNO | MB_ICONWARNING);
				if (Mess_Ret == IDYES) {
					Sleep(5000);
					continue;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		Sleep(5000);
		
	}

	return 0;
}

