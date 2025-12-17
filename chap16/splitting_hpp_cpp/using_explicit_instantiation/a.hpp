#pragma once

template<typename T>

struct A 
{
  void test();
};

template class A<int>;
template class A<double>;
template class A<float>;
