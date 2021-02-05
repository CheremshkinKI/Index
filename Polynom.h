#pragma once
#include "Monom.h"
#include <iostream>
class Polynom : public Monom
{
	
private:
	Monom* StartMonom;//Указатель на первый моном(СД список)
	int SIZE=1;//Размер списка
public:
	Polynom();//Дефолтный конструктор
	Polynom(int size);//Конструктор с заданием размера
	Polynom(const Polynom& polynom);//Конструктор копирования
	void DeleteList();//Удаляет список
	void SetSize(int size);//Ставит размер
	void Equalizer();//Складывания в один моном 2-х с одинаковыми степенями
	Polynom& operator+(const Monom& monom);//Операторы сложения, вычитания, умножения и деления с мономом
	Polynom& operator-(const Monom& monom);
	Polynom& operator*(const Monom& monom);
	Polynom& operator/(const Monom& monom);

	Polynom& operator=(const Polynom& polynom);//Операторы сложения, вычитания, умножения ,деления присваивания с полиномом
	Polynom operator+(const Polynom& polynom);
	Polynom operator-(const Polynom& polynom);
	Polynom operator*(const Polynom& polynom);
	Polynom operator/(const Polynom& polynom);

	friend std::ostream& operator<<(std::ostream& out, const Polynom& monom);//оператор вывода
	friend std::istream& operator>>(std::istream& in, Polynom& monom);//оператор ввода
	~Polynom();
	double Calculate(double X);
};

