#ifndef CMEDIAN_HPP_
#define CMEDIAN_HPP_

#include <queue>

template<typename T>
class CMedian
{
private:
	std::priority_queue<T> _firstHalf; //top() -> max
	std::priority_queue<T, std::vector<T>, std::greater<T>> _secondHalf; //top() -> min
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
	if(_firstHalf.size() > 0 && elem > _firstHalf.top())
	{
		_secondHalf.push(elem);
	}
	else
	{
		_firstHalf.push(elem);
	}

	if(_firstHalf.size() > _secondHalf.size() + 1)
	{
		_secondHalf.push(_firstHalf.top());
		_firstHalf.pop();
	}
	else if(_secondHalf.size() > _firstHalf.size() + 1)
	{
		_firstHalf.push(_secondHalf.top());
		_secondHalf.pop();
	}
}

template<typename T>
double CMedian<T>::GetMedian() const
{
	//we need to check situation when both queues are empty
	//not implemented

	if(_firstHalf.size() > _secondHalf.size())
	{
		return (double)_firstHalf.top();
	}
	else if(_firstHalf.size() < _secondHalf.size())
	{
		return (double)_secondHalf.top();
	}
	else
	{
		return ((double)(_firstHalf.top() + _secondHalf.top())) / 2.0;
	}
}

#endif /* CMEDIAN_HPP_ */
