#pragma once
#include <iostream>

template <typename T>
struct v2 {
	T x, y;
};

template <typename T>
v2<T> operator + (v2<T> a, v2<T> b);

template <typename T>
v2<T> operator - (v2<T> a, v2<T> b);

v2<float> operator * (v2<float> a, float b);

v2<float> operator / (v2<float> a, float b);

v2<float> v2i2f(v2<int> v);

v2<int> v2f2i(v2<float> v);

float randf(float min, float max);

v2<int> bezier(v2<int> a, v2<int> b, v2<int> c, float t);

v2<float> project(v2<float> p);

v2<float> aproject(v2<float> p);

float dist2d(v2<float> a, v2<float> b);