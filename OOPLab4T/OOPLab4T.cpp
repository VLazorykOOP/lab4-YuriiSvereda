#include<iostream>

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
	
	~VectorDouble();

	//unary operations ++ --
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
			--this->vec[i];
		}
		return *this;
	}

	VectorDouble& operator++ (int value)
	{
		VectorDouble temp(*this);
		for (int i = 0; i < this->size; i++) {
			++this->vec[i];
		}
		return temp;
	}

	VectorDouble& operator-- (int value)
	{
		VectorDouble temp(*this);
		for (int i = 0; i < this->size; i++) {
			--this->vec[i];
		}
		return temp;
	}

	//
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

	VectorDouble& operator = (VectorDouble& other) 
	{
		this->size = other.size;
		other.vec = new double[other.size];
		for (int i = 0; i < other.size; i++) {
			this->vec[i] = other.vec[i];
		}
		return *this;
	}

	VectorDouble& operator += (VectorDouble& other)
	{
		//int rezult_size;
		//this->size >= other.size ? rezult_size = this->size : rezult_size = this->size;
		if (this->size != other.size) {
			cout << "ERROR += different sizes\n";
		}
		else {
			for (int i = 0; i < this->size; i++) {
				this->vec[i] += other.vec[i];
			}
		}
		return *this;
	}

	VectorDouble& operator -= (VectorDouble& other)
	{		
		if (this->size != other.size) {
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

	double& operator [](int value)
	{
		return this->vec[value];
	}

	bool operator >(const VectorDouble& other)
	{
		if (this->size != other.size) {
			cout << "ERROR different sizes";
			return false;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (this->vec[i] <= other.vec[i])
					return false;
			}
			return true;
		}
	}

	bool operator >=(const VectorDouble& other)
	{
		if (this->size != other.size) {
			cout << "ERROR different sizes";
			return false;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (this->vec[i] < other.vec[i])
					return false;
			}
			return true;
		}
	}

	bool operator <(const VectorDouble& other)
	{
		if (this->size != other.size) {
			cout << "ERROR different sizes";
			return false;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (this->vec[i] >= other.vec[i])
					return false;
			}
			return true;
		}
	}

	bool operator <=(const VectorDouble& other)
	{
		if (this->size != other.size) {
			cout << "ERROR different sizes";
			return false;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (this->vec[i] > other.vec[i])
					return false;
			}
			return true;
		}
	}
	



private:
	double* vec;
	int size;
	short codeError;

	
};

VectorDouble::VectorDouble()
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

VectorDouble::~VectorDouble() {
	delete[]vec;
}

istream& operator>>(istream& input, VectorDouble& vector) 
{
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



void Task1()
{

}

int main()
{
	

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


