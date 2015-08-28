#include "stdafx.h"
#include "LineCounter.h"


LineCounter::LineCounter(string path, ifstream infile)
{
	m_path = path;
	m_inFile = infile;
}




LineCounter::~LineCounter()
{
}
