//Daniel Pintor
//H346N927
#include <iostream>
#include <string>
#define SIZE 30
using namespace std;
class Car{
	private:
		int id;
		string make;
		string model;
		string category;
	public:
		Car();
		int getid(); //id accessor function THIS IS ADDITION
		string getmake(); //make accessor function
		string getmodel(); //model accessor function
		string getcat(); //category accessor function
		void setid(int num); //id setter function
		void setmake(string manu); //make setter function
		void setmodel(string mode); //model setter function
		void setcat(string cate); //category setter function ANOTHER CHANGe
};

//getid
int Car::getid(){
	return id;
}

//getmake
string Car::getmake(){
	return make;
}

//getmodel
string Car::getmodel(){
	return model;
}

//getcat
string Car::getcat(){
	return category;
}

//setid
void Car::setid(int num){
	id = num;
}

//setmake
void Car::setmake(string manu){
	make = manu;
}

//setmodel
void Car::setmodel(string mode){
	model = mode;
}

//setcat
void Car::setcat(string cate){
	category = cate;
}

typedef Car data_type;

class ArrayList{

	public:
		ArrayList(){count = 0;} //constructor
		void add (data_type obj); //adds obj
		void add (data_type obj, int index); //adds obj to specified index
		int search (data_type obj); //searches for specified object
		data_type get (int index); //returns class obj by index
		void del (int index); //deletes part of array by index
		void set (data_type obj, int index); //place object of type car
											 //	into part of array by
											 //	index
		int size(); //returns count
		void traverse(); //prints entire array
	private:
		data_type arr[SIZE];
		int count;
};

//first function
void ArrayList::add (data_type obj){
	if (count < SIZE)
		arr[count++] = obj;
	else
		cout << "Array full" << endl;
}

//second function
void ArrayList::add (data_type obj, int index){
	if (index <= count && count < SIZE){ //checks for index validity and size
		for (int i = count - 1; i >= index; i--)
			arr[i + 1] = arr[i]; //shifts objects
		arr[index] = obj;
		count++; //increments number of cars
	}
	else
		cout << "Invalid index or Array is full" << endl;
}	

//search
int ArrayList::search (data_type obj){
	int tempidobj = obj.getid(); //copies specified object's id to temp variable
	for (int i = 0; i < count; i++){
		int tempidarr = arr[i].getid(); //copies current car id to temp variable
		if (tempidobj == tempidarr && (obj.getmake().compare(arr[i].getmake())) && (obj.getmodel().compare(arr[i].getmodel())) && (obj.getcat().compare(arr[i].getcat())))
		//^^^ Sees if current object in array matches specified object
			return i;
	}
	return -1;
}

//get
data_type ArrayList::get (int index){
	if (index >= 0 && index < count)
		return arr[index];
	cout << "Invalid index" << endl;
}

//del
void ArrayList::del (int index){
	if (0 <= index && index < count){
		for (int i = index; i < count - 1; i++){
			arr[i] = arr[i + 1];
			count--;//lessens the count to account for deletion
		}
	}
		else
			cout << "Invalid index" << endl;
}

//set
void ArrayList::set (data_type obj, int index){
	if (0 <= index && index < count)
		arr[index] = obj;
	else
		cout << "Invalid index" << endl;
}

//size
int ArrayList::size(){
	return count;
}

//traverse
void ArrayList::traverse(){
	for (int i = 0; i < count; i++){ //prints whole array contents
		cout << arr[i].getmake() << " ";
		cout << arr[i].getmodel() << ", ";
		cout << arr[i].getcat() << endl;;
	}	
}

