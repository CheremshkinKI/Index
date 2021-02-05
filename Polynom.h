#pragma once
#include "Monom.h"
#include <iostream>
class Polynom : public Monom
{
	
private:
	Monom* StartMonom;//��������� �� ������ �����(�� ������)
	int SIZE=1;//������ ������
public:
	Polynom();//��������� �����������
	Polynom(int size);//����������� � �������� �������
	Polynom(const Polynom& polynom);//����������� �����������
	void DeleteList();//������� ������
	void SetSize(int size);//������ ������
	void Equalizer();//����������� � ���� ����� 2-� � ����������� ���������
	Polynom& operator+(const Monom& monom);//��������� ��������, ���������, ��������� � ������� � �������
	Polynom& operator-(const Monom& monom);
	Polynom& operator*(const Monom& monom);
	Polynom& operator/(const Monom& monom);

	Polynom& operator=(const Polynom& polynom);//��������� ��������, ���������, ��������� ,������� ������������ � ���������
	Polynom operator+(const Polynom& polynom);
	Polynom operator-(const Polynom& polynom);
	Polynom operator*(const Polynom& polynom);
	Polynom operator/(const Polynom& polynom);

	friend std::ostream& operator<<(std::ostream& out, const Polynom& monom);//�������� ������
	friend std::istream& operator>>(std::istream& in, Polynom& monom);//�������� �����
	~Polynom();
	double Calculate(double X);
};

