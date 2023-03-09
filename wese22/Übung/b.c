#ifndef __MATH_H__
#define __MATH_H__
#include <math.h>
#endif

#ifndef _Projektname_Dateiname_Dateiendung_INCLUDED_
#define _Projektname_Dateiname_Dateiendung_INCLUDED_
// Eigentlicher Inhalt der Header‐Datei
#endif

#define ADD(x) x + x

int main()
{
    int b = ADD(a++) * ADD(++a);

    int b = (a++ + a++) * (++a + ++a);
}