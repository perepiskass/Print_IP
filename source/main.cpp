#include "version_lib.h"
#include "print.h"




int main(int argc, char *argv[]) 
{
  const std::string ver = "-version";
  if ( argc > 1)
  {
    if (argv[1] == ver)     std::cout << "version: " << version_major()<< '.'<< version_minor() << '.' << version_patch() << std::endl;
    else                    std::cout << "Type: -version, if you want to known proramm version" << std::endl;    
  }
  
    
  try
  {
    char  a(-1);
    short b(0);
    int   c(2130706433);
    long  d(8875824491850138409);
    std::string str{"trololo"};
    std::vector<int> vec{192,168,0,1};
    std::list<int> lst{};
    lst.push_back(127);
    lst.push_back(0);
    lst.push_back(0);
    lst.push_back(1);

    std::cout <<  str << std::endl;
    

    //ShowBin(a);
    printIP(a);
    printIP(b);
    printIP(c);
    printIP(d);

    printIP(str);
    printIP(vec);
    printIP(lst);

  }
  
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

    return 0;
}
