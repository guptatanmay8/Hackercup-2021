#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("weak_typing_chapter_1_input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("weak_typing_chapter_1_output_naiza.txt", "w", stdout);
    #endif   
  int t;
    cin>>t;
    int l = 1;
    while(t--){
        int n;
        cin>>n;
    string s;
    cin>>s;
    int right = 0;
    int curr1 = 1;
    int left = 0;
    int curr2 = 1;
    
    for(int i = 0; i<s.size(); i++){
        char c = s[i];
        if(c=='F') continue;
        if(c=='O'){
            if(curr1==0){
                right++;
                curr1 = 1;
            }
            if(curr2==1){
                left++;
                curr2 = 0;
            }
        }
        if(c=='X'){
            if(curr1==1){
                right++;
                curr1 = 0;
            }
            if(curr2==0){
                curr2= 1;
                left++;
            }
        }
        
    }
    cout << "Case #"<< l <<": "<<min(left,right)<<endl;
    l++;
    }
    return 0;
}