#include<iostream>
#include<string>

/*
*  Demonstrate Deep Copy.
*  Demonstrate Copy Constructor.
*/

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1]; // not to forget to add 1 to make zero at the end of buffer.
		memcpy(m_Buffer, string, m_Size + 1);
		// or 
		m_Buffer[m_Size] = 0; // make sure the last byte is null.
	}

	/*
	// The copy constructor. The modern C++ has already done it for us.
	String(const String& other)
	{
		memcpy(this, &other, sizeof(String));
	}
	*/

	// Copy Constructor for Deep Copy from the Cherno
	String(const String& other)
		:m_Size(other.m_Size)
	{
		std::cout << "Copy happend!" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()
	{
		delete[] m_Buffer; // here happens break down if the second m_Buffer gets destroyed.
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

void PrintString(String string)
{
	std::cout << string << std::endl;
}

int main()
{
	// closure into a brace to observe the break down when destruct for both m_Buffer...
	{
		String string = "Cherno";
		String string_2nd = string;

		string_2nd[2] = 'a';
		// if you run this code, the display would be "Cherno Charno"
		// Means the copy is successful 
		// Also means this was a "Deep Copy".
		// And it will NOT run into break down when comes to destructor.
		std::cout << string << std::endl;
		std::cout << string_2nd << std::endl;
	}
	std::cin.get();
}