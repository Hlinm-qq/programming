#include <iostream>
#include <string>

// abstract class
class Food {
    public:
        enum class Type {
            IdiotSandwich,
            NormalSandwich
        };
        friend std::ostream & operator << (std::ostream &out, Food &d) {
            d.print(out);
            return out;
        }
        Type getType() { return type; }
        void setType(Type x) { type = x; }
        virtual ~Food() {}
    private:
        virtual void print(std::ostream &out) {}
        Type type;
};

class IdiotSandwich : public Food {
    public:
        IdiotSandwich(int x) {
            setType(Type::IdiotSandwich);
            setINT(x);
        }
        void setINT(int x) { intelligence = x; }
        int getINT() { return intelligence; }
    private:
        // TODO
        void print(std::ostream &out);
        int intelligence;
};

class NormalSandwich : public Food {
    public:
        NormalSandwich(std::string x) {
            setType(Type::NormalSandwich);
            setName(x);
        }
        void setName(std::string x) { name = x; }
        std::string getName() { return name; }
    private:
        // TODO
        void print(std::ostream &out);
        std::string name;
};

class Dish {
    public:
        Dish() { food = nullptr; }
        // TODO
        ~Dish();
        Food &getFood() { return (*food); }
        const Food &getFood() const { return (*food); }
        // TODO
        friend std::istream & operator >> (std::istream &in, Dish &d);
        Food *food;
};

void IdiotSandwich::print(std::ostream &out){
    out << "An idiot sandwich with intelligence level " << getINT() << " only.";
}

void NormalSandwich::print(std::ostream& out){
    out << getName() << ". Masterpiece of sandwiches.";
}

std::istream& operator >> (std::istream &in, Dish &d){
    std::string temp;
    int lvl;
    in >> temp;
    if(temp == "Ramsay"){
        in >> lvl;
        d.food = new IdiotSandwich(lvl);
        d.food->setType(Food::Type::IdiotSandwich);
    } else {
        d.food = new NormalSandwich(temp);
        d.food->setType(Food::Type::NormalSandwich);
    }
    return in;
}

Dish::~Dish(){
    delete food;
}

int n;
Dish dish;

int main() {
    std::cin >> n;
    while(n--) {
        std::cin >> dish;
        std::cout << dish.getFood() << std::endl;
    }
    return 0;
}