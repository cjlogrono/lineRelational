#ifndef LINES_CPP
#define LINES_CPP

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "Lines.h"

using namespace std;

namespace linesFn{
	
	lineType::lineType(){

		line.a = 0;
	}

	lineType::~lineType(){}

	void lineType::setCoefA(double aVal){

		line.a = aVal;
	}

	void lineType::setCoefB(double bVal){

		line.b = bVal;
	}

	void lineType::setValueC(double cVal){

		line.c = cVal;
	}

	void lineType::setSlope(double slopeVal){

		line.properties.slope = slopeVal;
	}

	void lineType::setPOIx(double POIVal){

		line.properties.POIx = POIVal;
	}

	void lineType::setPOIy(double POIVal){

		line.properties.POIy = POIVal;
	}

	void lineType::setVertical(bool verVal){

		line.properties.vertical = verVal;
	}

	void lineType::setHorizontal(bool horiVal){

		line.properties.horizontal = horiVal;
	}

	double lineType::getCoefA(){

		return line.a;
	}

	double lineType::getCoefB(){

		return line.b;
	}

	double lineType::getValueC(){

		return line.c;
	}

	double lineType::getSlope(){

		return line.properties.slope;
	}

	double lineType::getPOIx(){

		return line.properties.POIx;
	}

	double lineType::getPOIy(){

		return line.properties.POIy;
	}

	bool lineType::getVertical(){

		return line.properties.vertical;
	}

	bool lineType::getHorizontal(){

		return line.properties.horizontal;
	}
}

#endif //LINES_CPP