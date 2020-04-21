//
// Created by Administrator on 2020/4/21.
//

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#include <stdlib.h>
#include <unistd.h>
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

   // string http = "GET / HTTP/1.1\ncontent-type:text/html\r\n";
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
    //string s1 = "DO ok chinese";
    //int index = http.find_first_of(s1);
    //cout<<index<<endl;

//    FILE *fp;
//    fp = fopen("test.log","wb");
//    if (fp==NULL)
//    {
//        cout<<"error\n";
//        exit(0);
//    }
//    string content = "japanese";
//    for (int i = 0; i <100000 ; ++i) {
//        content.insert(content.length(),"china is developed countrychina is developed countrychina is developed countrychina is developed countrychina is developed countrychina is developed country\n");
//    }
//    size_t  size=fwrite(content.c_str(),content.length(),1,fp);
//    cout<<size<<endl;
//    fclose(fp);
//    cout<<content<<endl;
//    cout<<content.length()<<endl;

    string s = "ok\r\ngood\r\nnice\r\n";

    string s1= "\r\n";
    for (int i = 0; i <s.substr(s.find(s1)) ; ++i) {

    }

    return 0;
}