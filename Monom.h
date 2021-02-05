#pragma once
#include <iostream>
using namespace std;
class Monom
{
private: 
	double Coef;//Коофецент
	int degree;//Степень
	Monom* NextMonom = NULL;//Указатель на следующий моном
	Monom* BackMonom = NULL;//Указатель на предыдущий моном
public:
	Monom();//Дефолтный конструктор
	Monom(double coef, int degree);//Конструктор с параметрами 
	Monom(const Monom& tmp);//Конструктор копирования
	//Operation
	Monom& operator=(const Monom& tmp);//Операторы сложения,вычитания,умножения,деление , приравнивания 
	Monom operator+(const Monom& tmp)const;
	Monom operator-(const Monom& tmp)const;
	Monom operator*(const Monom& tmp)const;
	Monom operator/(const Monom& tmp)const;
	~Monom();//Деструктор
	friend std::ostream& operator<<(std::ostream& out, const Monom& monom);//Оператор вывода
	friend std::istream& operator>>(std::istream& in, Monom& monom);//Оператор ввода
	Monom* GetNextMonom();//Вернуть следующий моном
	void SetNextMonom(const Monom& tmp);//Поставить следующий моном
	Monom *GetBackMonom();//Дать задний моном
	void SetBackMonom(const Monom& tmp);//Поставить задний моном
	Monom* GetCurrentMonom();//текущий
	int GetDegree()const;//Вернуть степень 
	void SetDegree(int deg);//Поставить степень
	double GetCoef()const;//Вернуть коофецент
	void SetCoef(double coef);//Поставить коофецент
};

