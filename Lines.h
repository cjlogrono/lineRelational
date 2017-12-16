#ifndef LINES_H
#define LINES_H

using namespace std;

namespace linesFn{

	class lineType{

	public:

		lineType();

		~lineType();

		void setCoefA(double aVal);

		void setCoefB(double bVal);

		void setValueC(double cVal);

		void setSlope(double slopeVal);

		void setPOIx(double POIVal);

		void setPOIy(double POIVal);

		void setVertical(bool verVal);

		void setHorizontal(bool horiVal);

		double getCoefA();

		double getCoefB();

		double getValueC();

		double getSlope();

		double getPOIx();

		double getPOIy();

		bool getVertical();

		bool getHorizontal();


	private:

		struct lineProperties{

			bool vertical;
			bool horizontal;
			double slope;
			double POIx;
			double POIy;
		};

		struct lineComposition{

			double a;
			double b;
			double c;
			lineProperties properties;	
		};

		lineComposition line;

	};
} //empleados
#endif //LINES_H

#include "Lines.cpp"