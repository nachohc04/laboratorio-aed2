#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int j=0;
    while(s[j]!='\0')
    {
        j++;
    }   
    return j;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool res=true;
    int j=0;
    while((!(s1[j]=='\0'|| s2[j]=='\0'))&& res)
    {
        res = s1[j]==s2[j];
        j++;
    }
    if(((s1[j]=='\0')!= (s2[j]=='\0')))
    {
        res= false;
    }
    return res;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool res;
    int j=0;
    
    while(s1[j]==s2[j] && !(s1[j]=='\0'|| s2[j]=='\0'))
    {
        j++;
    }

    res = s1[j]<=s2[j];

    return res;
}