#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>

int main(int argc, char **argv)
{
    if (argc<2 || argc>2)
    {
        std::cout<<"Usage:"<<std::endl;
        std::cout<<"      StringSubs <String as Parameter>"<<std::endl;
        getchar();
        return -1;
    }
    
    std::string param=argv[1];
    std::string vchars;
    std::vector<std::string> stringlist;
    
    for (std::string::iterator it = param.begin();it != param.end();it++)
    {
        if ((*it>=65 && *it<=90) || (*it>=97 && *it<=122))
        {
            vchars+=*it;
        }
    }
    
    if (vchars.length()<2)
    {
        std::cout<<"Expecting a String (minimum of two chars)"<<std::endl;
        getchar();
        return -1;
    }
    
    for(unsigned int i=2;i<=6;i++)
    {
        if (vchars.length()<=i)
        {
            stringlist.push_back(vchars);
            break;
        }
        for (unsigned int j=0;j<=(vchars.length()-i);j++)
        {
            if (std::find(stringlist.begin(),stringlist.end(),vchars.substr(j,i))==stringlist.end())
                stringlist.push_back(vchars.substr(j,i));
        }
    }
    
    std::sort (stringlist.begin(),stringlist.end());
    
    for (std::vector<std::string>::iterator it = stringlist.begin();it != stringlist.end();it++)
    {
        std::cout<<*it<<std::endl;
    }
    getchar();
    return 0;
}
