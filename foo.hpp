#pragma once

#include "Human.hpp"

#include <algorithm>
#include <list>
#include <vector>

using namespace std;

std::vector< char > foo(std::list< Human >& people)
{
    vector< char > retval(people.size()); //tworzymy wektor o rozmiarze people

    auto lam = [](Human& person) { person.birthday(); };
    for_each(people.begin(), people.end(), lam); //wykonujemy na kazdym elemencie lam czyli wywoluje metode birthday dla kazdego skladnika w wektorze. Uzywamy Human& bo przekazujemy oryginalny obiekt, a nie kopie

    auto lambda = [](Human& person) 
    { 
        char result = 'y';
        if (person.isMonster()) 
        {
            result = 'n';
        }
        return result;
    };
    // Tworzenie wektora zwracanego w odwrotnej kolejności i sprawdzanie warunku isMonster
    transform(people.rbegin(), people.rend(), retval.begin() ,lambda);

    return retval;
}
