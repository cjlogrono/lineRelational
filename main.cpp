#include <iostream>
#include <cctype>
#include "Lines.h"
#include "functions.cpp"

using namespace std;
using namespace functions;
using namespace linesFn;

int main(){

	do{

		lineType lineOne, lineTwo;

		introduccion();

		createLines(lineOne, lineTwo);

		slopeCalculator(lineOne, lineTwo);

		if(!lineEqual(lineOne, lineTwo)){

			if(lineParallel(lineOne, lineTwo)){


			}else{

				linePerpendicular(lineOne, lineTwo);

				linesPOI(lineOne, lineTwo);
			}
		}

	}while(seguir());

	cout << "\n\nGracias por usar el programa. Tenga un buen dia.\n\n";

	return 0;
}