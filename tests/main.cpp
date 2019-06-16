#include "tst_cpp_deliberates.h"
#include "tst_designpatterns.h"

int main(int argc, char *argv[])
{
   int status = 0;
   {
       CppDeliberates cppDeliberates;
       status |= QTest::qExec(&cppDeliberates, argc, argv);
   }

   {
       DesignPatterns designPatterns;
       status |= QTest::qExec(&designPatterns, argc, argv);
   }

   return status;
}
