/**
*************************************************************
* @file gutils_regex.cpp
* @brief Description
*
* @author Gaspar Fernández <blakeyed@totaki.com>
* @version
* @date 05 oct 2013
* Changelog:
*
*
*
*
*************************************************************/

#include "gutils_regex.h"
#include "gutils_exception.h"
#include "gutils_string.h"

namespace Gutils
{
  RegexMatches::RegexMatches(ustring regex, ustring text, int offset, RegexMatchFlags match_options,  RegexCompileFlags compile_options)
  {
    RefPtr<Regex> rg = Regex::create(regex, compile_options);
    MatchInfo minfo;
    rg->match(text, offset, minfo, match_options);
    ipr=0;
    unsigned i;
    int start, end;
    this->end=false;
    _original=text;
    workCopy=text;
    while (minfo.matches())
      {
	Match m;
	for (unsigned j=0; j<minfo.get_match_count(); ++j)
	  {
	    if (minfo.fetch_pos(j, start, end))
	      {
		SingleMatch sM={minfo.fetch(j), start, end, end-start};
		m.push_back(sM);
	      }
	  }
	matches.push_back(m);
	minfo.next();
	++i;
      }
  }

  RegexMatches::~RegexMatches()
  {
  }

  RegexMatches::Matches RegexMatches::getAll()
  {
    return matches;
  }

  RegexMatches::Match RegexMatches::get()
  {
    if (ipr<matches.size())
      return matches[ipr];
    else
      throw Exception(1000, "RegexMatches::get: Match not found");
  }

  RegexMatches::SingleMatch RegexMatches::get(unsigned e, bool exception)
  {
    if (ipr<matches.size())
      {
	if (e<matches[ipr].size())
	  return matches[ipr][e];
	else if (exception)
	  throw Exception(1001, "RegexMatches::get: Sub-match not found");
	else
	  return (!matches[ipr].empty())?matches[ipr].back():SingleMatch();
      }
    else if (exception)
      throw Exception(1000, "RegexMatches::get: Match not found");
    else
      return SingleMatch();
  }

  bool RegexMatches::haveMatch()
  {
    return ( (ipr<matches.size()) && (!this->end) );
  }

  int RegexMatches::count()
  {
    return matches.size();
  }

  int RegexMatches::countSub(int n)
  {
    return (n<matches.size())? matches[n].size():0;
  }

  bool RegexMatches::next()
  {
    if (ipr>=matches.size()-1)
      {
	this->end=true;
	return false;
      }

    ++ipr;
    return true;
  }

  void RegexMatches::rewind()
  {
    ipr=0;
    end=false;
  }

  RegexMatches::Match RegexMatches::getn(unsigned n, bool exception)
  {
    if (n<matches.size())
      return matches[n];
    else if (exception)
      throw Exception(1002, "RegexMatches::getn: Match not found");
    else
      return Match();
  }

  RegexMatches::SingleMatch RegexMatches::getn(unsigned n, unsigned e, bool exception)
  {
    if (n<matches.size())
      {
	if (e<matches[n].size())
	  return matches[n][e];
	else if (exception)
	  throw Exception(1003, "RegexMatches::getn: Submatch not found");
	else
	  return SingleMatch();
      }
    else if (exception)
      throw Exception(1002, "RegexMatches::getn: Match not found");
    else
      return SingleMatch();
  }

  void RegexMatches::revertChanges()
  {
    workCopy=_original;
  }

  bool RegexMatches::replaceMatch(ustring newText, unsigned e, bool cont, int n)
  {
    if (n==-1)
      n=ipr;

    if (n<matches.size())
      {
	if (e<matches[n].size())
	  {
	    workCopy.replace(matches[n][e].start, matches[n][e].size, newText);
	    int offset=newText.length()-matches[n][e].size;
	    matches[n][e].end+=offset;

	    // Make sure it's the unique SingleMatch
	    SingleMatch tmp =matches[n][e];
	    matches[n].clear();
	    matches[n].push_back(tmp);

	    for (unsigned i=n+1; i<matches.size(); ++i)
	      {
		for (unsigned j=0; j<matches[i].size(); ++j)
		  {
		    matches[i][j].start+=offset;
		    matches[i][j].end+=offset;
		  }
	      }
	    return true;
	  }
	else
	  return false;
      }
    else
      return false;
  }

  ustring RegexMatches::str()
  {
    return workCopy;
  }

  ustring RegexMatches::original()
  {
    return _original;
  }

  ustring RegexMatches::debug()
  {
    ustring ret;
    for (unsigned i=0; i<matches.size(); ++i)
      {
	ret+="Match "+ustring::format(i)+endl;
	for (unsigned j=0; j<matches[i].size(); ++j)
	  {
	    ret+=matches[i][j].str+" (Start: "+
	      ustring::format(matches[i][j].start)+"; End: "+
	      ustring::format(matches[i][j].end)+"; Size: "+
	      ustring::format(matches[i][j].size)+")"+endl;
	  }
      }

    return ret;
  }
};
