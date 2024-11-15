#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <cassert>

using namespace std;

int main(int argc, char** argv) {

    int sockets[2];
    int ret_code = socketpair(AF_UNIX, SOCK_STREAM, 0, sockets);
    assert(ret_code >= 0);

    ret_code = fork();
    assert(ret_code >= 0);

    if(ret_code == 0) {
        cout << "We are in the child" << endl;
        const char *message = "coucou";
        write(sockets[1], message, 7);
    } else {
        cout << "We are in the parent" << endl;
        char t[100];
        read(sockets[0], t, sizeof(t));
        cout << "Output : " << t << endl;
    }
}
