/**
*************************************************************
* @file regexCallback.cpp
* @brief More tests with regex
*  In this example we will parse a regex in a string and then parse it in
*  a function.
*
*  Idea: Useful to create functions or keywords in a user input (or internal
*  input within our program) to modify the behavior of our libs.
*
*
* @author Gaspar Fernández <blakeyed@totaki.com>
* @version
* @date 07 oct 2013
* Changelog
*  - 20131008 Initial release
*
*
*************************************************************/
#include <glibmm/ustring.h>
#include <iostream>
#include "gutils.h"

using namespace Glib;
using namespace std;

ustring cback(Gutils::RegexMatches::Match m)
{
  if (m[1].str=="measure")
    {
      if (m[2].str=="time")
	return "minute";
      else if (m[2].str=="space")
	return "Mb";
      else if (m[2].str=="speed")
	return "Mbps";
      else
	return "Unkown measure";
    }
  else
    return "Wrong code";
}

int main()
{
  Glib::ustring str1 = "Take a %measure(time)% to download 50%measure(space)% at 6.7%measure(speed)% ... %anything(else)%";

  // Warning! We have to escape \ for then C++ string, it will be used to escape a (
  // for the regex.
  Gutils::RegexMatches m("%([a-zA-Z]*)\\(([a-zA-Z_]*)\\)%", str1);

  while (m.haveMatch())
    {
      Gutils::RegexMatches::Match mt = m.get();
      m.replaceMatch(cback(mt));
      m.next();
    }
  cout << "Resulting string: "<< m.str()<<endl;
}
