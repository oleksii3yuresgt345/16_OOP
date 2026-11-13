#include <iostream>
using namespace std;

class Animal //abstract class
{
    string name;
    string place;
    float weight;
public:
    Animal() :name("no name"), place("no place"), weight(0) {}
    Animal(string n, string p, float w) :name(n), place(p)
    {
       /* if (w > 0)
            weight = w;
        else
            weight = 0;*/
        weight = (w > 0) ? w : 0;
    }
    void Show()const
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Weight : " << weight << endl;
    }
    virtual void MakeSound() = 0; //pure virtual function
    virtual void Move() 
    {
        cout << "I am moving......." << endl;
    }
};

class Dog : public Animal
{
    string breed;
public:
    Dog():breed("no breed"),Animal(){}
    Dog(string name, string place, float weight, string b):breed(b),Animal(name,place,weight){}
    void MakeSound() override
    {
        cout << "Gav-gav" << endl;
    }
    void Move()
    {
        cout << "I am running and jumping....." << endl;
    }
    void Show()
    {
        Animal::Show();
        cout << "Type breed : " << breed << endl << endl;
    }
};
class Parrot : public Animal
{
    float flyHeight;
    bool canSpeak;
public:
    Parrot() :flyHeight(0), canSpeak(false), Animal(){}
    Parrot(string name, string place, float weight, float fH, bool speak) :
        flyHeight(fH), canSpeak(speak), Animal(name,place,weight){}
    void MakeSound() override
    {
        cout << "Kar-kar" << endl;
    }
    void Move() override
    {
        cout << "I am flying up to " << flyHeight << " and I can Speak or not : "
            << canSpeak << endl;
    }
    void Show()
    {
        Animal::Show();
        cout << "Fly Height : " << flyHeight << "m " << endl;
        cout << "Can speak : " << canSpeak << endl << endl;
    }
};
class Amphibian : public Animal
{
protected:
    float swimDeep;
public:
    Amphibian():swimDeep(0),Animal(){}
    Amphibian(string name, string place, float weight, float sD):
        swimDeep(sD),Animal(name, place, weight){}
    /*void MakeSound() override
    {
        cout << "kar-kar" << endl;
    }*/
    void Move() override
    {
        cout << "I am swimming down " << swimDeep << endl;
    }
    void Show()
    {
        Animal::Show();
        cout << "Swim deep : " << swimDeep << "m " << endl << endl;
    }
};
class Frog : public Amphibian
{
public:
    Frog():Amphibian(){}
    Frog(string name, string place, float weight, float swim) :
        Amphibian(name,place,weight,swim) {}
    void MakeSound() override
{
    cout << "kva-kva-kva" << endl;
}
    void Move() override
    {
        cout << "I am swimming down " << swimDeep << endl;
    }
};

void RollCall(Animal& a)
{
    a.MakeSound();
    a.Move();
}
int main()
{
   /* Animal animal("Tom", "Flat", 12);
    animal.Move();
    animal.Show();
    animal.MakeSound();*/
    Dog dog("Roki", "Flat", 12, "Taksa");
    dog.MakeSound();
    dog.Move();
    dog.Show();

    Parrot parrot("Kesha", "House", 0.6, 5, true);
    parrot.MakeSound();
    parrot.Move();
    parrot.Show();

    Frog frog("Crazy Frog", "Lake", 0.2, 2);
    frog.MakeSound();
    frog.Move();
    frog.Show();

    RollCall(dog);
    RollCall(parrot);
    RollCall(frog);
}
