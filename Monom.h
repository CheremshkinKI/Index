#pragma once
#include <iostream>
using namespace std;
class Monom
{
private: 
	double Coef;//���������
	int degree;//�������
	Monom* NextMonom = NULL;//��������� �� ��������� �����
	Monom* BackMonom = NULL;//��������� �� ���������� �����
public:
	Monom();//��������� �����������
	Monom(double coef, int degree);//����������� � ����������� 
	Monom(const Monom& tmp);//����������� �����������
	//Operation
	Monom& operator=(const Monom& tmp);//��������� ��������,���������,���������,������� , ������������� 
	Monom operator+(const Monom& tmp)const;
	Monom operator-(const Monom& tmp)const;
	Monom operator*(const Monom& tmp)const;
	Monom operator/(const Monom& tmp)const;
	~Monom();//����������
	friend std::ostream& operator<<(std::ostream& out, const Monom& monom);//�������� ������
	friend std::istream& operator>>(std::istream& in, Monom& monom);//�������� �����
	Monom* GetNextMonom();//������� ��������� �����
	void SetNextMonom(const Monom& tmp);//��������� ��������� �����
	Monom *GetBackMonom();//���� ������ �����
	void SetBackMonom(const Monom& tmp);//��������� ������ �����
	Monom* GetCurrentMonom();//�������
	int GetDegree()const;//������� ������� 
	void SetDegree(int deg);//��������� �������
	double GetCoef()const;//������� ���������
	void SetCoef(double coef);//��������� ���������
};

