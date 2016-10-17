#include <iostream>

class TComplex
{
public:
	TComplex();
	TComplex(double a,double b)
	{
		real=a;
		image=b;
	}
	TComplex operator+(const TComplex&c);
	//TComplex operator-(const TComplex&c);
	TComplex operator*(const TComplex&c);
	TComplex operator/(const TComplex&c);

	friend TComplex operator-(const TComplex&c1,const TComplex&c2);
	void display();
	~TComplex();

private:
	double real,image;
};


TComplex::TComplex()
{
	real=image=0;
}

TComplex::~TComplex()
{
}

TComplex operator-(const TComplex&c1,const TComplex&c2)
{
	return TComplex(c1.real-c2.real,c1.image-c2.image);
}
TComplex TComplex::operator+(const TComplex&c)
{
	return TComplex(real+c.real,image+c.image);
}
//TComplex TComplex::operator-(const TComplex&c)
//{
//	return TComplex(real-c.real,image-c.image);
//}
TComplex TComplex::operator*(const TComplex&c)
{
	return TComplex(real*c.real,image*c.image);
}
TComplex TComplex::operator/(const TComplex&c)
{
	return TComplex(real/c.real,image/c.image);
}
void TComplex::display()
{
	cout<<"real:"<<real<<"image:"<<image<<endl;
}