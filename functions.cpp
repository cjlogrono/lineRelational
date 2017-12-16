#include <iostream>
#include <fstream>
#include <string>
#include "Lines.h"
using namespace linesFn;

namespace functions{
	
	bool validoresFunciones(int choice, int opcion, char character){

		bool truefalse;

		switch(choice){

			case 1:

				if(character == 'Y' || character == 'y' || character == 'N' || character == 'n'){

					truefalse = false;

				}else{

					truefalse = true;
					cout << "\n**Introdujo un caracter invalido**\n";

				}

				break;

			case 2:

				if(character == 'Y' || character == 'y'){

					truefalse = true;

				}
				else{

					truefalse = false;

				}

				break;

		}

		return truefalse;
	}

	bool seguir(){

		char contestacion;

			do{

				cout << "\n\nDesea seguir usando el programa? (Y/N)\n";
				cout << "Contestacion: ";
				cin >> contestacion;

			}while(validoresFunciones(1, 0,contestacion));

			return validoresFunciones(2,0,contestacion);
	}

	void introduccion(){

		cout << "\n\nBienvenidos, este programa creara dos ecuaciones de lineas con los datos\n que usted introduzca.\n";
	 	cout << "Luego le dire todo tipo de informacion que tienen el relacion estas dos lineas.\n";
	}

	void createLines(lineType &lineOne, lineType &lineTwo){

		double dummyVal;
		bool invalid;

		do{

			cout << "\nCurrently line #1 looks like: ax + by = c\n";

			do{

				cout << "what value does (a) equal to?\n";
				cout << "a = ";
				cin >> dummyVal; 

				if(cin.fail()){

					cin.clear();
					cin.ignore();
					invalid = true;

					cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";
				}else{

					invalid = false;
				}

			}while(invalid);

			lineOne.setCoefA(dummyVal);

			cout << "\nCurrently line #1 looks like: " << lineOne.getCoefA() << "x + by = c\n\n";

			do{

				cout << "what value does (b) equal to?\n";
				cout << "b = ";
				cin >> dummyVal; 

				if(cin.fail()){

					cin.clear();
					cin.ignore();
					invalid = true;

					cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";
				}else{

					invalid = false;
				}

			}while(invalid);

			lineOne.setCoefB(dummyVal);

			if(lineOne.getCoefA() == 0 && lineOne.getCoefB() == 0){

				cout << "\n\n** Los valores de a Y b no pueden 0 a la misma vez, introduzcalos otra vez **\n\n";
				invalid = true;
			
			}else{

				invalid = false;
			}

		}while(invalid);

		cout << "\nCurrently line #1 looks like: " << lineOne.getCoefA() << "x + " << lineOne.getCoefB()<< "y = c\n\n";

		do{

				cout << "what value does (c) equal to?\n";
				cout << "c = ";
				cin >> dummyVal; 

				if(cin.fail()){

					cin.clear();
					cin.ignore();
					invalid = true;

					cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";
				}else{

					invalid = false;
				}

		}while(invalid);

		lineOne.setValueC(dummyVal);

		cout << "\nLine #1 is: " << lineOne.getCoefA() << "x + " << lineOne.getCoefB()<< "y = " << lineOne.getValueC() << "\n\n"; 

		do{

			cout << "\nCurrently line #2 looks like: ax + by = c\n";

			do{

				cout << "what value does (a) equal to?\n";
				cout << "a = ";
				cin >> dummyVal; 

				if(cin.fail()){

					cin.clear();
					cin.ignore();
					invalid = true;

					cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";
				}else{

					invalid = false;
				}

			}while(invalid);

			lineTwo.setCoefA(dummyVal);

			cout << "\nCurrently line #2 looks like: " << lineTwo.getCoefA() << "x + by = c\n\n";

			do{

				cout << "what value does (b) equal to?\n";
				cout << "b = ";
				cin >> dummyVal; 

				if(cin.fail()){

					cin.clear();
					cin.ignore();
					invalid = true;

					cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";
				}else{

					invalid = false;
				}

			}while(invalid);

			lineTwo.setCoefB(dummyVal);

			if(lineTwo.getCoefA() == 0 && lineTwo.getCoefB() == 0){

				cout << "\n\n** Los valores de a Y b no pueden 0 a la misma vez, introduzcalos otra vez **\n\n";
				invalid = true;
			
			}else{

				invalid = false;
			}

		}while(invalid);

		cout << "\nCurrently line #2 looks like: " << lineTwo.getCoefA() << "x + " << lineTwo.getCoefB()<< "y = c\n\n";

		do{

			cout << "what value does (c) equal to?\n";
			cout << "c = ";
			cin >> dummyVal; 

			if(cin.fail()){

				cin.clear();
				cin.ignore();
				invalid = true;

				cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";
			}else{

				invalid = false;
			}

		}while(invalid);

		lineTwo.setValueC(dummyVal);

		cout << "\n\nThe two lines being used in these operations will be:\n";
		cout << "Line one: "<< lineOne.getCoefA() << "x + " << lineOne.getCoefB()<< "y = " << lineOne.getValueC();
		cout << " & Line two: " << lineTwo.getCoefA() << "x + " << lineTwo.getCoefB()<< "y = " << lineTwo.getValueC();
	}

	void slopeCalculator(lineType &lineOne, lineType &lineTwo){

		if(lineOne.getCoefA() == 0 && lineOne.getCoefB() != 0){

			lineOne.setHorizontal(true);
			lineOne.setVertical(false);
			lineOne.setSlope(0);

		}else if(lineOne.getCoefB() == 0 && lineOne.getCoefA() != 0){

			lineOne.setVertical(true);
			lineOne.setHorizontal(false);

		}else{

			lineOne.setSlope( -(lineOne.getCoefA()) / lineOne.getCoefB() ) ;
			lineOne.setVertical(false);
			lineOne.setHorizontal(false);
		}

		if(lineTwo.getCoefA() == 0 && lineTwo.getCoefB() != 0){

			lineTwo.setHorizontal(true);
			lineTwo.setVertical(false);
			lineTwo.setSlope(0);

		}else if(lineTwo.getCoefB() == 0 && lineTwo.getCoefA() != 0){

			lineTwo.setVertical(true);
			lineTwo.setHorizontal(false);

		}else{

			lineTwo.setSlope( -(lineTwo.getCoefA()) / lineTwo.getCoefB() ) ;
			lineTwo.setVertical(false);
			lineTwo.setHorizontal(false);
		}

		cout << "\n\nSlopes:\n";

		cout << "Line one: ";

		if( lineOne.getVertical() && !lineOne.getHorizontal() ){

			cout << "-undefined-";

		}else if( !lineOne.getVertical() && lineOne.getHorizontal() ){

			cout << "-none or 0-";

		}else{

			cout << lineOne.getSlope();
		} 

		cout << " & Line two: ";

		if( lineTwo.getVertical() && !lineTwo.getHorizontal() ){

			cout << "-undefined-";

		}else if( !lineTwo.getVertical() && lineTwo.getHorizontal() ){

			cout << "-none or 0-";

		}else{

			cout << lineTwo.getSlope();
		}
	}

	bool lineEqual(lineType lineOne, lineType lineTwo){

		bool equal;

		if(lineOne.getCoefA() == lineTwo.getCoefA() && 
		   lineOne.getCoefB() == lineTwo.getCoefB() && 
		   lineOne.getValueC() == lineTwo.getValueC())
		{

			equal = true;

		}else if( !(lineOne.getCoefA() == 0 || lineOne.getCoefB() == 0) &&
				  static_cast<int>(lineOne.getCoefA()) % static_cast<int>(lineTwo.getCoefA()) == 0 && 
				  static_cast<int>(lineOne.getCoefB()) % static_cast<int>(lineTwo.getCoefB()) == 0 &&
				  static_cast<int>(lineOne.getValueC()) % static_cast<int>(lineTwo.getValueC()) == 0 && 
				  lineOne.getSlope() == lineTwo.getSlope())
		{

			equal = true;
		
		}else if( !(lineTwo.getCoefA() == 0 || lineTwo.getCoefB() == 0) &&
				  static_cast<int>(lineTwo.getCoefA()) % static_cast<int>(lineOne.getCoefA()) == 0 && 
				  static_cast<int>(lineTwo.getCoefB()) % static_cast<int>(lineOne.getCoefB()) == 0 &&
				  static_cast<int>(lineTwo.getValueC()) % static_cast<int>(lineOne.getValueC()) == 0 && 
				  lineOne.getSlope() == lineTwo.getSlope())
		{

			equal = true;
		
		}else{

			equal = false;
		}

		cout << "\n\nAre the lines equal to each other?";

		if(equal){

			cout << " Yes!\n";
			cout << "Are the lines parallel? Yes!\n";
			cout << "Are the lines perpendicular? No!\n";	
			cout << "Points of Intersection? none.\n";	

		}else{

			cout << " No!";
			cout << "\nAre the lines parallel?";
		}

		return equal;
	}

	bool lineParallel(lineType lineOne, lineType lineTwo){

		bool parallel;

		if((lineOne.getVertical() && lineTwo.getVertical()) || (lineOne.getSlope() == lineTwo.getSlope()) ){

			cout << " Yes!\n";
			cout << "Are the lines perpendicular? No!\n";	
			cout << "Points of Intersection? none.\n";
			parallel = true;

		}else{

			cout << " No!\n";
			cout << "Are the lines perpendicular?";
			parallel = false;
		}

		return parallel;
	}

	void linePerpendicular(lineType lineOne, lineType lineTwo){

		if((lineOne.getHorizontal() && lineTwo.getVertical()) || (lineTwo.getHorizontal() && lineOne.getVertical()) || (lineOne.getSlope() * lineTwo.getSlope() == -1) ){

			cout << " Yes!\n";

		}else{

			cout << " No!\n";
		}
	}

	void linesPOI(lineType &lineOne, lineType &lineTwo){

		if( lineOne.getVertical() && lineTwo.getHorizontal() ){

			lineOne.setPOIx( lineOne.getValueC() / lineOne.getCoefA() );
			lineOne.setPOIy( lineTwo.getValueC() / lineTwo.getCoefB() );

			lineTwo.setPOIx( lineOne.getValueC() / lineOne.getCoefA() );
			lineTwo.setPOIy( lineTwo.getValueC() / lineTwo.getCoefB() );

		}else if( lineTwo.getVertical() && lineOne.getHorizontal() ){

			lineOne.setPOIx( lineTwo.getValueC() / lineTwo.getCoefA() );
			lineOne.setPOIy( lineOne.getValueC() / lineOne.getCoefB() );

			lineTwo.setPOIx( lineTwo.getValueC() / lineTwo.getCoefA() );
			lineTwo.setPOIy( lineOne.getValueC() / lineOne.getCoefB() );
			
		}else{

			lineOne.setPOIx(( (lineTwo.getValueC() / lineTwo.getCoefB()) - (lineOne.getValueC() / lineOne.getCoefB()) ) / ( -(lineOne.getCoefA() / lineOne.getCoefB()) + (lineTwo.getCoefA() / lineTwo.getCoefB()) ));
			lineOne.setPOIy(( -(lineOne.getCoefA() / lineOne.getCoefB() ) * lineOne.getPOIx()) + ( lineOne.getValueC() / lineOne.getCoefB() ));

			lineTwo.setPOIx(( (lineTwo.getValueC() / lineTwo.getCoefB()) - (lineOne.getValueC() / lineOne.getCoefB()) ) / ( -(lineOne.getCoefA() / lineOne.getCoefB()) + (lineTwo.getCoefA() / lineTwo.getCoefB()) ));
			lineTwo.setPOIy(( -(lineOne.getCoefA() / lineOne.getCoefB() ) * lineTwo.getPOIx()) + ( lineOne.getValueC() / lineOne.getCoefB() ));
		}	

		cout << "Points of Intersection? (" << lineOne.getPOIx() << ", " << lineOne.getPOIy() << ")";

	}

}