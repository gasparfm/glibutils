/**
*************************************************************
* @file regextest.cpp
* @brief First test with regex
* Use regex to match strings and replace them with another thing
*
*
* @author Gaspar Fernández <blakeyed@totaki.com>
* @version
* @date 03 oct 2013
* Historial de cambios:
*  - 20131003 Initial release
*  - 20131008 Change to demo, to cout found text
*
*
*************************************************************/

#include <glibmm/ustring.h>
#include <iostream>
#include "gutils.h"

using namespace Glib;
using namespace std;

int main()
{
  Glib::ustring str1 = "Just want to %find% some %keywords% in this %text%";

  Gutils::RegexMatches m("%([a-z]*)%", str1);

  cout << m.get(0).str << " found."<<endl;
  m.replaceMatch("paint");
  m.next();
  cout << m.get(0).str << " found."<<endl;
  m.replaceMatch("paintings");
  m.next();
  cout << m.get(0).str << " found."<<endl;
  m.replaceMatch("room");
  cout << "String: "<<m.str()<<endl;
}
