#include <stdio.h>

//gcc hellocgi.c -o hellocgi.cgi
int main() {

    printf("Content-Type: text/html\n\n");

    printf("<h1>Hello CGI</h1>");

    return 0;
}

