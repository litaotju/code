#include<string.h>
#include<stdio.h>

struct CMyString{
	public:
		CMyString( char *p=NULL );
		CMyString(const CMyString &str);
		~CMyString(void){ delete [] m_pData;};
		CMyString & operator = (const CMyString & str);
		CMyString & operator += (const CMyString & str);
		void display(){	printf(this->m_pData);};

	private:
		char *m_pData;
};

CMyString::CMyString(char *p = NULL){
	if(p != NULL){
		m_pData = p;
	}
}

CMyString::CMyString(const CMyString & str){
	m_pData = new char[strlen(str.m_pData)+1];
	strcpy(m_pData, str.m_pData);
}

CMyString & CMyString::operator = (const CMyString & str){
	if(this == &str){
		return *this;
	}
	delete [] m_pData;
	m_pData = NULL;
	m_pData = new char[strlen(str.m_pData)+1];
	strcpy(m_pData, str.m_pData);
	return *this;
}

CMyString & CMyString::operator += (const CMyString & str){
	if(this != &str){
		CMyString tempStr(str);
		char * p = tempStr.m_pData;
		tempStr.m_pData = m_pData;
		m_pData = p;
	}
	return *this;
}


int main(){
	char *s1 = (char *)"This is a string\n";
	char *s2 = (char *)"Another string\n";
	
	CMyString cs1(s1);
	CMyString cs3(s2);
	CMyString cs2(s2);
	
	cs1.display();
	cs2.display();
	cs2 = cs1;
	cs2.display();
	
	cs3 += cs1;
	cs3.display();
	
	cs2 = cs2;
	cs2.display();
	
	cs3 = cs2 = cs1;
}