#include <iostream.h>

main()
{
      char tc[10];
      int ti[10];
      
      char* pc=tc;
      int* pi=ti;
      
      cout << "char*" << long(pc+1)-long(pc) << '\n';
      cout << "int*" << long(pi+1)-long(pi) << '\n';
      
      getchar();
}
