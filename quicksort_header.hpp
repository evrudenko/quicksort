#ifndef _QUICKSORT_HEADER_HPP_
#define _QUICKSORT_HEADER_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

/*
 * Приводит строку row в удобную для дальнейшей обработки форму.
 * Удаляет лишние пробелы.
*/
string format_string(string str);

/*
 * Функция возвращает вектор, содержащий числа, находящиеся в
 * файле filename.
*/
vector<double> read_array(string filename);

/*
 * Функция выводит вектор v в консоль.
*/
void list_array(vector<double> v);

/*
 * Вспомогательная функция для функции quicksort().
 * Функция рассматривает только элементы вектора v, начинающиеся
 * с позиции begin и заканчивающиеся позицией end включительно.
 * Выбирает первый элемент вектора v и назначает его опорным.
 * Все числа вектора, большие или равные опорному, переносятся
 * в правую часть вектора, остальные остаются в левой.
 * Возвращает номер граничного элемента - последний элемент
 * левой части.
*/
int partition(vector<double> &v, int begin, int end);

/*
 * Функция сортировки элементов вектора v, начинающихся с
 * позиции begin и заканчивающихся позицией end включительно.
*/
void quicksort(vector<double> &v, int begin, int end);

#endif