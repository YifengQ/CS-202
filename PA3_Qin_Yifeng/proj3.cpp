#include <iostream>
#include <fstream>
using namespace std;

const int maxsize=255;

//Function along with my setter and getter functions
int str_compare(float* price1, float* price2)
{
	
}
void myStringCopy (char *destination, const char *source)
{
	while( *source!= '\0')
	{
		*destination = *source;
		source++;
		destination++;
	
	}
	*destination = '\0';

}

class rentalcar
{
	public:
	void setYear (int temp_year);
	
	int getyear ()
	{
		return m_year;
	}


	void setMake (char *temp_make)
	{
	myStringCopy(m_make, temp_make);	
	}
	
	char* getmake ()
	{	
		return m_make;
	}

	void setModel (char *temp_model)
	{
	myStringCopy(m_model, temp_model);	
	}
	
	char* getmodel ()
	{
		return m_model;
	}

	void setPrice (float temp_price);
	
	float getprice ()
	{
		return m_price;
	}

	void setAvailable (bool temp_Available);
	
	bool getAvailable ()
	{
		return m_available;
	}
	void printData();

	private:
	
	int m_year;
	char m_make[maxsize];
	char m_model[maxsize];
	float m_price;
	bool m_available;
	

};

void rentalcar::setYear(int temp_year)
	{
		m_year = temp_year;
	}

void rentalcar::setPrice(float temp_price)
	{
		m_price = temp_price;
	}

void rentalcar::setAvailable(bool temp_Available)
	{
		m_available = temp_Available;
	}
struct rentalagency
{
	char name [maxsize];
	int zipcode;
	rentalcar inventory[maxsize];

};
void copycar(char filename[maxsize], rentalagency *agency );

void printcar(rentalagency *agency);
int main()
{
int menu;
int i=0;
char filename[maxsize];
rentalcar* cars;
int temp[maxsize];
int* ptemp = temp;
char temp_char[10];
char* ptemp_char = temp_char;
int zipcode;
rentalagency agency[3];

/*char make[30];
char model[30];
int year;
float price;
bool available;
int * num_array_pt;
char n_agency[30]; */

	cout << "=====================================" << endl;
	cout << "                Menu"<< endl;
	cout << "=====================================" << endl;
	cout << "1) Input File Name" << endl;
	cout << "2) Print Out Stuff" << endl;
	cout << "3) Estimate Car Rental Cost" << endl;
	cout << "4) Most Expensive Car" << endl;
	cout << "5) Avaiable Cars" << endl;
	cout << "6) Exit Program" << endl;
	cout << "Enter Option: ";
	
	cin >> menu;
//swithces between the menu when the user enters a value
	while(menu != 6)
	{
	
		switch(menu)
		{
		
		case(1):
		{	

			// Enter file name
			cout << endl;
			cout << "Enter the input file name: ";
	  		cin >> filename;

			copycar(filename, agency);	
	
			
			break;
			}


		case(2):
		{
		printcar(agency);
		break;
		}
		
		case(3):
		{

		int a;
		int c;
 		int p;
		int k;
		cout << "Enter Agency (1-3):";
		cin >> a;

		cout << "Enter Car (1-5):";
		cin >> c;


	//moves throught the array to get increment the values of different classes and structs
			rentalagency* agency_ptr = agency;
			
			rentalcar* rentalcar_ptr = agency_ptr->inventory;
			
			for(p=0 ; p < a; p++)
			{
			agency_ptr++;
			
				for(k=0; k < c -1; k++)
				{
				rentalcar_ptr++;
			


				}
			
			}
			cout << rentalcar_ptr -> getprice();
			
			
			

		break;
		}
	
		case(4):
		{
		/*float temp_price;
		rentalagency* agency_ptr = agency;
			rentalcar* rentalcar_ptr = agency_ptr->inventory;
			for(int i = 0 ; i < 3; i++, agency_ptr++)
			{
				rentalcar* rentalcar_ptr = agency_ptr->inventory;
				for (int j = 0; j < 5; ++j) 
				{
				if(rentalcar_ptr->getprice() > rentalcar_ptr++)
				 
				}
			}
		break;*/
		}
	
	case(5):
	{
		//asks the user for and output file and saves it to a value
		char input[30];
		cout << "Enter an output file: " ;
		cin >> input;

		ofstream outfile;
		outfile.open(input);
		rentalagency* agency_ptr = agency;
			
			for(int i = 0 ; i < 3; i++, agency_ptr++)
			{
			
				cout << agency_ptr -> name << " " << agency_ptr-> zipcode << endl;
				cout << endl;
rentalcar* rentalcar_ptr = agency_ptr->inventory;
				for (int z = 0; z < 5; z++,rentalcar_ptr++) {
			
				if(rentalcar_ptr->getAvailable() == true)
				{
					cout << rentalcar_ptr-> getyear();
					 cout << " " << rentalcar_ptr->getmake();
					 cout << " " << rentalcar_ptr->getmodel();
					 cout << ", $" << rentalcar_ptr->getprice() ;
					 cout << "per day " << "Available: " << boolalpha << rentalcar_ptr->getAvailable() << endl;
					 cout << endl;
	
					outfile << rentalcar_ptr-> getyear();
					outfile << " " << rentalcar_ptr->getmake();
					outfile << " " << rentalcar_ptr->getmodel();
					outfile << " " << rentalcar_ptr->getprice();
					outfile << " " << rentalcar_ptr->getAvailable() << endl;
					outfile << endl;	
				}
					 
				}
			}
		outfile.close();
				
					

			
				
		break;

	}

	case(6):
	{
	
		
	}

			
	}
		
	cout << endl;
	cout << "Enter Menu Option: ";
	cin >> menu;
	}
	
	  return 0;
}
void rentalcar::printData()
{			
	cout << m_year;
	cout << " " << m_make;
	cout << " " << m_model;
	cout << ", " << "$" << m_price << " per day,";
	cout << " " << "Avaiable: " << boolalpha << m_available << endl;
	cout << endl;
}
void copycar(char filename[maxsize], rentalagency *agency){


char make[30];
char model[30];
int year;
float price;
bool available;
int * num_array_pt;
char n_agency[30];
//rentalagency agency[3];
int temp_int;
ifstream file;
	  		file.open(filename);
			//reads till end of file
			
		
				// sorts the data of the file into an array
				
				
		// pointer that points to the stuct rentalagency and points to the class in it
			rentalagency* agency_ptr = agency;
			

			
			for(int i = 0 ; i < 3; ++i)
			{
				file >> agency_ptr -> name;
				file >> agency_ptr->zipcode;
				rentalcar* rentalcar_ptr = agency_ptr->inventory;
				for (int j = 0; j < 5; ++j) 
				{
					file >> year >> make >> model >> price >> available;
					rentalcar_ptr->setYear(year);
					rentalcar_ptr->setMake(make);
					rentalcar_ptr->setModel(model);
				  	rentalcar_ptr->setPrice(price);
					rentalcar_ptr->setAvailable(available);
					
					rentalcar_ptr++;

				}
				agency_ptr++;	
			
			}
				
				
				
				
	
			
			//close file
			
			file.close();



}

void printcar(rentalagency *agency){
			
			rentalagency* agency_ptr = agency;
			//prints out the getmake for the specific values.
			for(int i = 0 ; i < 3; ++i)
			{
			
				cout << agency_ptr -> name << " " << agency_ptr-> zipcode << endl;
				cout << endl;
				rentalcar* rentalcar_ptr = agency_ptr->inventory;

				for (int z = 0; z < 5; ++z)
				{
					rentalcar_ptr->printData();
					rentalcar_ptr++;
				}
				agency_ptr++;
			}
			
				
}

