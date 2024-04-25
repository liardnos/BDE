
#include <fstream>
#include <filesystem>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

#include "lib/json.hpp"
#include "bde.hpp"
#include <pty.h>

Bde::Bde() {
}

Bde::~Bde() {
}

bool Bde::checkForBderc() {
    std::ifstream i(".bderc");
    if (!i.is_open()) {
        std::cout << "No .bderc file" << std::endl;
        return false;
    }
    std::cout << ".bderc file found!" << std::endl;
    if (_config.isAllowed(std::filesystem::current_path()/".bderc")) {
        std::cout << "Allowed" << std::endl;
        return true;
    } else {
        std::cout << "Not allowed" << std::endl;
    }
    return false;
}

void Bde::exec() {
    if (!checkForBderc())
        return;

    int fd[2];
    // pipe(fd);

    // int cin = dup(0);
    // int cout = dup(1);
    // int cerr = dup(2);
    

    int master;
    int pid = forkpty(&master, NULL, NULL, NULL);
    std::cout << "pid: " << pid << std::endl;
    // int pid = fork();
    if (pid == 0) {
        std::cout << "child" << std::endl;
        std::cout << "starting new bash" << std::endl;
        //set up new fds
        // dup2(pipefd[1], 0);
        // exit(execve("/bin/bash", (char *const *)envp, nullptr));
        // close(fd[1]);
		// dup2(fd[0], 0);

        char * const * bashArgs = { NULL };
        int r = execvp("bash", bashArgs);
        // write(0, "end\n", 4);
        // exit(r);
        return;
    } else {
        close(fd[0]);
        while (1) {
            char buff[2048];
            ssize_t s = read(0, buff, 2048);
            if (s <= 0)
                break;
            std::cout << "write to master" << std::endl;
            write(master, buff, s);
        }
        // dup2(fd[1], 0);
        waitpid(pid, nullptr, 0);
        // close(fd[1]);
        // restore original fds
        // dup2(cin, 0);
        std::cout << "resuming previous bash" << std::endl;
        // dup2(cout, 1);
        // dup2(cerr, 2);
    }
    // close(cin);
    // close(cout);
    // close(cerr);
}

void Bde::allow() {
    _config.allow(std::filesystem::current_path()/".bderc");
}