#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	ofstream ofile(argv[1]);
	ifstream ifile("boilerplatecode.txt");
	char ch;
	ifile >> noskipws;
	while(ifile >> ch) {
		ofile << ch;
	}
	ofile.close();
	ifile.close();
	return 0;
}
