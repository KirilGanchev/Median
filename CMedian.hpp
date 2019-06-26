#ifndef CMEDIAN_HPP_
#define CMEDIAN_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template<typename T>
class CMedian
{
private:
	std::vector<T> _data;
public:
	CMedian() = default;
	~CMedian() = default;
	CMedian (const CMedian&) = delete;
	CMedian (CMedian&&) = delete;
	CMedian& operator= (const CMedian&) = delete;
	CMedian& operator= (CMedian&&) = delete;

	void Add(const T& elem);
	void Add_1(const T& elem);
	double GetMedian() const;
	void Print() const;
};

template<typename T>
void CMedian<T>::Add(const T& elem)
{
	auto elemPosition = std::upper_bound(_data.begin(), _data.end(), elem);
	_data.insert(elemPosition, elem);
}

template<typename T>
void CMedian<T>::Add_1(const T& elem)
{
	_data.push_back(elem);

	int index = _data.size() - 1;

	while(index > 0 && _data[index - 1] > elem)
	{
		_data[index] = _data[index - 1];
		--index;
	}

	if(index != _data.size() - 1)
	{
		_data[index] = elem;
	}
}

template<typename T>
double CMedian<T>::GetMedian() const
{
	size_t length = _data.size();

	if(length == 0) throw std::length_error("The array size is zero");

	if(length % 2 == 0)
	{
		return ((double)(_data[(length - 1) / 2] + _data[length / 2]) / 2.0);
	}
	else
	{
		return (double)_data[length / 2];
	}
}

template<typename T>
void CMedian<T>::Print() const
{
	for(T elem : _data)
	{
		std::cout << elem << " ";
	}
	std::cout<<std::endl;
}

#endif /* CMEDIAN_HPP_ */
