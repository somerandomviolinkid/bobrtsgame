#include "mathUtil.h"

template <typename T>
v2<T> operator + (v2<T> a, v2<T> b) {
	return {a.x + b.x, a.y + b.y};
};

template <typename T>
v2<T> operator - (v2<T> a, v2<T> b) {
	return { a.x - b.x, a.y - b.y };
};

v2<float> operator * (v2<float> a, float b) {
	return { a.x * b, a.y * b };
};

v2<float> operator / (v2<float> a, float b) {
	return { a.x / b, a.y / b };
};

v2<float> v2i2f(v2<int> v) {
	return {(float)v.x, float(v.y)};
}

v2<int> v2f2i(v2<float> v) {
	return { (int)v.x, int(v.y) };
}

float randf(float min, float max) {
	return (((float)rand() / (float)RAND_MAX) * (max - min)) + min;
}

v2<int> bezier(v2<int> a, v2<int> b, v2<int> c, float t) {
	return v2f2i((v2i2f(a) * ((1.0f - t) * (1.0f - t))) + (v2i2f(b) * (2.0f * (1.0f - t) * t)) + (v2i2f(c) * (t * t)));
}