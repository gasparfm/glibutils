/**
*************************************************************
* @file test.cpp
* @brief Replace strings with glib
* Replace words in strings. You can replace once, twice or
* everytime. You can also use a map to input all the 
* strings being substituted.
*
* @author Gaspar Fernández <blakeyed@totaki.com>
* @version
* @date 01 oct 2013
* Historial de cambios:
*  - Initial demo release
*
*
*************************************************************/

#include <iostream>
#include "gutils.h"

using namespace std;

int main(int argc, char *argv[])
{
  Glib::ustring str1 = "I enjoy writing strings in my typewriter. Writing books in my typewriter instead of visiting Facebook.";
  map<ustring, ustring> m;
  m["writing"] = "replacing";
  m["typewriter"] = "computer";
  m["books"] = "code";
  m["Facebook"] = "Twitter";

  cout <<"Original string: "<<str1<<endl;

  cout << "First try: " << Gutils::replaceAll(str1, "typewriter", "computer") << endl;
  cout << "Second try (with map): "<< Gutils::replaceAll(str1, m) <<endl;

  return 0;
}

