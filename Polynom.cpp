#include "Polynom.h"

Polynom::Polynom()
{
	StartMonom = new Monom();
	SIZE = 3;
}

Polynom::Polynom(int size)
{
	StartMonom = new Monom();
	SIZE = size;
}

Polynom::Polynom(const Polynom& polynom)
{/*
	SIZE = polynom.SIZE;
	Monom* mas = new Monom[polynom.SIZE];
	mas[0] = *polynom.StartMonom;
	for (int i = 1; i < SIZE; i++)
	{
		mas[i] = *(mas[i - 1].GetNextMonom());
	}
	StartMonom = &mas[0];
	mas = NULL;
	delete mas;*/

	SIZE = polynom.SIZE;
//	this->DeleteList();
//  delete StartMonom;
	StartMonom = new Monom(polynom.StartMonom->GetCoef(), polynom.StartMonom->GetDegree());
	Monom* ptr = StartMonom;
	Monom* ptr2 = polynom.StartMonom;
	for (int i = 1; i < SIZE; i++)
	{
		ptr->SetNextMonom(Monom(ptr2->GetNextMonom()->GetCoef(), ptr2->GetNextMonom()->GetDegree()));
		if (ptr2->GetNextMonom() == NULL)
		{
			break;
		}
		ptr = ptr->GetNextMonom();
		ptr2 = ptr2->GetNextMonom();
	}
}

void Polynom::DeleteList()
{
	Monom* ptr=StartMonom;
	Monom* ptr2;
	for (int i = 0; i < SIZE; i++)
	{
		if (ptr->GetNextMonom() == NULL)
		{
			ptr->~Monom();
			break;
		}
		ptr2 = ptr->GetNextMonom();;
		ptr->~Monom();
	}
}

void Polynom::SetSize(int size)
{
	SIZE = size;
}

void Polynom::Equalizer()
{
	Polynom f = Polynom(1);
	Polynom g = Polynom(*this);
	Monom* ptr1 = this->StartMonom;
	Monom* ptr2 = g.StartMonom;
	Monom* ptr3 = f.StartMonom;
	int size = SIZE;
	int degree1 = 0;
	int degree2 = 0;
	int* degree3 = new int[size];
	degree3[0] = -100;
	int newsize = 0;
	bool flag;
	int* switch1 = new int[size];
	int* switch2 = new int[size];
	double ccoef1 = 0.0;
	double ccoef2 = 0.0;
	double ccoef3 = 0.0;
	for (int j = 0; j < size; j++)
	{
		degree1 = ptr2->GetCurrentMonom()->GetDegree();
		ccoef1 = ptr2->GetCurrentMonom()->GetCoef();
		switch1[j] = 1;
		flag = true;
		
		for (int k = 0; k < size; k++)
		{
			if (degree3[k] == degree1)
			{
				flag = false;
				break;
			}
		}
		if (j == 0)
		{
			degree3[0] = degree1;
		}
		degree3[j] = degree1;
		
		//Прописать хождения по первому списку
		if (flag == true)
		{
			for (int i = 0; i < size; i++)
			{
				degree2 = ptr1->GetCurrentMonom()->GetDegree();
				ccoef2 = ptr1->GetCurrentMonom()->GetCoef();

				if (degree1 == degree2)
				{
					if (i == j)
					{
						if (i + 1 == size)
						{
							continue;
						}
						ptr1 = ptr1->GetNextMonom();
						continue;
					}
					if (switch2[i] == 1 || switch1[i] == 1)
					{
						if (i + 1 == size)
						{
							continue;
						}
						ptr1 = ptr1->GetNextMonom();
						continue;
					}
					switch2[i] = 1;
					ccoef1 += ccoef2;
				}
				if (i + 1 == size)
				{
					continue;
				}
				ptr1 = ptr1->GetNextMonom();
				//Сравнивать все эементы второго списка с элементом превого . В случае совпадени Coef складывать и во втром списке ставить -100,-100 вместого того , что было 
			}
		}
		if (ccoef1 == 0.0)
		{
			continue;
		}
		if (flag == true)
		{
			ptr3->GetCurrentMonom()->SetCoef(ccoef1);
			ptr3->GetCurrentMonom()->SetDegree(degree1);
			newsize++;
		}
		ccoef1 = 0.0;
		if (j + 1 == size)
		{
			break;
		}
		if (flag == true)
		{
			Monom g = Monom();
			ptr3->SetNextMonom(g);
			ptr3 = ptr3->GetNextMonom();
		}
		ptr2 = ptr2->GetNextMonom();
		ptr1 = this->StartMonom;
	}
	f.StartMonom;
	f.SIZE = newsize;
	*this = f;
	ptr1 = NULL;
	ptr2 = NULL;
	ptr3 = NULL;
	/*delete ptr1;
	delete ptr2;
	delete ptr3;*/
	delete[] degree3;
	delete[] switch1;
	delete[] switch2;
	/*
	this->DeleteList();
	delete this->StartMonom;
	this->StartMonom = new Monom();
	ptr2 = StartMonom;
	ptr3 = f.StartMonom;
	for (int i = 0; i < newsize; i++)
	{
		ptr2->GetCurrentMonom()->SetCoef(ptr3->GetCurrentMonom()->GetCoef());
		ptr2->GetCurrentMonom()->SetDegree(ptr3->GetCurrentMonom()->GetDegree());
		/*if (i + 1 == newsize)
		{
			break;
		}
		ptr2 = ptr2->GetNextMonom();
		ptr2 = NULL;
	    ptr2 = new Monom();
		ptr3 = ptr3->GetNextMonom();
	}
	cout << *(this->StartMonom);
	this->SIZE = newsize;*/
	//cout << *this;
	//Удалить изначальный список, и перезаписать в из нового(ptr3) в изначальный 
}


Polynom& Polynom::operator+(const Monom& monom)
{
	Monom* ptr;
	Monom* ptr2;
	ptr = StartMonom;
	int deg=monom.GetDegree();
	double coef=monom.GetCoef();
	for (int i = 0; i < SIZE; i++)
	{
		if (ptr->GetCurrentMonom()->GetDegree() == deg)
		{
			ptr->GetCurrentMonom()->SetCoef(ptr->GetCurrentMonom()->GetCoef() + coef);
			return *this;
		}
		if (i + 1 == SIZE)
		{
			break;
		}
		ptr = (ptr->GetNextMonom());
	/*	ptr->GetCurrentMonom().GetCoef();
		ptr->GetCurrentMonom().GetDegree();
		ptr = &ptr->GetNextMonom();*/
	}
	ptr2 = new Monom(coef, deg);
	ptr->SetNextMonom(*ptr2);
	SIZE++;
	ptr2 = NULL;
	ptr = NULL;
	delete ptr2;
	delete ptr;
	return *this;
}

Polynom& Polynom::operator-(const Monom& monom)
{
	Monom* ptr;
	Monom* ptr2;
	ptr = StartMonom;
	int deg = monom.GetDegree();
	double coef = monom.GetCoef();
	for (int i = 0; i < this->SIZE; i++)
	{
		if (ptr->GetCurrentMonom()->GetDegree() == deg)
		{
			if (ptr->GetCurrentMonom()->GetCoef() == coef ||ptr->GetCurrentMonom()->GetDegree()==deg )
			{
			//	ptr->GetCurrentMonom()->~Monom();
			//	this->SetSize(SIZE - 1);
			//	return *this;
			}
			ptr->GetCurrentMonom()->SetCoef(ptr->GetCurrentMonom()->GetCoef() - coef);
			return *this;
		}
		if (i + 1 == SIZE)
		{
			break;
		}
		ptr = (ptr->GetNextMonom());
		/*	ptr->GetCurrentMonom().GetCoef();
			ptr->GetCurrentMonom().GetDegree();
			ptr = &ptr->GetNextMonom();*/
	}
	ptr2 = new Monom(coef, deg);
	ptr->SetNextMonom(*ptr2);
	SIZE++;
	ptr2 = NULL;
	ptr = NULL;
	delete ptr2;
	delete ptr;
	return *this;
}

Polynom& Polynom::operator*(const Monom& monom)
{
	Monom* ptr;
	Monom* ptr2;
	ptr = StartMonom;
	int deg = monom.GetDegree();
	double coef = monom.GetCoef();
	for (int i = 0; i < SIZE; i++)
	{
		/*if (ptr->GetCurrentMonom()->GetDegree() == deg)
		{
			ptr->GetCurrentMonom()->SetCoef(ptr->GetCurrentMonom()->GetCoef() - coef);
			return *this;
		}*/
	
		ptr->GetCurrentMonom()->SetCoef(ptr->GetCurrentMonom()->GetCoef() * monom.GetCoef());
		ptr->GetCurrentMonom()->SetDegree(ptr->GetCurrentMonom()->GetDegree() + monom.GetDegree());
		if (i + 1 == SIZE)
		{
			break;
		}
		ptr = (ptr->GetNextMonom());
		/*	ptr->GetCurrentMonom().GetCoef();
			ptr->GetCurrentMonom().GetDegree();
			ptr = &ptr->GetNextMonom();*/
	}
	ptr2 = NULL;
	ptr = NULL;
	delete ptr2;
	delete ptr;
	//ptr2 = new Monom(coef, deg);
    //ptr->SetNextMonom(*ptr2);
	//SIZE++;
	return *this;
}

Polynom& Polynom::operator/(const Monom& monom)
{
	Monom* ptr;
	Monom* ptr2;
	ptr = StartMonom;
	int deg = monom.GetDegree();
	double coef = monom.GetCoef();
	for (int i = 0; i < SIZE; i++)
	{
		/*if (ptr->GetCurrentMonom()->GetDegree() == deg)
		{
			ptr->GetCurrentMonom()->SetCoef(ptr->GetCurrentMonom()->GetCoef() - coef);
			return *this;
		}*/
		
		ptr->GetCurrentMonom()->SetCoef(ptr->GetCurrentMonom()->GetCoef() / monom.GetCoef());
		ptr->GetCurrentMonom()->SetDegree(ptr->GetCurrentMonom()->GetDegree() - monom.GetDegree());
		if (i + 1 == SIZE)
		{
			break;
		}
		ptr = (ptr->GetNextMonom());
		/*	ptr->GetCurrentMonom().GetCoef();
			ptr->GetCurrentMonom().GetDegree();
			ptr = &ptr->GetNextMonom();*/
	}
	//ptr2 = new Monom(coef, deg);
	//ptr->SetNextMonom(*ptr2);
	//SIZE++;
	ptr2 = NULL;
	ptr = NULL;
	delete ptr2;
	delete ptr;
	return *this;
}

Polynom& Polynom::operator=(const Polynom& polynom)
{
	SIZE = polynom.SIZE;
	this->DeleteList();
	delete StartMonom;
	StartMonom = new Monom(polynom.StartMonom->GetCoef(), polynom.StartMonom->GetDegree());
	Monom* ptr = StartMonom;
	Monom* ptr2 = polynom.StartMonom;
	for (int i = 1; i < SIZE; i++)
	{
		Monom*g = new Monom(ptr2->GetNextMonom()->GetCoef(), ptr2->GetNextMonom()->GetDegree());
		ptr->SetNextMonom(*g);
		if (ptr2->GetNextMonom() == NULL)
		{
			break;
		}
		ptr = ptr->GetNextMonom();
		ptr2 = ptr2->GetNextMonom();
	}
	ptr2 = NULL;
	ptr = NULL;
	delete ptr2;
	delete ptr;
	/*
	Monom* mas = new Monom[SIZE];
	mas[0] = *polynom.StartMonom;
	for (int i = 1; i < SIZE; i++)
	{
		mas[i] = *(mas[i - 1].GetBackMonom());
	}
	StartMonom = &mas[0];*/
	//mas = NULL;
//	delete mas;
	return*this;
}

Polynom Polynom::operator+(const Polynom& polynom)
{//
	Monom* ptr1 = this->StartMonom;
	Monom* ptr2 = polynom.StartMonom;
	Polynom f = Polynom(1);
	Monom* ptr3 = f.StartMonom;
	int size1 = this->SIZE;
	int size2 = polynom.SIZE;
	int size3;
	int* degree1 = new int[size1];
	int* degree2 = new int[size2];
	int* switch1 = new int[size1];
	int* switch2 = new int[size2];
	double coef1 = 0.0;
	double coef2 = 0.0;
	for (int i = 0; i < size1; i++)
	{
		degree1[i]=ptr1->GetCurrentMonom()->GetDegree();
		coef1 = ptr1->GetCurrentMonom()->GetCoef();

		for (int j = 0; j < size2; j++)
		{
			degree2[j] = ptr2->GetCurrentMonom()->GetDegree();
			coef2 = ptr2->GetCurrentMonom()->GetCoef();
			if (switch2[j] != 1)
			{
				//if(ptr1->GetCurrentMonom()->GetDegree()==ptr2->GetCurrentMonom()->GetDegree())
				if (degree1[i] == degree2[j])
				{
					coef1 += coef2;
					switch2[j] = 1;
				}
			}
			if (j+1 == size2)
			{
				ptr2 = polynom.StartMonom;
				break;
			}
			ptr2 = ptr2->GetNextMonom();
		}
		ptr3->GetCurrentMonom()->SetCoef(coef1);
		ptr3->GetCurrentMonom()->SetDegree(degree1[i]);
		if (i + 1 == size1)
		{
			break;
		}
		Monom g = Monom();
		ptr3->SetNextMonom(g);
		ptr3 = ptr3->GetNextMonom();
		ptr1 = ptr1->GetNextMonom();
	}
	delete[] degree1;
	delete[] degree2;
	size3 = size1;
	for (int i = 0; i < size2; i++)
	{
		if (switch2[i]!=1)
		{
			size3++;
		}
	}
	ptr2 = polynom.StartMonom;
	for (int i = 0; i < size2; i++)
	{
		ptr2->GetCurrentMonom();
		if (switch2[i] != 1)
		{
			Monom m = Monom(ptr2->GetCurrentMonom()->GetCoef(), ptr2->GetCurrentMonom()->GetDegree());
			ptr3->SetNextMonom(m);
			ptr3 = ptr3->GetNextMonom();
		}
		if (i+ 1 == size2)
		{
			break;
		}
		ptr2 = ptr2->GetNextMonom();
	}
	delete[] switch1;
	delete[] switch2;
	f.SIZE = size3;
	f.Equalizer();
	Polynom* Res =new Polynom();
	*Res = f;
	ptr1 = NULL;
	ptr2 = NULL;
	delete ptr1;
	delete ptr2;
	f.DeleteList();
	f.~Polynom();
	ptr3=NULL;
	delete ptr3;

	return *Res; 
	/*
	Monom* ptr1 = this->StartMonom;
	Monom* ptr2 = polynom.StartMonom;
	Polynom f = Polynom(1);
	Monom* ptr3 = f.StartMonom;
	int BigSize = this->SIZE + polynom.SIZE;
	for (int i = 0; i < this->SIZE; i++)
	{
		ptr3->GetCurrentMonom()->SetCoef(ptr1->GetCurrentMonom()->GetCoef());
		ptr3->GetCurrentMonom()->SetDegree(ptr1->GetCurrentMonom()->GetDegree());
		Monom m = Monom();
		ptr3->SetNextMonom(m);
		ptr3 = ptr3->GetNextMonom();
		if (i + 1 == this->SIZE)
		{
			break;
		}
		ptr1 = ptr1->GetNextMonom();
	}
	for (int i = 0; i < polynom.SIZE; i++)
	{
		ptr3->GetCurrentMonom()->SetCoef((ptr2->GetCurrentMonom()->GetCoef()));
		ptr3->GetCurrentMonom()->SetDegree(ptr2->GetCurrentMonom()->GetDegree());
		if (i + 1 == polynom.SIZE)
		{
			break;
		}
		ptr2 = ptr2->GetNextMonom();
		Monom m = Monom();
		ptr3->SetNextMonom(m);
		ptr3 = ptr3->GetNextMonom();
	}
	ptr3 = f.StartMonom;
	f.SIZE = BigSize;
	f.Equalizer();
	ptr1 = NULL;
	ptr2 = NULL;
	ptr3 = NULL;
	delete ptr1;
	delete ptr2;
	delete ptr3;
	Polynom* Res = new Polynom();
	*Res = f;
	//	Res->Equalizer();
	f.DeleteList();
	f.~Polynom();
	return *Res;*/
}

Polynom Polynom::operator-(const Polynom& polynom)
{
	Monom* ptr1 = this->StartMonom;
	Monom* ptr2 = polynom.StartMonom;
	Polynom f = Polynom(1);
	Monom* ptr3 = f.StartMonom;
	int BigSize = this->SIZE + polynom.SIZE;
	for (int i = 0; i < this->SIZE; i++)
	{			
		ptr3->GetCurrentMonom()->SetCoef(ptr1->GetCurrentMonom()->GetCoef());
		ptr3->GetCurrentMonom()->SetDegree(ptr1->GetCurrentMonom()->GetDegree());
		Monom m = Monom();
		ptr3->SetNextMonom(m);
		ptr3 = ptr3->GetNextMonom();
		if (i+ 1 ==this->SIZE )
		{
			break;
		}
		ptr1 = ptr1->GetNextMonom();
	}
	for (int i = 0; i < polynom.SIZE; i++)
	{
		ptr3->GetCurrentMonom()->SetCoef(-(ptr2->GetCurrentMonom()->GetCoef()));
		ptr3->GetCurrentMonom()->SetDegree(ptr2->GetCurrentMonom()->GetDegree());
		if (i + 1 == polynom.SIZE)
		{
			break;
		}
		ptr2 = ptr2->GetNextMonom();
		Monom m = Monom();
		ptr3->SetNextMonom(m);
		ptr3 = ptr3->GetNextMonom();
	}
	ptr3 = f.StartMonom;
	f.SIZE = BigSize;
	f.Equalizer();
	ptr1 = NULL;
	ptr2 = NULL;
	ptr3 = NULL;
	delete ptr1;
	delete ptr2;
	delete ptr3;
	Polynom* Res = new Polynom();
	*Res = f;
//	Res->Equalizer();
	f.DeleteList();
	f.~Polynom();
	return *Res;
}

Polynom Polynom::operator*(const Polynom& polynom)
{
	Monom* ptr1 = this->StartMonom;
	Monom* ptr2 = polynom.StartMonom;
	Polynom f = Polynom(1);
	Monom* ptr3 = f.StartMonom;
	int size1 = this->SIZE;
	int size2 = polynom.SIZE;
	double coef1=0.0;
	double coef2=0.0;
	int degree1 = 0;
	int degree2 = 0;
	for (int i = 0; i < size1; i++)
	{
		coef1=ptr1->GetCurrentMonom()->GetCoef();
		degree1=ptr1->GetCurrentMonom()->GetDegree();
		for (int j = 0; j < size2; j++)
		{
			coef2 = ptr2->GetCurrentMonom()->GetCoef();
			degree2 = ptr2->GetCurrentMonom()->GetDegree();
			coef1 *= coef2;
			degree1 += degree2;
			coef2 = 0.0;
			degree2 = 0;
			if (j + 1 == size2)
			{
				ptr2 = polynom.StartMonom;
				break;
			}
			ptr2 = ptr2->GetNextMonom();
		}
		ptr3->GetCurrentMonom()->SetCoef(coef1);
		ptr3->GetCurrentMonom()->SetDegree(degree1);
		coef1 = 0.0;
		degree1 = 0;
		if (i + 1 == size1)
		{
			break;
		}
		ptr1=ptr1->GetNextMonom();
		Monom g = Monom();
		ptr3->SetNextMonom(g);
		ptr3 = ptr3->GetNextMonom();
	}
	f.SIZE = size1;
//	f.Equalizer();
	return f;
}

Polynom Polynom::operator/(const Polynom& polynom)
{
	Monom* ptr1 = this->StartMonom;
	Monom* ptr2 = polynom.StartMonom;
	Polynom f = Polynom(1);
	Monom* ptr3 = f.StartMonom;
	int size1 = this->SIZE;
	int size2 = polynom.SIZE;
	double coef1 = 0.0;
	double coef2 = 0.0;
	int degree1 = 0;
	int degree2 = 0;
	for (int i = 0; i < size1; i++)
	{
		coef1 = ptr1->GetCurrentMonom()->GetCoef();
		degree1 = ptr1->GetCurrentMonom()->GetDegree();
		for (int j = 0; j < size2; j++)
		{
			coef2 = ptr2->GetCurrentMonom()->GetCoef();
			degree2 = ptr2->GetCurrentMonom()->GetDegree();
			coef1 /= coef2;
			degree1 -= degree2;
			coef2 = 0.0;
			degree2 = 0;
			if (j + 1 == size2)
			{
				ptr2 = polynom.StartMonom;
				break;
			}
			ptr2 = ptr2->GetNextMonom();
		}
		ptr3->GetCurrentMonom()->SetCoef(coef1);
		ptr3->GetCurrentMonom()->SetDegree(degree1);
		coef1 = 0.0;
		degree1 = 0;
		if (i + 1 == size1)
		{
			break;
		}
		ptr1 = ptr1->GetNextMonom();
		Monom g = Monom();
		ptr3->SetNextMonom(g);
		ptr3 = ptr3->GetNextMonom();
	}
	f.SIZE = size1;
	//	f.Equalizer();
	return f;
}

Polynom::~Polynom()
{
	/*
	Monom* ptr;
	Monom* ptr2;
	ptr= StartMonom->GetNextMonom();
	for (int i = 0; i < SIZE; i++)
	{
		ptr->GetNextMonom();
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (i + 1 == SIZE)
		{
			ptr->~Monom();
			break;
		}
		ptr2 = ptr->GetBackMonom();
		ptr->~Monom();
		ptr = ptr2;
	}
	ptr2 = NULL;
	ptr = NULL;
	delete ptr;
	delete ptr2;*/
	this->DeleteList();
	//delete StartMonom;
	SIZE = 0;
}

double Polynom::Calculate(double X)
{
	double x = 0;
	int buf1 = 1;
	Monom* ptr1 = StartMonom;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < ptr1->GetCurrentMonom()->GetDegree(); j++)
		{
			buf1 *= X;
		}
		x += ptr1->GetCurrentMonom()->GetCoef() * buf1;
		buf1 = 1;
		if (i + 1 == SIZE)
		{
			break;
		}
		ptr1=ptr1->GetNextMonom();
	}
	return x;
}

std::ostream& operator<<(std::ostream& out, const Polynom& monom)
{
	Monom* ptr;
	Monom* ptr2;
	//out << monom.StartMonom;
	ptr = monom.StartMonom;
	out << *ptr;
	int size = monom.SIZE;
	for(int i=1;i<size;i++)
	{
	/*	if (ptr->GetNextMonom()->GetCoef() == 0.0 || ptr->GetNextMonom()->GetDegree() == 0)
		{
			ptr2 = ptr->GetNextMonom()->GetNextMonom();
			ptr->GetNextMonom()->~Monom();
			ptr = ptr2;
		}*/
		out << *(ptr->GetNextMonom());
		ptr = ptr->GetNextMonom();
	}
	return out;
}

std::istream& operator>>(std::istream& in,Polynom& monom)
{
	if (monom.GetNextMonom() != NULL)
	{
		monom.DeleteList();
	}
	delete monom.StartMonom;
	monom.StartMonom = new Monom();
	Monom* ptr = monom.StartMonom;
	in >> *ptr;
	for (int i = 0; i < monom.SIZE; i++)
	{
		if (i + 1 == monom.SIZE)
		{
			break;
		}
		Monom* g = new Monom();
		in >> *g;

		ptr->SetNextMonom(*g);
		ptr = ptr->GetNextMonom();
	}
//	-------------------------------------------------------------------------------------------
/*
	in >> *monom.StartMonom;
	Monom* r = new Monom[monom.SIZE - 1];
	monom.StartMonom->SetNextMonom(r[0]);
	r[0].SetBackMonom(*monom.StartMonom);
	for (int i = 1; i < monom.SIZE; i++)
	{
		in >> r[i];
		if (i + 1 == monom.SIZE)
		{
			break;
		}
		r[i].SetNextMonom(r[i + 1]);
		if (i == 1)
		{
			continue;
		}
		r[i].SetBackMonom(r[i - 1]);
	}*/
	return in;
}


/*	Polynom f = Polynom(1);
	Monom* ptr3 = f.StartMonom;
	//Polynom g = Polynom(*this);
	Monom* ptr1 = this->StartMonom;
	Monom* ptr2 = polynom.StartMonom;
	int size = SIZE;
	int size2 = polynom.SIZE;
	int degree1 = 0;
	int degree2 = 0;
	int* degree3 = new int[size];
	degree3[0] = -100;
	int newsize = 0;
	bool flag;
	int* switch1 = new int[size];
	int* switch2 = new int[size2];
	double ccoef1 = 0.0;
	double ccoef2 = 0.0;
	double ccoef3 = 0.0;
	for (int j = 0; j < size; j++)
	{
		degree1 = ptr2->GetCurrentMonom()->GetDegree();
		ccoef1 = ptr2->GetCurrentMonom()->GetCoef();
		switch1[j] = 1;
		flag = true;

		for (int k = 0; k < size; k++)
		{
			if (degree3[k] == degree1)
			{
				flag = false;
				break;
			}
		}
		if (j == 0)
		{
			degree3[0] = degree1;
			switch2[0] = 0;
		}
		degree3[j] = degree1;

		//Прописать хождения по первому списку
		if (flag == true)
		{
			for (int i = 0; i < size2; i++)
			{
				degree2 = ptr1->GetCurrentMonom()->GetDegree();
				ccoef2 = ptr1->GetCurrentMonom()->GetCoef();
				if (degree1 != degree2)
				{
					if (switch2[i] == 1)
					{
						;
					}
					else
					{
						switch2[i] = 0;
					}
					
				}
				if (degree1 == degree2)
				{
					/*if (i == j)
					{
						if (i + 1 == size)
						{
							continue;
						}
						ptr1 = ptr1->GetNextMonom();
						continue;
					}//
if (switch2[i] == 1 || switch1[j] == 1)
{
	if (i + 1 == size)
	{
		continue;
	}
	ptr1 = ptr1->GetNextMonom();
	continue;
}
switch2[i] = 1;
ccoef1 += ccoef2;
				}
				if (i + 1 == size)
				{
					continue;
				}
				ptr1 = ptr1->GetNextMonom();
				//Сравнивать все эементы второго списка с элементом превого . В случае совпадени Coef складывать и во втром списке ставить -100,-100 вместого того , что было 
			}
		}
		if (ccoef1 == 0.0)
		{
			continue;
		}
		if (flag == true)
		{
			ptr3->GetCurrentMonom()->SetCoef(ccoef1);
			ptr3->GetCurrentMonom()->SetDegree(degree1);
			newsize++;
		}
		ccoef1 = 0.0;
		if (j + 1 == size)
		{
			break;
		}
		if (flag == true)
		{
			Monom g = Monom();
			ptr3->SetNextMonom(g);
			ptr3 = ptr3->GetNextMonom();
		}
		ptr2 = ptr2->GetNextMonom();
		ptr1 = this->StartMonom;
	}
	Polynom Res = Polynom(newsize);
	Monom* ptr5 = f.StartMonom;
	for (int i = 0; i < f.SIZE; i++)
	{
		if (i + 1 == f.SIZE)
		{
			break;
		}
		ptr5 = ptr5->GetNextMonom();
	}
	for (int i = 0; i < size2; i++)
	{
		if (switch2[i] == 0)
		{
			size++;
		}
	}
	Monom* ptr4 = f.StartMonom;
	f.SIZE = size;
	int sssize = polynom.SIZE;
	Monom* ptr6 = polynom.StartMonom;
	for (int i = 0; i < size; i++)
	{
		if (i == sssize)
		{
			break;
		}
		ptr6->GetCurrentMonom();
		if (switch2[i] == 0)
		{
			Monom* newm = new Monom(ptr6->GetCoef(), ptr6->GetDegree());
			ptr5->SetNextMonom(*newm);
		}
	}

	//	Polynom Res = Polynom(newsize);
	f.StartMonom;
	f.SIZE = size;
	f.Equalizer();
	Res = f;
	ptr1 = NULL;
	ptr2 = NULL;
	ptr3 = NULL;
	delete ptr1;
	delete ptr2;
	delete ptr3;
	delete[] degree3;
	delete[] switch1;
	delete[] switch2;
	return Res; */
