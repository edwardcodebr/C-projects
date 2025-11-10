#include <iostream>
using namespace std;

class cat
{
  public:
    std::string nome;
    std::string race;
    int idade;
    
    string comer(){
      return "eat the fish";
    }
    string miar(){
      return "meowt";
    }
};

class human
{
  public:
    std::string nome;
    std::string country;
    int age;
    
    string guy(){
      return "this guy is";
    }
    string like(){
      return "love your kitty";
    }
};

int main() 
{
    cat kit1;
    human peop;
    
    kit1.nome = "midoria";
    kit1.race = "black";
    kit1.idade = 2;

    peop.nome = "edward";
    peop.country = "brazil";
    peop.age = 23;

    std::cout << "the " << kit1.nome << " " << kit1.comer() << " " << "and " << kit1.miar() << " and your friend " << peop.guy() << " " << peop.nome << " lives in " << peop.country << " and " << peop.like();
    return 0;
}
