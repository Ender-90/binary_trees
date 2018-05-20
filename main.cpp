#include <iostream>

using namespace std;

struct ele {
    int dane;
    ele * lewy;
    ele * prawy;
};

// Zadanie 1

void preorder(ele * root){
    if(root){
        cout<<root->dane<<" ";
        preorder(root->lewy);
        preorder(root->prawy);
    }
}

void postorder(ele * root){
    if(root){
        postorder(root->lewy);
        postorder(root->prawy);
        cout<<root->dane<<" ";;
    }
}

void inorder(ele * root){
    if(root){
        inorder(root->lewy);
        cout<<root->dane<<" ";;
        inorder(root->prawy);
    }
}

// Zadanie 2

void recurentCount(int &counter, ele * root){
    if(root){
        counter++;
        recurentCount(counter, root->lewy);
        recurentCount(counter, root->prawy);
    }
}

int countNodes(ele * root){
    int counter = 0;
    recurentCount(counter, root);

    return counter;
}

// Zadanie 4 - przy użyciu postorder

ele * addressMaxInTree(ele * root){
    ele * result = root;

    if(root){
        addressMaxInTree(root->lewy);
        addressMaxInTree(root->prawy);
        if(root->dane > result->dane)
            result = root;
    }

    return result;
}

// Zadanie 6 - przy założeniu, że w drzewie BST na lewo są wartości mniejsze, a na prawo - większe

ele * searchInBST(int n, ele * root){

    if(root){
        if(root->dane == n){
            return root;
        }
        if(root->dane > n){
            searchInBST(n, root->lewy);
        }
        if(root->dane < n){
            searchInBST(n, root->prawy);
        }
    }
}

// Zadanie 7 - przy założeniu, że w drzewie BST na lewo są wartości mniejsze, a na prawo - większe

void addToBST(int n, ele * &root){
    if(root){
        if(n > root->dane)
            addToBST(n, root->prawy);
        if(n < root->dane)
            addToBST(n, root->lewy);

    }else{
        ele * tmp = new ele{n, 0, 0};
        root = tmp;
    }
}

void removeFromBST(int n, ele * &root){

}

int main()
{
    ele * korzonek;
    korzonek = 0;

    addToBST(10, korzonek);
    addToBST(12, korzonek);
    addToBST(11, korzonek);
    addToBST(18, korzonek);
    addToBST(3, korzonek);
    addToBST(4, korzonek);

    preorder(korzonek);
    cout<<"\n";
    inorder(korzonek);
    cout<<"\n";
    postorder(korzonek);
    cout<<"\n";

    cout<<countNodes(korzonek)<<"\n";
    cout<<searchInBST(18, korzonek)->dane;

    return 0;
}
