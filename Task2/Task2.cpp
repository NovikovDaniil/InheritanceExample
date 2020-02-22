// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
#include<clocale>
using namespace std;

class ComputerGameObject
{
private:
	string title;
protected:
	ComputerGameObject(const string& _title) :title(_title) {}
	ComputerGameObject(const ComputerGameObject& obj) : title(obj.title) {}
	virtual ~ComputerGameObject() { cout << "Computer game object deleted" << endl; }
	virtual void  _print() const { cout << "title: " << title; }
public:
	virtual void draw() = 0;
	void  print() const
	{
		cout << typeid(*this).name() << ": (";
		_print();
		cout << ")\n\n";
	}
};
class Creature :public ComputerGameObject
{
private:
	int healthPoints;
	int coordinateX;
	int coordinateY;
	int endurance;
public:
	Creature(const string& _title, int _healthPoints, int _endurance) :ComputerGameObject(_title), healthPoints(_healthPoints), endurance(_endurance), coordinateX(0), coordinateY(0) {}
	Creature(const Creature& obj) :
		ComputerGameObject(obj), healthPoints(obj.healthPoints), coordinateX(obj.coordinateX), coordinateY(obj.coordinateY), endurance(obj.endurance) {}
	Creature(const string& _title, int _healthPoints, int _coordinateX, int _coordinateY, int _endurance) :
		ComputerGameObject(_title), healthPoints(_healthPoints), coordinateX(_coordinateX), coordinateY(_coordinateY), endurance(_endurance) {}
	void _move(int X, int Y) {
		coordinateX = X;
		coordinateY = Y;
	}
	int getX() { return coordinateX; }
	int getY() { return coordinateY; }
	~Creature() { cout << "Creature deleted" << endl; }
protected:
	virtual void move(int, int) = 0;
	void  _print()const override
	{
		ComputerGameObject::_print();
		cout << ", healthPoints: " << healthPoints << ", coordinateX: " << coordinateX << ", coordinateY: " << coordinateY << ", endurance: " << endurance;
	}
};
class MythicalAnimal :public Creature
{
private:
	bool wool;
public:
	MythicalAnimal(const string& _title, int _healthPoints, int _endurance, bool _wool) :Creature(_title, _healthPoints, _endurance), wool(_wool) {}
	MythicalAnimal(const MythicalAnimal& obj) : Creature(obj), wool(obj.wool) {}
	MythicalAnimal(const string& _title, int _healthPoints, int _coordinateX, int _coordinateY, int _endurance, bool _wool) :
		Creature(_title, _healthPoints, _coordinateX, _coordinateY, _endurance), wool(_wool) {}
	~MythicalAnimal() { cout << "Mythical animal deleted" << endl; }
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Mythical animal went to a new place: (" << getX() << ";" << getY() << ")" << endl;
	}
	void draw()
	{
		cout << "Location of a mythical animal: (" << getX() << ";" << getY() << ")\n";
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << ", wool: " << wool;
	}
};
class HumanoidCharacter :public Creature
{
private:
	int weaponCount;
	int height;
public:
	HumanoidCharacter(const string& _title, int _healthPoints, int _endurance, int _weaponCount, int _height) :Creature(_title, _healthPoints, _endurance), weaponCount(_weaponCount), height(_height) {}
	HumanoidCharacter(const HumanoidCharacter& obj) : Creature(obj), weaponCount(obj.weaponCount), height(obj.height) {}
	HumanoidCharacter(const string& _title, int _healthPoints, int _coordinateX, int _coordinateY, int _endurance, int _weaponCount, int _height) :
		Creature(_title, _healthPoints, _coordinateX, _coordinateY, _endurance), weaponCount(_weaponCount), height(_height) {}
	~HumanoidCharacter() { cout << "Humanoid character deleted" << endl; }
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Humanoid character went to a new place: (" << getX() << ";" << getY() << ")" << endl;
	}
	void draw() override
	{
		cout << "Location of a humanoid character: (" << getX() << ";" << getY() << ")\n";
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << ", number of weapons: " << weaponCount << ", height: " << height;
	}
};
class MagicCharacter :public Creature
{
private:
	string kindOfMagic;
public:
	MagicCharacter(const string& _title, int _healthPoints, int _endurance, string _kindOfMagic) :Creature(_title, _healthPoints, _endurance), kindOfMagic(_kindOfMagic) {}
	MagicCharacter(const MagicCharacter& obj) : Creature(obj), kindOfMagic(obj.kindOfMagic) {}
	MagicCharacter(const string& _title, int _healthPoints, int _coordinateX, int _coordinateY, int _endurance, string _kindOfMagic) :
		Creature(_title, _healthPoints, _coordinateX, _coordinateY, _endurance), kindOfMagic(_kindOfMagic) {}
	~MagicCharacter() { cout << "Magic character deleted" << endl; }
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Magic character went to a new place: (" << getX() << ";" << getY() << ")" << endl;
	}
	void draw() override
	{
		cout << "Location of a magic character: (" << getX() << ";" << getY() << ")\n";
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << ", kind of magic: " << kindOfMagic;
	}
};
class MagicItem :public ComputerGameObject
{
private:
	int value;//value to the owner of this item
	int price;
	int coordinateX;
	int coordinateY;
public:
	MagicItem(const string& _title) :ComputerGameObject(_title), coordinateX(0), coordinateY(0), value(0), price(0) {}
	MagicItem(const string& _title, int _value, int _price) :ComputerGameObject(_title), value(_value), price(_price), coordinateX(0), coordinateY(0) {}
	MagicItem(const string& _title, int _value, int _price, int _coordinateX, int _coordinateY) :
		ComputerGameObject(_title), value(_value), price(_price), coordinateX(_coordinateX), coordinateY(_coordinateY) {}
	MagicItem(const MagicItem& obj) :ComputerGameObject(obj), coordinateX(obj.coordinateX), coordinateY(obj.coordinateY), value(obj.value), price(obj.price) {}
	~MagicItem() { cout << "Magic item deleted\n"; }
	void draw() override
	{
		cout << "Location of a magic item: (" << coordinateX << ";" << coordinateY << ")\n";
	}
protected:
	void _print()const override
	{
		ComputerGameObject::_print();
		cout << ", value: " << value << ", price: " << price << ", coordinateX: " << coordinateX << ", coordinateY: " << coordinateY;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	MagicItem book("Stone", 1, 2);
	book.print();
	book.draw();
	MythicalAnimal lion("Лев", 100, 200, 1);
	lion.move(100, 150);
	lion.draw();
	lion.print();
	HumanoidCharacter BigSmoke("Big Smoke", 12,100,150, 2, 1000, 185);
	BigSmoke.draw();
	BigSmoke.move(234, 567);
	BigSmoke.print();
	MagicCharacter Fly("Муха",100,56,"Смертельно жужжит");
	Fly.draw();
	Fly.move(234, 567);
	Fly.print();
}

