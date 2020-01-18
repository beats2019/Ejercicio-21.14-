#include <iostream>
#include <string>
using namespace std;
string charToBits(unsigned char);
void printBits(unsigned);
unsigned maskCharacters(unsigned char, unsigned char, unsigned char, unsigned char);
void unmaskCharacters(unsigned);


int main()
{
    unsigned maskedNumber = maskCharacters('A', 'f','C','D');
    unmaskCharacters(maskedNumber);
}


/*
    Return an unsigned variable(result) which contains the four given characters. The package works by inserting
    the binary of the first element into the first byte and the binary of the second character into the
    second byte.


    @param value1,value2... The characters to be inserted

    @return unsigned int containing the bits of value1 and value2
*/
unsigned maskCharacters(unsigned char value1, unsigned char value2,
                        unsigned char value3, unsigned char value4)                                                                                                                                                                                                                                                                                                                                   
{
    string result("");
    result = charToBits(value1);
    result = result + charToBits(value2);
    result = result + charToBits(value3);
    result = result + charToBits(value4);
    return strtoul(&result[0], nullptr, 2);
}

/*
    Prints the individual characters that are contained in the mask
    @param mask The unsigned value that contains the characters
*/
void unmaskCharacters(unsigned mask)
{
    /*
        255 = 00000000 00000000 00000000 11111111
        255 is the base mask and shifting it may access the rest of the characters
    */
    int shiftValue = 8 * 3;
    char resultCharacter1 = (mask & (255 << shiftValue)) >> shiftValue;
    shiftValue = 8 * 2;
    char resultCharacter2 = (mask & (255 << shiftValue)) >> shiftValue;
    shiftValue = 8;
    char resultCharacter3 = (mask & (255 << shiftValue)) >> shiftValue;
    char resultCharacter4 = mask & 255;
    cout << "Mask = "; printBits(mask);
    cout << "\nCharacter 1 = " << resultCharacter1 << endl
        << "Character 2 = " << resultCharacter2 << endl
        << "Character 3 = " << resultCharacter3 << endl
        << "Character 4 = " << resultCharacter4 << endl;
}


/*
    Returns a string containing the 8 bits of a given char


    @param givenCharacter The character to be converted to binary

    @return The binary form of value
*/
string charToBits(unsigned char givenCharacter)
{
    string resultString("");
    for (int i = 0; i < sizeof(givenCharacter) * 8; i++)
        resultString.insert(0, to_string((givenCharacter >> i) & 1));
    return resultString;
}


/*
    Prints the 32 bit secuence of a given value


    @param value The value to be printed as binary
*/
void printBits(unsigned value)
{
    const int limit = 8 * sizeof(unsigned) - 1;
    unsigned mask = 1 << limit;
    for (unsigned i = 1; i <= limit + 1; i++)
    {
        cout << (value & mask ? '1' : '0');
        value <<= 1;

        if (i % 8 == 0)
            cout << ' ';
    }
}