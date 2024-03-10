#include <iostream>
#include <cstdlib>

class String {


    public:
        String() = default;

        String(const char* d) {
            std::cout << "Created!" << std::endl;
            size = strlen(d);
            data = new char[size];
            memcpy( data, d, size );
        }

        String(const String& other) {
            std::cout << "Copied!" << std::endl;
            size = other.size;
            data = new char[size];
            memcpy( data, other.data, size );
        }

        String( String&& other ) { // rvalue reference
            std::cout << "Moved!" << std::endl;
            size = other.size;
            data = other.data;

            other.data = nullptr;
            other.size = 0;
        }

        void Print() {
            for ( int i = 0; i < size; ++i )
                std::cout << data[i];
            std::cout << std::endl;
        }

        ~String() {
            std::cout << "Destroyed!" << std::endl;
            delete data;
        }

    private:
        u_int32_t size;
        char *data;

};

class Entity {

    public:
        Entity( const String& nm )
            : name(nm)
        {

        }

        Entity( String&& nm )
            //: name(nm)
            : name ( (String&&) nm )
            //: name ( std::move(nm) ) 
        {

        }

        void PrintName() {
            name.Print();
        }

    private:
        String name;

};


int main() {

    Entity myentity("hello");
    myentity.PrintName();
    //String mystr("hello");
    //mystr.Print();

    return 0;
}