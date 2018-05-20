#include <iostream>

using namespace std;

struct ele {
    int dane;
    ele * lewy;
    ele * prawy;
};

// Exercise 1

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

// Exercise 2

int countNodes(ele * root){

    if(!root)
        return 0;
    else
        return countNodes(root->lewy) + countNodes(root->prawy) + 1;
}


// Exercise 3

int wysokosc(ele * root){
    if(!root)
        return 0;
    else{
        int lewaWys = wysokosc(root->lewy);
        int prawaWys = wysokosc(root->prawy);

        if (lewaWys > prawaWys)
            return lewaWys + 1;
        else return prawaWys + 1;
    }
}


// Exercise 4 - with postorder

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

// Exercise 6

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

// Exercise 7

// Adding to tree is so simple...

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

//... but removing from tree is not simple.

ele * minChildFromRight(ele * &root){
    ele * current = root;
    while(current->lewy != 0)
        current = current->lewy;

    return current;
}

void removeFromBST(int n, ele * &root){

    if(root){
        if(n > root->dane){
            removeFromBST(n, root->prawy);
        }
        else if(n < root->dane){
            removeFromBST(n, root->lewy);
        }
        else{
            ele * tmp = 0;
            if(!root->lewy && !root->prawy){
                delete root;
                root = 0;
                return;
            }else if(!root->lewy)
                tmp = root->prawy;
            else if(!root->prawy)
                tmp = root->lewy;
            else
                tmp = minChildFromRight(root->prawy);

            root->dane = tmp->dane;

            removeFromBST(tmp->dane, root->prawy);
        }
    }
}

// Exercise 8

void cleanTree(ele * &root){
    if(root){
        cleanTree(root->lewy);
        cleanTree(root->prawy);
        delete root;
        root = 0;
    }
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
    cout<<"\n"<<wysokosc(korzonek)<<"\n";

    removeFromBST(12, korzonek);
    preorder(korzonek);
    cout<<"\n";

    ele * root_01;
    root_01 = 0;

    addToBST(70, root_01);
    addToBST(90, root_01);
    addToBST(80, root_01);
    addToBST(170, root_01);
    addToBST(200, root_01);
    addToBST(30, root_01);
    addToBST(15, root_01);
    addToBST(11, root_01);
    addToBST(45, root_01);
    addToBST(33, root_01);
    addToBST(36, root_01);
    addToBST(50, root_01);

    cout<<"\n"<<wysokosc(root_01);
    cout<<"\n"<<countNodes(root_01);

    return 0;
}
