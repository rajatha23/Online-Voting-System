#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int already_voted(char *id) {
    FILE *f = fopen("C:\\xampp\\data\\voted.txt", "r");
    if(!if) return 0;
    char line[100];
    while(fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = 0;
        if(strcmp(line, id) == 0) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int main(void) {
    printf("Content-Type: text/html\n\n");

    char *data = getenv("QUERY_STRING");
    if(!data) {
        printf("<h2>Error: No data received!</h2>");
        return 0;
    }

    char voter_id[50];
    sscanf(data, "voter_id=%49s", voter_id);

    if(already_voted(voter_id)) {
        printf("<h2 style='color:red;'>You already voted!</h2>");
       
    } else {
        printf("<html><body>");
        printf("<h2>Select Candidate</h2>");
        printf("<form action='/cgi-bin/vote.cgi' method='get'>");
        printf("<input type='hidden' name='voter_id' value='%s'>", voter_id);
        printf("<input type='radio' name='candidate' value='Moksha' required> Moksha<br>");
        printf("<input type='radio' name='candidate' value='Rajatha' required> Rajatha<br>");
        printf("<input type='radio' name='candidate' value='Sandhya' required> Sandhya<br><br>");
        printf("<button type='submit'>Submit Vote</button>");
        printf("</form></body></html>");
    }
    return 0;
}
