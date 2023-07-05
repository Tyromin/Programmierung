#include <stdarg.h>
#include <stdlib.h>


/** @brief Addition zweier ganzer Zahlen
*
*   Zwei ganze Zahlen werden mit einander addiert.
*
*   @param [in] ganzzahlige Zahl 1
*   @param [in] ganzzahlige Zahl 2
*   @return Summe der Addition.
*/

int add (int zahl1, int zahl2)
    {
        // ---- Start TODO ----
        return zahl1+zahl2;
        // ---- Ende TODO ----
    }




int main(int argc,char* argv[])
{
    int z1=2;
    int z2=2;

    if(argc==3)
    {
        z1 = atoi(argv[1]);
        z2 = atoi(argv[2]);
    }

    printf("\nDie Summe von %i + %i = %i\n",z1,z2,add(z1,z2));

    return 0;
}
