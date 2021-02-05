
#include <iostream>
#include "Polynom.h"
#include "Monom.h"
#include <locale.h>
int main()
{
    setlocale(LC_CTYPE,"Rus");
	cout << "Выбреите действие" << endl << "1)Работа с мономом" << "2)Работа с полиномом"<<endl;
	Monom g;
	int sw=0;
	Monom* gg = new Monom();
	cin >> sw;
	switch (sw)
	{
	case 1:
	{
		cout << "Введите первый моном"<<endl;
		Monom test1(0,0);
		cin >> test1;
		Monom test2(0, 0);
		cout << "Введите второй моном" << endl;
		cin >> test2;
		Monom res (0, 0);
		res= test1 +test2;
		cout << res;
		res = test1 -test2;
		cout << res;
		res = test1 *test2;
		cout << res;
		res = test1 / test2;
		cout << res;
	}break;
	case 2:
	{
		cout << "Введите первый полином" << endl;
		Polynom Test1(4);
		cin >> Test1;
		cout << "Введите второй полином" << endl;
		Polynom Test2(3);
		cin >> Test2;
		cout << "Вывод первого полинома";
		cout << endl;
		cout << Test1;
     	cout << endl;
		cout << "Вывод второго полинома";
		cout << endl;
		cout << Test2;
		cout << endl;
		Polynom Res(1);
		cout << "Введите моном";
		cout << endl;
		Monom test1(2, 2);
		cin >> test1;
		cout << endl;
		//Monom test1(2, 2);
		cout << "res=Polynom+monom: " << endl;
		Res=Test1 + test1;
		cout << Res;
		cout << endl;
		Test1 - test1;
		/*Res = Test1 + test1;
		cout << Res;
		cout << endl;*/
		cout << "res=Polynom-monom: " << endl;
		Res = Test1 - test1;
		cout << Res;
		cout << endl;
		Test1 + test1;
		cout << "res=Polynom*monom: " << endl;
		Res = Test1 * test1;
		cout << Res;
		cout << endl;
		Test1 / test1;
		cout << "res=Polynom/monom: " << endl;
		Res = Test1 / test1;
		cout << Res;
		cout << endl;
		Test1 * test1;
		cout << "Test Equalizer " << endl;
		Test2.Equalizer();
		cout << Test2;
		cout << endl;
		cout << "res=Polynom-Polynom: " << endl;
		Test2.Equalizer();
		Test1.Equalizer();
		cout << Test1 << endl;
		cout << Test2 << endl;
		Res = Test1 - Test2;
		cout << Res;
		cout << endl;
		cout << "res=Polynom+Polynom: " << endl;
		Res = Test1 + Test2;
		cout << Res;
		cout << endl;
		cout << "res=Polynom*polynom" << endl;
		Res = Test1 * Test2;
		cout << Res;
		cout << endl;
		cout << "res=Polynom/polynom" << endl;
		Res = Test1 / Test2;
		cout << Res;
		cout << endl;
		cout << "res=Polynom*X" << endl;
		double X = 0;
		cin >> X;
		double ress = 0;
		ress=Test1.Calculate(X);
		cout << ress;
		cout << endl;
	}break;
	default:
		break;
	}
	return 0;
}


