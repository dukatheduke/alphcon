/**
 *  @author     Dušan Vudragović, dusan.vudragovic@gmail.com
 *  @file       cli.cpp
 */

#include "cli.hpp"

#include <iostream>

#define APP_NAME              "alphcon"
#define APP_VERSION           "1.0.0"
#define APP_RELEASE           "28 Oct 2016"

using std::cout;
using std::endl;

using boost::program_options::store;
using boost::program_options::notify;
using boost::program_options::variables_map;
using boost::program_options::command_line_parser;
using boost::program_options::options_description;
using boost::program_options::positional_options_description;

cli::cli(int argc, char **argv) {
    mode = MODE_UNKNOWN;

    cli_opt = new options_description("Command line options");
    cli_pos = new positional_options_description();
    cli_vm  = new variables_map();

    cli_opt->add_options()
    ("lattocyr,l", "Latin to Cyrillic alphabet conversion.")
    ("cyrtolat,c", "Cyrillic to Latin alphabet conversion.")
    ("help,h",     "Alphcon usage.")
    ;

    try {
        store(command_line_parser(argc, argv).options(*cli_opt).positional(*cli_pos).run(), *cli_vm);
    } catch (boost::exception &e) {
        help();
    }

    notify(*cli_vm);

    if (cli_vm->count("lattocyr"))      mode = MODE_LATTOCYR;
    else if (cli_vm->count("cyrtolat")) mode = MODE_CYRTOLAT;
    else if (cli_vm->count("help"))     mode = MODE_HELP;
    else mode = MODE_UNKNOWN;
}

cli::~cli() {
    delete cli_vm;
    delete cli_pos;
    delete cli_opt;
}

void cli::help() {
    cout << "Alphcon is Latin to Cyrillic (Cyrillic to Latin) alphabet converter." << endl;
    cout << endl;
    cout << *cli_opt << endl;
    cout << "Usage: " << endl;
    cout << "  echo <text_for_conversion> | " << APP_NAME << " [-clh]" << endl;
    cout << endl;
    cout << APP_NAME << "-" << APP_VERSION << " (" << APP_RELEASE << ")" << endl;

    return;
}

int cli::get_mode() {
    return mode;
}
