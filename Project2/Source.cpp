#include <iostream>
#include <cassert>
using namespace std;

template<typename T, int MAX = 5>
class Stack
{
	T _container[MAX]{};
	int _top = -1;

public:
	Stack() = default;

	void push(T element)
	{
		if (isFull())
			assert(!"Stack overflow");

		_container[++_top] = element;
	}
	void pop()
	{
		if (isEmpty())
			assert(!"Stack underflow");

		_top--;
	}
	T peek() const
	{
		if (isEmpty())
			assert(!"Stack is Empty");

		return _container[_top];
	}

	bool isEmpty() const { return _top == -1; }
	bool isFull() const { return _top + 1 == MAX; }
	int size() const { return _top + 1; }

	const T* getContainer() const
	{
		return _container;
	}
};

class Engine {
public:
	string _engine_no;
	string _company;
	float _volume;

public:
	Engine() {
		_engine_no = "";
		_company = "";
		_volume = 0;
	}
	Engine(string engine_no, string company, float volume) {
		if (engine_no != "")_engine_no = engine_no;
		if (company != "")_company = company;
		if (volume > 0)_volume = volume;
	}

	friend ostream& operator<<(ostream& os, const Engine& eg);
};
ostream& operator<<(ostream& os, const Engine& eg) {
	os << eg._engine_no; for (size_t i = eg._engine_no.length(); i < 12; i++) { os << " "; }os << "|  ";
	os << eg._company; for (size_t i = eg._company.length(); i < 13; i++) { os << " "; }os << " |   ";
	os << "     " << eg._volume; (eg._volume / 10 > 0) ? os << "    | " : os << "   | ";
	return os;
}

class Car {
	static int _static_id_car;
	int _id;
	string _model;
	string _vendor;
	Engine _engine;
	bool _hasSpoiler;

public:
	Car() {
		_id = 0;
		_model = "";
		_vendor = "";
		_hasSpoiler = false;
		_id = _static_id_car++;
	}
	Car(string model, string vendor, Engine engine, bool has_spoiler) {

		_id = _static_id_car++;
		set_model(model);
		set_vendor(vendor);
		_engine = engine;
		_hasSpoiler = has_spoiler;
	}

	void set_model(string model) {
		if (model.size() > 0 && model.size() < 100) {
			_model = model;
			return;
		}
		assert(!"Incorrect initializing.");
	}
	void set_vendor(string vendor) {
		if (vendor.size() > 0 && vendor.size() < 100) {
			_vendor = vendor;
			return;
		}
		assert(!"Incorrect initializing.");
	}

	string get_model() { return _model; }
	string get_vendor() { return _vendor; }
	int get_id() { return _id; }
	Engine get_engine() { return _engine; }
	bool get_spoiler_info() { return _hasSpoiler; }

	void show() {
		cout << "Car ID: " << _id << endl
			<< "Model: " << _model << endl
			<< "Vendor: " << _vendor << endl
			<< _engine << endl
			<< "Spoiler: ";
		_hasSpoiler == true ? cout << "Var" << endl : cout << "YOX" << endl;
	}

	friend ostream& operator<<(ostream& os, const Car& car);

};
int Car::_static_id_car = 1;
ostream& operator<<(ostream& os, const Car& car) {
	os << "| " << car._id << "  |  ";
	os << car._model;  for (size_t i = car._model.length(); i < 10; i++) { os << " "; }os << "|   ";
	os << car._vendor; for (size_t i = car._vendor.length(); i < 8; i++) { os << " "; }os << "|   ";
	os << car._engine;
	car._hasSpoiler == true ? os << "  Var   |" : os << "  YOX   |";

	return os;
}

class Ship {
	static int _static_id_ship;
	int _id;
	string _model;
	string _vendor;
	Engine _engine;
	bool _has_Sail;

public:
	Ship() {
		_id = 0;
		_model = "";
		_vendor = "";
		_has_Sail = false;
		_id = _static_id_ship++;
	}
	Ship(string model, string vendor, Engine engine, bool has_Sail) {

		_id = _static_id_ship++;
		set_model(model);
		set_vendor(vendor);
		_engine = engine;
		_has_Sail = has_Sail;
	}

	void set_model(string model) {
		if (model.size() > 0 && model.size() < 100) {
			_model = model;
			return;
		}
		assert(!"Incorrect initializing.");
	}
	void set_vendor(string vendor) {
		if (vendor.size() > 0 && vendor.size() < 100) {
			_vendor = vendor;
			return;
		}
		assert(!"Incorrect initializing.");
	}

	string get_model() { return _model; }
	string get_vendor() { return _vendor; }
	int get_id() { return _id; }
	Engine get_engine() { return _engine; }
	bool get_spoiler_info() { return _has_Sail; }

	void show() {
		cout << "Ship ID: " << _id << endl
			<< "Model: " << _model << endl
			<< "Vendor: " << _vendor << endl
			<< _engine << endl
			<< "Sail: ";
		_has_Sail == true ? cout << "Var" << endl : cout << "YOX" << endl;
	}

	friend ostream& operator<<(ostream& os, const Ship& ship);
};
int Ship::_static_id_ship = 1;
ostream& operator<<(ostream& os, const Ship& ship) {

	os << "| " << ship._id << "  | ";
	os << ship._model;  for (size_t i = ship._model.length(); i < 11; i++) { os << " "; }os << "|   ";
	os << ship._vendor; for (size_t i = ship._vendor.length(); i < 8; i++) { os << " "; }os << "|   ";
	os << ship._engine;
	ship._has_Sail == true ? os << "  Var   |" : os << "  YOX   |";
	return os;
}

class Airplane {
	static int _static_id_airplane;
	int _id;
	string _model;
	string _vendor;
	Engine _engine;
	size_t _engine_count;
	int _passengerCapacity;

public:
	Airplane() {
		_id = 0;
		_model = "";
		_vendor = "";
		_engine_count = 0;
		_passengerCapacity = 0;
		_id = _static_id_airplane++;
	}
	Airplane(string model, string vendor, Engine engine, size_t engine_count, int passengerCapacity) {

		_id = _static_id_airplane++;
		set_model(model);
		set_vendor(vendor);
		_engine = engine;
		_passengerCapacity = passengerCapacity;
		_engine_count = engine_count;
	}

	void set_model(string model) {
		if (model.size() > 0 && model.size() < 100) {
			_model = model;
			return;
		}
		assert(!"Incorrect initializing.");
	}
	void set_vendor(string vendor) {
		if (vendor.size() > 0 && vendor.size() < 100) {
			_vendor = vendor;
			return;
		}
		assert(!"Incorrect initializing.");
	}

	string get_model() { return _model; }
	string get_vendor() { return _vendor; }
	int get_id() { return _id; }
	Engine get_engine() { return _engine; }
	size_t get_engine_count() { return _engine_count; }
	int get_passenger_capacity() { return _passengerCapacity; }

	void show() {
		cout << "Airplane ID: " << _id << endl
			<< "Model: " << _model << endl
			<< "Vendor: " << _vendor << endl
			<< _engine << endl
			<< "Engine Count: " << _engine_count << endl
			<< "Passenger Capacity: " << _passengerCapacity << endl;
	}

	friend ostream& operator<<(ostream& os, const Airplane& airplane);
};
int Airplane::_static_id_airplane = 1;
ostream& operator<<(ostream& os, const Airplane& airplane) {
	os << "| " << airplane._id << "  | ";
	os << airplane._model;  for (size_t i = airplane._model.length(); i < 8; i++) { os << " "; }os << " | ";
	os << airplane._vendor; for (size_t i = airplane._vendor.length(); i < 6; i++) { os << " "; }os << "|   ";
	os << airplane._engine; os << "      ";
	os << airplane._engine_count; (airplane._engine_count / 100 > 0) ? os << "     | " : os << "      |   ";
	os << airplane._passengerCapacity; (airplane._passengerCapacity / 20 > 0) ? os << "    |" : os << "      |";
	return os;

}

class VehicleDepo {
	Stack<Car>cars;
	Stack<Ship>ships;
	Stack<Airplane>airplanes;

public:
	VehicleDepo(Stack<Car> cars, Stack<Ship> ships, Stack<Airplane>airplanes) {
		this->cars = cars;
		this->ships = ships;
		this->airplanes = airplanes;
	}
	void showAllVehicle() {
		int airplane_size = airplanes.size();
		cout << endl << endl << "\t\t\t\t\tAIRPLANES" << endl << endl;
		for (size_t i = 0; i < 105; i++) { cout << "-"; } cout << endl;
		cout << "| ID | " << "   Model   " << "|   Vendor  " << "| ENGINE NUMBER " << "| ENGINE COMPANY " << "| ENGINE VOLUME" << "| ENGINE COUNT " << "| CAPACITY |" << endl;
		for (size_t i = 0; i < 105; i++) { cout << "-"; }cout << endl;
		for (int i = 0; i < airplane_size; i++) {
			cout << airplanes.getContainer()[i] << endl;
			for (size_t i = 0; i < 105; i++) { cout << "-"; } cout << endl;
		}

		int car_size = cars.size();

		cout << endl << "\t\t\t\t\t  CARS" << endl << endl;
		for (size_t i = 0; i < 90; i++) { cout << "-"; } cout << endl;
		cout << "| ID | " << "   Model   " << "|   Vendor  " << "| ENGINE NUMBER " << "| ENGINE COMPANY " << "| ENGINE VOLUME " << "| SPOILER |" << endl;
		for (size_t i = 0; i < 90; i++) { cout << "-"; }cout << endl;
		for (int i = 0; i < car_size; i++) {
			cout << cars.getContainer()[i] << endl;
			for (size_t i = 0; i < 90; i++) { cout << "-"; } cout << endl;
		}

		int ship_size = ships.size();
		cout << endl << endl << "\t\t\t\t\t  SHIPS" << endl << endl;
		for (size_t i = 0; i < 90; i++) { cout << "-"; } cout << endl;
		cout << "| ID | " << "   Model   " << "|   Vendor  " << "| ENGINE NUMBER " << "| ENGINE COMPANY " << "| ENGINE VOLUME " << "|   SAIL  |" << endl;
		for (size_t i = 0; i < 90; i++) { cout << "-"; }cout << endl;
		for (int i = 0; i < ship_size; i++) {
			cout << ships.getContainer()[i] << endl;
			for (size_t i = 0; i < 90; i++) { cout << "-"; } cout << endl;
		}

	}


};



void main() {
	//-----------------ENGINE-----------------------------//
	string engine_name1 = "SSL300";
	string engine_name2 = "TXI 4300";
	string engine_name3 = "1200 SSL";
	string engine_company1 = "Mercedes";
	string engine_company2 = "KIA MOTORS";
	string engine_company3 = "TYT MOTORS";



	//-----------------CAR-----------------------------//
	string car_model1 = "Mercedes";
	string car_model2 = "KIA";
	string car_model3 = "Toyota";
	string car_vendor1 = "GLE";
	string car_vendor2 = "OPTIMA";
	string car_vendor3 = "Prius";

	Engine engine1(engine_name1, engine_company1, 5.5);
	Engine engine2(engine_name2, engine_company2, 5.6);
	Engine engine3(engine_name3, engine_company3, 2.2);

	Car car1(car_model1, car_vendor1, engine1, true);
	Car car2(car_model2, car_vendor2, engine2, false);
	Car car3(car_model3, car_vendor3, engine3, false);

	//car1.show();
	//cout << car1<<endl;
	//cout << car2;

	//-----------------SHIP---------------------------//
	string engine_ship = "9800T";
	string eng_cmp_ship = "IEX ENGINE";
	Engine engine_ship1(engine_ship, eng_cmp_ship, 9.5);

	string ship_model = "UnderWater";
	string ship_vendor = "3300";

	Ship ship1(ship_model, ship_vendor, engine_ship1, true);

	//cout << ship1;
	//ship1.show();


	//-----------------AIRPLANE------------------------//

	string engine_air = "Maximus 900";
	string engine_cmp_air = "R.Max Company";
	Engine engine_air1(engine_air, engine_cmp_air, 56);

	string air_model = "Boeing 787";
	string air_vendor = "Dreamliner";

	Airplane airplane1(air_model, air_vendor, engine_air1, 4, 250);

	//cout << airplane1;
	//airplane1.show();


	//-------------------STACKS-------------------------//

	Stack<Car>stack_car;
	stack_car.push(car1);
	stack_car.push(car2);
	stack_car.push(car3);


	Stack<Ship>stack_ship;
	stack_ship.push(ship1);


	Stack<Airplane>stack_airplane;
	stack_airplane.push(airplane1);

	VehicleDepo depo(stack_car, stack_ship, stack_airplane);
	depo.showAllVehicle();

}