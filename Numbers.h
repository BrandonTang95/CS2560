
#pragma once

class Numbers
{
private:
	double *array;
	int size;
	void chkIndex(int index) const;
public:
	Numbers(int size = 100);
	~Numbers();
	void set(int index, double value);
	double get(int index) const;
	double getAverage() const;
};