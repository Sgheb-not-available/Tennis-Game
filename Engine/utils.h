#pragma once
#include <cmath>
#include <iostream>

typedef char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

#define globalVar static

inline int Clamp(int min, int val, int max) {
    if (val < min) return min;
    else if (val > max) return max;
    return val;
}

inline int Bigger(int a, int b) {
    return (a > b) ? a : b;
}

inline int CheckBounds(int val, int min, int max) {
    return (val >= min && val <= max);
}

inline float Pythagoran(float aX, float aY, float bX, float bY) {
    float result = sqrtf((aX - bX) * (aX - bX) + (aY - bY) * (aY - bY));
    return result;
}