#include <iostream>
using namespace std;

class CSingleton
{
private:
    CSingleton()
    {
    }
    static CSingleton *m_pInstance;
public:
    static CSingleton* GetInstance()
    {
        if (m_pInstance == NULL)
            m_pInstance = new CSingleton();
        return m_pInstance;
    }
};