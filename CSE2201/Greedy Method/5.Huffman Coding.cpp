/*
1st:
create node class 
-ch,freq,left,right
2nd:*/
#include<bits/stdc++.h>
using namespace std;
struct huffman{
    char ch;
    int freq;
    huffman *left;
    huffman *right;
};
struct comp{
     bool operator()(huffman *a,huffman *b){
        return a->freq>b->freq; // return small freq
    }
};

void encode(huffman*root,string str, unordered_map<char,string>&huffManCode){
    if(!root) return;
    if(!root->left && !root->right){
        huffManCode[root->ch]=str;
    }
    encode(root->left,str+"0",huffManCode);
    encode(root->right,str+"1",huffManCode);
}
int main()
{
    string text;
    getline(cin,text);
    unordered_map<char,int>fq; // chaar koibar ache tar tracking
    for(auto it: text){
        fq[it]++;
    }
    priority_queue<huffman*,vector<huffman*>,comp>pq;
    for(auto it: fq){
        huffman* node = new huffman{it.first,it.second,nullptr,nullptr};
        pq.push(node);

    }
    while(pq.size()>1){
        huffman *left = pq.top();
        pq.pop();
        huffman *right = pq.top();
        pq.pop();
        huffman* sumNode = new huffman{'\0',left->freq+right->freq,left,right};// ch='\0' cz majher tree char carry kore nah
        //tree dekho only leaves node ra character hold korbe so all majhe null, then parent e jabe small 2tar sum
        pq.push(sumNode);
    }
    huffman* root = pq.top();
    unordered_map<char,string>huffManCode;
    encode(root,"",huffManCode);
    cout<<"Huffman codes\n";
    for(auto it: huffManCode){
        cout<<it.first<<":"<<it.second<<" ";
    }
    string str = "";
    for(auto ch: text){
        str+=huffManCode[ch];
    }
    cout<<endl;
    cout<<"Encoded string: "<<str<<endl;
    return 0;
}