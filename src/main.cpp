#include <iostream>

#include "bde.hpp"


int main(int argc, char const *argv[]) {
    Bde shellEnv;
    if (argc == 2) {
        if (argv[1] == std::string("allow")) {
            shellEnv.allow();
            return 0;
        } else if (argv[1] == std::string("exec")) {
            shellEnv.exec();
            return 0;
        } else if (argv[1] == std::string("isallowed")) {
            return !shellEnv.checkForBderc();
        } else if (argv[1] == std::string("hook")) {
            // std::cout << "_bde_hook() {" << std::endl;
            // std::cout << "    local previous_exit_status=$?;" << std::endl;
            // std::cout << "    bde exec;" << std::endl;
            // std::cout << "    return $previous_exit_status;" << std::endl;
            // std::cout << "};" << std::endl;
            // std::cout << "if ! [[ \"${PROMPT_COMMAND:-}\" =~ _bde_hook ]]; then" << std::endl;
            // std::cout << "  PROMPT_COMMAND=\"_bde_hook${PROMPT_COMMAND:+;$PROMPT_COMMAND}\"" << std::endl;
            // std::cout << "fi" << std::endl;
            // std::cout << "" << std::endl;


            // std::cout << "if (bde isallowed); then" << std::endl;
            // std::cout << "source ./.bderc" << std::endl;
            // std::cout << "fi" << std::endl;
            return 0;
        } else {
            std::cout << "Invalid argument" << std::endl;
            return 1;
        }
    }
    std::cout << "Invalid argument" << std::endl;
    return 1;
}