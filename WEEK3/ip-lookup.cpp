#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* left,* right;
    bool star, end;
};
int activeIPs, employeeIPs;
string IP;
Node root ={NULL,NULL , false, false};



void printTree(Node* node, string prefix = "");
void printTree(Node* node, string prefix) {
    if (!node) return;

    cout << prefix;
    if (node->star) cout << "*";
    if (node->end) cout << "(end)";
    cout << endl;

    if (node->left) {
        cout << prefix << "0→ ";
        printTree(node->left, prefix + "  ");
    }

    if (node->right) {
        cout << prefix << "1→ ";
        printTree(node->right, prefix + "  ");
    }
}

void insertTree(string ip){
    Node* curr = &root;
    for(int i = 0; i < ip.length(); i++){
        if(ip.at(i) == '0'){
            if(!curr->left) curr->left = new Node{NULL,NULL,false,false};
            curr= curr->left;
        }else if(ip.at(i) == '1'){
            if(!curr->right)curr->right = new Node{NULL,NULL,false,false};
            curr= curr->right;
        }else if(ip.at(i) == '*'){
            curr->star = true;
        }else{
            //cout << "Invalid CHAR " << ip.at(i) << endl;
        }
    }
    curr->end = true;
}

bool checkTree(string ip){
    Node* curr = &root;
    for(int i = 0; i < ip.length(); i++){
        if(curr->star) return true;
        if(ip.at(i) == '0'){
            if(curr->left){ curr= curr->left;}
            else{ return false;}
        }else if(ip.at(i) == '1'){
            if(curr->right) {curr= curr->right;}
            else{ return false;}
        }
    }
    return (curr->star || curr->end);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> activeIPs;
    for(int i = 0; i < activeIPs; i++){
        cin >> IP;
        insertTree(IP);
    }
    //printTree(&root);
    cin >> employeeIPs;
    for(int i = 0; i < employeeIPs; i++){
        cin >> IP;
        if(checkTree(IP)){
            cout <<"Yes"<<endl;
        }else{
            cout << "No" <<endl;
        }
    }

}