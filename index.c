#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple BST node for candidate
typedef struct Candidate {
    char name[50];
    int votes;
    struct Candidate *left, *right;
} Candidate;

// Simple list of voter IDs who voted (very naive)
#define MAX_VOTERS 1000
static char voters[MAX_VOTERS][50];
static int voter_count = 0;

Candidate *root = NULL;

// Utility: create candidate node
Candidate *new_candidate(const char *name) {
    Candidate *p = malloc(sizeof(Candidate));
    strcpy(p->name, name);
    p->votes = 0;
    p->left = p->right = NULL;
    return p;
}

// Insert candidate into BST (by name)
Candidate *insert_candidate(Candidate *node, const char *name) {
    if (!node) return new_candidate(name);
    int cmp = strcmp(name, node->name);
    if (cmp < 0) node->left  = insert_candidate(node->left, name);
    else if (cmp > 0) node->right = insert_candidate(node->right, name);
    return node;
}

// Find candidate
Candidate *find_candidate(Candidate *node, const char *name) {
    if (!node) return NULL;
    int cmp = strcmp(name, node->name);
    if (cmp == 0) return node;
    else if (cmp < 0) return find_candidate(node->left, name);
    else return find_candidate(node->right, name);
}

// A naive check if voter already exists
int has_voted(const char *voter_id) {
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i], voter_id) == 0) return 1;
    }
    return 0;
}

// Add voter
void add_voter(const char *voter_id) {
    if (voter_count < MAX_VOTERS) {
        strcpy(voters[voter_count++], voter_id);
    }
}

// Traverse BST in-order and print results
void print_results(Candidate *node) {
    if (!node) return;
    print_results(node->left);
    printf("<tr><td>%s</td><td>%d</td></tr>\n", node->name, node->votes);
    print_results(node->right);
}

// Example: initialize some candidates
void init_candidates() {
    root = insert_candidate(root, "Moksha");
    root = insert_candidate(root, "Rajatha");
    root = insert_candidate(root, "Sandhya");
}

// Main CGI logic (very simplified)
int main(void) {
    char *data;
    init_candidates();

    printf("Content-Type: text/html\n\n");
    printf("<html><body>\n");

    // For simplicity assume GET with candidate=name&voter_id=xxx
    data = getenv("QUERY_STRING");
    if (!data) {
        printf("<p>No data received</p>");
    } else {
        char voter_id[50] = {0}, cand[50] = {0};
        sscanf(data, "voter_id=%49[^&]&candidate=%49s", voter_id, cand);
        if (has_voted(voter_id)) {
            printf("<p style='color:red;'>You have already voted.</p>\n");
        } else {
            add_voter(voter_id);
            Candidate *c = find_candidate(root, cand);
            if (c) {
                c->votes++;
                printf("<p >Thanks! Your vote for %s has been recorded.</p>\n", cand);
            } else {
                printf("<p>Candidate not found.</p>\n");
            }
        }
    }

    printf("</body></html>\n");
    return 0;
}
