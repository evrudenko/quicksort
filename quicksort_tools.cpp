#include "quicksort_header.hpp"

// Удаление из строки лишних символов и пробелов.
string format_string(string str) {
	size_t index = 0;

	while(true) {
		index = str.find("[");

		if(index == string::npos)
			break;

		str.replace(index, 1, "");
	}
	while(true) {
		index = str.find("]");

		if(index == string::npos)
			break;

		str.replace(index, 1, "");
	}
	while(true) {
		index = str.find(",");

		if(index == string::npos)
			break;

		str.replace(index, 1, "");
	}

	auto tail_begin = unique(str.begin(), str.end(), [](char l, char r) {
		return isspace(l) && isspace(r) && l == r;
	});

	str.erase(tail_begin, str.end());

	if(str[0] == ' ')
		str.erase(0, 1);
	if(str[str.length() - 1] == ' ')
		str.erase(str.length() - 1, 1);

	return str;
}

// Чтение чисел файла в вектор.
vector<double> read_array(string filename) {
	ifstream fin(filename);
	vector<double> v_res;

	if(!fin.is_open()) {
		cout << "ERRORS~!";
		return v_res;
	}

	stringstream ss;
	double buff_value;
	string buff_string;

	while(!fin.eof()) {
		getline(fin, buff_string);

		buff_string = format_string(buff_string);

		if(buff_string.length() < 1)
			continue;

		ss.str(buff_string);

		while(!ss.eof()) {
			ss >> buff_value;

			v_res.push_back(buff_value);
		}
		ss.clear();
	}

	fin.close();

	return v_res;
}

// Вывод вектора v в консоль.
void list_array(vector<double> v) {
	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << (i == v.size() - 1 ? "" : " ");
	cout << endl;
}

// Разбиение вектора на левую и правую части, в левую
// переносятся значения, меньшие опорного, остальные
// в правую. Опорным элементом выбирается первый эелемент
// вектора.
int partition(vector<double> &v, int begin, int end) {
	double x = v[begin];
	int i = begin, j = end;

	while(true) {
		while(v[j] >= x && j > begin)
			--j;
		while(v[i] < x && i < end)
			++i;
		if(i < j)
			swap(v[i], v[j]);
		else
			return j;
	}
}

// Сортировка элементов вектора с индекса begin до end,
// включительно.
void quicksort(vector<double> &v, int begin, int end) {
	if(begin < end) {
		int wall = partition(v, begin, end);
		quicksort(v, begin, wall);
		quicksort(v, wall + 1, end);
	}
}