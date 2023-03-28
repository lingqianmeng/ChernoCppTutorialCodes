#include<iostream>
#include<string>

/*
*  Demonstrate Shallow Copy.
*  After adjust on string_2nd the first one also be changed.
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

int main()
{
	// closure into a brace to observe the break down when destruct for both m_Buffer...
	{
		String string = "Cherno";
		String string_2nd = string;

		string_2nd[2] = 'a';
		// if you run this code, the display would be two "Charno Charno" instead of "Cherno Charno"
		// Means the copy is not successful 
		// Also means this was a "Shallow Copy".
		// And it runs into break down when comes to destructor.
		std::cout << string << std::endl;
		std::cout << string_2nd << std::endl;
	}
	std::cin.get();
}