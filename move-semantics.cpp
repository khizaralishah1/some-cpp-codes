#include <iostream>
#include <cstdlib>

class String {


    public:
        String() { data = nullptr; size = 0; }

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

        String& operator=( String&& other ) { // move assignment

            if ( this != &other ) {
                std::cout << "Moved Assignment!" << std::endl;
                if (data != nullptr) delete[] data;
                size = other.size;
                data = other.data;

                other.data = nullptr;
                other.size = 0;
            }

            return *this;
        }

        void Print() {
            std::cout << "Print, Size = " << size << std::endl;
            for ( int i = 0; i < size; ++i )
                std::cout << data[i];
            std::cout << std::endl;
        }

        ~String() {
            std::cout << "Destroyed!" << std::endl;
            delete[] data;
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

    String str = "khizar"; // looks like ASSIGNMENT, but NO.
    String str2;

    str.Print();
    std::cout << "HEY" << std::endl;
    str2.Print();

    str2 = std::move(str);

    str.Print();
    std::cout << "HEY" << std::endl;
    str2.Print();

    //Entity myentity("hello");
    //myentity.PrintName();

    //String mystr("hello");
    //mystr.Print();

    return 0;
}