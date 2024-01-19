#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		size_t	ActSize;
		size_t	Arraysize;
		std::vector<int> Array;
	public:
		Span();
		Span(size_t size);
		~Span();
		Span(const Span &tmp);
		Span &operator=(const Span &tmp);
		void	addNumber(int data);
		template <typename T>
		void	addManyNumbers(T &container)
		{
			if (std::distance(container.begin(), container.end()) > (int)(this->Arraysize - this->ActSize))
				throw std::overflow_error("this container is bigger than this vector's capacity");
			typename T::iterator iter;
			iter = container.begin();
			while (iter != container.end())
			{
				this->Array.push_back(*iter);
				this->ActSize++;
				iter++;
			}
		};
		size_t	longestSpan() const;
		size_t	shortestSpan() const;
};

#endif