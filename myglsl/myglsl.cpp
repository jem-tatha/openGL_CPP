#include <cassert>
#include <cmath>
#include <iostream>
#include "myglsl.h"

using namespace std;

typedef float f32;

vec_f operator-(const vec_f& x, const vec_f& y)
{ 
	assert(x.size() == y.size());
	vec_f tmp;
	for(size_t i = 0; i < x.size(); ++i)
		tmp.push_back(x[i] - y[i]);

	return tmp;
}

double operator*(const vec_f& x, const vec_f& y)
{
	assert(x.size() == y.size());

	double sum = 0.;

	for (size_t i = 0; i < x.size(); ++i)
		sum += x[i]*y[i];

	return sum;
}

// 三维的情况
vec_f operator^(const vec_f& x, const vec_f& y)
{
	assert(x.size() == y.size() && x.size() == 3); 

	return vec_f{x[1]*y[2]-x[2]*y[1], x[2]*y[0]-x[0]*y[2], x[0]*y[1]-x[1]*y[0]};
}

// 二维就姑且返回其模长吧
double twoDCrossProd(const vec_f& x, const vec_f& y)
{
	return x[0]*y[1]-x[1]*y[0];
}

double norm(const vec_f& x)
{
	double val = 0.;

	for(auto elem: x)
		val += elem*elem;

	return sqrt(val);
}

int main()
{
	vec_f color = {12.3456, 23.4567, 34.5678, 45.6789};
	vec_f lightning = {1.0, 1.0, 1.0, 1.0};

	for (size_t i = 0; i < color.size(); ++i)
	{
		cout << showpoint << color[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < lightning.size(); ++i)
	{
		cout << showpoint << lightning[i] << " ";
	}
	cout << endl;

	vec_f tmp = color - lightning;
	
	for (size_t i = 0; i < tmp.size(); ++i)
	{
		cout << showpoint << tmp[i] << " ";
	}
	cout << endl;

	cout << "norm(12.3456, 23.4567, 34.5678, 45.6789) = " << norm(color) << endl;

	return 0;
}
