#include "smlist.h"
#include <string>

int main()
{
	list sparseMatrix;
	string mat = "0,1,0,0,3,4,0,0,2,0";
	int idx = 0, pos = 0, n;
	while (mat.length() > 0 && pos != -1) {
		pos = mat.find(",");
		n = (pos < 0) ? stoi(mat) : stoi(mat.substr(0, pos));
		if (n != 0)
			sparseMatrix.insert(idx, stoi(mat.substr(0, pos)));
		mat = mat.substr(pos + 1);
		idx++;
	}
	sparseMatrix.printAll();
	return 0;
}