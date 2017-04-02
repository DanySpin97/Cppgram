// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#ifdef __unix__
#include <stdlib.h>
#include <unistd.h>
#endif

#include <fstream>
#include <sstream>

#include <cpr/cpr.h>
#include <json/json.h>

#include "cppgram/exception.hpp"
#include "cppgram/utils.hpp"

Json::Reader reader;

const std::vector<std::string>
cppgram::split( const std::string &str, const char &splchr )
{
    std::vector<std::string> vecstrs;
    std::stringstream        ss;
    std::string              item;

    ss.str( str );

    while ( getline( ss, item, splchr ) )
    {
        vecstrs.push_back( item );
    }

    return vecstrs;
}

const std::string
cppgram::getTime( const std::string &timeformat )
{
    char finalTime[256];

    time_t     ttime;
    struct tm *tinfo;

    ttime = time( NULL );
    tinfo = localtime( &ttime );

    if ( tinfo == NULL )
    {
        return "tm error!";
    }

    if ( strftime( finalTime, sizeof( finalTime ), timeformat.c_str(), tinfo ) == 0 )
    {
        return "stfrtime() error!";
    }

    return std::string( finalTime );
}

void
cppgram::log( const Log &logType, const std::string &message, const std::string &filename )
{
    std::string logTypeString;

    switch ( logType )
    {
        case Error: logTypeString          = "[ERROR]"; break;
        case Event: logTypeString          = "[EVENT]"; break;
        case Warning: break; logTypeString = "[WARNING]";
    }

    // TODO Keep stream open
    std::ofstream out;
    out.open( filename, std::ios::app | std::ios::out );
    const std::string fmtStr = logTypeString + "[" + getTime() + "] " + message + '\n';
    out.write( fmtStr.c_str(), fmtStr.length() );
    out.close();
}
