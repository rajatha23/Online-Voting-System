#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int count;
    struct Node *left, *right;
} Node;

Node* insert(Node *root, char *name) {
    if(!root) {
        root = malloc(sizeof(Node));
        strcpy(root->name, name);
        root->count = 0;
        root->left = root->right = NULL;
    } else if(strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name);
    } else if(strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name);
    }
    return root;
}

Node* find_node(Node *root, char *name) {
    if(!root) return NULL;
    int cmp = strcmp(name, root->name);
    if(cmp == 0) return root;
    else if(cmp < 0) return find_node(root->left, name);
    else return find_node(root->right, name);
}

void save_tree(Node *root, FILE *f) {
    if(!root) return;
    save_tree(root->left, f);
    fprintf(f, "%s %d\n", root->name, root->count);
    save_tree(root->right, f);
}

int main(void) {
    printf("Content-Type: text/html\n\n");

    /* ---------------- UI + CSS ---------------- */
    printf("<html><head><style>"
           "body {"
           "   background: linear-gradient(135deg, #4b79a1, #283e51);"
           "   height: 100vh;"
           "   display: flex;"
           "   justify-content: center;"
           "   align-items: center;"
           "   font-family: Arial, sans-serif;"
           "   color: white;"
           "}"
           ".box {"
           "   background: rgba(255,255,255,0.15);"
           "   width: 400px;"
           "   padding: 40px;"
           "   border-radius: 15px;"
           "   backdrop-filter: blur(6px);"
           "   text-align: center;"
           "   box-shadow: 0 0 15px rgba(0,0,0,0.3);"
           "}"
           "h2 { font-size: 28px; margin-bottom: 20px; }"
           "a {"
           "   display: inline-block;"
           "   margin-top: 20px;"
           "   background: #00c6ff;"
           "   padding: 10px 20px;"
           "   color: white;"
           "   border-radius: 8px;"
           "   font-size: 18px;"
           "   text-decoration: none;"
           "}"
           "a:hover { background: #0072ff; }"
           "</style></head><body><div class='box'>");
    /* ---------------- END UI ---------------- */

    char *data = getenv("QUERY_STRING");
    if(!data) {
        printf("<h2>Error!</h2>");
        printf("</div></body></html>");
        return 0;
    }

    char voter_id[50], candidate[50];
    sscanf(data, "voter_id=%49[^&]&candidate=%49s", voter_id, candidate);

    Node *root = NULL;
    root = insert(root, "Moksha");
    root = insert(root, "Rajatha");
    root = insert(root, "Sandhya");

    FILE *f = fopen("C:\\xampp\\data\\votes.txt", "r");
    if(f) {
        char name[50];
        int ct;
        while(fscanf(f, "%s %d", name, &ct) == 2) {
            Node *n = find_node(root, name);
            if(n) n->count = ct;
        }
        fclose(f);
    }

    Node *sel = find_node(root, candidate);
    if(sel) sel->count++;

    f = fopen("C:\\xampp\\data\\votes.txt", "w");
    save_tree(root, f);
    fclose(f);

    f = fopen("C:\\xampp\\data\\voted.txt", "a");
    fprintf(f, "%s\n", voter_id);
    fclose(f);

    printf("<h2>Thank you for voting!</h2>");
    printf("<a href='/index.html'>Go to Home</a>");

    printf("</div></body></html>");

    return 0;
}
