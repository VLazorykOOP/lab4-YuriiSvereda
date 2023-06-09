﻿#include<iostream>
#include<limits>
#include<string>

using namespace std;


/*Завдання 1. Варіанти задач. Перевантаження операцій. Вектори.
Розробити та реалізувати клас «вектор» згідно варіантів, у класі переважити
операції. Написати програму обчислення «векторних» виразів (тобто вираз
складається операцій на векторами та скалярними величинами). В програмі має
бути декілька виразів, вираз має складатися із 5 та більше операцій.
Перевантажені операції повинні бути присутні хоча б одному з виразів.*/
/*Створити тип даних - клас вектор VectorDouble(вектор дійсних чисел), який має
вказівник на double, число елементів size і змінну стану codeError.У класі визначити
o конструктор без параметрів( виділяє місце для одного елемента та інінціалізує
його в нуль);
o конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує
масив значенням нуль);
o конструктор із двома параметрами - розмір вектора та значення
ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує
значенням другого аргументу).
o деструктор звільняє пам'ять;
o перевантаження операцій (операції перевантажувати через функції класу або
дружні функції, якщо не вказано яким чином це робити):
• унарних префіксних та постфіксних ++ та --: одночасно збільшує
(зменшує) значення елементів масиву на 1.0;
• унарної логічної ! (заперечення): повертає значення true, якщо
елементи якщо size не дорівнює – нулю, інакше false;
• унарний арифметичний - (мінус) : повертає всі елементи масиву
класу вектор з протилежним знаком;
• присвоєння =: копіює вектор(перевантажити через функцію класу);*/
/*• присвоєння з(перевантажити через функцію класу)
o += - додаванням векторів;
o -= - відніманням векторів;
o *= - множення, вектора на число;
o /= - ділення, вектора на число;
o %= - остача від ділення, вектора на число;
• арифметичних бінарні:
o + - додавання векторів;
o – - віднімання векторів;
o * - множення, вектора на число;
o / - ділення, вектора на число;
o % - остача від ділення, вектора на число типу int;
• побітові операції зсувів, як дружні операції введення та виведення
вектора у потік (перевантажувати через дружні функції)
o введення >> (побітовий зсув право) ;
o введення << (побітовий зсув ліво);
• рівності == та нерівності!= , функція-операція виконує певні дії над
кожною парою елементів векторів за індексом;
• операцію індексації [] – функцію, яка звертається до елементу
масиву за індексом, якщо індекс невірний функція вказує на останній
елемент масиву та встановлює код помилки у змінну codeError;
• розподілу пам’яті new та delete;
• виклику функції ();
• порівняння (функція-операція виконує певні дії над кожною парою
елементів векторів за індексом), які повертають true або false:
o > (більше) для двох векторів;
o >= (більше рівне) для двох векторів;
o < (менше) для двох векторів;
o <=(менше рівне) для двох векторів.
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву.
Передбачити можливість підрахунку числа об'єктів даного типу. Перевірити роботу цього
класу.*/

class VectorDouble
{
public:
	
	VectorDouble();

	VectorDouble(int size);

	VectorDouble(int size, double inicialisated_value);

	VectorDouble(string rand_variable, int limit_size, int limit_element);

	VectorDouble(const VectorDouble& other) : size(other.size), vec(new double[other.size]) {
		for (int i = 0; i < this->size; i++) {
			this->vec[i] = other.vec[i];
		}
	}
	
	~VectorDouble();

	VectorDouble& operator++ ()
	{
		for (int i = 0; i < this->size; i++) {
			++this->vec[i];
		}
		return *this;
	}

	VectorDouble& operator-- ()
	{
		for (int i = 0; i < this->size; i++) {
			this->vec[i]--;
		}
		return *this;
	}

	VectorDouble& operator++ (int)
	{
		VectorDouble temp(*this);
		for (int i = 0; i < this->size; i++) {
			this->vec[i]++;
		}
		memory_free_variable = false;
		return temp;
	}

	VectorDouble& operator-- (int)
	{
		VectorDouble temp(*this);
		for (int i = 0; i < this->size; i++) {
			this->vec[i]--;
		}
		memory_free_variable = false;
		return temp;
	}

	bool operator! () 
	{
		return size != 0;
	}

	VectorDouble& operator- () 
	{
		for (int i = 0; i < this->size; i++) {
			this->vec[i] = -this->vec[i];
		}
		return *this;
	}

	VectorDouble& operator = (const VectorDouble& other) 
	{
		if (*this != other) {
			if (this->vec != nullptr) {
				delete[] this->vec;
			}
			this->size = other.size;
			this->vec = new double[other.size];
			for (int i = 0; i < other.size; i++) {
				this->vec[i] = other.vec[i];
			}
		}
		return *this;
	}


	VectorDouble& operator += (const VectorDouble& other)
	{
		if (this->size < other.size) {
			cout << "ERROR += different sizes\n";
		}
		else {
			for (int i = 0; i < this->size; i++) {
				this->vec[i] += other.vec[i];
			}
		}
		return *this;
	}

	VectorDouble& operator -= (const VectorDouble& other)
	{		
		if (this->size < other.size) {
			cout << "ERROR += different sizes\n";
		}
		else {
			for (int i = 0; i < this->size; i++) {
				this->vec[i] -= other.vec[i];
			}
		}
		return *this;
	}

	VectorDouble& operator *= (int number)
	{		
		for (int i = 0; i < this->size; i++) {
				this->vec[i] *= number;
		}
		return *this;
	}

	VectorDouble& operator /= (int number)
	{
		for (int i = 0; i < this->size; i++) {
			this->vec[i] /= number;
		}
		return *this;
	}

	friend istream& operator>>(istream& input, VectorDouble& vector);
	friend ostream& operator<<(ostream& output, const VectorDouble& vector);

	bool operator ==(const VectorDouble& other) 
	{
		if (this->size != other.size)
			return false;
		for (int i = 0; i < size; i++) {
			if (this->vec[i] != other.vec[i])
				return false;
		}
		return true;
	}

	bool operator !=(const VectorDouble& other) 
	{
		if (this->size != other.size)
			return true;
		for (int i = 0; i < size; i++) {
			if (this->vec[i] != other.vec[i])
				return true;
		}
		return false;
	}

	double& operator [](int index)
	{
		if (index<0 || index>this->size) {
			this->codeError = 2; //going beyond the array
			this->Error_counter++;
			index = 0;
		}
		return this->vec[index];
	}

	short GetSize() {
		return this->size;
	}
	
	bool operator >(const VectorDouble& other)
	{
		double this_modul = 0, other_modul = 0;
		for (short i = 0; i < this->size; i++) {
			this_modul += this->vec[i] * this->vec[i];
		}
		this_modul = sqrt(this_modul);

		for (short i = 0; i < other.size; i++) {
			other_modul += other.vec[i] * other.vec[i];
		}
		other_modul = sqrt(other_modul);

		if (this_modul > other_modul) {
			return true;
		}
		return false;
	}

	bool operator >=(const VectorDouble& other)
	{
		double this_modul = 0, other_modul = 0;
		for (short i = 0; i < this->size; i++) {
			this_modul += this->vec[i] * this->vec[i];
		}
		this_modul = sqrt(this_modul);

		for (short i = 0; i < other.size; i++) {
			other_modul += other.vec[i] * other.vec[i];
		}
		other_modul = sqrt(other_modul);

		if (this_modul >= other_modul) {
			return true;
		}
		return false;
	}

	bool operator <(const VectorDouble& other)
	{
		double this_modul = 0, other_modul = 0;
		for (short i = 0; i < this->size; i++) {
			this_modul += this->vec[i] * this->vec[i];
		}
		this_modul = sqrt(this_modul);

		for (short i = 0; i < other.size; i++) {
			other_modul += other.vec[i] * other.vec[i];
		}
		other_modul = sqrt(other_modul);

		if (this_modul < other_modul) {
			return true;
		}
		return false;
	}

	bool operator <=(const VectorDouble& other)
	{
		double this_modul = 0, other_modul = 0;
		for (short i = 0; i < this->size; i++) {
			this_modul += this->vec[i] * this->vec[i];
		}
		this_modul = sqrt(this_modul);

		for (short i = 0; i < other.size; i++) {
			other_modul += other.vec[i] * other.vec[i];
		}
		other_modul = sqrt(other_modul);

		if (this_modul <= other_modul) {
			return true;
		}
		return false;
	}


private:
	double* vec;
	int size;
	short codeError, Error_counter;
	bool memory_free_variable = true;
	
};

VectorDouble::VectorDouble() :size(1)
{
	
	this->vec = new double[1];
	vec[0] = 0;
}

VectorDouble::VectorDouble(int size) :size(size)
{
	this->vec = new double[size];
	for (int i = 0; i < size; i++) {
		this->vec[i] = 0;
	}
}

VectorDouble::VectorDouble(int size, double inicialisated_value) :size(size)
{
	this->vec = new double[size];
	for (int i = 0; i < size; i++) {
		this->vec[i] = inicialisated_value;
	}
}

VectorDouble::VectorDouble(string rand_variable, int limit_size, int limit_element)
{
	if (rand_variable == "rand") {
		srand(time(NULL));
		this->size = rand() % limit_size;
		vec = new double[this->size];
		for (int i = 0; i < this->size; i++) {
			this->vec[i] = rand() % limit_element;
		}
	}
}

VectorDouble::~VectorDouble() {
	if (memory_free_variable) {
		delete[]vec;
	}
	else
		memory_free_variable = true;
}

istream& operator>>(istream& input, VectorDouble& vector) 
{
	if (vector.vec != nullptr)
		delete[]vector.vec;
	cout << "enter size: ";
	cin >> vector.size;
	vector.vec = new double[vector.size];
	for (int i = 0; i < vector.size; i++) {
		input >> vector.vec[i];
	}
	return input;
}

ostream& operator<<(ostream& output, const VectorDouble& vector) 
{
	for (int i = 0; i < vector.size; i++) {
		output << vector.vec[i] << '\t';
	}
	output << endl;
	return output;
}




/*Завдання 2. Варіанти задач. Побудувати асоційований клас збереження
двох сутностей. В завданні створити клас, який представляє собою
асоціативний масив між двома сутностями. Написати функцію створення
набору асоціативних сутностей. Перевантажити операцію індексації [] –
функцію, яка звертається до об’єкта класу, за однією сутністю, якщо індекс,
повертає асоціативну сутність, якщо відповідної сутності немає в встановлює
код помилки у змінну CodeError, альтернативні звернення через
перевантаження операції виклику функції(); перевантажити дружні операції
введення та виведення.
Задача 2.3. Доменних імен та ІР - адреса*/


class Associated
{

public:

	class IP
	{
	public:
		IP() {
			counter++;
			srand(IP::counter);
			for (int i = 0; i < 4; i++) {
				this->adress[i] = rand() % 999;
			}
		}

		friend istream& operator>>(istream& input, Associated::IP& object);
		friend ostream& operator<<(ostream& output, Associated::IP& object);

		short& operator [](int index)
		{
			if (index < 0 || index>4) {
				cout << "IP index error" << endl;
				index = 0;
			}
			return this->adress[index];
		}

		bool operator==(const IP& other)
		{
			for (int i = 0; i < 4; i++) {
				if (this->adress[i] != other.adress[i])
					return false;
				return true;
			}
		}

		static int counter;
		short adress[4];
	};

	Associated()
	{
		srand(time(NULL));
		short size = 4 + rand() % 6;
		char* generate_name;
		generate_name = new char[size];
		for (short i = 0; i < size; i++) {
			if (i == size - 1) {
				generate_name[i] = '\0';
			}
			else
				generate_name[i] = 'a' + rand() % 26;
			
		}
		this->Domain = generate_name;
	}

	Associated(string domain)
	{
		this->Domain = domain;
	}

	Associated& operator = (const Associated& other) {
		this->Domain = other.Domain;
		this->IP_adress = other.IP_adress;
		return *this;
	}

	string GetDomainFromIP(const IP& IPadress)
	{
		if (this->IP_adress == IPadress)
			return this->Domain;
		return "error";
		
	}

	friend ostream& operator<<(ostream& output, Associated& object);

	friend class AssociativeArr;

	void PrintIP() {
		cout << IP_adress;
	}

private:

	string Domain;
	IP IP_adress;
	
};


int Associated::IP::counter = 0;


//operator of input and output for class ASSOCIATIVE
ostream& operator<<(ostream& output, Associated& object) {
	output << "Domain: " << object.Domain << "\nIP: ";
	for (int i = 0; i < 4; i++) {
		output << object.IP_adress[i];
		if (i < 3)
			output << '.';
	}
	return output;
}

//operator of input and output for class IP
ostream& operator<<(ostream& output, Associated::IP& object) {
	for (int i = 0; i < 4; i++) {
		output << object[i];
		if (i < 3)
			output << '.';
	}
	return output;
}

istream& operator>>(istream& input, Associated::IP& object) {
	for (int i = 0; i < 4; i++) {
		input >> object[i];
	}
	return input;
}

/// <summary>
/// ARRAY OF ASSOCIATED OBJECTS
/// </summary>
class AssociativeArr
{
public:
	AssociativeArr(Associated initial_element) :size(1) {
		arr = new Associated[1];
		arr[0] = initial_element;
	}
	
	AssociativeArr (const AssociativeArr& other) {
		if (this->arr != nullptr) {
			delete[]this->arr;
		}
		this->size = other.size;
		this->arr = new Associated[other.size];
		for (int i = 0; i < other.size; i++) {
			this->arr[i] = other.arr[i];
		}
	}

	Associated& operator[](Associated::IP IPkey)
	{
		for (int i = 0; i < this->size; i++) {
			if (IPkey == this->arr[i].IP_adress)
				return arr[i];
		}
		cout << "ERROR incorrect input of IP" << endl;
		Associated error("ERROR of input");
		for (int i = 0; i < 4; i++) {
			error.IP_adress.adress[i] = -1;
		}
		return error;
	}

	//void push_back(Associated& new_element)
	//{
	//	AssociativeArr temp(*this);
	//	delete[]this->arr;
	//	this->arr = new Associated[size + 1];
	//	for (int i = 0; i < this->size; i++) {
	//		this->arr[i] = temp.arr[i];
	//	}
	//	this->arr[size] = new_element;
	//	++this->size;
	//	//cout << "CHEcking: " << endl << "temp: " << temp << endl << "this: " << *this;
	//}

	void operator()(Associated& new_element)
	{
		AssociativeArr temp(*this);
		delete[]this->arr;
		this->arr = new Associated[size + 1];
		for (int i = 0; i < this->size; i++) {
			this->arr[i] = temp.arr[i];
		}
		this->arr[size] = new_element;
		++this->size;
	}

	friend ostream& operator<<(ostream& output, AssociativeArr& object);

private:
	Associated* arr;
	short size;

};

ostream& operator<<(ostream& output, AssociativeArr& object) 
{
	for (int i = 0; i < object.size; i++) {
		output << object.arr[i] << endl;
	}
	return output;
}



void Task1()
{
	VectorDouble common, common_1(6), common_2(6, 4), unic(4);
	cout << common;
	if (common_2 > common_1) {
		cout << "COMMON_1:\n" << common_1;
		cout << "COMMON_2:\n" << common_2;
	}
	cout << "input unic vector:\n";
	cin >> unic;
	cout << "UNIC VECTOR:\n" << unic;

	VectorDouble random_vec("rand", 10, 1616), pre_increment(5, 6.89), post_decrement(5, 4.4), temp_vec;
	cout << "RANDOM VECTOR:" << endl << random_vec;
	cout << "incremented vectotr: \n" << ++pre_increment;
	temp_vec = post_decrement--;
	cout << "decremented vectotr:\n " << post_decrement;

	VectorDouble a(8, 3.48), b(3, 4.6);
	b /= 2;
	a += b;
	cout << "Vector A: \n" << a;
	cout << "Vector B: \n" << b;
}

void Task2()
{
	Associated feel("I love Dashulya"), duck("duckling"), cow("calf"), woolf("puppy");
	

	Associated arr[] = { feel, duck, cow, woolf };
	Associated::IP desirved_ip;
	Associated result;

	AssociativeArr main_arr(feel);
	main_arr(duck);
	main_arr(cow);
	main_arr(woolf);
	cout << main_arr;


	cout << "enter IP of diserved domain:" << endl;
	cin >> desirved_ip;
	result = main_arr[desirved_ip];
	cout << result;
	

	/*have to create class IP into class Associated to overload operator of inputing >>
	it will make possible to input IP-adress to find its domain name
	(and maybe should create class Domain too)*/
	
}

int main()
{
	int choise;
	cout << "choose task:\n" << "1. VectorDouble;\n" << "2. Associative class\n";
	cin >> choise;
	switch (choise) {
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		default:
			cout << "incorrect input";
			break;
	}

	return 0;
}









// // OOPLab4T.cpp : Цей файл містить є шаблоном для 
//// виконання лаб. роботи №4. 
//// Він містинь функцію "main" з якої починається та закінчується виконання програми.
////
//
//
//#include <iostream>
//
//// Ваші файли загловки 
////
//#include "Lab4Exmaple.h"
//int main()
//{
//    std::cout << " Lab #4  task chain  !\n";
//    //  Код виконання завдань
//    //  Головне меню завдань
//    //  Функції та класи можуть знаходитись в інших файлах проекту
//
//    int chain = 1;
//    if (chain == 1) chain = mainExample1();
//    if (chain == 2) chain = mainExample2();
//    if (chain == 3) chain = mainExample3();
//
//}


