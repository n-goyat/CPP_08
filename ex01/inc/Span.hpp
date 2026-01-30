/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoyat <ngoyat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 20:24:57 by ngoyat            #+#    #+#             */
/*   Updated: 2026/01/30 20:24:57 by ngoyat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span
{
private:
    std::vector<int> _numbers; // Stores all the numbers
    unsigned int _capacity;    // Maximum number of elements allowed

public:
    // Constructor: sets the maximum number of elements
    Span(unsigned int n) : _capacity(n) {}
    ~Span() {}
    Span(const Span& other) : _numbers(other._numbers), _capacity(other._capacity) {}

    Span& operator=(const Span& other)
    {
        if (this != &other)
        {
            _numbers = other._numbers;
            _capacity = other._capacity;
        }
        return *this;
    }

    // Add a single number to the span
    void addNumber(int number)
    {
        if (_numbers.size() >= _capacity)
            throw std::out_of_range("Span is full");
        _numbers.push_back(number);
    }

    // Add multiple numbers using iterators
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end)
    {
        if (_numbers.size() + std::distance(begin, end) > _capacity)
            throw std::out_of_range("Adding this range exceeds capacity");
        _numbers.insert(_numbers.end(), begin, end);
    }

    // Calculate the shortest span (minimum difference)
    int shortestSpan()
    {
        if (_numbers.size() < 2)
            throw std::logic_error("Not enough numbers to find a span");

        std::vector<int> sorted(_numbers); // Copy to sort
        std::sort(sorted.begin(), sorted.end());

        int minSpan = sorted[1] - sorted[0];
        for (size_t i = 1; i < sorted.size() - 1; ++i)
        {
            int diff = sorted[i + 1] - sorted[i];
            if (diff < minSpan)
                minSpan = diff;
        }
        return minSpan;
    }

    // Calculate the longest span (max difference)
    int longestSpan()
    {
        if (_numbers.size() < 2)
            throw std::logic_error("Not enough numbers to find a span");

        int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
        int minVal = *std::min_element(_numbers.begin(), _numbers.end());

        return maxVal - minVal;
    }

    // Debug function: print all numbers
    void print() const
    {
        std::cout << "Span contents: ";
        for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
};

#endif
