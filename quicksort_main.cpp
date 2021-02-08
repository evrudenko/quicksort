#include "quicksort_tools.cpp"

int main(int argc, char const *argv[]) {
	if(argc != 2) {
		cout << "Right call: " << *argv << " filename.txt";
		return 1;
	}
	
	vector<double> v = read_array(argv[1]);

	cout << "Unsorted array:" << endl;
	list_array(v);

	quicksort(v, 0, v.size() - 1);

	cout << "\nSorted array:" << endl;
	list_array(v);
	
	return 0;
}