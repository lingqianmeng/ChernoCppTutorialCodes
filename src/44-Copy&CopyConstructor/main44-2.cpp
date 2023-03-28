#include<iostream>
#include<string>

/*
*  To demonstrate in debug mode the break down, when the both m_Buffer in String destroyed by the destructor...
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

	~String()
	{
		delete[] m_Buffer; // here happens break down if the second m_Buffer gets destroyed.
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

int main()
{
	// closure into a brace to observe the break down when destruct for both m_Buffer...
	{
		String string = "Cherno";
		String string_2nd = string;
		std::cout << string << std::endl;
		std::cout << string_2nd << std::endl;
	}
	std::cin.get();
}