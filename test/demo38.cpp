//
// Created by Administrator on 2020/4/21.
//

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{

//    string s1;
//    string s2="china";
//    string s3=s2;
//
//    string s5(5,'b');
//    cout<<s1<<endl;
//    cout<<s2<<endl;
//    cout<<s3<<endl;
//    cout<<s5<<endl;
//
//    cout<<s5.length()<<endl;
//    cout<<s2.find("n",1)<<endl;
//
//    char *name = (char*)"japanese";
//    printf("%s\n",name);
//    for (int i = 0; i <strlen(name) ; ++i) {
//        printf("%c\n",*(name+i));
//    }
//
//    printf("%s\n",s2.c_str());

//    string s;
//    cin>>s;
//    cout<<s<<endl;
    //string s = "123456789";
//    for (int i = 0; i <s.length() ; ++i) {
//        cout<<s[i]<<endl;
//    }
//    string s = "china";
//    string s1 = "japanese";
//    string s2 = s+s1;
//    cout<<s2<<endl;

    //string s = "123456789";
//    cout<<s<<endl;
//    s.insert(2,"800");
//    cout<<s<<endl;
    //cout<<s.erase(2,3)<<endl;
    //cout<<s.erase(3);

    //cout<<s.substr(2,3)<<endl;

    string http = "GET / HTTP/1.1\ncontent-type:text/html\r\n";
    //cout<<http.substr(3);
    //cout<<http.find("GET")<<endl;
    //cout<<http.substr()<<endl;

//    int index = http.rfind("GET",3);
//    cout<<index<<endl;
//    if (index<http.length()){
//        cout<<"find\n";
//    }else{
//        cout<<"not found\n";
//    }
    string s1 = "DO ok chinese";
    int index = http.find_first_of(s1);
    cout<<index<<endl;
    return 0;
}