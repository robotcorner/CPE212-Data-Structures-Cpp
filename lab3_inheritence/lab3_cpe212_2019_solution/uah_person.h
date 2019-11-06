#ifndef UAH_PERSON_H
#define UAH_PERSON_H

/* this is the uah_person include file */

#include <iostream>
#include <string>
using namespace std;


class uah_person
{
private:  /* private members */
  string u_name;
  string u_email;
  string u_anumber;

public:  /* public members */

uah_person();        /* null constructor */

uah_person(string somename, string somemail, string someanumber); /* not null constructor */


void set(string somename, string somemail, string someanumber);

void print() const;

};

#endif

