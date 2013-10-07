/**
*************************************************************
* @file test.cpp
* @brief Breve descripción
* Pequeña documentación del archivo
*
*
*
*
*
* @author Gaspar Fernández <blakeyed@totaki.com>
* @version
* @date 01 oct 2013
* Historial de cambios:
*
*
*
*
*
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

