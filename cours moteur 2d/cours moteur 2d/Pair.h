#pragma once

template <typename T, typename U> class Pair
{
private:
	T t;
	U u;
public:
	Pair(T firstValue, U secondValue) :
		t(firstValue), u(secondValue) {
	};

	T GetFirstValue();
	void SetFirstValue(T newFirstValue);

	U GetSecondValue();
	void SetSecondValue(U newSecondValue);
};

template<typename T, typename U>
inline T Pair<T, U>::GetFirstValue()
{
	return T();
}

template<typename T, typename U>
inline void Pair<T, U>::SetFirstValue(T newFirstValue)
{
	t = newFirstValue;
}

template<typename T, typename U>
inline U Pair<T, U>::GetSecondValue()
{
	return U();
}

template<typename T, typename U>
inline void Pair<T, U>::SetSecondValue(U newSecondValue)
{
	u = newSecondValue;
}
