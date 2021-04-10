//Yifeng Qin
//CS202
//10/3/17
//Project 4

/*
Layout
------------------
Declared classes / Prototypes

Menu Functions Prototype

Main

Menu Functions

Menu Functions

Class Sensor Functions

Class Car Functions

Class Agency Functions


*/

#include <iostream>
#include <fstream>

using namespace std;

const int maxsize = 255;

void myStringCopy (char *destination, const char *source);

void intStringCopy (int *destination, const int *source);

class sensor{
    
    public:
	//defaul and paramaterized constructors
	sensor();
	
	sensor(char* temp_type, float extracost);

	void setType (char* t_type);
	char* getType();

	void setExtracost(float t_extracost);
	float getExtracost();
	// overload operator
	sensor operator[](int sensor);
	//reset functions for static int

	void reset_gps();
	void reset_camera();
	void reset_lidar();
	void reset_radar();
    private:
    char m_type [maxsize];
    float m_extracost;
	static int gps_cnt;
    static int camera_cnt;
    static int lidar_cnt;
	static int radar_cnt;

};

//sensor::sensor(char *m_type){
//	myStringCopy(this.m_type, m_type);
//}
	//set all my static variables to zero
	int sensor::gps_cnt = 0;
	int sensor::camera_cnt = 0;
	int sensor::lidar_cnt = 0;
	int sensor::radar_cnt = 0;


class car{
    
    public:
	//defaul and paramaterized constructors
	car();
	
	car(char* temp_make, char* temp_model, char* temp_owner, int tempyear, float b_price, float f_price, bool t_avail);

	void setMake (char* t_make);
	char* getMake();

	void setModel (char* t_model);
	char* getModel();

	void setOwner (char* t_owner);
	char* getOwner();

	void setYear(int t_year);
	int getYear();

	void setBaseprice(float t_baseprice);
	float getBaseprice();

	void setFinalprice(float t_finalprice);
	float getFinalprice();

	void setAvailable(bool t_avaliable);
	bool getAvailable();

	void printData();

	void setSensor(int j, char* tempSensor);
	void getSensor(int j);
	// overload operator
	car operator[](int cars);

    private:

    char m_make [maxsize];
    char m_model [maxsize];
	int m_year;
    sensor m_sensors [3];
    float m_baseprice;
    float m_finalprice;
    bool m_available;
    char m_owner [maxsize];
};

class agency{
 
    public:
	//defaul and paramaterized constructors
	agency();
	agency(char* tempname, int* tempzipcode);

	void setName(char* t_name);
	char* getName();

	
	void setInv(int i, int tempYear, char *tempMake, char* tempModel, float baseprice, float finalprice, bool 		avail, char* tempOwner);

	void getInv(int j);
	void getInv2(int j);
	
	void getAgency();

	void printExp();

	void setZip(int t_zip);
	int* getZip();
	
	void EstPrice(int i);

	void ResetAvail(char *temp_name);
	// overload operator
	agency operator[](int agency);

    private:
    char m_name[maxsize];
    int m_zipcode[5];
  	car m_inventory [5];


};

//prototypes for my case functions
void case_1(agency* agency1, car* carz, int &cg, int &cl, int &cr, int &cc);

void case_2(agency* agency1, car* carz);

void case_3(int cg, int cl, int cr, int cc);

void case_4(agency* agency1);

void myStringCopy (char *destination, const char *source);

int main()
{
    int menu;
    bool if_file = false;
	int i;
	agency agency1[1];
	car carz[5];

	int z= 0;
	int cg = 0, cl = 0, cr = 0, cc =0;

	cout << "=====================================" << endl;
	cout << "                Menu"<< endl;
	cout << "=====================================" << endl;
	cout << "1) Input File Name" << endl;
	cout << "2) Print Data" << endl;
	cout << "3) TOTAL Number of Sensors" << endl;
	cout << "4) Most Expensive Car" << endl;
	cout << "5) Exit Program" << endl;
	cout << "Enter Option: ";
	
	cin >> menu;


    while(menu != 5)
    {
        switch(menu)
        {

            case(1):
            {
				
				case_1(agency1, carz, cg, cl, cr, cc);
                if_file = true;
                break;
            }

            case(2):
            {
                if(if_file == false)
				{
					cout << "No File Was Entered. Please Enter a File (Menu 1) " << endl;
				}
				else
				{
					case_2(agency1, carz);
				}
				
                break;
            }

            case(3):
            {
                if(if_file == false)
				{
					cout << "No File Was Entered. Please Enter a File (Menu 1) " << endl;
				}
				else
				{
				case_3(cg, cl, cr, cc);
				}
                break;
            }


            case(4):
            {
                if(if_file == false)
				{
					cout << "No File Was Entered. Please Enter a File (Menu 1) " << endl;
				}
				else
				{
				case_4(agency1);
				}
                break;
            }


        }

    cout << endl;
    cout << "Enter Menu Option: ";
    cin >> menu;

    }

    return 0;
}


//Input File Function

void case_1(agency* agency1, car* carz, int &cg, int &cl, int &cr, int &cc)
{

// all my temporary variables to pass to functions
char name[20];
char filename[20];
int zipcode;
int tyear;
float bprice;
float fprice = 100;
char tmake[30];
char tmodel[30];
bool tavail = 0;
int j= 0;
int i = 0;
int a = 0;
int z = 0;
char c , x, y;
int c_gps = 0;
int c_radar = 0;
int c_lidar = 0;
int c_camera = 0;
int c_none = 0;
int p_gps = 5;
int p_radar = 20;
int p_lidar = 15;
int p_camera = 10;
int p_none = 0;
/////////////////////////// count gps, count lidar, cound radar, count camera
cg = 0, cl = 0, cr = 0, cc = 0;
char t_owner = '\0';
char c_owner [maxsize];
char* owner_ptr = c_owner;
char* owner_ptrz = &c_owner[0];
char t_sensor[maxsize];
char* sensor_ptr = t_sensor;
char* sensor_ptrz = &t_sensor[0];

// opens file
	cout << endl;
	cout << "Enter the input file name: ";
	cin >> filename;
	cout << endl;
	agency* agency_ptr = agency1;
	car* car_ptr = carz;

	ifstream file;
	file.open(filename);
	//pointer to agency to set agency name and zipcode
	file >> name;
	agency_ptr -> setName(name);
	file >> zipcode;
	
	agency_ptr -> setZip(zipcode);
	//agency_ptr -> getAgency(); 
	for(a = 0; a < 5 ; a++, j++, z++)
	{
		//takes in all the values for the car up to the sensor;
	    file >> tyear >> tmake >> tmodel >> bprice;
		file >> c;
		
		if( c == '{')
		{
			while( c != '}')
	   	 	{
				x=c;
				file >> c;
				 //checks if the char value is equal to letters that correspond to the sensors
				// then if it finds on it will increment it and set a temp char array with the snensor name   
				if(x == '{' & c == '}')
				{
					c_none++;
					*sensor_ptr = 'n';
					sensor_ptr++;
					*sensor_ptr = 'o';
					sensor_ptr++;
					*sensor_ptr = 'n';
					sensor_ptr++;
					*sensor_ptr = 'e';
					sensor_ptr++;
					
					

				}
				//checks if the char value is equal to letters that correspond to the sensors
				// then if it finds on it will increment it and set a temp char array with the snensor name  
				if(x== 'g' & c == 'p'){
		
					c_gps++;
					cg++;
					*sensor_ptr = 'g';
					sensor_ptr++;
					*sensor_ptr = 'p';
					sensor_ptr++;
					*sensor_ptr = 's';
					sensor_ptr++;
					*sensor_ptr = ' ';
					sensor_ptr++;
				}
				//checks if the char value is equal to letters that correspond to the sensors
				// then if it finds on it will increment it and set a temp char array with the snensor name  
				if(x== 'a' & c == 'd'){
		
					c_radar++;
					cr++;
					*sensor_ptr = 'r';
					sensor_ptr++;
					*sensor_ptr = 'a';
					sensor_ptr++;
					*sensor_ptr = 'd';
					sensor_ptr++;
					*sensor_ptr = 'a';
					sensor_ptr++;
					*sensor_ptr = 'r';
					sensor_ptr++;
					*sensor_ptr = ' ';
					sensor_ptr++;
					
				}
				//checks if the char value is equal to letters that correspond to the sensors
				// then if it finds on it will increment it and set a temp char array with the snensor name  
				if(x== 'l' & c == 'i'){
		
					c_lidar++;
					cl++;
					*sensor_ptr = 'l';
					sensor_ptr++;
					*sensor_ptr = 'i';
					sensor_ptr++;
					*sensor_ptr = 'd';
					sensor_ptr++;
					*sensor_ptr = 'a';
					sensor_ptr++;
					*sensor_ptr = 'r';
					sensor_ptr++;
					*sensor_ptr = ' ';
					sensor_ptr++;
				}
				//checks if the char value is equal to letters that correspond to the sensors
				// then if it finds on it will increment it and set a temp char array with the snensor name  
				if(x== 'c' & c == 'a'){
		
					c_camera++;
					cc++;
					*sensor_ptr = 'c';
					sensor_ptr++;
					*sensor_ptr = 'a';
					sensor_ptr++;
					*sensor_ptr = 'm';
					sensor_ptr++;
					*sensor_ptr = 'e';
					sensor_ptr++;
					*sensor_ptr = 'r';
					sensor_ptr++;
					*sensor_ptr = 'a';
					sensor_ptr++;
					*sensor_ptr = ' ';
					sensor_ptr++;
				}
			
			}
		}
		// totals the price by adding the base price with the total amount of that sensors and its repsected price
		fprice = bprice + (p_gps*c_gps + p_radar*c_radar + p_lidar * c_lidar + p_camera * c_camera);
		file >> tavail;
		t_owner = file.get();
		//checks it there is a owner by using the get function to check if there is a new line or a charcter
			if( t_owner == '\n')
			{

				*c_owner = '\0';
			}

			while(t_owner != '\n')
			{
			//if there is a character it will copy over the contents and end it with a null
				t_owner = file.get();
			
				if(t_owner == '\n')
				{
					break;

				}
		*owner_ptr = t_owner;
		owner_ptr++;
		}
		*owner_ptr = '\0';
		*sensor_ptr = '\0';	
		owner_ptr = owner_ptrz;
		sensor_ptr = sensor_ptrz;
		agency_ptr -> setInv(j, tyear, tmake, tmodel, bprice, fprice, tavail, c_owner);
		car_ptr -> setSensor(j, t_sensor);
		c_none = 0, c_gps = 0, c_lidar = 0, c_radar = 0, c_camera = 0;
		
		
    }
	file.close();
}

//Print to terminal All data for the Gency and all its correspinding Cars

void case_2(agency* agency1, car* carz)
{
int z;
// calls all the print funtioncs that i have decalred
agency* agency_ptr = agency1;
	cout << endl;
	agency_ptr -> getAgency();
	agency_ptr -> getZip();
	car* car_ptr = carz;
	

	for( z = 0; z < 5; z++)
	{
	 
	agency_ptr -> getInv(z);
	car_ptr -> getSensor(z);
	agency_ptr -> getInv2(z);
	}

}

//Print to terminal the Total number of sensors

void case_3(int cg, int cl, int cr, int cc)
{
//prints out all the sensors that there are
int t_sensors =0;
t_sensors = cg + cl + cr + cc;
	
	cout << endl;
	cout << "Total Sensors: " << t_sensors << endl;
	cout << "Gps: " << cg << endl;
	cout << "Lidar: " << cl << endl;
	cout << "Radar: " << cr << endl;
	cout << "Camera: " << cc << endl;

}

//Find the most expensive available car
void case_4(agency* agency1)
{
	//calls the functions to set the prices and change the bool values and owner
	int answer;
	int days;
	char name[10];
	agency* agency_ptr = agency1;
	agency_ptr -> printExp();
	cout << "Would You Like To Rent it? Yes(1)/No(2): " ;
	cin >> answer;
	
	if(answer == 1)
	{
		cout << "How Many Days Would You Like to Rent It? : "; 
		cin >> days;
		agency_ptr -> EstPrice(days);
		cout << "Enter Your Name :";
		cin >> name;
		agency_ptr -> ResetAvail(name);
		cout << "Successful" << endl;
	}
	
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


void intStringCopy (int *destination, const int *source)
{
	while( *source!= '\0')
	{
		*destination = *source;
		source++;
		destination++;
	
	}
	*destination = '\0';

}
/////////////////////SENSOR+++++++++++++++++++++++++++++++++++++++_+___+_+_+++_++_+__+
//default  constructor and paramater constructor
sensor::sensor()
{

char tempType[10] = "none";

	myStringCopy(m_type, tempType);
	m_extracost = 0;
	
}
//default  constructor and paramater constructor
sensor::sensor(char* temp_type, float extracost)
{

	myStringCopy(m_type, temp_type);
	m_extracost = extracost;

}
void sensor::setType(char* t_type)
{
	myStringCopy(m_type, t_type);
}

char* sensor::getType()
{
	return m_type;	
}

void sensor::setExtracost(float t_extracost)
{
		m_extracost = t_extracost;
}

float sensor::getExtracost()
{
	return m_extracost;
}


void sensor::reset_gps(){

	gps_cnt = 0;
}
void sensor::reset_camera(){

	camera_cnt = 0;
}
void sensor::reset_lidar(){

	lidar_cnt = 0;
}
void sensor::reset_radar(){

	radar_cnt = 0;
}


/////////////////////// CAR  ++++++++++++++++++++++++++++++++++++++++++++++++++++++
//default  constructor and paramater constructor//default  constructor and paramater constructor
car::car()
{
char tempval[5]= "\0";

	myStringCopy(m_make, tempval);
	myStringCopy(m_owner, tempval);
	myStringCopy(m_model, tempval);
	m_year = 0;
	m_baseprice = 0;
	m_finalprice = 0;
	m_available = 0;
	
	

}
//default  constructor and paramater constructor
car::car(char* temp_make, char* temp_model, char* temp_owner, int tempyear, float b_price, float f_price, bool t_avail)
{


	myStringCopy(m_make, temp_make);
	myStringCopy(m_owner, temp_model);
	myStringCopy(m_model, temp_model);
	m_year = tempyear;
	m_baseprice = b_price;
	m_finalprice = f_price;
	m_available = t_avail;



}
void car::setMake(char* t_make)
{
	myStringCopy(m_make, t_make);
}

char* car::getMake()
{
	return m_make;	
}

void car::setModel(char* t_model)
{
	myStringCopy(m_model, t_model);
}

char* car::getModel()
{
	return m_model;	
}

void car::setOwner(char* t_owner)
{
	myStringCopy(m_owner, t_owner);
}

char* car::getOwner()
{
	return m_owner;	
}

void car::setYear(int t_year)
{
		m_year = t_year;
}

int car::getYear()
{
	return m_year;
}

void car::setBaseprice(float t_baseprice)
{
		m_baseprice = t_baseprice;
}

float car::getBaseprice()
{
	return m_baseprice;
}

void car::setFinalprice(float t_finalprice)
{
		m_finalprice = t_finalprice;
}

float car::getFinalprice()
{
	return m_finalprice;
}

void car::setAvailable(bool t_available)
{
		m_available = t_available;
}

bool car::getAvailable()
{
	return m_available;
}


void car::setSensor(int j, char* tempSensor)
{
	int i;
	sensor* sensor_ptr = m_sensors;
	sensor_ptr += j;
	sensor_ptr -> setType(tempSensor);
		
	
}

void car::getSensor(int j)
{
	int i;
	sensor* sensor_ptr = m_sensors;
	sensor_ptr += j;
	cout << endl;
	cout << "Sensors:" <<sensor_ptr -> getType() << ", ";
	
	

}



////////////////////Agency ++++++++++++++++++++++++
//default  constructor and paramater constructor
agency::agency()
{
	char tempval[5]= "\0";
	myStringCopy(m_name, tempval);
	int tempzip[5] = {0};
    intStringCopy(m_zipcode, tempzip);

	
	
}
//default  constructor and paramater constructor
agency::agency(char* tempname, int* tempzipcode)
{

	myStringCopy(m_name, tempname);
	intStringCopy(m_zipcode, tempzipcode);

}

void agency::setName(char* t_name)
{
		myStringCopy(m_name, t_name);
}

char* agency::getName()
{
	return m_name;
}


void agency::getAgency()
{
	cout << m_name << " ";
	
}

void agency::printExp()
{
float temp_price;
int k = 0;
int j = 0;

car* car_ptr = m_inventory;
car* car_ptr2 = m_inventory;
car* car_ptr3 = m_inventory;
	
		// i want to run through all the price values to find the most expensive car.
				
		for (j = 0; j < 5; ++j) 
		{
			car_ptr++;
				// if one car price is bigger it will enter this for loop.
			if(car_ptr -> getFinalprice() < car_ptr2 -> getFinalprice())
				{		
					// then if the get price is larger than the current temp_price, it will replace it.	
					if(temp_price < car_ptr2 -> getFinalprice())	
					{			
						temp_price = car_ptr2 -> getFinalprice();
						car_ptr++;
						k++;
					}
				}
			car_ptr2++;
		}
		
	car_ptr+= k;
	cout << "Most Expensive Car: " << car_ptr3 -> getYear() << " " << car_ptr3 -> getMake() << " " <<  car_ptr3 -> getModel() << " $" << temp_price << endl;
}
//uses the same method to find the amount needed to increment the pointer to change the values and make an estmated price. 
void agency::EstPrice(int i)
{
float temp_price;
int k = 0;
int j = 0;
float full_price;
car* car_ptr = m_inventory;
car* car_ptr2 = m_inventory;

	
		// i want to run through all the price values to find the most expensive car.
				
		for (j = 0; j < 5; ++j) 
		{
			car_ptr++;
				// if one car price is bigger it will enter this for loop.
			if(car_ptr -> getFinalprice() < car_ptr2 -> getFinalprice())
				{		
					// then if the get price is larger than the current temp_price, it will replace it.	
					if(temp_price < car_ptr2 -> getFinalprice())	
					{			
						temp_price = car_ptr2 -> getFinalprice();
						car_ptr++;
						k++;
					}
				}
			car_ptr2++;
		}
	// the full price is multiplied by the number that is passed in
	full_price = temp_price * i;
	cout <<"Total Cost: $" <<full_price << endl;
}

void agency::ResetAvail(char *temp_name)
{
float temp_price;
int k = 0;
int j = 0;
float full_price;
car* car_ptr = m_inventory;
car* car_ptr2 = m_inventory;
car* car_ptr3 = m_inventory;
int avail = 1;
		// i want to run through all the price values to find the most expensive car.
				
		for (j = 0; j < 5; ++j) 
		{
			car_ptr++;
				// if one car price is bigger it will enter this for loop.
			if(car_ptr -> getFinalprice() < car_ptr2 -> getFinalprice())
				{		
					// then if the get price is larger than the current temp_price, it will replace it.	
					if(temp_price < car_ptr2 -> getFinalprice())	
					{			
						temp_price = car_ptr2 -> getFinalprice();
						car_ptr++;
						k++;
					}
				}
			car_ptr2++;
		}
		
	car_ptr += k;
	car_ptr3 -> setAvailable(avail);
	car_ptr3 -> setOwner(temp_name);

}

void agency::setInv(int i, int tempYear, char *tempMake, char* tempModel, float baseprice, float finalprice, bool avail, char* tempOwner) 
{
	//function in the agency so it has access to the private members of the class
	//pass in a value to increment the pointer to the car i want.
	int j;
	car* car_ptr = m_inventory;
	car_ptr += i;
	car_ptr -> setYear(tempYear);
	car_ptr ->setMake(tempMake);
	car_ptr ->setModel(tempModel);
	car_ptr ->setBaseprice(baseprice);
	car_ptr ->setFinalprice(finalprice);
	car_ptr ->setAvailable(avail);
	car_ptr ->setOwner(tempOwner);
	
	
}

void agency::getInv(int j)
{
	//function in the agency so it has access to the private members of the class
	//pass in a value to increment the pointer to the car i want.
	int z;
	car* car_ptr =  m_inventory;
	car_ptr += j;
	cout << car_ptr -> getYear() << " ";
	cout << car_ptr -> getMake() << " ";
	cout << car_ptr -> getModel() << ", Base Price: $";
	cout << car_ptr -> getBaseprice() << ", Final Price: $";
	cout << car_ptr -> getFinalprice();

}

void agency::getInv2(int j)
{
	//function in the agency so it has access to the private members of the class
	//pass in a value to increment the pointer to the car i want.
	car* car_ptr =  m_inventory;
	car_ptr += j;

	cout << "Available: " << car_ptr -> getAvailable() << boolalpha << ", ";
	cout << "Owner:" << car_ptr -> getOwner();
	cout << endl;
	car_ptr++;

}

void agency::setZip(int t_zip)
{
	
	
	int i = 0;
	int* zip_ptr = m_zipcode;
	int z;
	zip_ptr += 4;
	while(t_zip != 0)
			{
	
				// increment the zip pointer because i want to give a value into the memory allocation in the array. Because the module saves it backwords, i have to increment the pointer and then decrement it to have the zop code in the right direction.
			z = t_zip % 10;
				
				*zip_ptr = z;
				t_zip /= 10;
				--zip_ptr;			
			
			}
	



//intStringCopy(m_zipcode, t_zip);
} 

int* agency::getZip()
{
	//have to use a for loop to print out the zipcode array
	int* zip_ptr = m_zipcode;
	int i=0;
	zip_ptr = m_zipcode;
	for(i = 0; i< 5; i++)
	{
	cout << *zip_ptr;
	zip_ptr++;
	}
	cout << endl;
	
}

