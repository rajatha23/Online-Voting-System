#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Content-Type: text/html\n\n");

    char *data = getenv("QUERY_STRING");
    char pwd[50];
    sscanf(data, "password=%49s", pwd);

    if(strcmp(pwd, "MSR1234") != 0) {
    printf("<h2>Wrong Password!</h2>");
    printf("<a href='/admin.html'>Try Again</a>");
    return 0;
}


    printf("<html><body><h2>Vote Count</h2><table border='1'>");
    printf("<tr><th>Candidate</th><th>Votes</th></tr>");

    FILE *f = fopen("C:\\xampp\\data\\votes.txt", "r");
    if(f) {
        char name[50];
        int ct;
        while(fscanf(f, "%s %d", name, &ct) == 2) {
            printf("<tr><td>%s</td><td>%d</td></tr>", name, ct);
        }
        fclose(f);
    }

    printf("</table><br><a href='/index.html'>Home</a></body></html>");

    return 0;
}
