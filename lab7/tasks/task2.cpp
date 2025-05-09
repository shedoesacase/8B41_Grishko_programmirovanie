#include <iostream>
#include <cstdlib>

// Функция проверки возможности достижения цели за указанное время
bool canReach(signed int sx, signed int sy, signed int fx, signed int fy, unsigned int t) {
    // Вычисляем расстояние по осям X и Y
    signed int dx = abs(sx - fx);
    signed int dy = abs(sy - fy);
    
    // Определяем минимальное необходимое количество шагов
    signed int minSteps = std::max(dx, dy);
    
    // Проверяем условие достижимости
    return t >= static_cast<unsigned int>(minSteps);
}