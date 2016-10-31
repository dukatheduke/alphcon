/**
 *  @author     Dušan Vudragović, dusan.vudragovic@gmail.com
 *  @file       cli.hpp
 */

#ifndef _CLI_HPP_
#define _CLI_HPP_

#include <boost/program_options.hpp>

#define MODE_UNKNOWN          0
#define MODE_HELP             1
#define MODE_CYRTOLAT         2
#define MODE_LATTOCYR         3

class cli {
public:
    cli(int, char **);
    ~cli();
    void help();
    int  get_mode();
private:
    int                                                    mode;
    boost::program_options::options_description            *cli_opt;
    boost::program_options::positional_options_description *cli_pos;
    boost::program_options::variables_map                  *cli_vm;
};

#endif
