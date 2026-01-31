/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoyat <ngoyat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:16:20 by ngoyat            #+#    #+#             */
/*   Updated: 2026/01/31 20:07:23 by ngoyat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

/*
    MutantStack inherits from std::stack.
    std::stack stores its elements in a protected container called "c".
    Make the stack iterable by exposing iterators to this container.
*/

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    MutantStack& operator=(const MutantStack& other)
    {
        std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    // Iterator types taken from the underlying container
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    // Begin iterator
    iterator begin()
    {
        return this->c.begin();
    }

    // End iterator
    iterator end()
    {
        return this->c.end();
    }

    // Const versions
    const_iterator begin() const
    {
        return this->c.begin();
    }

    const_iterator end() const
    {
        return this->c.end();
    }
};

#endif
